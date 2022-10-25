begin
	set this load type = L_order_room	
	move into waiter.w_room_in
	rotate this current container vehicle absolute to z 0
	travel to waiter.w_room_out
	order 1 loads satisfying V_order_id = this load V_order_id from OL_waiting_person to continue
	rotate this current container vehicle absolute to z 180
	send to die
end


