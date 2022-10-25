// decls.h
// AutoMod 12.6.1 Generated File
// Build: 12.6.1.12
// Model name:	drive_in
// Model path:	C:\Users\Periot\Desktop\Digital production project\Quick Fix Demon - project delivery - Digital production mod. 1\Automod project\drive_in.dir\
// Generated:	Sun Jun 26 14:24:14 2022
// Applied/AutoMod Licensee Confidential
// NO DISTRIBUTION OR REPRODUCTION RIGHTS GRANTED!
// Copyright (c) 1988-2015 Applied Materials All rights reserved.
//
// All Rights Reserved.  Reproduction or transmission in whole or
// in part, in any form or by any means, electronic, mechanical or
// otherwise, is prohibited without the prior written consent of
// copyright owner.
//
// Licensed Material - Property of Applied Materials, Inc.
//
// Applied Materials, Inc.
// 3050 Bowers Drive
// P.O. Box 58039
// Santa Clara, CA 95054-3299
// U.S.A.
//


#ifndef __DECLS_H__
#define __DECLS_H__

#include "user.h"
struct model_conv_struct {
	System* $sys;
	LocHead* am_sta_first_ing_1;
	LocHead* am_sta_first_ing_2;
	LocHead* am_sta_first_ing_3;
	LocHead* am_sta_room;
	LocHead* am_sta_second_ing_3;
	LocHead* am_sta_second_ing_1;
	LocHead* am_sta_car;
	LocHead* am_sta_second_ing_2;
	System* am_parentsys;
	LocHead* am_sta_drink;
	LocHead* am_sta_chips;
	LocHead* am_sta_bread;
};
struct model_conv_car_struct {
	System* $sys;
	LocHead* am_sta_order;
	LocHead* am_sta_start;
	System* am_parentsys;
	LocHead* am_sta_pay;
	LocHead* am_sta_take;
};
struct model_conv_person_struct {
	System* $sys;
	LocHead* am_person_out;
	System* am_parentsys;
	LocHead* am_person_in;
};
struct model_restock_struct {
	System* $sys;
	LocHead* am_re_drink;
	LocHead* am_re_chips;
	LocHead* am_re_veg;
	VehType* am_re_stocker;
	LocHead* am_re_meat_1;
	LocHead* am_re_stock;
	LocHead* am_re_chick_1;
	LocHead* am_re_chick_2;
	LocHead* am_re_meat_2;
	System* am_parentsys;
	VehSegSpec* am_restocker_seg;
	LocHead* am_re_bread;
};
struct model_waiter_struct {
	System* $sys;
	LocHead* am_w_room_in;
	LocHead* am_w_room_out;
	System* am_parentsys;
	VehSegSpec* am_waiter_segment;
	VehType* am_waiter;
};
char* Acceleration_valstrfunc(void*);
Acceleration Acceleration_strvalfunc(char*);
char* BlockPtr_valstrfunc(void*);
block* BlockPtr_strvalfunc(char*);
char* BlockList_valstrfunc(void*);
char* Color_valstrfunc(void*);
ASI_Color Color_strvalfunc(char*);
char* ContainerPtr_valstrfunc(void*);
Container* ContainerPtr_strvalfunc(char*);
char* ContainerList_valstrfunc(void*);
char* CounterPtr_valstrfunc(void*);
counter* CounterPtr_strvalfunc(char*);
char* Distance_valstrfunc(void*);
Distance Distance_strvalfunc(char*);
char* FilePtr_valstrfunc(void*);
iofile* FilePtr_strvalfunc(char*);
char* GraphPtr_valstrfunc(void*);
bgraph* GraphPtr_strvalfunc(char*);
char* Integer_valstrfunc(void*);
int32 Integer_strvalfunc(char*);
char* LabelPtr_valstrfunc(void*);
label* LabelPtr_strvalfunc(char*);
char* LoadPtr_valstrfunc(void*);
load* LoadPtr_strvalfunc(char*);
char* LoadList_valstrfunc(void*);
char* LoadTypePtr_valstrfunc(void*);
loadtype* LoadTypePtr_strvalfunc(char*);
char* Location_valstrfunc(void*);
simloc* Location_strvalfunc(char*);
char* LocationList_valstrfunc(void*);
char* LocationTypePtr_valstrfunc(void*);
LocationType* LocationTypePtr_strvalfunc(char*);
char* LocationTypeList_valstrfunc(void*);
char* MonitorPtr_valstrfunc(void*);
State_machine* MonitorPtr_strvalfunc(char*);
char* MotorPtr_valstrfunc(void*);
ConvMotor* MotorPtr_strvalfunc(char*);
char* MotorList_valstrfunc(void*);
char* MotorTypePtr_valstrfunc(void*);
MotorType* MotorTypePtr_strvalfunc(char*);
char* MotorTypeList_valstrfunc(void*);
char* OrderListPtr_valstrfunc(void*);
ordlist* OrderListPtr_strvalfunc(char*);
char* PathPtr_valstrfunc(void*);
Path* PathPtr_strvalfunc(char*);
char* PathList_valstrfunc(void*);
char* PathTypePtr_valstrfunc(void*);
AgvPathType* PathTypePtr_strvalfunc(char*);
char* PathTypeList_valstrfunc(void*);
char* PhotoeyePtr_valstrfunc(void*);
Photoeye* PhotoeyePtr_strvalfunc(char*);
char* PhotoeyeList_valstrfunc(void*);
char* PhotoeyeTypePtr_valstrfunc(void*);
PhotoeyeType* PhotoeyeTypePtr_strvalfunc(char*);
char* PhotoeyeTypeList_valstrfunc(void*);
char* ProcessPtr_valstrfunc(void*);
process* ProcessPtr_strvalfunc(char*);
char* QueuePtr_valstrfunc(void*);
queue* QueuePtr_strvalfunc(char*);
char* QueueList_valstrfunc(void*);
char* Rate_valstrfunc(void*);
Rate Rate_strvalfunc(char*);
char* Real_valstrfunc(void*);
double Real_strvalfunc(char*);
char* ResourcePtr_valstrfunc(void*);
resource* ResourcePtr_strvalfunc(char*);
char* ResourceList_valstrfunc(void*);
char* SchedJobPtr_valstrfunc(void*);
SchedJob* SchedJobPtr_strvalfunc(char*);
char* SchedJobList_valstrfunc(void*);
char* SectionPtr_valstrfunc(void*);
ConvSection* SectionPtr_strvalfunc(char*);
char* SectionList_valstrfunc(void*);
char* SectionTypePtr_valstrfunc(void*);
ConvSectionType* SectionTypePtr_strvalfunc(char*);
char* SectionTypeList_valstrfunc(void*);
char* StatePtr_valstrfunc(void*);
States* StatePtr_strvalfunc(char*);
char* StreamPtr_valstrfunc(void*);
rnstream* StreamPtr_strvalfunc(char*);
char* String_valstrfunc(void*);
char* String_strvalfunc(char*);
char* StringList_valstrfunc(void*);
char* SystemPtr_valstrfunc(void*);
System* SystemPtr_strvalfunc(char*);
char* TablePtr_valstrfunc(void*);
table* TablePtr_strvalfunc(char*);
char* Time_valstrfunc(void*);
ASITime Time_strvalfunc(char*);
char* TransferPtr_valstrfunc(void*);
ConvTransfer* TransferPtr_strvalfunc(char*);
char* TransferTypePtr_valstrfunc(void*);
TransferType* TransferTypePtr_strvalfunc(char*);
char* VehiclePtr_valstrfunc(void*);
vehicle* VehiclePtr_strvalfunc(char*);
char* VehicleList_valstrfunc(void*);
char* VehSegPtr_valstrfunc(void*);
VehSeg* VehSegPtr_strvalfunc(char*);
char* VehSegList_valstrfunc(void*);
char* Velocity_valstrfunc(void*);
Velocity Velocity_strvalfunc(char*);
struct model_struct {
	System* $sys;
	variable* am_V_car_out_counter$var;
	int32 am_V_car_out_counter;
	loadtype* am_L_menu;
	label* am_LB_stock;
	variable* am_V_file_car_w_t_ptr$var;
	iofile* am_V_file_car_w_t_ptr;
	variable* am_V_file_input_ptr$var;
	iofile* am_V_file_input_ptr;
	process* am_die;
	attribute* am_V_stock_type$att;
	loadtype* am_L_veggy_complete;
	variable* am_V_file_downtime_ptr$var;
	iofile* am_V_file_downtime_ptr;
	attribute* am_V_order_level$att;
	process* am_P_menu;
	loadtype* am_L_veggy_ing_1;
	attribute* am_V_arrival_time$att;
	variable* am_V_pers_queue_w_time$var;
	ASITime am_V_pers_queue_w_time;
	variable* am_V_headers$var;
	char* am_V_headers;
	attribute* am_V_chips$att;
	loadtype* am_L_veggy_closed;
	loadtype* am_L_bread;
	rnstream* am_stream_R_op_drink_1;
	attribute* am_V_load_ptr$att;
	variable* am_V_stock_downtime$var;
	double am_V_stock_downtime;
	variable* am_V_car_queue_w_time$var;
	ASITime am_V_car_queue_w_time;
	variable* am_V_eat_avg$var;
	ASITime am_V_eat_avg;
	loadtype* am_L_chicken_complete;
	attribute* am_V_drink$att;
	attribute* am_V_order_provenience$att;
	ordlist* am_OL_take_person;
	rnstream* am_stream_R_op_second_1;
	variable* am_V_file_menu_list_name$var;
	char* am_V_file_menu_list_name;
	rnstream* am_stream_R_op_take_car_1;
	variable* am_OPCTimestamp$var;
	char* am_OPCTimestamp;
	queue* am_Q_room;
	variable* am_V_pers_room_counter$var;
	int32 am_V_pers_room_counter;
	variable* am_V_pers_eating_counter$var;
	int32 am_V_pers_eating_counter;
	ordlist* am_OL_take_car;
	resource* am_R_op_bread;
	table* am_T_sta_proc_time_ratio;
	attribute* am_V_order_ready$att;
	variable* am_V_file_menu_list_ptr$var;
	iofile* am_V_file_menu_list_ptr;
	variable* am_V_pers_current_counter$var;
	int32 am_V_pers_current_counter;
	variable* am_V_sta_proc_time_ratio$var;
	double *am_V_sta_proc_time_ratio;
	variable* am_V_pers_counter$var;
	int32 am_V_pers_counter;
	resource* am_R_op_second;
	queue* am_Q_restock;
	attribute* am_V_load_type_ptrs$att;
	variable* am_V_pers_out_counter$var;
	int32 am_V_pers_out_counter;
	variable* am_V_car_current_counter$var;
	int32 am_V_car_current_counter;
	attribute* am_V_menu_pointer$att;
	loadtype* am_L_meat_ing_1;
	variable* am_V_menu_counter$var;
	int32 am_V_menu_counter;
	process* am_P_stock;
	loadtype* am_L_veggy_drink;
	attribute* am_V_stock_location$att;
	queue* am_Q_take_person;
	rnstream* am_stream_R_op_first_1;
	loadtype* am_L_stock;
	System* am_modelsys;
	attribute* am_V_station_proc_time$att;
	variable* am_V_file_pers_w_t_name$var;
	char* am_V_file_pers_w_t_name;
	loadtype* am_L_chicken_closed;
	struct model_conv_person_struct am_conv_person;
	counter* am_C_stock;
	attribute* am_V_order_id$att;
	queue* am_Q_totem;
	queue* am_Q_person;
	process* am_P_person;
	loadtype* am_L_chicken_ing_1;
	loadtype* am_L_meat_chips;
	resource* am_R_op_first;
	struct model_restock_struct am_restock;
	resource* am_R_op_drink;
	variable* am_V_file_downtime_name$var;
	char* am_V_file_downtime_name;
	label* am_LB_eating_pers;
	queue* am_Q_take_car;
	loadtype* am_L_chicken_chips;
	attribute* am_V_menu_processing_time$att;
	process* am_P_init_output;
	loadtype* am_L_meat_complete;
	loadtype* am_L_person;
	process* am_P_init_stock;
	loadtype* am_L_veggy_chips;
	loadtype* am_L_meat_closed;
	rnstream* am_stream_L_dummy_1;
	loadtype* am_L_meat_drink;
	rnstream* am_stream_R_op_pay_1;
	variable* am_V_menu_pers_time$var;
	ASITime am_V_menu_pers_time;
	rnstream* am_stream0;
	process* am_P_init_read_input;
	rnstream* am_stream_R_op_chips_1;
	variable* am_V_debug$var;
	int32 am_V_debug;
	resource* am_R_op_chips;
	loadtype* am_L_order_room;
	process* am_P_init;
	process* am_P_menu_generator;
	variable* am_V_file_input_name$var;
	char* am_V_file_input_name;
	loadtype* am_L_car;
	struct model_conv_struct am_conv;
	loadtype* am_L_chicken_drink;
	variable* am_V_sing_order_car_avg$var;
	ASITime am_V_sing_order_car_avg;
	variable* am_V_sta_oper_time_avg$var;
	ASITime *am_V_sta_oper_time_avg;
	process* am_P_car;
	variable* am_V_order_counter$var;
	int32 am_V_order_counter;
	process* am_P_order_room;
	struct model_waiter_struct am_waiter;
	attribute* am_V_order_time$att;
	variable* am_V_menu_car_time$var;
	ASITime am_V_menu_car_time;
	variable* am_V_file_car_w_t_name$var;
	char* am_V_file_car_w_t_name;
	attribute* am_V_menu_value$att;
	resource* am_R_op_take_car;
	resource* am_R_op_pay;
	variable* am_V_file_pers_w_t_ptr$var;
	iofile* am_V_file_pers_w_t_ptr;
	rnstream* am_stream_R_op_bread_1;
	variable* am_OPCQuality$var;
	int32 am_OPCQuality;
	attribute* am_V_menu_type$att;
	variable* am_V_sing_order_pers_avg$var;
	ASITime am_V_sing_order_pers_avg;
	ordlist* am_OL_waiting_person;
	struct model_conv_car_struct am_conv_car;
	label* am_LB_waiting_pers;
	attribute* am_V_order_dim$att;
};
extern struct model_struct am_model;
void initglobs0();
#endif // __DECLS_H__
