begin
	set this load type = L_stock
	if procindex = 1 then set this color to gold
	else if procindex = 2 then set this load color to red
	else if procindex = 3 then set this color to green
	else if procindex = 4 then set this color to ltgreen
	else if procindex = 5 then set this color to orange
   	else if procindex = 6 then set this color to red orange
   	else if procindex = 7 then set this color to yellow
   	else if procindex = 8 then set this color to green


	while 1 = 1 do 
		begin
			// WAIT TO STOCK TO FINISH AND CALL RESTOCKER USING THE SPECIFIED POLICY
			move into Q_restock
			while C_stock(procindex) current > C_stock(procindex) capacity / 5   do begin // IMPROVED RESTOCK POLICY
			//while C_stock(procindex) current > 0   do begin	// DEFAULT RESTOCK POLICY
				wait for 5 sec
			end
			move into restock.re_stock
			rotate this current container vehicle absolute to z 0
			travel to V_stock_location(procindex)
			
			// REFILL THE STOCK
			set C_stock(procindex) current = C_stock(procindex) capacity 
			
			// -- change the label
			print C_stock(procindex) current, "/", C_stock(procindex) capacity LB_stock(procindex)
			set LB_stock(procindex) color to green
			// -- label changed
			
			print "*** STOCK OF INDEX ", procindex, " REFILLED. CURRENT QUANTITY: ", C_stock(procindex) current, " ***" to message
			rotate this current container vehicle absolute to z 180
		end
end

