model: drive_in

	distance units m
	time units sec

movement systems:
	conv
	conv_car
	conv_person
	restock
	waiter
;
processes:
	P_read
	P_car
	P_person
	P_menu(3)
	P_order_room
	P_stock(9)
	P_init_stock
	P_menu_generator
	P_init_parameters
;
load types:
	L_dummy
		create every constant 0 sec
		first one at constant 0 sec
		generation limit 1
		first process P_read
		create every constant 0 sec
		first one at constant 0 sec
		generation limit 1
		first process P_init_stock
		create every constant 0 sec
		first one at constant 0 sec
		generation limit 1
		first process P_init_parameters
	L_menu
	L_person
	L_car
	L_order_room
	L_stock
	L_chicken_ing_1
	L_chicken_ing_2
	L_meat_ing_1
	L_meat_ing_2
	L_veggy_ing_1
	L_veggy_ing_2
	L_veggy_complete
	L_meat_complete
	L_chicken_complete
	L_bread
	L_veggy_drink
	L_meat_drink
	L_chicken_drink
	L_veggy_chips
	L_meat_chips
	L_chicken_chips
	L_chicken_closed
	L_meat_closed
	L_veggy_closed
;
attributes:
	String V_order_id
	Integer V_order_time
	String V_order_provenience
	Integer V_order_dim
	Real V_order_value
	String V_type
	Integer V_drink
	Integer V_chips
	ProcessPtr V_menu_pointer
	String V_stock_type
	Location V_stock_location(9)
	Integer V_order_ready
	Integer V_order_level
	LoadPtr V_load_ptr
	LoadTypePtr V_load_type_ptrs(5)
;
queues:
	Q_person(2) capacity infinite
	Q_totem(2) capacity 1
	Q_room capacity infinite
	Q_take_car capacity infinite
	Q_take_person capacity infinite
	Q_restock capacity infinite
;
order lists:
	OL_take_car
	sort by load attribute V_order_id with lowest value first
	If tie then use FIFO as tie breaker
	OL_take_person
	sort by priority with lowest value first
	If tie then use FIFO as tie breaker
	OL_waiting_person
	sort by entry time with lowest value first
	If tie then use FIFO as tie breaker
;
counters:
	C_stock(9) capacity infinite
	C_menu capacity infinite
	C_person capacity infinite
	C_car capacity infinite
	C_order capacity infinite
;
resources:
	R_op_bread capacity 1
		processing time constant 5 sec
	R_op_first(3) capacity 1
		processing time constant 5 sec
	R_op_second(3) capacity 1
		processing time constant 5 sec
	R_op_chips capacity 1
		processing time constant 5 sec
	R_op_drink capacity 1
		processing time constant 5 sec
	R_op_take_car capacity 1
		processing time constant 5 sec
	R_op_pay capacity 1
		processing time constant 5 sec
;
variables:
	FilePtr V_file_ptr
	Integer V_car_counter
	String V_headers
	Integer V_debug
	Time V_sing_order_car_avg
	Time V_sing_order_pers_avg
	Integer V_eat_avg
	Time V_bread_avg
	Time V_first_ing_avg(3)
	Time V_second_ing_avg(3)
	Time V_chips_avg
	Time V_drink_avg
;
User files:
P_reada.m
P_persona.m
P_cara.m
P_menua.m
P_menu_generatora.m
P_order_rooma.m
P_init_stocka.m
P_stocka.m
P_init_parametersa.m
;

	conveyor: conv	System Identification: 6
		minimum transfer angle is 45 deg
		maximum transfer angle is 135 deg

	section sec2
		length 3e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 2.5e+006 m to sec20 at 0 m
		transfer ahead at 2.5e+006 m to sec19 at 0 m
		transfer ahead at 3e+006 m to sec2_1 at 0 m
		transfer ahead at 3e+006 m to sec20 at 463648 m
		transfer ahead at 3e+006 m to sec19 at 463648 m
	section sec10
		length 7e+006 m
		width 0.60 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 7e+006 m to sec22 at 0 m
		transfer ahead at 7e+006 m to sec21 at 0 m
	section sec19
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 463648 m to sec2_1 at 0 m
		transfer ahead at 1.5708e+006 m to sec19_1 at 0 m
	section sec20
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 463648 m to sec2_1 at 0 m
		transfer ahead at 1.5708e+006 m to sec20_1 at 0 m
	section sec10_2
		length 4.5e+006 m
		width 0.60 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
	section sec19_1
		length 1e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1e+006 m to sec19_2 at 0 m
	section sec19_2
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec19_3 at 0 m
	section sec19_3
		length 5e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 5e+006 m to sec19_4 at 0 m
	section sec19_4
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec19_5 at 0 m
	section sec19_5
		length 1e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1e+006 m to sec19_6 at 0 m
	section sec19_6
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec10 at 2e+006 m
	section sec2_1
		length 7.5e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 6.5e+006 m to sec10 at 0 m
		transfer ahead at 7.5e+006 m to sec10 at 1e+006 m
	section sec20_1
		length 1e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1e+006 m to sec20_2 at 0 m
	section sec20_2
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec20_3 at 0 m
	section sec20_3
		length 5e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 5e+006 m to sec20_4 at 0 m
	section sec20_4
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec20_5 at 0 m
	section sec20_5
		length 1e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1e+006 m to sec20_6 at 0 m
	section sec20_6
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec10 at 2e+006 m
	section sec22_1
		length 1.5e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
	section sec21
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec10_2 at 0 m
	section sec22
		length 1.5708e+006 m
		width 0.6 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.5708e+006 m to sec22_1 at 0 m

	conveyor: conv_car	System Identification: 6
		minimum transfer angle is 45 deg
		maximum transfer angle is 135 deg

	section sec5
		length 1.6e+007 m
		width 2.5 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 1.6e+007 m to sec7 at 0 m
	section sec6
		length 2.6e+007 m
		width 2.5 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
	section sec7
		length 7.85398e+006 m
		width 2.5 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  
		transfer ahead at 7.85398e+006 m to sec6 at 0 m

	conveyor: conv_person	System Identification: 6
		minimum transfer angle is 45 deg
		maximum transfer angle is 135 deg

	section sec1
		length 7e+006 m
		width 1 m
		velocity  
			number of fixed interval sizes 0			no accumulation
			moving space  
			stopping space  
			induction space  

Path Mover: restock	System Identification: 2
	control point capacity 0
			release 
	path path6
		from 400000, 1e+007, 0	to 400000, 1.05e+007, 0
		Bidirectional  length 500000 m
	path path7
		from 3.4e+006, 1e+007, 0	to 3.4e+006, 1.05e+007, 0
		Bidirectional  length 500000 m
	path path9
		from 1.36e+007, 1e+007, 0	to 1.36e+007, 0, 0
		Bidirectional  length 1e+007 m
	path path14
		from 9e+006, 4e+006, 0	to 1.31e+007, 4e+006, 0
		Bidirectional  length 4.1e+006 m
	path path16
		from 1.31e+007, 4e+006, 0	to 1.36e+007, 3.5e+006, 0
		Bidirectional  length 785398 m
	path path17
		from -6.1e+006, 1.1e+007, 0	to 1.26e+007, 1.1e+007, 0
		Bidirectional  length 1.87e+007 m
	path path19
		from 400000, 1.05e+007, 0	to 900000, 1.1e+007, 0
		Bidirectional  length 785398 m
	path path20
		from 3.4e+006, 1.05e+007, 0	to 3.9e+006, 1.1e+007, 0
		Bidirectional  length 785398 m
	path path21
		from 1.26e+007, 1.1e+007, 0	to 1.36e+007, 1e+007, 0
		Bidirectional  length 1.5708e+006 m
	path path23
		from 400000, 0, 0	to 400000, -500000, 0
		Bidirectional  length 500000 m
	path path24
		from 3.4e+006, 0, 0	to 3.4e+006, -500000, 0
		Bidirectional  length 500000 m
	path path25
		from 1.26e+007, -1e+006, 0	to -3.5e+006, -1e+006, 0
		Bidirectional  length 1.61e+007 m
	path path26
		from 400000, -500000, 0	to 900000, -1e+006, 0
		Bidirectional  length 785398 m
	path path27
		from 3.9e+006, -1e+006, 0	to 3.4e+006, -500000, 0
		Bidirectional  length 785398 m
	path path28
		from 1.36e+007, 0, 0	to 1.26e+007, -1e+006, 0
		Bidirectional  length 1.5708e+006 m
	path path29
		from 1.6e+007, 8e+006, 0	to 1.6e+007, 3e+006, 0
		Bidirectional  length 5e+006 m
	path path30
		from 1.5e+007, 2e+006, 0	to 1.41e+007, 2e+006, 0
		Bidirectional  length 900000 m
	path path31
		from 1.6e+007, 3e+006, 0	to 1.5e+007, 2e+006, 0
		Bidirectional  length 1.5708e+006 m
	path path35
		from -6.6e+006, 7e+006, 0	to -6.6e+006, 1.05e+007, 0
		Bidirectional  length 3.5e+006 m
	path path36
		from -6.6e+006, 1.05e+007, 0	to -6.1e+006, 1.1e+007, 0
		Bidirectional  length 785398 m
	path path32
		from 1.36e+007, 2.5e+006, 0	to 1.41e+007, 2e+006, 0
		Bidirectional  length 785398 m
	path path33
		from 1.41e+007, 2e+006, 0	to 1.36e+007, 1.5e+006, 0
		Bidirectional  length 785398 m
	path path34
		from 6.4e+006, 6.4e+006, 0	to 1.31e+007, 6.4e+006, 0
		Bidirectional  length 6.7e+006 m
	path path37
		from 1.31e+007, 6.4e+006, 0	to 1.36e+007, 5.9e+006, 0
		Bidirectional  length 785398 m
	path path38
		from 1.36e+007, 6.9e+006, 0	to 1.31e+007, 6.4e+006, 0
		Bidirectional  length 785398 m
	path path39
		from -4e+006, 3e+006, 0	to -4e+006, -500000, 0
		Bidirectional  length 3.5e+006 m
	path path41
		from -3.5e+006, -1e+006, 0	to -4e+006, -500000, 0
		Bidirectional  length 785398 m
	;
	control points:

	lists of control points:
		list list_start_r
		re_stock
		;

	point re_drink path path35 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_meat_1 path path7 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_meat_2 path path6 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_bread path path14 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_chick_1 path path24 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_chick_2 path path23 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_stock path path29 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		work search list
			at re_stock
		park search list
			at re_stock

	point re_chips path path39 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	point re_veg path path34 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at re_stock

	vehicles:
type re_stocker
	number of vehicles 1
	starting locations list list_start_r
			when empty (default)
				acceleration 0.3 Meters / Seconds / Seconds
				deceleration 0.3 Meters / Seconds / Seconds
				forward velocity 1 Meters / Seconds
				forward curve velocity 1 Meters / Seconds
				forward spur velocity 1 Meters / Seconds
				reverse velocity 1 Meters / Seconds
				reverse curve velocity 1 Meters / Seconds
				reverse spur velocity 1 Meters / Seconds
				crab velocity 1 Meters / Seconds
				rotation velocity 2 deg/sec
			when carrying type re_stocker:Empty loads
				acceleration default 
				deceleration default 
				forward velocity default 
				forward curve velocity default 
				forward spur velocity default 
				reverse velocity default 
				reverse curve velocity default 
				reverse spur velocity default 
				crab velocity default 
				rotation velocity default 
;


Path Mover: waiter	System Identification: 2
	control point capacity 0
			release 
	path path3
		from -9e+006, 3e+006, 0	to -9.5e+006, 3e+006, 0
		Bidirectional  length 500000 m
	path path4
		from -1e+007, 2.5e+006, 0	to -1e+007, -3.2e+006, 0
		Bidirectional  length 5.7e+006 m
	path path5
		from -9.5e+006, 3e+006, 0	to -1e+007, 2.5e+006, 0
		Bidirectional  length 785398 m
	;
	control points:

	lists of control points:
		list list_start_w
		w_room_in
		;

	point w_room_out path path4 distance 5.5e+006 m
		capacity 2147483647
		parking enroute limit -1
		park search list
			at w_room_in

	point w_room_in path path3 distance 0 m
		capacity 2147483647
		parking enroute limit -1
		work search list
			at w_room_in

	vehicles:
type waiter
	number of vehicles 1
	starting locations random
			when empty (default)
				acceleration 0.3 Meters / Seconds / Seconds
				deceleration 0.3 Meters / Seconds / Seconds
				forward velocity 1 Meters / Seconds
				forward curve velocity 1 Meters / Seconds
				forward spur velocity 1 Meters / Seconds
				reverse velocity 1 Meters / Seconds
				reverse curve velocity 1 Meters / Seconds
				reverse spur velocity 1 Meters / Seconds
				crab velocity 1 Meters / Seconds
				rotation velocity 2 deg/sec
			when carrying type waiter:Empty loads
				acceleration default 
				deceleration default 
				forward velocity default 
				forward curve velocity default 
				forward spur velocity default 
				reverse velocity default 
				reverse curve velocity default 
				reverse spur velocity default 
				crab velocity default 
				rotation velocity default 
;

Process System Identification: 0
source file description:
process: P_read
	traffic limit infinite
	send to die
	procedure when arriving
begin

	// SET THE BEHAVIOUR REGARDING THE DEBUG MESSAGES
	set V_debug = 1
	// READING ORDERS FROM FILE
	open "arc/input.csv" for reading save result as V_file_ptr		// AutomoD only accepts .csv or .txt
	
	read V_headers from V_file_ptr with delimiter "\n"
	// print V_headers  to message
	
	while V_file_ptr eof = false do
	begin
		read V_order_id, V_order_time, V_order_provenience, V_order_dim, V_order_value from V_file_ptr with delimiter ";" at end
		print "Per ordine " V_order_id, " time: ", V_order_time  to message
		wait for (V_order_time - ac) sec 		// need to wait the time of creation of the order, otherwise all orders placed at time 0
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


;
P_car
	traffic limit infinite
	send to die
	procedure when arriving
begin
	// ADD THE CAR INTO THE SYSTEM
	print "** CAR WITH ORDER ", V_order_id, " ARRIVED AT TIME ", ac, "**" to message
	set this load type = L_car 
	inc C_car by 1
	
	move into conv_car.sta_start
	travel to conv_car.sta_order
	wait for normal 20+V_order_dim*V_sing_order_car_avg,7 sec
	
	// SEND THE ORDERS OF THE CAR TO THE MENU GENERATOR
	clone V_order_dim load to P_menu_generator
	
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
	print "*** CAR ORDER ", V_order_id, " COMPLETED AND TAKEN AT TIME ", ac, " ***" to message
	send to die
end

;
P_person
	traffic limit infinite
	send to die
	procedure when arriving
begin
	// ADD THE PERSON INTO THE SYSTEM
	print "** PERSON WITH ORDER ", V_order_id, " ARRIVED AT TIME ",ac, "**" to message   
	set this load type = L_person
	inc C_person by 1
	
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
	
	// GO TOWARDS THE EATING ROOM
	move into conv_person.person_in
	travel to conv_person.person_out
	move into Q_room
	
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
	
	// the order (all the menus) arrived! Eat them and exit the room
	wait for normal V_eat_avg,V_eat_avg/5 sec 
	print "*** PERSON ORDER ", V_order_id, " FINISHED TO EAT AND WENT AWAY ", ac, " ***" to message
	send to die
end




/*
print "---------Finito il processo (order_room) la lista di ordini contiene---------" to message
	for each V_load_ptr in OL_take_person load list do 
		begin
			print "LOAD dell'ordine ", V_load_ptr V_order_id to message	
		end
	print "---------" to message*/
	
/*print "La persone con ordine ", V_order_id, " finisce di mangiare e se ne va" to message
	print "---------Nella room abbiamo le persone---------" to message
	for each V_load_ptr in Q_room load list do 
		begin
			print "PERSONA con ordine ", V_load_ptr V_order_id to message	
		end
	print "---------" to message*/



	// old instruction before priority
	// order V_order_dim loads satisfying V_order_id = this load V_order_id from OL_take_person to die

;
P_menu(3)
	traffic limit infinite
	send to die
	procedure when arriving
begin

	// ADD BREAD
	move into conv.sta_bread
	while C_stock(1) current = 0 do
		begin
			wait for 2 sec
		end
	dec C_stock(1) by 1
	use R_op_bread for normal V_bread_avg,V_bread_avg/5 sec // maxdev = avg/5
	set this load type = V_load_type_ptrs(1)
	
	// ADD FIRST INGREDIENT
	travel to conv.sta_first_ing_(procindex)
	while C_stock(1+procindex) current = 0 do
		begin
			wait for 2 sec
		end
	dec C_stock(1+procindex) by 1
	use R_op_first(procindex) for normal V_first_ing_avg(procindex),V_first_ing_avg(procindex)/5 sec // maxdev = avg/5
	set this load type = V_load_type_ptrs(2)
	
	// ADD SECOND INGREDIENT
	travel to conv.sta_second_ing_(procindex)
	while C_stock(1+procindex*2) current = 0 do
		begin
			wait for 2 sec
		end
	dec C_stock(1+procindex*2) by 1
	use R_op_second(procindex) for normal V_second_ing_avg(procindex),V_second_ing_avg(procindex)/5 sec // maxdev = avg/5
	set this load type = V_load_type_ptrs(3)
	
	// ADD CHIPS
	travel to conv.sta_chips
	while C_stock(8) current = 0 do
		begin
			wait for 2 sec
		end
	dec C_stock(8) by 1
	use R_op_chips for normal V_chips_avg,V_chips_avg/5 sec // maxdev = avg/5
	set this load type = V_load_type_ptrs(4)
	
	// ADD DRINKS
	travel to conv.sta_drink
	while C_stock(9) current = 0 do
		begin
			wait for 2 sec
		end
	dec C_stock(9) by 1
	use R_op_drink for normal V_drink_avg,V_drink_avg/5 sec // maxdev = avg/5
	set this load type =  V_load_type_ptrs(5)
	
	// SEND TOWARDS THE CORRECT DIRECTION
	if V_order_provenience = "car" then
		begin
			print "travelling to car"
			travel to conv.sta_car
			move into Q_take_car
			
			// final setting to hand in the order
			// take out the order from the conveyor and put it in the "bag" for the delivery
			use R_op_take_car for 5 sec	
			wait to be ordered on OL_take_car
		end
	else 
		begin
			print "travelling to room"
			travel to conv.sta_room
			
			// take out the order from the conveyor
			// final setting to hand in the order will be performed by the waiter
			// the time to prepare the final order is modelled with the pick-up time
			move into Q_take_person
			set priority to C_person current
			wait to be ordered on OL_take_person
		end
end

;
P_order_room
	traffic limit infinite
	send to die
	procedure when arriving
begin
	set this load type = L_order_room	
	move into waiter.w_room_in
	travel to waiter.w_room_out
	order 1 loads satisfying V_order_id = this load V_order_id from OL_waiting_person to continue
	send to die
end


;
P_stock(9)
	traffic limit infinite
	send to die
	procedure when arriving
begin
	set this load type = L_stock
	
	while 1 = 1 do 
		begin
			move into Q_restock
			while C_stock(procindex) current >= 5 do begin
				wait for 5 sec
			end
	
			move into restock.re_stock
			travel to V_stock_location(procindex)
			
			set C_stock(procindex) current = C_stock(procindex) current + 30
			print "*** STOCK OF INDEX ", procindex, " REFILLED. CURRENT QUANTITY: ", C_stock(procindex) current, " ***" to message
		end
end

;
P_init_stock
	traffic limit infinite
	send to die
	procedure when arriving
begin 
	set V_stock_type = "bread"
	set V_stock_location(1) = restock:re_bread
	set C_stock(1) current = 30
	clone 1 load to P_stock(1)
   	
  	set V_stock_type = "meat1"  	
	set V_stock_location(2) = restock:re_meat_1
	set C_stock(2) current = 100
   	clone 1 load to P_stock(2)
   	
   	set V_stock_type = "meat2"
	set V_stock_location(3) = restock:re_meat_2
	set C_stock(3) current = 100
   	clone 1 load to P_stock(3)
   	
   	// there is only a point where to load veggy ingredients
   	set V_stock_type = "veggy"
	set V_stock_location(4) = restock:re_veg
	set C_stock(4) current = 100
   	clone 1 load to P_stock(4)
   	
   	set V_stock_location(5) = restock:re_veg
   	set C_stock(5) current = 30
   	clone 1 load to P_stock(5)
   	
   	set V_stock_type = "chicken1"
   	set V_stock_location(6) = restock:re_chick_1
   	set C_stock(6) current = 100
   	clone 1 load to P_stock(6)
   	
   	set V_stock_type = "chicken2"
   	set V_stock_location(7) = restock:re_chick_2
   	set C_stock(7) current = 100
   	clone 1 load to P_stock(7)
   	
   	set V_stock_type = "drink"
   	set V_stock_location(8) = restock:re_drink
   	set C_stock(8) current = 100
   	clone 1 load to P_stock(8)
   	
   	set V_stock_type = "chips"   	
   	set V_stock_location(9) = restock:re_chips
   	set C_stock(9) current = 100
   	clone 1 load to P_stock(9)
   	
   	print "*** STOCK FOR EACH OPERATOR REFILLED ***" to message
end

;
P_menu_generator
	traffic limit infinite
	send to die
	procedure when arriving
begin
	set this load type = L_menu
	set V_menu_pointer = oneof(33:P_menu(1),33:P_menu(2),33:P_menu(3))	
	set V_chips = oneof(50:0,50:1)	
	set V_drink = oneof(50:0,50:1)

	set V_load_type_ptrs(1) = L_bread
	
	if V_menu_pointer = P_menu(1) then 
		begin
			set V_load_type_ptrs(2) = L_meat_ing_1
			set V_load_type_ptrs(3) = L_meat_ing_2
			if V_chips = 0 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_meat_closed
					set V_load_type_ptrs(5) = L_meat_closed
				end
			else if V_chips = 1 and V_drink=0 then
				begin
					set V_load_type_ptrs(4) = L_meat_chips
					set V_load_type_ptrs(5) = L_meat_chips
				end
			else if V_chips = 0 and V_drink=1 then
				begin
					set V_load_type_ptrs(4) = L_meat_drink
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
			set V_load_type_ptrs(2) = L_veggy_ing_1
			set V_load_type_ptrs(3) = L_veggy_ing_2
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
					set V_load_type_ptrs(4) = L_veggy_drink
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
			set V_load_type_ptrs(2) = L_chicken_ing_1
			set V_load_type_ptrs(3) = L_chicken_ing_2
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
					set V_load_type_ptrs(4) = L_chicken_drink
					set V_load_type_ptrs(5) = L_chicken_drink
				end
			else
				begin
					set V_load_type_ptrs(4) = L_chicken_chips
					set V_load_type_ptrs(5) = L_chicken_complete
					end
		end
	send to V_menu_pointer
end

;
P_init_parameters
	traffic limit infinite
	send to die
	procedure when arriving
begin 
	set V_sing_order_car_avg = 15
	set V_sing_order_pers_avg = 30
	set V_eat_avg = 20*60 
	set V_bread_avg = 20
	set V_first_ing_avg(1) = 40		// meat menu: time to prepare the meat
	set V_first_ing_avg(2) = 30		// veggy menu: time to put the vegan burger
	set V_first_ing_avg(3) = 35		// chicken menu: time to prepare the chicken
	set V_second_ing_avg(1) = 30	// meat menu: time to prepare the cheese
	set V_second_ing_avg(2) = 5		// veggy menu: time to put the cocumber
	set V_second_ing_avg(3) = 7		// chicken menu: time to put the tomatoes
	set V_chips_avg = 15
	set V_drink_avg = 20
end

;
snap length 24
