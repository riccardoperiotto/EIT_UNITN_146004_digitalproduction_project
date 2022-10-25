begin
	// ADD THE PERSON INTO THE SYSTEM
	print "** PERSON WITH ORDER ", V_order_id, " ARRIVED AT TIME ",ac, "**" to message   
	set this load type = L_person
	inc V_pers_counter by 1
	inc V_pers_current_counter by 1
	
	// select the shortest queue
	if Q_person(1) current <= Q_person(2) current then
		begin
			move into Q_person(1)
			move into Q_totem(1)
		end		
		else
		begin
			move into Q_person(2)
			move into Q_totem(2)
		end
	
	wait for normal V_order_dim*V_sing_order_pers_avg,V_order_dim*5 sec 

	// SEND THE ORDERS OF THE PERSON TO THE MENU GENERATOR
	clone V_order_dim load to P_menu_generator
	set V_order_time to ac
	set V_pers_queue_w_time to (V_order_time - V_arrival_time)/60
	
	// GO TOWARDS THE EATING ROOM
	move into conv_person.person_in
	travel to conv_person.person_out
	move into Q_room
	inc V_pers_room_counter by V_order_dim
	print "Wating: ", Q_room current - V_pers_eating_counter to  LB_waiting_pers
	
	// check the list to see if the whole order (all the menus) are ready
	while V_order_ready <> 1 do begin
		if (OL_take_person current loads > 0) then begin
			wait for 1 sec
			for each V_load_ptr in OL_take_person load list do begin
				if V_load_ptr V_order_id = V_order_id then begin
					inc V_order_level by 1
				end
				if V_order_level = V_order_dim then 
					begin
						set V_order_ready to 1
					break
				end
			end
		end
		wait for 5 sec
		set V_order_level to 0
	end
	
	// all the menus are ready:
	// - set their priority to the menus of the order to 0 (they will be taken by the waiter)
	// - wait for them to be delivered by the waiter
	for each V_load_ptr in OL_take_person load list do begin
			if V_load_ptr V_order_id = V_order_id then begin
				set V_load_ptr priority = V_load_ptr priority - 100
			end
		end
	if V_debug = 1 then 
		begin
			print "-- PERSON ORDER ", V_order_id, ": completation at time ", ac, "; wating for waiter." to message
			print "-- PERSON ORDER ", V_order_id, ": OL_take_person before ordering " to message
			if (OL_take_person current loads > 0) then begin
				for each V_load_ptr in OL_take_person load list do begin
						print "    load for order ", V_load_ptr V_order_id to message	
					end
				end
			else begin
					print "    empty " to message
				end
			print "---- end of OL_take_person ----" to message
		end
	
	order V_order_dim loads from OL_take_person to die
	clone 1 load to P_order_room
	
	if V_debug = 1 then 
		begin
			print "-- PERSON ORDER ", V_order_id, ": OL_take_person after ordering" to message
			if (OL_take_person current loads > 0) then begin
				for each V_load_ptr in OL_take_person load list do begin
						print "    load for order ", V_load_ptr V_order_id to message	
					end
				end
			else begin
					print "    empty " to message
				end
			print "---- end of OL_take_person ----" to message
		end
	
	wait to be ordered on OL_waiting_person
	
	// the order (all the menus) arrived! 
	inc V_pers_eating_counter by 1	
	print "Wating: ",  (Q_room current - V_pers_eating_counter) to LB_waiting_pers
	print "Eating: ", V_pers_eating_counter to  LB_eating_pers
	set V_menu_pers_time to (ac-V_order_time)/60
	open V_file_pers_w_t_name for appending save result as V_file_pers_w_t_ptr
		print (ac-V_order_time)/60, ",", ac to V_file_pers_w_t_ptr // same as V_menu_pers_time
	close V_file_pers_w_t_ptr
	wait for normal V_eat_avg,V_eat_avg/5 sec 
	
	// order has been consumed, the person can go away
	dec V_pers_eating_counter by 1
	dec V_pers_room_counter by V_order_dim
	dec V_pers_current_counter by 1
	dec V_pers_out_counter by 1

	print "Eating: ", V_pers_eating_counter to  LB_eating_pers
	print "*** PERSON ORDER ", V_order_id, " FINISHED TO EAT AND WENT AWAY ", ac, " ***" to message
	send to die
end


