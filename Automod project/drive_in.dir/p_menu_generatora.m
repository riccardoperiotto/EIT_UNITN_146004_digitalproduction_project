begin
	set this load type = L_menu
	
	// GENERATE THE ORDERED MENU
	set V_menu_pointer = oneof(33:P_menu(1),33:P_menu(2),33:P_menu(3))	
	set V_chips = oneof(25:0,75:1)	
	set V_drink = oneof(10:0,90:1)

	set V_load_type_ptrs(1) = L_bread
	
	// SET THE GRAPHIC PARAMETERS
	if V_menu_pointer = P_menu(1) then 
		begin
			set V_menu_type = "meat"
			set V_load_type_ptrs(2) = L_meat_ing_1
			set V_load_type_ptrs(3) = L_meat_closed
			
			if V_chips = 0 and V_drink=0 then
				begin 
					set V_load_type_ptrs(4) = L_meat_closed
					set V_load_type_ptrs(5) = L_meat_closed
				end
			if V_chips = 1 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_meat_chips
					set V_load_type_ptrs(5) = L_meat_chips
				end
			else if V_chips = 0 and V_drink=1 then
				begin
					set V_load_type_ptrs(4) = L_meat_closed
					set V_load_type_ptrs(5) = L_meat_drink
				end
			else 
				begin
					set V_load_type_ptrs(4) = L_meat_chips
					set V_load_type_ptrs(5) = L_meat_complete
				end
		end
	else if V_menu_pointer = P_menu(2) then
		begin
			set V_menu_type = "veggy"
			set V_load_type_ptrs(2) = L_veggy_ing_1
			set V_load_type_ptrs(3) = L_veggy_closed
			if V_chips = 0 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_veggy_closed
					set V_load_type_ptrs(5) = L_veggy_closed
				end
			else if V_chips = 1 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_veggy_chips
					set V_load_type_ptrs(5) = L_veggy_chips
				end
			else if V_chips = 0 and V_drink=1 then
				begin
					set V_load_type_ptrs(4) = L_veggy_closed
					set V_load_type_ptrs(5) = L_veggy_drink
				end
			else
				begin
					set V_load_type_ptrs(4) = L_veggy_chips
					set V_load_type_ptrs(5) = L_veggy_complete
				end
		end
	else
		begin
			set V_menu_type = "chicken"
			set V_load_type_ptrs(2) = L_chicken_ing_1
			set V_load_type_ptrs(3) = L_chicken_closed
			if V_chips = 0 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_chicken_closed
					set V_load_type_ptrs(5) = L_chicken_closed
				end
			else if V_chips = 1 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_chicken_chips
					set V_load_type_ptrs(5) = L_chicken_chips
				end
			else if V_chips = 0 and V_drink=1 then
				begin
					set V_load_type_ptrs(4) = L_chicken_closed
					set V_load_type_ptrs(5) = L_chicken_drink
				end
			else
				begin
					set V_load_type_ptrs(4) = L_chicken_chips
					set V_load_type_ptrs(5) = L_chicken_complete
					end
		end
	
	// CALCULATE THE MENU PRICE
	if V_menu_pointer = P_menu(1) then set V_menu_value = 7
	if V_menu_pointer = P_menu(2) then set V_menu_value = 5
	if V_menu_pointer = P_menu(3) then set V_menu_value = 6
	
	if V_chips = 1 then set V_menu_value=V_menu_value + 3
	if V_drink = 1 then set V_menu_value=V_menu_value + 2.5
	
	open V_file_menu_list_name for appending save result as V_file_menu_list_ptr
		print V_order_id, ",", V_menu_type, ",", V_chips, ",", V_drink, ",", V_menu_value, ",", ac to V_file_menu_list_ptr
	close V_file_menu_list_ptr
					
	send to V_menu_pointer
end

