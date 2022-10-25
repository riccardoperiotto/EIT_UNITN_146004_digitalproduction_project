// P_menua.c
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
P_menu_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
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
	case Step 14: goto Label14;
	case Step 15: goto Label15;
	case Step 16: goto Label16;
	case Step 17: goto Label17;
	case Step 18: goto Label18;
	case Step 19: goto Label19;
	case Step 20: goto Label20;
	case Step 21: goto Label21;
	case Step 22: goto Label22;
	case Step 23: goto Label23;
	case Step 24: goto Label24;
	case Step 25: goto Label25;
	case Step 26: goto Label26;
	case Step 27: goto Label27;
	case Step 28: goto Label28;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			am2_V_menu_counter = am2_V_menu_counter + 1;
			EntityChanged(0x01000000);
		}
		{
			this->attribute->am2_V_menu_processing_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			pushppa(this, P_menu_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_conv.am_sta_bread, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[1]), 10, counter*)) == 0) {
				{
					while (CntGetCurConts(ValidPtr(&(am2_C_stock[1]), 10, counter*)) == 0) {
						{
							if (waitfor(ToModelTime(2, UNITSECONDS), this, P_menu_arriving, Step 3, am_localargs) == Delayed)
								return Delayed;
Label3: ; // Step 3
						}
					}
				}
				{
					if (am2_V_debug == 1) {
						{
							am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "a");
						}
						{
							{
								if (isFileValid(am2_V_file_downtime_ptr, 0)) {
									int32 pArg1 = 1;
									char* pArg2 = " ";
									char* pArg3 = ",";
									char* pArg4 = " ";
									double pArg5 = FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
									char* pArg6 = " ";
									char* pArg7 = ",";
									char* pArg8 = " ";
									double pArg9 = FromModelTime(ASIclock, UNITSECONDS);

									fprintf((am2_V_file_downtime_ptr)->fp, "%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
									fflush((am2_V_file_downtime_ptr)->fp);
								}
							}
						}
						{
							CloseFilePtr(am2_V_file_downtime_ptr);
						}
						{
							{
								char* pArg1 = "  # Downtime for station ";
								char* pArg2 = " ";
								int32 pArg3 = 1;
								char* pArg4 = " ";
								char* pArg5 = " ";
								char* pArg6 = " ";
								double pArg7 = FromModelTime(ASIclock - this->attribute->am2_V_station_proc_time, UNITSECONDS);

								message("%s%s%d%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);
							}
						}
					}
				}
				{
					am2_V_stock_downtime = am2_V_stock_downtime + FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
					EntityChanged(0x01000000);
				}
			}
		}
		{
			{
				int result = deccount(&(am2_C_stock[1]), 1, this, P_menu_arriving, Step 4, am_localargs);
				if (result != Continue) return result;
Label4: ;	// Step 4
			}
		}
		{
			{
				int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[1]), 10, counter*));
				char* pArg2 = " ";
				char* pArg3 = "/";
				char* pArg4 = " ";
				int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[1]), 10, counter*));

				updatelabel(&(am2_LB_stock[1]), "%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5);
			}
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[1]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[1]), 10, counter*)) / 10) {
				{
					LabSetColor(ValidPtr(&(am2_LB_stock[1]), 29, label*), 1);
					EntityChanged(0x00000800);
				}
			}
			else {
				if (CntGetCurConts(ValidPtr(&(am2_C_stock[1]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[1]), 10, counter*)) * 3 / 10) {
					{
						LabSetColor(ValidPtr(&(am2_LB_stock[1]), 29, label*), 3);
						EntityChanged(0x00000800);
					}
				}
			}
		}
		{
			return usefor(am2_R_op_bread, 1, this, P_menu_arriving, Step 5, am_localargs, ToModelTime(normal1(am2_stream0, am2_V_sta_oper_time_avg[1], am2_V_sta_oper_time_avg[1] / 5), UNITSECONDS));
Label5: ; // Step 5
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock - this->attribute->am2_V_station_proc_time;
			EntityChanged(0x00000040);
		}
		{
			am2_V_sta_proc_time_ratio[1] = this->attribute->am2_V_station_proc_time / am2_V_sta_oper_time_avg[1];
			EntityChanged(0x01000000);
		}
		{
			tabulate(&(am2_T_sta_proc_time_ratio[1]), am2_V_sta_proc_time_ratio[1]);	// Tabulate the value
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "    Menu of type ";
						char* pArg2 = " ";
						int32 pArg3 = CurProcIndex();
						char* pArg4 = " ";
						char* pArg5 = ": bread added in ";
						char* pArg6 = " ";
						double pArg7 = FromModelTime(this->attribute->am2_V_station_proc_time, UNITSECONDS);
						char* pArg8 = " ";
						char* pArg9 = " sec";

						message("%s%s%d%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
			}
		}
		{
			LdSetType(this, this->attribute->am2_V_load_type_ptrs[1]);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			pushppa(this, P_menu_arriving, Step 6, am_localargs);
			load_SetDestLoc(this, SysGetQualifier(am_model.am_conv.$sys, "sta_first_ing_", CurProcIndex(), -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label6: ; // Step 6
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) == 0) {
				{
					while (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) == 0) {
						{
							if (waitfor(ToModelTime(2, UNITSECONDS), this, P_menu_arriving, Step 7, am_localargs) == Delayed)
								return Delayed;
Label7: ; // Step 7
						}
					}
				}
				{
					if (am2_V_debug == 1) {
						{
							am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "a");
						}
						{
							{
								if (isFileValid(am2_V_file_downtime_ptr, 0)) {
									int32 pArg1 = 2 * CurProcIndex();
									char* pArg2 = " ";
									char* pArg3 = ",";
									char* pArg4 = " ";
									double pArg5 = FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
									char* pArg6 = " ";
									char* pArg7 = ",";
									char* pArg8 = " ";
									double pArg9 = FromModelTime(ASIclock, UNITSECONDS);

									fprintf((am2_V_file_downtime_ptr)->fp, "%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
									fflush((am2_V_file_downtime_ptr)->fp);
								}
							}
						}
						{
							CloseFilePtr(am2_V_file_downtime_ptr);
						}
						{
							{
								char* pArg1 = "  # Downtime for station ";
								char* pArg2 = " ";
								int32 pArg3 = 2 * CurProcIndex();
								char* pArg4 = " ";
								char* pArg5 = " ";
								char* pArg6 = " ";
								double pArg7 = FromModelTime(ASIclock - this->attribute->am2_V_station_proc_time, UNITSECONDS);

								message("%s%s%d%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);
							}
						}
					}
				}
				{
					am2_V_stock_downtime = am2_V_stock_downtime + FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
					EntityChanged(0x01000000);
				}
			}
		}
		{
			{
				int result = deccount(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 1, this, P_menu_arriving, Step 8, am_localargs);
				if (result != Continue) return result;
Label8: ;	// Step 8
			}
		}
		{
			{
				int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*));
				char* pArg2 = " ";
				char* pArg3 = "/";
				char* pArg4 = " ";
				int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*));

				updatelabel(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 2 * CurProcIndex(), 9)]), "%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5);
			}
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) / 10) {
				{
					LabSetColor(ValidPtr(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 2 * CurProcIndex(), 9)]), 29, label*), 1);
					EntityChanged(0x00000800);
				}
			}
			else {
				if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 2 * CurProcIndex(), 9)]), 10, counter*)) * 3 / 10) {
					{
						LabSetColor(ValidPtr(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 2 * CurProcIndex(), 9)]), 29, label*), 3);
						EntityChanged(0x00000800);
					}
				}
			}
		}
		{
			return usefor(&(am2_R_op_first[ValidIndex("am_model.am_R_op_first", CurProcIndex(), 3)]), 1, this, P_menu_arriving, Step 9, am_localargs, ToModelTime(normal1(am2_stream0, am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 2 * CurProcIndex(), 9)], am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 2 * CurProcIndex(), 9)] / 5), UNITSECONDS));
Label9: ; // Step 9
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock - this->attribute->am2_V_station_proc_time;
			EntityChanged(0x00000040);
		}
		{
			am2_V_sta_proc_time_ratio[ValidIndex("am_model.am_V_sta_proc_time_ratio", 2 * CurProcIndex(), 9)] = this->attribute->am2_V_station_proc_time / am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 2 * CurProcIndex(), 9)];
			EntityChanged(0x01000000);
		}
		{
			tabulate(&(am2_T_sta_proc_time_ratio[ValidIndex("am_model.am_T_sta_proc_time_ratio", 2 * CurProcIndex(), 9)]), am2_V_sta_proc_time_ratio[ValidIndex("am_model.am_V_sta_proc_time_ratio", 2 * CurProcIndex(), 9)]);	// Tabulate the value
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "    Menu of type ";
						char* pArg2 = " ";
						int32 pArg3 = CurProcIndex();
						char* pArg4 = " ";
						char* pArg5 = ": first ing added in ";
						char* pArg6 = " ";
						double pArg7 = FromModelTime(this->attribute->am2_V_station_proc_time, UNITSECONDS);
						char* pArg8 = " ";
						char* pArg9 = " sec";

						message("%s%s%d%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
			}
		}
		{
			LdSetType(this, this->attribute->am2_V_load_type_ptrs[2]);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			pushppa(this, P_menu_arriving, Step 10, am_localargs);
			load_SetDestLoc(this, SysGetQualifier(am_model.am_conv.$sys, "sta_second_ing_", CurProcIndex(), -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label10: ; // Step 10
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) == 0) {
				{
					while (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) == 0) {
						{
							if (waitfor(ToModelTime(2, UNITSECONDS), this, P_menu_arriving, Step 11, am_localargs) == Delayed)
								return Delayed;
Label11: ; // Step 11
						}
					}
				}
				{
					if (am2_V_debug == 1) {
						{
							am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "a");
						}
						{
							{
								if (isFileValid(am2_V_file_downtime_ptr, 0)) {
									int32 pArg1 = 1 + 2 * CurProcIndex();
									char* pArg2 = " ";
									char* pArg3 = ",";
									char* pArg4 = " ";
									double pArg5 = FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
									char* pArg6 = " ";
									char* pArg7 = ",";
									char* pArg8 = " ";
									double pArg9 = FromModelTime(ASIclock, UNITSECONDS);

									fprintf((am2_V_file_downtime_ptr)->fp, "%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
									fflush((am2_V_file_downtime_ptr)->fp);
								}
							}
						}
						{
							CloseFilePtr(am2_V_file_downtime_ptr);
						}
						{
							{
								char* pArg1 = "  # Downtime for station ";
								char* pArg2 = " ";
								int32 pArg3 = 1 + 2 * CurProcIndex();
								char* pArg4 = " ";
								char* pArg5 = " ";
								char* pArg6 = " ";
								double pArg7 = FromModelTime(ASIclock - this->attribute->am2_V_station_proc_time, UNITSECONDS);

								message("%s%s%d%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);
							}
						}
					}
				}
				{
					am2_V_stock_downtime = am2_V_stock_downtime + FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
					EntityChanged(0x01000000);
				}
			}
		}
		{
			{
				int result = deccount(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 1, this, P_menu_arriving, Step 12, am_localargs);
				if (result != Continue) return result;
Label12: ;	// Step 12
			}
		}
		{
			{
				int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*));
				char* pArg2 = " ";
				char* pArg3 = "/";
				char* pArg4 = " ";
				int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*));

				updatelabel(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 1 + 2 * CurProcIndex(), 9)]), "%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5);
			}
		}
		{
			if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) / 10) {
				{
					LabSetColor(ValidPtr(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 1 + 2 * CurProcIndex(), 9)]), 29, label*), 1);
					EntityChanged(0x00000800);
				}
			}
			else {
				if (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", 1 + 2 * CurProcIndex(), 9)]), 10, counter*)) * 3 / 10) {
					{
						LabSetColor(ValidPtr(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", 1 + 2 * CurProcIndex(), 9)]), 29, label*), 3);
						EntityChanged(0x00000800);
					}
				}
			}
		}
		{
			return usefor(&(am2_R_op_second[ValidIndex("am_model.am_R_op_second", CurProcIndex(), 3)]), 1, this, P_menu_arriving, Step 13, am_localargs, ToModelTime(normal1(am2_stream0, am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 1 + 2 * CurProcIndex(), 9)], am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 1 + 2 * CurProcIndex(), 9)] / 5), UNITSECONDS));
Label13: ; // Step 13
		}
		{
			this->attribute->am2_V_station_proc_time = ASIclock - this->attribute->am2_V_station_proc_time;
			EntityChanged(0x00000040);
		}
		{
			am2_V_sta_proc_time_ratio[ValidIndex("am_model.am_V_sta_proc_time_ratio", 1 + 2 * CurProcIndex(), 9)] = this->attribute->am2_V_station_proc_time / am2_V_sta_oper_time_avg[ValidIndex("am_model.am_V_sta_oper_time_avg", 1 + 2 * CurProcIndex(), 9)];
			EntityChanged(0x01000000);
		}
		{
			tabulate(&(am2_T_sta_proc_time_ratio[ValidIndex("am_model.am_T_sta_proc_time_ratio", 1 + 2 * CurProcIndex(), 9)]), am2_V_sta_proc_time_ratio[ValidIndex("am_model.am_V_sta_proc_time_ratio", 1 + 2 * CurProcIndex(), 9)]);	// Tabulate the value
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "    Menu of type ";
						char* pArg2 = " ";
						int32 pArg3 = CurProcIndex();
						char* pArg4 = " ";
						char* pArg5 = ": second ing added in ";
						char* pArg6 = " ";
						double pArg7 = FromModelTime(this->attribute->am2_V_station_proc_time, UNITSECONDS);
						char* pArg8 = " ";
						char* pArg9 = " sec";

						message("%s%s%d%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
			}
		}
		{
			LdSetType(this, this->attribute->am2_V_load_type_ptrs[3]);
			EntityChanged(0x00000040);
		}
		{
			if (this->attribute->am2_V_chips == 1) {
				{
					this->attribute->am2_V_station_proc_time = ASIclock;
					EntityChanged(0x00000040);
				}
				{
					pushppa(this, P_menu_arriving, Step 14, am_localargs);
					load_SetDestLoc(this, LocGetQualifier(am_model.am_conv.am_sta_chips, -9999));
					pushppa(this, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label14: ; // Step 14
				}
				{
					if (CntGetCurConts(ValidPtr(&(am2_C_stock[8]), 10, counter*)) == 0) {
						{
							while (CntGetCurConts(ValidPtr(&(am2_C_stock[8]), 10, counter*)) == 0) {
								{
									if (waitfor(ToModelTime(2, UNITSECONDS), this, P_menu_arriving, Step 15, am_localargs) == Delayed)
										return Delayed;
Label15: ; // Step 15
								}
							}
						}
						{
							if (am2_V_debug == 1) {
								{
									am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "a");
								}
								{
									{
										if (isFileValid(am2_V_file_downtime_ptr, 0)) {
											int32 pArg1 = 8;
											char* pArg2 = " ";
											char* pArg3 = ",";
											char* pArg4 = " ";
											double pArg5 = FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
											char* pArg6 = " ";
											char* pArg7 = ",";
											char* pArg8 = " ";
											double pArg9 = FromModelTime(ASIclock, UNITSECONDS);

											fprintf((am2_V_file_downtime_ptr)->fp, "%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
											fflush((am2_V_file_downtime_ptr)->fp);
										}
									}
								}
								{
									CloseFilePtr(am2_V_file_downtime_ptr);
								}
								{
									{
										char* pArg1 = "  # Downtime for station ";
										char* pArg2 = " ";
										int32 pArg3 = 8;
										char* pArg4 = " ";
										char* pArg5 = " ";
										char* pArg6 = " ";
										double pArg7 = FromModelTime(ASIclock - this->attribute->am2_V_station_proc_time, UNITSECONDS);

										message("%s%s%d%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);
									}
								}
							}
						}
						{
							am2_V_stock_downtime = am2_V_stock_downtime + FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
							EntityChanged(0x01000000);
						}
					}
				}
				{
					{
						int result = deccount(&(am2_C_stock[8]), 1, this, P_menu_arriving, Step 16, am_localargs);
						if (result != Continue) return result;
Label16: ;	// Step 16
					}
				}
				{
					{
						int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[8]), 10, counter*));
						char* pArg2 = " ";
						char* pArg3 = "/";
						char* pArg4 = " ";
						int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[8]), 10, counter*));

						updatelabel(&(am2_LB_stock[8]), "%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5);
					}
				}
				{
					if (CntGetCurConts(ValidPtr(&(am2_C_stock[8]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[8]), 10, counter*)) / 10) {
						{
							LabSetColor(ValidPtr(&(am2_LB_stock[8]), 29, label*), 1);
							EntityChanged(0x00000800);
						}
					}
					else {
						if (CntGetCurConts(ValidPtr(&(am2_C_stock[8]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[8]), 10, counter*)) * 3 / 10) {
							{
								LabSetColor(ValidPtr(&(am2_LB_stock[8]), 29, label*), 3);
								EntityChanged(0x00000800);
							}
						}
					}
				}
				{
					return usefor(am2_R_op_chips, 1, this, P_menu_arriving, Step 17, am_localargs, ToModelTime(normal1(am2_stream0, am2_V_sta_oper_time_avg[8], am2_V_sta_oper_time_avg[8] / 5), UNITSECONDS));
Label17: ; // Step 17
				}
				{
					this->attribute->am2_V_station_proc_time = ASIclock - this->attribute->am2_V_station_proc_time;
					EntityChanged(0x00000040);
				}
				{
					am2_V_sta_proc_time_ratio[8] = this->attribute->am2_V_station_proc_time / am2_V_sta_oper_time_avg[8];
					EntityChanged(0x01000000);
				}
				{
					tabulate(&(am2_T_sta_proc_time_ratio[8]), am2_V_sta_proc_time_ratio[8]);	// Tabulate the value
				}
				{
					if (am2_V_debug == 1) {
						{
							{
								char* pArg1 = "    Menu of type ";
								char* pArg2 = " ";
								int32 pArg3 = CurProcIndex();
								char* pArg4 = " ";
								char* pArg5 = ": chips added in ";
								char* pArg6 = " ";
								double pArg7 = FromModelTime(this->attribute->am2_V_station_proc_time, UNITSECONDS);
								char* pArg8 = " ";
								char* pArg9 = " sec";

								message("%s%s%d%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
							}
						}
					}
				}
				{
					LdSetType(this, this->attribute->am2_V_load_type_ptrs[4]);
					EntityChanged(0x00000040);
				}
			}
		}
		{
			if (this->attribute->am2_V_drink == 1) {
				{
					this->attribute->am2_V_station_proc_time = ASIclock;
					EntityChanged(0x00000040);
				}
				{
					pushppa(this, P_menu_arriving, Step 18, am_localargs);
					load_SetDestLoc(this, LocGetQualifier(am_model.am_conv.am_sta_drink, -9999));
					pushppa(this, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label18: ; // Step 18
				}
				{
					if (CntGetCurConts(ValidPtr(&(am2_C_stock[9]), 10, counter*)) == 0) {
						{
							while (CntGetCurConts(ValidPtr(&(am2_C_stock[9]), 10, counter*)) == 0) {
								{
									if (waitfor(ToModelTime(2, UNITSECONDS), this, P_menu_arriving, Step 19, am_localargs) == Delayed)
										return Delayed;
Label19: ; // Step 19
								}
							}
						}
						{
							if (am2_V_debug == 1) {
								{
									am2_V_file_downtime_ptr = OpenFilePtr(am_model.$sys, am2_V_file_downtime_name, "a");
								}
								{
									{
										if (isFileValid(am2_V_file_downtime_ptr, 0)) {
											int32 pArg1 = 9;
											char* pArg2 = " ";
											char* pArg3 = ",";
											char* pArg4 = " ";
											double pArg5 = FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
											char* pArg6 = " ";
											char* pArg7 = ",";
											char* pArg8 = " ";
											double pArg9 = FromModelTime(ASIclock, UNITSECONDS);

											fprintf((am2_V_file_downtime_ptr)->fp, "%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
											fflush((am2_V_file_downtime_ptr)->fp);
										}
									}
								}
								{
									CloseFilePtr(am2_V_file_downtime_ptr);
								}
								{
									{
										char* pArg1 = "  # Downtime for station ";
										char* pArg2 = " ";
										int32 pArg3 = 9;
										char* pArg4 = " ";
										char* pArg5 = " ";
										char* pArg6 = " ";
										double pArg7 = FromModelTime(ASIclock - this->attribute->am2_V_station_proc_time, UNITSECONDS);

										message("%s%s%d%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7);
									}
								}
							}
						}
						{
							am2_V_stock_downtime = am2_V_stock_downtime + FromModelTime((ASIclock - this->attribute->am2_V_station_proc_time) / 60, UNITSECONDS);
							EntityChanged(0x01000000);
						}
					}
				}
				{
					{
						int result = deccount(&(am2_C_stock[9]), 1, this, P_menu_arriving, Step 20, am_localargs);
						if (result != Continue) return result;
Label20: ;	// Step 20
					}
				}
				{
					{
						int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[9]), 10, counter*));
						char* pArg2 = " ";
						char* pArg3 = "/";
						char* pArg4 = " ";
						int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[9]), 10, counter*));

						updatelabel(&(am2_LB_stock[9]), "%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5);
					}
				}
				{
					if (CntGetCurConts(ValidPtr(&(am2_C_stock[9]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[9]), 10, counter*)) / 10) {
						{
							LabSetColor(ValidPtr(&(am2_LB_stock[9]), 29, label*), 1);
							EntityChanged(0x00000800);
						}
					}
					else {
						if (CntGetCurConts(ValidPtr(&(am2_C_stock[9]), 10, counter*)) < CntGetCapacity(ValidPtr(&(am2_C_stock[9]), 10, counter*)) * 3 / 10) {
							{
								LabSetColor(ValidPtr(&(am2_LB_stock[9]), 29, label*), 3);
								EntityChanged(0x00000800);
							}
						}
					}
				}
				{
					return usefor(am2_R_op_drink, 1, this, P_menu_arriving, Step 21, am_localargs, ToModelTime(normal1(am2_stream0, am2_V_sta_oper_time_avg[9], am2_V_sta_oper_time_avg[9] / 5), UNITSECONDS));
Label21: ; // Step 21
				}
				{
					this->attribute->am2_V_station_proc_time = ASIclock - this->attribute->am2_V_station_proc_time;
					EntityChanged(0x00000040);
				}
				{
					am2_V_sta_proc_time_ratio[9] = this->attribute->am2_V_station_proc_time / am2_V_sta_oper_time_avg[9];
					EntityChanged(0x01000000);
				}
				{
					tabulate(&(am2_T_sta_proc_time_ratio[9]), am2_V_sta_proc_time_ratio[9]);	// Tabulate the value
				}
				{
					if (am2_V_debug == 1) {
						{
							{
								char* pArg1 = "    Menu of type ";
								char* pArg2 = " ";
								int32 pArg3 = CurProcIndex();
								char* pArg4 = " ";
								char* pArg5 = ": drink added in ";
								char* pArg6 = " ";
								double pArg7 = FromModelTime(this->attribute->am2_V_station_proc_time, UNITSECONDS);
								char* pArg8 = " ";
								char* pArg9 = " sec";

								message("%s%s%d%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
							}
						}
					}
				}
				{
					LdSetType(this, this->attribute->am2_V_load_type_ptrs[5]);
					EntityChanged(0x00000040);
				}
			}
		}
		{
			this->attribute->am2_V_menu_processing_time = (ASIclock - this->attribute->am2_V_menu_processing_time) / 60;
			EntityChanged(0x00000040);
		}
		{
			if (am2_V_debug == 1) {
				{
					{
						char* pArg1 = "    Order ";
						char* pArg2 = " ";
						char* pArg3 = this->attribute->am2_V_order_id;
						char* pArg4 = " ";
						char* pArg5 = ": finished in ";
						char* pArg6 = " ";
						double pArg7 = FromModelTime(this->attribute->am2_V_menu_processing_time, UNITSECONDS);
						char* pArg8 = " ";
						char* pArg9 = " min";

						message("%s%s%s%s%s%s%lf%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
			}
		}
		{
			if (StringCompare(this->attribute->am2_V_order_provenience, "car") == 0) {
				{
					pushppa(this, P_menu_arriving, Step 22, am_localargs);
					load_SetDestLoc(this, LocGetQualifier(am_model.am_conv.am_sta_car, -9999));
					pushppa(this, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label22: ; // Step 22
				}
				{
					pushppa(this, P_menu_arriving, Step 23, am_localargs);
					pushppa(this, inqueue, Step 1, am2_Q_take_car);
					return Continue; // go move into territory
Label23: ; // Step 23
				}
				{
					return usefor(am2_R_op_take_car, 1, this, P_menu_arriving, Step 24, am_localargs, ToModelTime(5, UNITSECONDS));
Label24: ; // Step 24
				}
				{
					return waitorder(am2_OL_take_car, this, P_menu_arriving, Step 25, am_localargs);
Label25: ; // Step 25
					if (!this->inLeaveProc && this->nextproc) {
						retval = Continue;
						goto LabelRet;
					}
				}
			}
			else {
				{
					pushppa(this, P_menu_arriving, Step 26, am_localargs);
					load_SetDestLoc(this, LocGetQualifier(am_model.am_conv.am_sta_room, -9999));
					pushppa(this, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label26: ; // Step 26
				}
				{
					pushppa(this, P_menu_arriving, Step 27, am_localargs);
					pushppa(this, inqueue, Step 1, am2_Q_take_person);
					return Continue; // go move into territory
Label27: ; // Step 27
				}
				{
					LdSetPriority(this, am2_V_pers_counter);
					EntityChanged(0x00000040);
				}
				{
					return waitorder(am2_OL_take_person, this, P_menu_arriving, Step 28, am_localargs);
Label28: ; // Step 28
					if (!this->inLeaveProc && this->nextproc) {
						retval = Continue;
						goto LabelRet;
					}
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_menu_arriving */



/* init function for P_menua.m */
void
model_P_menua_init(struct model_struct* data)
{
	data->am_P_menu->aprc = P_menu_arriving;
}

