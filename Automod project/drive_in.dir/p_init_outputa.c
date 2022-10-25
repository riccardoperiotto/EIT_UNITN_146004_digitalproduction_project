// P_init_outputa.c
// AutoMod 12.6.1 Generated File
// Build: 12.6.1.12
// Model name:	drive_in
// Model path:	C:\Users\Periot\Desktop\Digital production project\Quick Fix Demon - project delivery - Digital production mod. 1\Automod project\drive_in.dir\
// Generated:	Sun Jun 26 14:21:15 2022
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
P_init_output_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	{
		{
			am2_V_file_car_w_t_ptr = OpenFilePtr(am_model.$sys, am2_V_file_car_w_t_name, "w");
		}
		{
			{
				if (isFileValid(am2_V_file_car_w_t_ptr, 0)) {
					char* pArg1 = "Time elapsed [min],Timestamp [s]";

					fprintf((am2_V_file_car_w_t_ptr)->fp, "%s\n", pArg1);
					fflush((am2_V_file_car_w_t_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_downtime_ptr);
		}
		{
			am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "w");
		}
		{
			{
				if (isFileValid(am2_V_file_downtime_ptr, 0)) {
					char* pArg1 = "Station [number],Downtime [min],Timestamp [s]";

					fprintf((am2_V_file_downtime_ptr)->fp, "%s\n", pArg1);
					fflush((am2_V_file_downtime_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_downtime_ptr);
		}
		{
			am2_V_file_menu_list_ptr = OpenFilePtr(am_model.$sys, am2_V_file_menu_list_name, "w");
		}
		{
			{
				if (isFileValid(am2_V_file_menu_list_ptr, 0)) {
					char* pArg1 = "OrderId [number],Type [string],Chips [bool],Drink [bool],Value [€], Timestamp [s]";

					fprintf((am2_V_file_menu_list_ptr)->fp, "%s\n", pArg1);
					fflush((am2_V_file_menu_list_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_menu_list_ptr);
		}
		{
			am2_V_file_pers_w_t_ptr = OpenFilePtr(am_model.$sys, am2_V_file_pers_w_t_name, "w");
		}
		{
			{
				if (isFileValid(am2_V_file_pers_w_t_ptr, 0)) {
					char* pArg1 = "Time elapsed [min],Timestamp [s]";

					fprintf((am2_V_file_pers_w_t_ptr)->fp, "%s\n", pArg1);
					fflush((am2_V_file_pers_w_t_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_pers_w_t_ptr);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_init_output_arriving */



/* init function for P_init_outputa.m */
void
model_P_init_outputa_init(struct model_struct* data)
{
	data->am_P_init_output->aprc = P_init_output_arriving;
}

