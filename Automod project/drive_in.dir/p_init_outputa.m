begin 
	// WRITE HEADER FOR CAR ORDER WAITING TIME FILE
	open V_file_car_w_t_name for writing save result as V_file_car_w_t_ptr
		print "Time elapsed [min],Timestamp [s]" to V_file_car_w_t_ptr
	close V_file_downtime_ptr
	
	// WRITE HEADER FOR DOWNTIME FILE
	open V_file_downtime_name for writing save result as V_file_downtime_ptr
		print "Station [number],Downtime [min],Timestamp [s]" to V_file_downtime_ptr
	close V_file_downtime_ptr
	
	// WRITE HEADER FOR MENU LIST FILE
	open V_file_menu_list_name for writing save result as V_file_menu_list_ptr
		print "OrderId [number],Type [string],Chips [bool],Drink [bool],Value [€], Timestamp [s]" to V_file_menu_list_ptr
	close V_file_menu_list_ptr
	
	// WRITE HEADER FOR PERSON ORDER WAITING TIME FILE
	open V_file_pers_w_t_name for writing save result as V_file_pers_w_t_ptr
		print "Time elapsed [min],Timestamp [s]" to V_file_pers_w_t_ptr
	close V_file_pers_w_t_ptr
end


