begin
	// ADD THE CAR INTO THE SYSTEM
	print "** CAR WITH ORDER ", V_order_id, " ARRIVED AT TIME ", ac, "**" to message
	set this load type = L_car 
	inc V_car_current_counter by 1
	move into conv_car.sta_start
	travel to conv_car.sta_order
	wait for normal 20+V_order_dim*V_sing_order_car_avg,7 sec
	
	// SEND THE ORDERS OF THE CAR TO THE MENU GENERATOR
	clone V_order_dim load to P_menu_generator
	set V_order_time to ac
	set V_car_queue_w_time to (V_order_time - V_arrival_time)/60
	
	// GO TO THE NEXT STATION TO PAY
	travel to conv_car.sta_pay
	use R_op_pay for normal 30,5 sec
	
	// GO TO THE LAST STATION AND WAIT FOR THE ORDER 
	travel to conv_car.sta_take
	
	// check the list as long as the whole order (all the menus) are not ready
	while V_order_ready <> 1 do begin
		if (OL_take_car current loads > 0) then begin
			wait for 1 sec
			for each V_load_ptr in OL_take_car load list do begin
				if V_load_ptr V_order_id = V_order_id then begin
					inc V_order_level by 1
				end
				if V_order_level = V_order_dim then begin
					set V_order_ready to 1
					break
				end
			end
		end
		wait for 5 sec
		set V_order_level to 0
	end
	
	// all the menus are ready, the operator will give them to the car
	use R_op_take_car for normal 15,3 sec
	order V_order_dim loads from OL_take_car to die
	dec V_car_current_counter by 1
	inc V_car_out_counter by 1
	set V_menu_car_time to (ac-V_order_time)/60
	open V_file_car_w_t_name for appending save result as V_file_car_w_t_ptr
		print (ac-V_order_time)/60, ",", ac to V_file_car_w_t_ptr // same as V_menu_car_time
	close V_file_car_w_t_ptr		
	print "*** CAR ORDER ", V_order_id, " COMPLETED AND TAKEN AT TIME ", ac, " ***" to message
	send to die
end

