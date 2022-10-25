begin 
	// SET THE PARAMETERS OF ALL THE NORMAL DISTRIBUTIONS
	set V_sing_order_car_avg = 15
	set V_sing_order_pers_avg = 30
	set V_eat_avg = 20*60 
	set V_sta_oper_time_avg(1) = 12
	set V_sta_oper_time_avg(2) = 35		// meat menu: time to prepare the meat
	set V_sta_oper_time_avg(3) = 35		// veggy menu: time to put the vegan burger
	set V_sta_oper_time_avg(4) = 35		// chicken menu: time to prepare the chicken
	set V_sta_oper_time_avg(5) = 30		// meat menu: time to put the toppings and complete the burger
	set V_sta_oper_time_avg(6) = 25		// veggy menu: time to put the toppings and complete the burger
	set V_sta_oper_time_avg(7) = 30		// chicken menu: time to put the toppings and complete the burger
	set V_sta_oper_time_avg(8) = 15		// chips: time halved as the second improvement of the report (from 30 to 15)
	set V_sta_oper_time_avg(9) = 8
	
	// SET THE DEFAULT COLORS OF THE LABELS
	set LB_waiting_pers color to orange
	set LB_eating_pers color to green
	
	// SET THE BUFFER STOCK SIZE
	set C_stock(1) capacity to 	40	// bread  
	set C_stock(2) capacity to  30	// meat menu: ingredient 1
	set C_stock(3) capacity to  40	// meat menu: ingredient 2
	set C_stock(4) capacity to  40 	// veggy menu: ingredient 1
	set C_stock(5) capacity to 	40	// veggy menu: ingredient 2
	set C_stock(6) capacity to  30	// chicken menu: ingredient 1
	set C_stock(7) capacity to  40	// chicken menu: ingredient 2
	set C_stock(8) capacity to  40	// chips
	set C_stock(9) capacity to  50	// drink
	
	// SET THE NAME OF THE FILES INVOLVED IN THE MODEL
	// AutomoD only accepts .csv or .txt
	set V_file_input_name = "arc/input.csv"
	set V_file_car_w_t_name = "arc/car_waiting_time.txt"
	set V_file_downtime_name = "arc/downtime.txt"
	set V_file_menu_list_name = "arc/menu_list.txt"
	set V_file_pers_w_t_name = "arc/pers_waiting_time.txt"
	
	// EXECUTE THE OTHER FUNCTIONALITIES
	clone 1 load to P_init_output
	clone 1 load to P_init_read_input
	clone 1 load to P_init_stock
end

