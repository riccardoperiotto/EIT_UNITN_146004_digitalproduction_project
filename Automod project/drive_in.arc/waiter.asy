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
AGVSDEF secname path6 name w_room_in UserId 2
	NEXTPATH name path6 type DefaultGuidePath two
	NEXTCP name w_room_in type DefaultControlPoint
	ALTERNATE NONE ResumeSpeedWhenClaimed
	vel 0 Infinite Meters Seconds
	crabvel 0 Infinite Meters Seconds
	sprvel 0 Infinite Meters Seconds
	crvvel 0 Infinite Meters Seconds
AGVSTOL minang 450 maxang 1350
GPATHTYPE name DefaultGuidePath one normal attach rigid color -1 nav 1 vel 1 0 Meters Seconds 
GPATH name path3 type DefaultGuidePath two piece begx -9 begy 3 endx -9.5 endy 3 upz 1
GPATH name path4 type DefaultGuidePath two piece begx -10 begy 2.5 endx -10 endy -3.2 upz 1
GPATH name path5 type DefaultGuidePath two piece cenx -9.5 ceny 2.5 begx -9.5 begy 3 upz 1 angle 900
CPOINTTYPE name DefaultControlPoint cap 2147483647 release distance 0 Meters align leadingpap limit Infinite scale 1 color -1 nrot 0 nscale 1
CPOINT name w_room_out type DefaultControlPoint at path4 5.5
CPOINT name w_room_in type DefaultControlPoint at path3 0
NAMELST name list_start_w
NAMELST name list_start_w item w_room_in 
WORKLST name w_room_in Sequential item w_room_in 
PARKLST name w_room_out Sequential item w_room_in 
AGVVEHSEG name waiter_segment cap 1 pickup 15 Seconds setdown 15 Seconds
	figcurspeed 100
	figmaxspeed 100
	 display picpos begx -11 begy 4 endx -10 endy 4 scx 0.300000011920929 scy 0.300000011920929 scz 0.300000011920929

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
AGVSVEH type waiter numveh 1
	vehsegs item waiter_segment 
	start Random
	Stacking OTT_LDDISP	
	 picpos endx 1

	load Default 
		accel	0 0.3 Meters Seconds Seconds
		decel	0 0.3 Meters Seconds Seconds
		vel	0 1 Meters Seconds
		crvvel	0 1 Meters Seconds
		sprvel	0 1 Meters Seconds
		rvel	0 1 Meters Seconds
		rcrvvel	0 1 Meters Seconds
		rsprvel	0 1 Meters Seconds
		crabvel	0 1 Meters Seconds
		rotate	0 2 Seconds
		brakedist	0 1.7 Meters
		stopdist	0 0 Meters
	load Empty 
		accel	1 0 Meters Seconds Seconds
		decel	1 0 Meters Seconds Seconds
		vel	1 0 Meters Seconds
		crvvel	1 0 Meters Seconds
		sprvel	1 0 Meters Seconds
		rvel	1 0 Meters Seconds
		rcrvvel	1 0 Meters Seconds
		rsprvel	1 0 Meters Seconds
		crabvel	1 0 Meters Seconds
		rotate	1 0 Seconds
		brakedist	1 0 Meters
		stopdist	1 0 Meters
