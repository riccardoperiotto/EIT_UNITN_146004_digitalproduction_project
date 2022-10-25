// P_init_stocka.c
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
P_init_stock_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	{
		{
			SetString(&this->attribute->am2_V_stock_type, "bread");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[1] = LocGetQualifier(am_model.am_restock.am_re_bread, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[1]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[1]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[1]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[1]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "meat1");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[2] = LocGetQualifier(am_model.am_restock.am_re_meat_1, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[2]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[2]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[2]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[2]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "meat2");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[3] = LocGetQualifier(am_model.am_restock.am_re_meat_2, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[3]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[3]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[3]), 29, label*), 58);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[3]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "veggy");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[4] = LocGetQualifier(am_model.am_restock.am_re_veg, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[4]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[4]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[4]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[4]), NULL);
		}
		{
			this->attribute->am2_V_stock_location[5] = LocGetQualifier(am_model.am_restock.am_re_veg, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[5]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[5]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[5]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[5]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "chicken1");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[6] = LocGetQualifier(am_model.am_restock.am_re_chick_1, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[6]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[6]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[6]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[6]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "chicken2");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[7] = LocGetQualifier(am_model.am_restock.am_re_chick_2, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[7]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[7]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[7]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[7]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "chips");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[8] = LocGetQualifier(am_model.am_restock.am_re_chips, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[8]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[8]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[8]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[8]), NULL);
		}
		{
			SetString(&this->attribute->am2_V_stock_type, "drink");
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_stock_location[9] = LocGetQualifier(am_model.am_restock.am_re_drink, -9999);
			EntityChanged(0x00000040);
		}
		{
			CntSetContents(ValidPtr(&(am2_C_stock[9]), 10, counter*), CntGetCapacity(ValidPtr(&(am2_C_stock[9]), 10, counter*)) / 2, this);
			EntityChanged(0x00000010);
		}
		{
			LabSetColor(ValidPtr(&(am2_LB_stock[9]), 29, label*), 2);
			EntityChanged(0x00000800);
		}
		{
			clone(this, 1, &(am2_P_stock[9]), NULL);
		}
		{
			{
				char* pArg1 = "*** STOCK FOR EACH OPERATOR REFILLED ***";

				message("%s", pArg1);
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_init_stock_arriving */



/* init function for P_init_stocka.m */
void
model_P_init_stocka_init(struct model_struct* data)
{
	data->am_P_init_stock->aprc = P_init_stock_arriving;
}

