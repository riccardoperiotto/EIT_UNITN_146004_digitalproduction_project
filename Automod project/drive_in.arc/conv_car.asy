VERSION 12.6.1.12
SYSTYPE Conveyor
UNITS Meters Seconds
SYSDEF timeout 60 Seconds confname Config1
FLAGS
	System Inherit
	Text Inherit
	Sections Inherit
	Section Names Invisible Inherit
	Direction Inherit
	Fixed Interval Inherit
	Loads Inherit
	Stations Inherit
	Station Names Inherit
	Transfers Inherit
	Photoeyes Inherit
	Photoeye Names Inherit
	Center Line Invisible Inherit
CONVDEF UserId 6
	NEXTSEC name sec7 type DefaultSection width 2 Meters
	NEXTSTA name sta_start1 type DefaultStation
	NEXTTRAN name tran26 type DefaultTransfer
	NEXTMOTOR name motor1 type DefaultMotor
	NEXTPHOTOEYE name photoeye1 type DefaultPhotoeye
	ALTERNATE NONE EXTRASECTIONWIDTH 0 Feet
CONVTOL minang 450 maxang 1350
CONVMOTORTYPE name DefaultMotor
CONVMOTOR name M_sec1 type DefaultMotor
CONVSECTIONTYPE name DefaultSection width 4 Feet color -1 motor M_sec1 vel 1 Feet Seconds acc 1 Feet Seconds Seconds dec 1 Feet Seconds Seconds accum load stopsize 1 0 Feet movesize 1 0 Feet inductsize 1 0 Feet nofixed align centered_in_interval attach rigid nav 1
CONVSECTION name sec5 type DefaultSection width 2.5 Meters piece begx 20 begy -7 endx 20 endy 9 upz 1
CONVSECTION name sec6 type DefaultSection width 2.5 Meters piece begx 15 begy 14 endx -11 endy 14 upz 1
CONVSECTION name sec7 type DefaultSection width 2.5 Meters piece cenx 15 ceny 9 begx 20 begy 9 upz 1 angle 900
CONVSTATIONTYPE name DefaultStation raise 0 Seconds lower 0 Seconds dist 0 Feet release norestriction align leading cap Infinite scale 1 color -1 nrot 0 nscale 1
CONVSTATION name sta_take type DefaultStation at sec6 23.5
CONVSTATION name sta_order type DefaultStation at sec5 12
CONVSTATION name sta_pay type DefaultStation at sec6 5
CONVSTATION name sta_start type DefaultStation at sec5 0
CONVPHOTOEYETYPE name DefaultPhotoeye blocktimeout 5 Seconds cleartimeout 5 Seconds
CONVTRANSFERTYPE name DefaultTransfer inductsize 1 0 Feet aheadinductsize 1 0 Feet speedadjust Origin starttime 0 Seconds finishtime 0 Seconds style double movemethod movesection
CONVTRANSFER name tran24 type DefaultTransfer from sec5 16 to sec7 0
CONVTRANSFER name tran25 type DefaultTransfer from sec7 7.85398163397448 to sec6 0
