// P_init_read_inputa.c
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
P_init_read_input_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			am2_V_debug = 1;
			EntityChanged(0x01000000);
		}
		{
			{
				char* pArg1 = "*** FILE READING STARTED ***";

				message("%s", pArg1);
			}
		}
		{
			am2_V_file_input_ptr = OpenFilePtr(am_model.$sys, am2_V_file_input_name, "r");
		}
				{
			if (isFileValid(am2_V_file_input_ptr, 1)) {
				int rflag;
				static ReadRef st1;

				setupReadRef(&st1, 0, am_model.am_V_headers$var, &am2_V_headers, NULL, -1, FALSE);
				rflag = readFile(am2_V_file_input_ptr->fp, "\n", &st1, NULL);
				SetFileAtEof(am2_V_file_input_ptr, EOF, rflag);
			}
		}
		{
			while (FileGetEof(ValidPtr(am2_V_file_input_ptr, 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_V_file_input_ptr, 1)) {
						int rflag;
						static ReadRef st1;
						static ReadRef st2;
						static ReadRef st3;
						static ReadRef st4;

						setupReadRef(&st1, 1, am_model.am_V_order_id$att, &this->attribute->am2_V_order_id, NULL, -1, FALSE);
						setupReadRef(&st2, 1, am_model.am_V_arrival_time$att, &this->attribute->am2_V_arrival_time, NULL, -1, FALSE);
						setupReadRef(&st3, 1, am_model.am_V_order_provenience$att, &this->attribute->am2_V_order_provenience, NULL, -1, FALSE);
						setupReadRef(&st4, 1, am_model.am_V_order_dim$att, &this->attribute->am2_V_order_dim, NULL, -1, FALSE);
						rflag = readFile(am2_V_file_input_ptr->fp, ";", &st1, &st2, &st3, &st4, NULL);
						SetFileAtEof(am2_V_file_input_ptr, EOF, rflag);
						if (rflag == EOF) {
							{
								char* pArg1 = "    Order read: Id: ";
								char* pArg2 = " ";
								char* pArg3 = this->attribute->am2_V_order_id;
								char* pArg4 = " ";
								char* pArg5 = ", time: ";
								char* pArg6 = " ";
								int32 pArg7 = this->attribute->am2_V_arrival_time;
								char* pArg8 = " ";
								char* pArg9 = ", provenience: ";
								char* pArg10 = " ";
								char* pArg11 = this->attribute->am2_V_order_provenience;
								char* pArg12 = " ";
								char* pArg13 = ", dim: ";
								char* pArg14 = " ";
								int32 pArg15 = this->attribute->am2_V_order_dim;

								message("%s%s%s%s%s%s%d%s%s%s%s%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15);
							}
						}
					}
				}
				{
					if (waitfor(ToModelTime((this->attribute->am2_V_arrival_time - FromModelTime(ASIclock, UNITSECONDS)), UNITSECONDS), this, P_init_read_input_arriving, Step 2, am_localargs) == Delayed)
						return Delayed;
Label2: ; // Step 2
				}
				{
					if (StringCompare(this->attribute->am2_V_order_provenience, "car") == 0) {
						{
							clone(this, 1, am2_P_car, NULL);
						}
					}
					else {
						{
							clone(this, 1, am2_P_person, NULL);
						}
					}
				}
			}
		}
		{
			{
				char* pArg1 = "*** FILE READING COMPLETED ***";

				message("%s", pArg1);
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
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_init_read_input_arriving */



/* init function for P_init_read_inputa.m */
void
model_P_init_read_inputa_init(struct model_struct* data)
{
	data->am_P_init_read_input->aprc = P_init_read_input_arriving;
}

