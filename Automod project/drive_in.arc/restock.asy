VERSION 12.6.1.12
SYSTYPE AGVS
UNITS Meters Seconds
SYSDEF timeout 60 Seconds confname Config1
FLAGS
	System Inherit
	Text Inherit
	Paths Inherit
	Path Names Invisible Inherit
	Direction Inherit
	Vehicles Inherit
	Path Attach Points Inherit
	Control Points Inherit
	Control Point Names Inherit
	Transfers Inherit
AGVSDEF secname path16 name re_veg1 UserId 2
	NEXTPATH name path16 type DefaultGuidePath two
	NEXTCP name re_veg1 type DefaultControlPoint
	ALTERNATE NONE ResumeSpeedWhenClaimed
	vel 0 Infinite Meters Seconds
	crabvel 0 Infinite Meters Seconds
	sprvel 0 Infinite Meters Seconds
	crvvel 0 Infinite Meters Seconds
AGVSTOL minang 450 maxang 1350
GPATHTYPE name DefaultGuidePath one normal attach rigid color -1 nav 1 vel 1 0 Meters Seconds 
GPATH name path6 type DefaultGuidePath two piece begx 0.4 begy 10 endx 0.4 endy 10.5 upz 1
GPATH name path7 type DefaultGuidePath two piece begx 3.4 begy 10 endx 3.4 endy 10.5 upz 1
GPATH name path9 type DefaultGuidePath two piece begx 13.6 begy 10 endx 13.6 endy 0.0 upz 1
GPATH name path14 type DefaultGuidePath two piece begx 9 begy 4 endx 13.1 endy 4 upz 1
GPATH name path16 type DefaultGuidePath two piece cenx 13.1 ceny 3.5 begx 13.1 begy 4 upz 1 angle -900
GPATH name path17 type DefaultGuidePath two piece begx -6.1 begy 11 endx 12.6 endy 11 upz 1
GPATH name path19 type DefaultGuidePath two piece cenx 0.9 ceny 10.5 begx 0.4 begy 10.5 upz 1 angle -900
GPATH name path20 type DefaultGuidePath two piece cenx 3.9 ceny 10.5 begx 3.4 begy 10.5 upz 1 angle -900
GPATH name path21 type DefaultGuidePath two piece cenx 12.6 ceny 10 begx 12.6 begy 11 upz 1 angle -900
GPATH name path23 type DefaultGuidePath two piece begx 0.4 begy 0.0 endx 0.4 endy -0.5 upz 1
GPATH name path24 type DefaultGuidePath two piece begx 3.4 begy 0.0 endx 3.4 endy -0.5 upz 1
GPATH name path25 type DefaultGuidePath two piece begx 12.6 begy -1 endx -3.5 endy -1 upz 1
GPATH name path26 type DefaultGuidePath two piece cenx 0.9 ceny -0.5 begx 0.4 begy -0.5 upz 1 angle 900
GPATH name path27 type DefaultGuidePath two piece cenx 3.9 ceny -0.5 begx 3.9 begy -1 upz 1 angle -900
GPATH name path28 type DefaultGuidePath two piece cenx 12.6 begx 13.6 upz 1 angle -900.000000000001
GPATH name path29 type DefaultGuidePath two piece begx 16 begy 8 endx 16 endy 3 upz 1
GPATH name path30 type DefaultGuidePath two piece begx 15 begy 2 endx 14.1 endy 2 upz 1
GPATH name path31 type DefaultGuidePath two piece cenx 15 ceny 3 begx 16 begy 3 upz 1 angle -900
GPATH name path35 type DefaultGuidePath two piece begx -6.6 begy 7 endx -6.6 endy 10.5 upz 1
GPATH name path36 type DefaultGuidePath two piece cenx -6.1 ceny 10.5 begx -6.6 begy 10.5 upz 1 angle -900.000000000002
GPATH name path32 type DefaultGuidePath two piece cenx 14.1 ceny 2.5 begx 13.6 begy 2.5 upz 1 angle 900
GPATH name path33 type DefaultGuidePath two piece cenx 14.1 ceny 1.5 begx 14.1 begy 2 upz 1 angle 900
GPATH name path34 type DefaultGuidePath two piece begx 6.4 begy 6.4 endx 13.1 endy 6.4 upz 1
GPATH name path37 type DefaultGuidePath two piece cenx 13.1 ceny 5.9 begx 13.1 begy 6.4 upz 1 angle -900
GPATH name path38 type DefaultGuidePath two piece cenx 13.1 ceny 6.9 begx 13.6 begy 6.9 upz 1 angle -900
GPATH name path39 type DefaultGuidePath two piece begx -4 begy 3 endx -4 endy -0.5 upz 1
GPATH name path41 type DefaultGuidePath two piece cenx -3.5 ceny -0.5 begx -3.5 begy -1 upz 1 angle -900
CPOINTTYPE name DefaultControlPoint cap 2147483647 release distance 0 Meters align leadingpap limit Infinite scale 1 color -1 nrot 0 nscale 1
CPOINT name re_drink type DefaultControlPoint at path35 0
CPOINT name re_meat_1 type DefaultControlPoint at path7 0
CPOINT name re_meat_2 type DefaultControlPoint at path6 0
CPOINT name re_bread type DefaultControlPoint at path14 0
CPOINT name re_chick_1 type DefaultControlPoint at path24 0
CPOINT name re_chick_2 type DefaultControlPoint at path23 0
CPOINT name re_stock type DefaultControlPoint at path29 0
CPOINT name re_chips type DefaultControlPoint at path39 0
CPOINT name re_veg type DefaultControlPoint at path34 0
NAMELST name list_start_r
NAMELST name list_start_r item re_stock 
WORKLST name re_stock Sequential item re_stock 
PARKLST name re_stock Sequential item re_stock 
 sameas re_drink
PARKLST name re_chick_1 Sequential item re_stock 
 sameas re_drink
PARKLST name re_drink Sequential item re_stock 
PARKLST name re_meat_2 Sequential item re_stock 
 sameas re_drink
PARKLST name re_chips Sequential item re_stock 
 sameas re_drink
PARKLST name re_meat_1 Sequential item re_stock 
 sameas re_drink
PARKLST name re_bread Sequential item re_stock 
 sameas re_drink
PARKLST name re_chick_2 Sequential item re_stock 
 sameas re_drink
PARKLST name re_veg Sequential item re_stock 
 sameas re_drink
AGVVEHSEG name restocker_seg cap 1 pickup 30 Seconds setdown 20 Seconds
	figcurspeed 100
	figmaxspeed 100
	 display picpos begx 17 begy 9 endx 16 endy 9 scx 0.300000011920929 scy 0.300000011920929 scz 0.300000011920929

	template Meters
700 17
1 1 0 1 1 man_cell
1
700 21
1 1 0 1 1 manset
-0.314999997615814  0  3.79999995231628
0 0 0 180
	1.00	1.00	1.00
13
310 21
1 1 0 1 1 chest
	0.00	0.00	0.00
0 0 0 90
	1.00	1.00	1.00
1 1.20000004768372 1 2 1.20000004768372 0 0
310 21
1 1 0 1 1 middle
0  0  -1
0	0.00	0.00	0.00
	1.00	1.00	1.00
1.20000004768372 1 1.20000004768372 1 1 0 0
310 21
1 1 0 1 1 leg
-1.35000002384186  0.300000011920929  -2
0 0 45 0
	1.00	1.00	1.00
0.5 0.600000023841858 0.600000023841858 1.20000004768372 2 0 0
310 21
1 1 0 1 1 leg
-1.25  0.300000011920929  -3.5
0	0.00	0.00	0.00
	1.00	1.00	1.00
0.400000005960464 0.400000005960464 0.5 0.600000023841858 1.70000004768372 0 0
310 21
1 1 0 1 1 leg
0.400000005960464  -0.300000011920929  -2.20000004768372
0 0 -15 0
	1.00	1.00	1.00
0.5 0.600000023841858 0.600000023841858 1.10000002384186 1.79999995231628 0 0
310 21
1 1 0 1 1 leg
1.14999997615814  -0.300000011920929  -3.40000009536743
0 0 -30 0
	1.00	1.00	1.00
0.400000005960464 0.400000005960464 0.5 0.699999988079071 1.70000004768372 0 0
310 5
10 10 0 1 1 foot
0.899999976158142  -0.300000011920929  -3.59999990463257
0 0 -20 0
	1.00	1.00	1.00
0.400000005960464 1 0.400000005960464 1 0.300000011920929 0 0
310 5
10 10 0 1 1 foot
-1.5  0.300000011920929  -3.79999995231628
0	0.00	0.00	0.00
	1.00	1.00	1.00
0.400000005960464 1 0.400000005960464 1 0.300000011920929 0 0
350 5
13 13 0 1 1 head
0  0  1.10000002384186
0	0.00	0.00	0.00
	1.00	1.00	1.00
0.300000011920929 0.600000023841858 0 0
700 17
1 1 0 1 1 larm
3
350 21
1 1 0 1 1 upper
-0.899999976158142  1  0.100000001490116
0 0 35 0
	1.00	1.00	1.00
0.200000002980232 1.20000004768372 0 0
360 21
1 1 0 1 1 lower
-1.79999995231628  1  0.200000002980232
0 0 90 0
	1.00	1.00	1.00
0.100000001490116 0.200000002980232 1 0 0
350 5
13 13 0 1 1 hand
-2  1  0.200000002980232
0 90 90 0
	1.00	1.00	1.00
0.100000001490116 0.200000002980232 0 0
700 21
1 1 0 1 1 rarm
0  -2  0
0	0.00	0.00	0.00
	1.00	1.00	1.00
4
350 21
1 1 0 1 1 upper
-0.899999976158142  1  0.100000001490116
0 0 35 0
	1.00	1.00	1.00
0.200000002980232 1.20000004768372 0 0
360 21
1 1 0 1 1 lower
-1.79999995231628  1  0.200000002980232
0 0 90 0
	1.00	1.00	1.00
0.100000001490116 0.200000002980232 1 0 0
350 5
13 13 0 1 1 hand
-2  1  0.200000002980232
0 90 90 0
	1.00	1.00	1.00
0.100000001490116 0.200000002980232 0 0
700 7
4 4 0 1 1 holder
	0
	0	0	0	0	1
	0.00	0.00	0.00
0	0.00	0.00	0.00
	1.00	1.00	1.00
	0
0  1  0
0 0 0 180
1  1  1
-1.9099999666214  1  0.300000011920929
0	0.00	0.00	0.00
	1.00	1.00	1.00
0
330 5
1 1 0 1 1 tophead
0  0  1.60000002384186
0 0 5 0
	1.00	1.00	1.00
0.400000005960464
310 5
1 1 0 1 1 cap
-0.300000011920929  0  1.62999999523163
0 0 5 0
	1.00	1.00	1.00
0.5 0.5 0.5 0.5 0.0500000007450581 0 0
end
	fconn length 0.0 Meters noscale 0
	rconn length 0.0 Meters noscale 0
	PAPATTACH
	PAP ind 0 
		trx 0 try 0 trz 0
AGVSVEH type re_stocker numveh 1
	vehsegs item restocker_seg 
	start list_start_r
	Stacking PLUSZ	
	color 1 picpos begx 14.8 begy 8 endx 14.8 endy 9

	load Default 
		accel	0 0.3 Meters Seconds Seconds
		decel	0 0.3 Meters Seconds Seconds
		vel	0 0.64 Meters Seconds
		crvvel	0 0.64 Meters Seconds
		sprvel	0 0.64 Meters Seconds
		rvel	0 0.64 Meters Seconds
		rcrvvel	0 0.64 Meters Seconds
		rsprvel	0 0.64 Meters Seconds
		crabvel	0 0.64 Meters Seconds
		rotate	0 1 Seconds
		brakedist	0 1.7 Meters
		stopdist	0 0 Meters
	load Empty 
		accel	1 1.2 Meters Seconds Seconds
		decel	1 1.2 Meters Seconds Seconds
		vel	1 1.2 Meters Seconds
		crvvel	1 1.2 Meters Seconds
		sprvel	1 1.2 Meters Seconds
		rvel	1 1.2 Meters Seconds
		rcrvvel	1 1.2 Meters Seconds
		rsprvel	1 1.2 Meters Seconds
		crabvel	1 1.2 Meters Seconds
		rotate	1 1.2 Seconds
		brakedist	1 0 Meters
		stopdist	1 0 Meters
