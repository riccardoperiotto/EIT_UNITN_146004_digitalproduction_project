// P_stocka.c
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
P_stock_arriving(load* this, int32 step, void* args)
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
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			LdSetType(this, am2_L_stock);
			EntityChanged(0x00000040);
		}
		{
			if (CurProcIndex() == 1) {
				LdSetColor(this, 33);
				EntityChanged(0x00000040);
			}
			else {
				if (CurProcIndex() == 2) {
					LdSetColor(this, 1);
					EntityChanged(0x00000040);
				}
				else {
					if (CurProcIndex() == 3) {
						LdSetColor(this, 2);
						EntityChanged(0x00000040);
					}
					else {
						if (CurProcIndex() == 4) {
							LdSetColor(this, 14);
							EntityChanged(0x00000040);
						}
						else {
							if (CurProcIndex() == 5) {
								LdSetColor(this, 13);
								EntityChanged(0x00000040);
							}
							else {
								if (CurProcIndex() == 6) {
									LdSetColor(this, 59);
									EntityChanged(0x00000040);
								}
								else {
									if (CurProcIndex() == 7) {
										LdSetColor(this, 3);
										EntityChanged(0x00000040);
									}
									else {
										if (CurProcIndex() == 8) {
											LdSetColor(this, 2);
											EntityChanged(0x00000040);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		{
			while (1 == 1) {
				{
					pushppa(this, P_stock_arriving, Step 2, am_localargs);
					pushppa(this, inqueue, Step 1, am2_Q_restock);
					return Continue; // go move into territory
Label2: ; // Step 2
				}
				{
					while (CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*)) > CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*)) / 5) {
						{
							if (waitfor(ToModelTime(5, UNITSECONDS), this, P_stock_arriving, Step 3, am_localargs) == Delayed)
								return Delayed;
Label3: ; // Step 3
						}
					}
				}
				{
					pushppa(this, P_stock_arriving, Step 4, am_localargs);
					load_SetDestLoc(this, LocGetQualifier(am_model.am_restock.am_re_stock, -9999));
					pushppa(this, move_in_loc, Step 1, NULL);
					return Continue; // go move into territory
Label4: ; // Step 4
				}
				{
					if (transformLoad(TX_LOAD_ROTATE, 0.0, 0.0, 0, 0, 0, 1, 0.0, CntnrGetVehicle(ValidPtr(LdGetCurContainer(this), 13, Container*)), this, P_stock_arriving, Step 5, am_localargs) == Delayed)
						return Delayed;
Label5: ; // Step 5
				}
				{
					pushppa(this, P_stock_arriving, Step 6, am_localargs);
					load_SetDestLoc(this, this->attribute->am2_V_stock_location[ValidIndex("am_model.am_V_stock_location", CurProcIndex(), 9)]);
					pushppa(this, travel_to_loc, Step 1, NULL);
					return Continue; // go move to location
Label6: ; // Step 6
				}
				{
					CntSetContents(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*)), this);
					EntityChanged(0x00000010);
				}
				{
					{
						int32 pArg1 = CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*));
						char* pArg2 = " ";
						char* pArg3 = "/";
						char* pArg4 = " ";
						int32 pArg5 = CntGetCapacity(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*));
						char* pArg6 = rel_actorname(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", CurProcIndex(), 9)]), am_model.$sys);

						fprintf(pfp, "%d%s%s%s%d%s\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6);
					}
				}
				{
					LabSetColor(ValidPtr(&(am2_LB_stock[ValidIndex("am_model.am_LB_stock", CurProcIndex(), 9)]), 29, label*), 2);
					EntityChanged(0x00000800);
				}
				{
					{
						char* pArg1 = "*** STOCK OF INDEX ";
						char* pArg2 = " ";
						int32 pArg3 = CurProcIndex();
						char* pArg4 = " ";
						char* pArg5 = " REFILLED. CURRENT QUANTITY: ";
						char* pArg6 = " ";
						int32 pArg7 = CntGetCurConts(ValidPtr(&(am2_C_stock[ValidIndex("am_model.am_C_stock", CurProcIndex(), 9)]), 10, counter*));
						char* pArg8 = " ";
						char* pArg9 = " ***";

						message("%s%s%d%s%s%s%d%s%s", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					}
				}
				{
					if (transformLoad(TX_LOAD_ROTATE, 0.0, 0.0, 180, 0, 0, 1, 0.0, CntnrGetVehicle(ValidPtr(LdGetCurContainer(this), 13, Container*)), this, P_stock_arriving, Step 7, am_localargs) == Delayed)
						return Delayed;
Label7: ; // Step 7
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_stock_arriving */



/* init function for P_stocka.m */
void
model_P_stocka_init(struct model_struct* data)
{
	data->am_P_stock->aprc = P_stock_arriving;
}

