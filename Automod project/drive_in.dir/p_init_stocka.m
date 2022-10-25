begin 
	set V_stock_type = "bread"
	set V_stock_location(1) = restock:re_bread
	set C_stock(1) current = C_stock(1) capacity / 2
	set LB_stock(1) color to green
	clone 1 load to P_stock(1)
   	
  	set V_stock_type = "meat1"  	
	set V_stock_location(2) = restock:re_meat_1
	set C_stock(2) current = C_stock(2) capacity / 2 
	set LB_stock(2) color to green
   	clone 1 load to P_stock(2)
   	
   	set V_stock_type = "meat2"
	set V_stock_location(3) = restock:re_meat_2
	set C_stock(3) current =  C_stock(3) capacity / 2
	set LB_stock(3) color to raw umber
   	clone 1 load to P_stock(3)
   	
   	// there is only a point where to load veggy ingredients
   	set V_stock_type = "veggy"
	set V_stock_location(4) = restock:re_veg
	set C_stock(4) current =  C_stock(4) capacity / 2
	set LB_stock(4) color to green
   	clone 1 load to P_stock(4)
   	
   	set V_stock_location(5) = restock:re_veg
   	set C_stock(5) current =  C_stock(5) capacity / 2
   	set LB_stock(5) color to green
   	clone 1 load to P_stock(5)
   	
   	set V_stock_type = "chicken1"
   	set V_stock_location(6) = restock:re_chick_1
   	set C_stock(6) current =  C_stock(6) capacity / 2
   	set LB_stock(6) color to green
   	clone 1 load to P_stock(6)
   	
   	set V_stock_type = "chicken2"
   	set V_stock_location(7) = restock:re_chick_2
   	set C_stock(7) current = C_stock(7) capacity / 2
   	set LB_stock(7) color to green
   	clone 1 load to P_stock(7)
   	
   	set V_stock_type = "chips"   	
   	set V_stock_location(8) = restock:re_chips
   	set C_stock(8) current = C_stock(8) capacity / 2
   	set LB_stock(8) color to green
   	clone 1 load to P_stock(8)
   	
   	set V_stock_type = "drink"
   	set V_stock_location(9) = restock:re_drink
   	set C_stock(9) current = C_stock(9) capacity / 2
   	set LB_stock(9) color to green
   	clone 1 load to P_stock(9)
   	
   	print "*** STOCK FOR EACH OPERATOR REFILLED ***" to message
end

