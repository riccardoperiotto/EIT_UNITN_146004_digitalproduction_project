// P_inita.c
// AutoMod 12.6.1 Generated File
// Build: 12.6.1.12
// Model name:	drive_in
// Model path:	C:\Users\Periot\Desktop\Digital production project\Quick Fix Demon - project delivery - Digital production mod. 1\Automod project\drive_in.dir\
// Generated:	Sun Jun 26 14:23:59 2022
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


#include "cdecls.h"


static int32
P_init_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	{
		{
			am2_V_sing_order_car_avg = ToModelTime(15, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sing_order_pers_avg = ToModelTime(30, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_eat_avg = ToModelTime(20 * 60, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[1] = ToModelTime(12, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[2] = ToModelTime(35, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[3] = ToModelTime(35, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[4] = ToModelTime(35, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[5] = ToModelTime(30, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[6] = ToModelTime(25, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[7] = ToModelTime(30, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[8] = ToModelTime(15, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			am2_V_sta_oper_time_avg[9] = ToModelTime(8, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			LabSetColor(am2_LB_waiting_pers, 13);
			EntityChanged(0x00000800);
		}
		{
			LabSetColor(am2_LB_eating_pers, 2);
			EntityChanged(0x00000800);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[1]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[2]), 10, counter*), 30);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[3]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[4]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[5]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[6]), 10, counter*), 30);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[7]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[8]), 10, counter*), 40);
			EntityChanged(0x00000010);
		}
		{
			CntSetCapacity(ValidPtr(&(am2_C_stock[9]), 10, counter*), 50);
			EntityChanged(0x00000010);
		}
		{
			SetString(&am2_V_file_input_name, "arc/input.csv");
			EntityChanged(0x01000000);
		}
		{
			SetString(&am2_V_file_car_w_t_name, "arc/car_waiting_time.txt");
			EntityChanged(0x01000000);
		}
		{
			SetString(&am2_V_file_downtime_name, "arc/downtime.txt");
			EntityChanged(0x01000000);
		}
		{
			SetString(&am2_V_file_menu_list_name, "arc/menu_list.txt");
			EntityChanged(0x01000000);
		}
		{
			SetString(&am2_V_file_pers_w_t_name, "arc/pers_waiting_time.txt");
			EntityChanged(0x01000000);
		}
		{
			clone(this, 1, am2_P_init_output, NULL);
		}
		{
			clone(this, 1, am2_P_init_read_input, NULL);
		}
		{
			clone(this, 1, am2_P_init_stock, NULL);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_init_arriving */



/* init function for P_inita.m */
void
model_P_inita_init(struct model_struct* data)
{
	data->am_P_init->aprc = P_init_arriving;
}

