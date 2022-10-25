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
	NEXTSEC name sec2 type DefaultSection width 1.5 Meters
	NEXTSTA name person_out1 type DefaultStation
	NEXTTRAN name tran1 type DefaultTransfer
	NEXTMOTOR name motor1 type DefaultMotor
	NEXTPHOTOEYE name photoeye1 type DefaultPhotoeye
	ALTERNATE NONE EXTRASECTIONWIDTH 0 Meters
CONVTOL minang 450 maxang 1350
CONVMOTORTYPE name DefaultMotor
CONVMOTOR name M_sec1 type DefaultMotor
CONVSECTIONTYPE name DefaultSection width 1 Meters color -1 motor M_sec1 vel 0.3 Meters Seconds acc 0.3 Meters Seconds Seconds dec 0.3 Meters Seconds Seconds accum load stopsize 1 0 Meters movesize 1 0 Meters inductsize 1 0 Meters nofixed align centered_in_interval attach rigid nav 1
CONVSECTION name sec1 type DefaultSection width 1 Meters piece begx 2 begy -4 endx -5 endy -4 upz 1
CONVSTATIONTYPE name DefaultStation raise 0 Seconds lower 0 Seconds dist 0 Meters release norestriction align leading cap Infinite scale 1 color -1 nrot 0 nscale 1
CONVSTATION name person_in type DefaultStation at sec1 0
CONVSTATION name person_out type DefaultStation at sec1 7
CONVPHOTOEYETYPE name DefaultPhotoeye blocktimeout 5 Seconds cleartimeout 5 Seconds
CONVTRANSFERTYPE name DefaultTransfer inductsize 1 0 Meters aheadinductsize 1 0 Meters speedadjust Origin starttime 0 Seconds finishtime 0 Seconds style double movemethod movesection
