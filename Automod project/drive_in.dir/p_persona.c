// P_persona.c
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
P_person_arriving(load* this, int32 step, void* args)
{
	struct _localargs {
		AMLoadListItem* lv0; // 'for each' loop variable
		AMLoadList* ls0; // 'for each' list
		AMLoadListItem* lv1; // 'for each' loop variable
		AMLoadList* ls1; // 'for each' list
		AMLoadListItem* lv2; // 'for each' loop variable
		AMLoadList* ls2; // 'for each' list
		AMLoadListItem* lv3; // 'for each' loop variable
		AMLoadList* ls3; // 'for each' list
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
	case Step 11: goto Label11;
	case Step 12: goto Label12;
	case Step 13: goto Label13;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	am_localargs = (struct _localargs*)xcalloc(1, sizeof(struct _localargs));
	{
		{
			{
				char* pArg1 = "** PERSON WITH ORDER ";
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
			LdSetType(this, am2_L_person);
			EntityChanged(0x00000040);
		}
		{
			am2_V_pers_counter += 1;
			EntityChanged(0x01000000);
		}
		{
			am2_V_pers_current_counter += 1;
			EntityChanged(0x01000000);
		}
		{
			if (QueGetCurConts(ValidPtr(&(am2_Q_person[1]), 50, queue*)) <= QueGetCurConts(ValidPtr(&(am2_Q_person[2]), 50, queue*))) {
				{
					pushppa(this, P_person_arriving, Step 2, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_person[1]));
					return Continue; // go move into territory
Label2: ; // Step 2
				}
				{
					pushppa(this, P_person_arriving, Step 3, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_totem[1]));
					return Continue; // go move into territory
Label3: ; // Step 3
				}
			}
			else {
				{
					pushppa(this, P_person_arriving, Step 4, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_person[2]));
					return Continue; // go move into territory
Label4: ; // Step 4
				}
				{
					pushppa(this, P_person_arriving, Step 5, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_totem[2]));
					return Continue; // go move into territory
Label5: ; // Step 5
				}
			}
		}
		{
			if (waitfor(ToModelTime(normal1(am2_stream0, this->attribute->am2_V_order_dim * am2_V_sing_order_pers_avg, this->attribute->am2_V_order_dim * 5), UNITSECONDS), this, P_person_arriving, Step 6, am_localargs) == Delayed)
				return Delayed;
Label6: ; // Step 6
		}
		{
			clone(this, this->attribute->am2_V_order_dim, am2_P_menu_generator, NULL);
		}
		{
			this->attribute->am2_V_order_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			am2_V_pers_queue_w_time = ToModelTime((FromModelTime(this->attribute->am2_V_order_time, UNITSECONDS) - this->attribute->am2_V_arrival_time) / 60, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			pushppa(this, P_person_arriving, Step 7, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_person.am_person_in, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label7: ; // Step 7
		}
		{
			pushppa(this, P_person_arriving, Step 8, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv_person.am_person_out, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label8: ; // Step 8
		}
		{
			pushppa(this, P_person_arriving, Step 9, am_localargs);
			pushppa(this, inqueue, Step 1, am2_Q_room);
			return Continue; // go move into territory
Label9: ; // Step 9
		}
		{
			am2_V_pers_room_counter += this->attribute->am2_V_order_dim;
			EntityChanged(0x01000000);
		}
		{
			{
				char* pArg1 = "Wating: ";
				char* pArg2 = " ";
				int32 pArg3 = QueGetCurConts(am2_Q_room) - am2_V_pers_eating_counter;

				updatelabel(am2_LB_waiting_pers, "%s%s%d", pArg1, pArg2, pArg3);
			}
		}
		{
			while (this->attribute->am2_V_order_ready != 1) {
				{
					if ((OrdGetCurConts(am2_OL_take_person) > 0)) {
						{
							if (waitfor(ToModelTime(1, UNITSECONDS), this, P_person_arriving, Step 10, am_localargs) == Delayed)
								return Delayed;
Label10: ; // Step 10
						}
						{
							am_localargs->ls0 = 0;
							ListCopy(LoadList, am_localargs->ls0, OrdGetLoadList(am2_OL_take_person));
							for (am_localargs->lv0 = (am_localargs->ls0) ? (am_localargs->ls0)->first : NULL; am_localargs->lv0; am_localargs->lv0 = am_localargs->lv0->next) {
								this->attribute->am2_V_load_ptr = am_localargs->lv0->item;
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
							ListRemoveAllAndFree(LoadList, am_localargs->ls0); /* End of for each */
						}
					}
				}
				{
					if (waitfor(ToModelTime(5, UNITSECONDS), this, P_person_arriving, Step 11, am_localargs) == Delayed)
						return Delayed;
Label11: ; // Step 11
				}
				{
					this->attribute->am2_V_order_level = 0;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			am_localargs->ls1 = 0;
			ListCopy(LoadList, am_localargs->ls1, OrdGetLoadList(am2_OL_take_person));
			for (am_localargs->lv1 = (am_localargs->ls1) ? (am_localargs->ls1)->first : NULL; am_localargs->lv1; am_localargs->lv1 = am_localargs->lv1->next) {
				this->attribute->am2_V_load_ptr = am_localargs->lv1->item;
				{
					{
						if (StringCompare(ValidPtr(this->attribute->am2_V_load_ptr, 32, load*)->attribute->am2_V_order_id, this->attribute->am2_V_order_id) == 0) {
							{
								LdSetPriority(ValidPtr(this->attribute->am2_V_load_ptr, 32, load*), LdGetPriority(ValidPtr(this->attribute->am2_V_load_ptr, 32, load*)) - 100);
								EntityChanged(0x00000040);
							}
						}
					}
				}
			}
			ListRemoveAllAndFree(LoadList, am_localargs->ls1); /* End of for each */
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "-- PERSON ORDER ";
						char* pArg2 = " ";
						char* pArg3 = this->attribute->am2_V_order_id;
						char* pArg4 = " ";
						char* pArg5 = ": completation at time ";
						char* pArg6 = " ";
						double pArg7 = FromModelTime(ASIclock, UNITSECONDS);
						char* pArg8 = " ";
						char* pArg9 = "; wating for waiter.";

						message("%s%s%s%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
				{
					{
						char* pArg1 = "-- PERSON ORDER ";
						char* pArg2 = " ";
						char* pArg3 = this->attribute->am2_V_order_id;
						char* pArg4 = " ";
						char* pArg5 = ": OL_take_person before ordering ";

						message("%s%s%s%s%s", pArg1, pArg2, pArg3, pArg4, pArg5);
					}
				}
				{
					if ((OrdGetCurConts(am2_OL_take_person) > 0)) {
						{
							am_localargs->ls2 = 0;
							ListCopy(LoadList, am_localargs->ls2, OrdGetLoadList(am2_OL_take_person));
							for (am_localargs->lv2 = (am_localargs->ls2) ? (am_localargs->ls2)->first : NULL; am_localargs->lv2; am_localargs->lv2 = am_localargs->lv2->next) {
								this->attribute->am2_V_load_ptr = am_localargs->lv2->item;
								{
									{
										{
											char* pArg1 = "    load for order ";
											char* pArg2 = " ";
											char* pArg3 = ValidPtr(this->attribute->am2_V_load_ptr, 32, load*)->attribute->am2_V_order_id;

											message("%s%s%s", pArg1, pArg2, pArg3);
										}
									}
								}
							}
							ListRemoveAllAndFree(LoadList, am_localargs->ls2); /* End of for each */
						}
					}
					else {
						{
							{
								char* pArg1 = "    empty ";

								message("%s", pArg1);
							}
						}
					}
				}
				{
					{
						char* pArg1 = "---- end of OL_take_person ----";

						message("%s", pArg1);
					}
				}
			}
		}
		{
			order(this->attribute->am2_V_order_dim, am2_OL_take_person, am2_die, NULL);		// Place an order
		}
		{
			clone(this, 1, am2_P_order_room, NULL);
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "-- PERSON ORDER ";
						char* pArg2 = " ";
						char* pArg3 = this->attribute->am2_V_order_id;
						char* pArg4 = " ";
						char* pArg5 = ": OL_take_person after ordering";

						message("%s%s%s%s%s", pArg1, pArg2, pArg3, pArg4, pArg5);
					}
				}
				{
					if ((OrdGetCurConts(am2_OL_take_person) > 0)) {
						{
							am_localargs->ls3 = 0;
							ListCopy(LoadList, am_localargs->ls3, OrdGetLoadList(am2_OL_take_person));
							for (am_localargs->lv3 = (am_localargs->ls3) ? (am_localargs->ls3)->first : NULL; am_localargs->lv3; am_localargs->lv3 = am_localargs->lv3->next) {
								this->attribute->am2_V_load_ptr = am_localargs->lv3->item;
								{
									{
										{
											char* pArg1 = "    load for order ";
											char* pArg2 = " ";
											char* pArg3 = ValidPtr(this->attribute->am2_V_load_ptr, 32, load*)->attribute->am2_V_order_id;

											message("%s%s%s", pArg1, pArg2, pArg3);
										}
									}
								}
							}
							ListRemoveAllAndFree(LoadList, am_localargs->ls3); /* End of for each */
						}
					}
					else {
						{
							{
								char* pArg1 = "    empty ";

								message("%s", pArg1);
							}
						}
					}
				}
				{
					{
						char* pArg1 = "---- end of OL_take_person ----";

						message("%s", pArg1);
					}
				}
			}
		}
		{
			return waitorder(am2_OL_waiting_person, this, P_person_arriving, Step 12, am_localargs);
Label12: ; // Step 12
			if (!this->inLeaveProc && this->nextproc) {
				retval = Continue;
				goto LabelRet;
			}
		}
		{
			am2_V_pers_eating_counter += 1;
			EntityChanged(0x01000000);
		}
		{
			{
				char* pArg1 = "Wating: ";
				char* pArg2 = " ";
				int32 pArg3 = (QueGetCurConts(am2_Q_room) - am2_V_pers_eating_counter);

				updatelabel(am2_LB_waiting_pers, "%s%s%d", pArg1, pArg2, pArg3);
			}
		}
		{
			{
				char* pArg1 = "Eating: ";
				char* pArg2 = " ";
				int32 pArg3 = am2_V_pers_eating_counter;

				updatelabel(am2_LB_eating_pers, "%s%s%d", pArg1, pArg2, pArg3);
			}
		}
		{
			am2_V_menu_pers_time = (ASIclock - this->attribute->am2_V_order_time) / 60;
			EntityChanged(0x01000000);
		}
		{
			am2_V_file_pers_w_t_ptr = OpenFilePtr(am_model.$sys, am2_V_file_pers_w_t_name, "a");
		}
		{
			{
				if (isFileValid(am2_V_file_pers_w_t_ptr, 0)) {
					double pArg1 = FromModelTime((ASIclock - this->attribute->am2_V_order_time) / 60, UNITSECONDS);
					char* pArg2 = " ";
					char* pArg3 = ",";
					char* pArg4 = " ";
					double pArg5 = FromModelTime(ASIclock, UNITSECONDS);

					fprintf((am2_V_file_pers_w_t_ptr)->fp, "%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5);
					fflush((am2_V_file_pers_w_t_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_pers_w_t_ptr);
		}
		{
			if (waitfor(ToModelTime(normal1(am2_stream0, am2_V_eat_avg, am2_V_eat_avg / 5), UNITSECONDS), this, P_person_arriving, Step 13, am_localargs) == Delayed)
				return Delayed;
Label13: ; // Step 13
		}
		{
			am2_V_pers_eating_counter -= 1;
			EntityChanged(0x01000000);
		}
		{
			am2_V_pers_room_counter -= this->attribute->am2_V_order_dim;
			EntityChanged(0x01000000);
		}
		{
			am2_V_pers_current_counter -= 1;
			EntityChanged(0x01000000);
		}
		{
			am2_V_pers_out_counter -= 1;
			EntityChanged(0x01000000);
		}
		{
			{
				char* pArg1 = "Eating: ";
				char* pArg2 = " ";
				int32 pArg3 = am2_V_pers_eating_counter;

				updatelabel(am2_LB_eating_pers, "%s%s%d", pArg1, pArg2, pArg3);
			}
		}
		{
			{
				char* pArg1 = "*** PERSON ORDER ";
				char* pArg2 = " ";
				char* pArg3 = this->attribute->am2_V_order_id;
				char* pArg4 = " ";
				char* pArg5 = " FINISHED TO EAT AND WENT AWAY ";
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
	ListRemoveAllAndFree(LoadList, am_localargs->ls0);
	ListRemoveAllAndFree(LoadList, am_localargs->ls1);
	ListRemoveAllAndFree(LoadList, am_localargs->ls2);
	ListRemoveAllAndFree(LoadList, am_localargs->ls3);
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_person_arriving */



/* init function for P_persona.m */
void
model_P_persona_init(struct model_struct* data)
{
	data->am_P_person->aprc = P_person_arriving;
}

