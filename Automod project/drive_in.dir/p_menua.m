begin
	set V_menu_counter = V_menu_counter + 1
	set V_menu_processing_time = ac
	
	// ADD BREAD
	move into conv.sta_bread
	set V_station_proc_time = ac
	if C_stock(1) current = 0  then
		begin
			while C_stock(1) current = 0 do
				begin
					wait for 2 sec
				end
			if V_debug = 1 then
				begin
					open V_file_downtime_name for appending save result as V_file_downtime_ptr
						print 1, ",", (ac - V_station_proc_time)/60, ",", ac to V_file_downtime_ptr
					close V_file_downtime_ptr
					print "  # Downtime for station ", 1, " ", ac - V_station_proc_time to message
				end
			set V_stock_downtime = V_stock_downtime +(ac-V_station_proc_time)/60
		end
	dec C_stock(1) by 1

	// -- LB_bread_qty: change of  label -- 
	print C_stock(1) current, "/", C_stock(1) capacity to LB_stock(1)
	if C_stock(1) current < C_stock(1) capacity / 10 then
		begin
			set LB_stock(1) color to red
		end
	else if C_stock(1) current < C_stock(1) capacity * 3 / 10 then
		begin
			set LB_stock(1) color to yellow
		end
	// -- LB_bread_qty: label changed --	
	
	use R_op_bread for normal V_sta_oper_time_avg(1),V_sta_oper_time_avg(1)/5 sec // maxdev = avg/5
	set V_station_proc_time = ac - V_station_proc_time
	set V_sta_proc_time_ratio(1) = V_station_proc_time / V_sta_oper_time_avg(1)
	tabulate V_sta_proc_time_ratio(1) in T_sta_proc_time_ratio(1)
	if V_debug = 1 then
		begin
			print "    Menu of type ", procindex, ": bread added in ", V_station_proc_time, " sec" to message 
		end
		
	set this load type = V_load_type_ptrs(1)
	
	
	// ADD FIRST INGREDIENT
	set V_station_proc_time = ac
	travel to conv.sta_first_ing_(procindex)
	if C_stock(2*procindex) current = 0  then
		begin
			while C_stock(2*procindex) current = 0 do
				begin
					wait for 2 sec
				end
			if V_debug = 1 then
				begin
					open V_file_downtime_name for appending save result as V_file_downtime_ptr
						print 2*procindex, ",", (ac - V_station_proc_time)/60, ",", ac to V_file_downtime_ptr
					close V_file_downtime_ptr
					print "  # Downtime for station ", 2*procindex, " ", ac-V_station_proc_time to message
				end
			set V_stock_downtime = V_stock_downtime +(ac-V_station_proc_time)/60
		end
	dec C_stock(2*procindex) by 1
	
	// -- LB_stock(2*procindex): change of  label -- 
	print C_stock(2*procindex) current, "/", C_stock(2*procindex) capacity to LB_stock(2*procindex)
	if C_stock(2*procindex) current < C_stock(2*procindex) capacity / 10 then
		begin
			set LB_stock(2*procindex) color to red
		end
	else if C_stock(2*procindex) current < C_stock(2*procindex) capacity * 3 / 10 then
		begin
			set LB_stock(2*procindex) color to yellow
		end
	// -- LB_first_ing_qty(2*procindex): label changed --
	
	use R_op_first(procindex) for normal V_sta_oper_time_avg(2*procindex),V_sta_oper_time_avg(2*procindex)/5 sec // maxdev = avg/5
	set V_station_proc_time = ac - V_station_proc_time
	set V_sta_proc_time_ratio(2*procindex) = V_station_proc_time / V_sta_oper_time_avg(2*procindex)
	tabulate V_sta_proc_time_ratio(2*procindex) in T_sta_proc_time_ratio(2*procindex)
	if V_debug = 1 then
		begin
			print "    Menu of type ", procindex, ": first ing added in ", V_station_proc_time, " sec" to message  
		end
		
	set this load type = V_load_type_ptrs(2)

	
	// ADD SECOND INGREDIENT
	set V_station_proc_time = ac
	travel to conv.sta_second_ing_(procindex)
	if C_stock(1+2*procindex) current = 0 then
		begin
			while C_stock(1+2*procindex) current = 0 do
				begin
					wait for 2 sec
				end
				if V_debug = 1 then
					begin
						open V_file_downtime_name for appending save result as V_file_downtime_ptr
							print 1+2*procindex, ",", (ac - V_station_proc_time)/60, ",", ac to V_file_downtime_ptr
						close V_file_downtime_ptr
						print "  # Downtime for station ", 1+2*procindex, " ", ac-V_station_proc_time to message
					end
				set V_stock_downtime = V_stock_downtime +(ac-V_station_proc_time)/60
		end
	dec C_stock(1+2*procindex) by 1
	
	// -- LB_stock(1+2*procindex): change of  label -- 
	print C_stock(1+2*procindex) current, "/", C_stock(1+2*procindex) capacity to LB_stock(1+2*procindex)
	if C_stock(1+2*procindex) current < C_stock(1+2*procindex) capacity / 10 then
		begin
			set LB_stock(1+2*procindex) color to red
		end
	else if C_stock(1+2*procindex) current < C_stock(1+2*procindex) capacity * 3 / 10 then
		begin
			set LB_stock(1+2*procindex) color to yellow
		end
	// -- LB_stock(1+2*procindex): label changed --
	
	use R_op_second(procindex) for normal V_sta_oper_time_avg(1+2*procindex),V_sta_oper_time_avg(1+2*procindex)/5 sec // maxdev = avg/5
	set V_station_proc_time = ac - V_station_proc_time
	set V_sta_proc_time_ratio(1+2*procindex) = V_station_proc_time / V_sta_oper_time_avg(1+2*procindex)
	tabulate V_sta_proc_time_ratio(1+2*procindex) in T_sta_proc_time_ratio(1+2*procindex)
	if V_debug = 1 then
		begin
			print "    Menu of type ", procindex, ": second ing added in ", V_station_proc_time, " sec" to message 
		end	
	set this load type = V_load_type_ptrs(3)
	
	// ADD CHIPS
	if V_chips = 1 then 
		begin
			set V_station_proc_time = ac
			travel to conv.sta_chips
			if C_stock(8) current = 0 then
				begin
					while C_stock(8) current = 0 do
						begin
							wait for 2 sec
						end
						if V_debug = 1 then
							begin
								open V_file_downtime_name for appending save result  as V_file_downtime_ptr
									print 8, ",", (ac - V_station_proc_time)/60, ",", ac to V_file_downtime_ptr
								close V_file_downtime_ptr	
								print "  # Downtime for station ", 8, " ", ac-V_station_proc_time to message
							end
						set V_stock_downtime = V_stock_downtime +(ac-V_station_proc_time)/60
				end
			dec C_stock(8) by 1
			
			// -- LB_stock(8): change of  label -- 
			print C_stock(8) current, "/", C_stock(8) capacity to LB_stock(8)
			if C_stock(8) current < C_stock(8) capacity / 10 then
				begin
					set LB_stock(8) color to  red
				end
			else if C_stock(8) current < C_stock(8) capacity * 3 / 10 then
				begin
					set LB_stock(8) color to yellow
				end
			// -- LB_stock(8): label changed --
	
			use R_op_chips for normal V_sta_oper_time_avg(8),V_sta_oper_time_avg(8)/5 sec // maxdev = avg/5
			
			set V_station_proc_time = ac - V_station_proc_time
			set V_sta_proc_time_ratio(8) = V_station_proc_time / V_sta_oper_time_avg(8)
			tabulate V_sta_proc_time_ratio(8) in T_sta_proc_time_ratio(8)
			if V_debug = 1 then
				begin
					print "    Menu of type ", procindex, ": chips added in ", V_station_proc_time, " sec" to message   
				end
			set this load type = V_load_type_ptrs(4)
		end

	
	// ADD DRINKS
	if V_drink=1 then 
		begin
			set V_station_proc_time = ac
			travel to conv.sta_drink
			if C_stock(9) current = 0 then
				begin			
					while C_stock(9) current = 0 do
						begin
							wait for 2 sec
						end
						if V_debug = 1 then
							begin
								open V_file_downtime_name for appending save result as V_file_downtime_ptr
									print 9, ",", (ac - V_station_proc_time)/60, ",", ac to V_file_downtime_ptr
								close V_file_downtime_ptr	
								print "  # Downtime for station ", 9, " ", ac-V_station_proc_time to message
							end
						set V_stock_downtime = V_stock_downtime +(ac-V_station_proc_time)/60
				end
			dec C_stock(9) by 1
			
			// -- LB_stock(9): change of  label -- 
			print C_stock(9) current, "/", C_stock(9) capacity to LB_stock(9)
			if C_stock(9) current < C_stock(9) capacity / 10 then
				begin
					set LB_stock(9) color to red
				end
			else if C_stock(9) current < C_stock(9) capacity * 3 / 10 then
				begin
					set LB_stock(9) color to yellow
				end
			// -- LB_stock(9): label changed --
	
			use R_op_drink for normal V_sta_oper_time_avg(9),V_sta_oper_time_avg(9)/5 sec // maxdev = avg/5
			
			set V_station_proc_time = ac - V_station_proc_time
			set V_sta_proc_time_ratio(9) = V_station_proc_time / V_sta_oper_time_avg(9)
			tabulate V_sta_proc_time_ratio(9) in T_sta_proc_time_ratio(9)
			if V_debug = 1 then
						begin
							print "    Menu of type ", procindex, ": drink added in ", V_station_proc_time, " sec" to message  
						end
						
			set this load type =  V_load_type_ptrs(5)
		end

	
	// MENU COMPLETED, GET PROCESSING TIME
	set V_menu_processing_time = (ac - V_menu_processing_time)/60
	
	if V_debug = 1 then
		begin
			print "    Order ", V_order_id, ": finished in ", V_menu_processing_time, " min" to message  
		end
		
	// SEND TOWARDS THE CORRECT DIRECTION
	if V_order_provenience = "car" then
		begin
			// print "travelling to car"
			travel to conv.sta_car
			move into Q_take_car
			
			// final setting to hand in the order
			// take out the order from the conveyor and put it in the "bag" for the delivery
			use R_op_take_car for 5 sec	
			wait to be ordered on OL_take_car
		end
	else 
		begin
			// print "travelling to room"
			travel to conv.sta_room
			
			// take out the order from the conveyor
			// final setting to hand in the order will be performed by the waiter
			// the time to prepare the final order is modelled with the pick-up time
			move into Q_take_person
			set priority to V_pers_counter
			wait to be ordered on OL_take_person
		end
end


