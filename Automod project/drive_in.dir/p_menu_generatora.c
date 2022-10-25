// P_menu_generatora.c
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



static process*
Func0(load* this)
{
	return &(am2_P_menu[1]);
}


static process*
Func1(load* this)
{
	return &(am2_P_menu[2]);
}


static process*
Func2(load* this)
{
	return &(am2_P_menu[3]);
}


typedef struct {
	double freq;
	process* (*value)(load*);
} Oneof0;

static Oneof0 List0[] = {
	{ 33, Func0},
	{ 66, Func1},
	{ 99, Func2}
};

static process*
oneofFunc0(load* this)
{
	int ind = 0;
	Oneof0* list = List0;
	double sample = getdrand(am2_stream0) * 99;

	tprintf(tfp, "In oneof\n");
	while (list->freq < sample) {
		ind++;
		list++;
	}
	return List0[ind].value(this);
}


typedef struct {
	double freq;
	int32 value;
} Oneof1;

static Oneof1 List1[] = {
	{ 25, 0},
	{ 100, 1}
};

static int32
oneofFunc1(load* this)
{
	int ind = 0;
	Oneof1* list = List1;
	double sample = getdrand(am2_stream0) * 100;

	tprintf(tfp, "In oneof\n");
	while (list->freq < sample) {
		ind++;
		list++;
	}
	return List1[ind].value;
}


typedef struct {
	double freq;
	int32 value;
} Oneof2;

static Oneof2 List2[] = {
	{ 10, 0},
	{ 100, 1}
};

static int32
oneofFunc2(load* this)
{
	int ind = 0;
	Oneof2* list = List2;
	double sample = getdrand(am2_stream0) * 100;

	tprintf(tfp, "In oneof\n");
	while (list->freq < sample) {
		ind++;
		list++;
	}
	return List2[ind].value;
}

static int32
P_menu_generator_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	{
		{
			LdSetType(this, am2_L_menu);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_menu_pointer = oneofFunc0(this);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_chips = oneofFunc1(this);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_drink = oneofFunc2(this);
			EntityChanged(0x00000040);
		}
		{
			this->attribute->am2_V_load_type_ptrs[1] = am2_L_bread;
			EntityChanged(0x00000040);
		}
		{
			if (this->attribute->am2_V_menu_pointer == &(am2_P_menu[1])) {
				{
					SetString(&this->attribute->am2_V_menu_type, "meat");
					EntityChanged(0x00000040);
				}
				{
					this->attribute->am2_V_load_type_ptrs[2] = am2_L_meat_ing_1;
					EntityChanged(0x00000040);
				}
				{
					this->attribute->am2_V_load_type_ptrs[3] = am2_L_meat_closed;
					EntityChanged(0x00000040);
				}
				{
					if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 0) {
						{
							this->attribute->am2_V_load_type_ptrs[4] = am2_L_meat_closed;
							EntityChanged(0x00000040);
						}
						{
							this->attribute->am2_V_load_type_ptrs[5] = am2_L_meat_closed;
							EntityChanged(0x00000040);
						}
					}
				}
				{
					if (this->attribute->am2_V_chips == 1 && this->attribute->am2_V_drink == 0) {
						{
							this->attribute->am2_V_load_type_ptrs[4] = am2_L_meat_chips;
							EntityChanged(0x00000040);
						}
						{
							this->attribute->am2_V_load_type_ptrs[5] = am2_L_meat_chips;
							EntityChanged(0x00000040);
						}
					}
					else {
						if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 1) {
							{
								this->attribute->am2_V_load_type_ptrs[4] = am2_L_meat_closed;
								EntityChanged(0x00000040);
							}
							{
								this->attribute->am2_V_load_type_ptrs[5] = am2_L_meat_drink;
								EntityChanged(0x00000040);
							}
						}
						else {
							{
								this->attribute->am2_V_load_type_ptrs[4] = am2_L_meat_chips;
								EntityChanged(0x00000040);
							}
							{
								this->attribute->am2_V_load_type_ptrs[5] = am2_L_meat_complete;
								EntityChanged(0x00000040);
							}
						}
					}
				}
			}
			else {
				if (this->attribute->am2_V_menu_pointer == &(am2_P_menu[2])) {
					{
						SetString(&this->attribute->am2_V_menu_type, "veggy");
						EntityChanged(0x00000040);
					}
					{
						this->attribute->am2_V_load_type_ptrs[2] = am2_L_veggy_ing_1;
						EntityChanged(0x00000040);
					}
					{
						this->attribute->am2_V_load_type_ptrs[3] = am2_L_veggy_closed;
						EntityChanged(0x00000040);
					}
					{
						if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 0) {
							{
								this->attribute->am2_V_load_type_ptrs[4] = am2_L_veggy_closed;
								EntityChanged(0x00000040);
							}
							{
								this->attribute->am2_V_load_type_ptrs[5] = am2_L_veggy_closed;
								EntityChanged(0x00000040);
							}
						}
						else {
							if (this->attribute->am2_V_chips == 1 && this->attribute->am2_V_drink == 0) {
								{
									this->attribute->am2_V_load_type_ptrs[4] = am2_L_veggy_chips;
									EntityChanged(0x00000040);
								}
								{
									this->attribute->am2_V_load_type_ptrs[5] = am2_L_veggy_chips;
									EntityChanged(0x00000040);
								}
							}
							else {
								if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 1) {
									{
										this->attribute->am2_V_load_type_ptrs[4] = am2_L_veggy_closed;
										EntityChanged(0x00000040);
									}
									{
										this->attribute->am2_V_load_type_ptrs[5] = am2_L_veggy_drink;
										EntityChanged(0x00000040);
									}
								}
								else {
									{
										this->attribute->am2_V_load_type_ptrs[4] = am2_L_veggy_chips;
										EntityChanged(0x00000040);
									}
									{
										this->attribute->am2_V_load_type_ptrs[5] = am2_L_veggy_complete;
										EntityChanged(0x00000040);
									}
								}
							}
						}
					}
				}
				else {
					{
						SetString(&this->attribute->am2_V_menu_type, "chicken");
						EntityChanged(0x00000040);
					}
					{
						this->attribute->am2_V_load_type_ptrs[2] = am2_L_chicken_ing_1;
						EntityChanged(0x00000040);
					}
					{
						this->attribute->am2_V_load_type_ptrs[3] = am2_L_chicken_closed;
						EntityChanged(0x00000040);
					}
					{
						if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 0) {
							{
								this->attribute->am2_V_load_type_ptrs[4] = am2_L_chicken_closed;
								EntityChanged(0x00000040);
							}
							{
								this->attribute->am2_V_load_type_ptrs[5] = am2_L_chicken_closed;
								EntityChanged(0x00000040);
							}
						}
						else {
							if (this->attribute->am2_V_chips == 1 && this->attribute->am2_V_drink == 0) {
								{
									this->attribute->am2_V_load_type_ptrs[4] = am2_L_chicken_chips;
									EntityChanged(0x00000040);
								}
								{
									this->attribute->am2_V_load_type_ptrs[5] = am2_L_chicken_chips;
									EntityChanged(0x00000040);
								}
							}
							else {
								if (this->attribute->am2_V_chips == 0 && this->attribute->am2_V_drink == 1) {
									{
										this->attribute->am2_V_load_type_ptrs[4] = am2_L_chicken_closed;
										EntityChanged(0x00000040);
									}
									{
										this->attribute->am2_V_load_type_ptrs[5] = am2_L_chicken_drink;
										EntityChanged(0x00000040);
									}
								}
								else {
									{
										this->attribute->am2_V_load_type_ptrs[4] = am2_L_chicken_chips;
										EntityChanged(0x00000040);
									}
									{
										this->attribute->am2_V_load_type_ptrs[5] = am2_L_chicken_complete;
										EntityChanged(0x00000040);
									}
								}
							}
						}
					}
				}
			}
		}
		{
			if (this->attribute->am2_V_menu_pointer == &(am2_P_menu[1])) {
				this->attribute->am2_V_menu_value = 7;
				EntityChanged(0x00000040);
			}
		}
		{
			if (this->attribute->am2_V_menu_pointer == &(am2_P_menu[2])) {
				this->attribute->am2_V_menu_value = 5;
				EntityChanged(0x00000040);
			}
		}
		{
			if (this->attribute->am2_V_menu_pointer == &(am2_P_menu[3])) {
				this->attribute->am2_V_menu_value = 6;
				EntityChanged(0x00000040);
			}
		}
		{
			if (this->attribute->am2_V_chips == 1) {
				this->attribute->am2_V_menu_value = this->attribute->am2_V_menu_value + 3;
				EntityChanged(0x00000040);
			}
		}
		{
			if (this->attribute->am2_V_drink == 1) {
				this->attribute->am2_V_menu_value = this->attribute->am2_V_menu_value + 2.5000000000000000;
				EntityChanged(0x00000040);
			}
		}
		{
			am2_V_file_menu_list_ptr = OpenFilePtr(am_model.$sys, am2_V_file_menu_list_name, "a");
		}
		{
			{
				if (isFileValid(am2_V_file_menu_list_ptr, 0)) {
					char* pArg1 = this->attribute->am2_V_order_id;
					char* pArg2 = " ";
					char* pArg3 = ",";
					char* pArg4 = " ";
					char* pArg5 = this->attribute->am2_V_menu_type;
					char* pArg6 = " ";
					char* pArg7 = ",";
					char* pArg8 = " ";
					int32 pArg9 = this->attribute->am2_V_chips;
					char* pArg10 = " ";
					char* pArg11 = ",";
					char* pArg12 = " ";
					int32 pArg13 = this->attribute->am2_V_drink;
					char* pArg14 = " ";
					char* pArg15 = ",";
					char* pArg16 = " ";
					double pArg17 = this->attribute->am2_V_menu_value;
					char* pArg18 = " ";
					char* pArg19 = ",";
					char* pArg20 = " ";
					double pArg21 = FromModelTime(ASIclock, UNITSECONDS);

					fprintf((am2_V_file_menu_list_ptr)->fp, "%s%s%s%s%s%s%s%s%d%s%s%s%d%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17, pArg18, pArg19, pArg20, pArg21);
					fflush((am2_V_file_menu_list_ptr)->fp);
				}
			}
		}
		{
			CloseFilePtr(am2_V_file_menu_list_ptr);
		}
		{
			this->nextproc = this->attribute->am2_V_menu_pointer; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_menu_generator_arriving */



/* init function for P_menu_generatora.m */
void
model_P_menu_generatora_init(struct model_struct* data)
{
	data->am_P_menu_generator->aprc = P_menu_generator_arriving;
}

