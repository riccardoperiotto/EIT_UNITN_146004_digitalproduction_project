// P_order_rooma.c
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
OrderCondFunc0(load* this)
{
	if (StringCompare(this->attribute->am2_V_order_id, this->attribute->am2_V_order_id) == 0)
		return TRUE;
	return FALSE;
}

static int32
P_order_room_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			LdSetType(this, am2_L_order_room);
			EntityChanged(0x00000040);
		}
		{
			pushppa(this, P_order_room_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_waiter.am_w_room_in, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			if (transformLoad(TX_LOAD_ROTATE, 0.0, 0.0, 0, 0, 0, 1, 0.0, CntnrGetVehicle(ValidPtr(LdGetCurContainer(this), 13, Container*)), this, P_order_room_arriving, Step 3, am_localargs) == Delayed)
				return Delayed;
Label3: ; // Step 3
		}
		{
			pushppa(this, P_order_room_arriving, Step 4, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_waiter.am_w_room_out, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label4: ; // Step 4
		}
		{
			order(1, am2_OL_waiting_person, NULL, OrderCondFunc0);		// Place an order
		}
		{
			if (transformLoad(TX_LOAD_ROTATE, 0.0, 0.0, 180, 0, 0, 1, 0.0, CntnrGetVehicle(ValidPtr(LdGetCurContainer(this), 13, Container*)), this, P_order_room_arriving, Step 5, am_localargs) == Delayed)
				return Delayed;
Label5: ; // Step 5
		}
		{
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_order_room_arriving */



/* init function for P_order_rooma.m */
void
model_P_order_rooma_init(struct model_struct* data)
{
	data->am_P_order_room->aprc = P_order_room_arriving;
}

