// P_cara.c
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
P_car_arriving(load* this, int32 step, void* args)
{
	struct _localargs {
		AMLoadListItem* lv4; // 'for each' loop variable
		AMLoadList* ls4; // 'for each' list
	} *am_localargs = (struct _localargs*)args;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	case Step 7: goto Label7;
	case Step 8: goto Label8;
	case Step 9: goto Label9;
	case Step 10: goto Label10;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	am_localargs = (struct _localargs*)xcalloc(1, sizeof(struct _localargs));
	{
		{
			{
				char* pArg1 = "** CAR WITH ORDER ";
				char* pArg2 = " ";
				char* pArg3 = this->attribute->am2_V_order_id;
				char* pArg4 = " ";
				char* pArg5 = " ARRIVED AT TIME ";
				char* pArg6 = " ";
				double pArg7 = FromModelTime(ASIclock, UNITSECONDS);
				char* pArg8 = " ";
				char* pArg9 = "**";

				message("%s%s%s%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
			}
		}
		{
			LdSetType(this, am2_L_car);
			EntityChanged(0x00000040);
		}
		{
			am2_V_car_current_counter += 1;
			EntityChanged(0x01000000);
		}
		{
			pushppa(this, P_car_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_car.am_sta_start, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			pushppa(this, P_car_arriving, Step 3, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_car.am_sta_order, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label3: ; // Step 3
		}
		{
			if (waitfor(ToModelTime(normal1(am2_stream0, 20 + FromModelTime(this->attribute->am2_V_order_dim * am2_V_sing_order_car_avg, UNITSECONDS), 7), UNITSECONDS), this, P_car_arriving, Step 4, am_localargs) == Delayed)
				return Delayed;
Label4: ; // Step 4
		}
		{
			clone(this, this->attribute->am2_V_order_dim, am2_P_menu_generator, NULL);
		}
		{
			this->attribute->am2_V_order_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			am2_V_car_queue_w_time = ToModelTime((FromModelTime(this->attribute->am2_V_order_time, UNITSECONDS) - this->attribute->am2_V_arrival_time) / 60, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			pushppa(this, P_car_arriving, Step 5, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_car.am_sta_pay, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label5: ; // Step 5
		}
		{
			return usefor(am2_R_op_pay, 1, this, P_car_arriving, Step 6, am_localargs, ToModelTime(normal1(am2_stream0, 30, 5), UNITSECONDS));
Label6: ; // Step 6
		}
		{
			pushppa(this, P_car_arriving, Step 7, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_car.am_sta_take, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label7: ; // Step 7
		}
		{
			while (this->attribute->am2_V_order_ready != 1) {
				{
					if ((OrdGetCurConts(am2_OL_take_car) > 0)) {
						{
							if (waitfor(ToModelTime(1, UNITSECONDS), this, P_car_arriving, Step 8, am_localargs) == Delayed)
								return Delayed;
Label8: ; // Step 8
						}
						{
							am_localargs->ls4 = 0;
							ListCopy(LoadList, am_localargs->ls4, OrdGetLoadList(am2_OL_take_car));
							for (am_localargs->lv4 = (am_localargs->ls4) ? (am_localargs->ls4)->first : NULL; am_localargs->lv4; am_localargs->lv4 = am_localargs->lv4->next) {
								this->attribute->am2_V_load_ptr = am_localargs->lv4->item;
								{
									{
										if (StringCompare(ValidPtr(this->attribute->am2_V_load_ptr, 32, load*)->attribute->am2_V_order_id, this->attribute->am2_V_order_id) == 0) {
											{
												this->attribute->am2_V_order_level += 1;
												EntityChanged(0x00000040);
											}
										}
									}
									{
										if (this->attribute->am2_V_order_level == this->attribute->am2_V_order_dim) {
											{
												this->attribute->am2_V_order_ready = 1;
												EntityChanged(0x00000040);
											}
											{
												break;
											}
										}
									}
								}
							}
							ListRemoveAllAndFree(LoadList, am_localargs->ls4); /* End of for each */
						}
					}
				}
				{
					if (waitfor(ToModelTime(5, UNITSECONDS), this, P_car_arriving, Step 9, am_localargs) == Delayed)
						return Delayed;
Label9: ; // Step 9
				}
				{
					this->attribute->am2_V_order_level = 0;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			return usefor(am2_R_op_take_car, 1, this, P_car_arriving, Step 10, am_localargs, ToModelTime(normal1(am2_stream0, 15, 3), UNITSECONDS));
Label10: ; // Step 10
		}
		{
			order(this->attribute->am2_V_order_dim, am2_OL_take_car, am2_die, NULL);		// Place an order
		}
		{
			am2_V_car_current_counter -= 1;
			EntityChanged(0x01000000);
		}
		{
			am2_V_car_out_counter += 1;
			EntityChanged(0x01000000);
		}
		{
			am2_V_menu_car_time = (ASIclock - this->attribute->am2_V_order_time) / 60;
			EntityChanged(0x01000000);
		}
		{
			am2_V_file_car_w_t_ptr = OpenFilePtr(am_model.$sys, am2_V_file_car_w_t_name, "a");
		}
		{
			{
				if (isFileValid(am2_V_file_car_w_t_ptr, 0)) {
					double pArg1 = FromModelTime((ASIclock - this->attribute->am2_V_order_time) / 60, UNITSECONDS);
					char* pArg2 = " ";
					char* pArg3 = ",";
					char* pArg4 = " ";
					double pArg5 = FromModelTime(ASIclock, UNITSECONDS);

					fprintf((am2_V_file_car_w_t_ptr)->fp, "%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5);
					fflush((am2_V_file_car_w_t_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_car_w_t_ptr);
		}
		{
			{
				char* pArg1 = "*** CAR ORDER ";
				char* pArg2 = " ";
				char* pArg3 = this->attribute->am2_V_order_id;
				char* pArg4 = " ";
				char* pArg5 = " COMPLETED AND TAKEN AT TIME ";
				char* pArg6 = " ";
				double pArg7 = FromModelTime(ASIclock, UNITSECONDS);
				char* pArg8 = " ";
				char* pArg9 = " ***";

				message("%s%s%s%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
			}
		}
		{
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	ListRemoveAllAndFree(LoadList, am_localargs->ls4);
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_car_arriving */



/* init function for P_cara.m */
void
model_P_cara_init(struct model_struct* data)
{
	data->am_P_car->aprc = P_car_arriving;
}

