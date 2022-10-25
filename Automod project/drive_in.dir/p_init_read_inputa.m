begin

	// SET THE BEHAVIOUR REGARDING THE DEBUG MESSAGES
	set V_debug = 1
	
	// READING ORDERS FROM FILE
	print "*** FILE READING STARTED ***" to message
	open V_file_input_name for reading save result as V_file_input_ptr		
	read V_headers from V_file_input_ptr with delimiter "\n"
	// print V_headers  to message
	
	while V_file_input_ptr eof = false do
	begin
		read V_order_id, V_arrival_time, V_order_provenience, V_order_dim from V_file_input_ptr with delimiter ";" at end
		print "    Order read: Id: ", V_order_id, ", time: ", V_arrival_time, ", provenience: ", V_order_provenience, ", dim: ", V_order_dim  to message
		wait for (V_arrival_time - ac) sec 		// need to wait the time of creation of the order, otherwise all orders placed at time 0
		if V_order_provenience = "car" then
			begin
				clone 1 load to P_car
			end
		else
			begin
				clone 1 load to P_person
			end
	end		
	print "*** FILE READING COMPLETED ***" to message
	send to die
end


