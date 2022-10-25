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
	NEXTSEC name sec20_6 type DefaultSection
	NEXTSTA name sta_bread type DefaultStation
	NEXTTRAN name tran59 type DefaultTransfer
	NEXTMOTOR name motor1 type DefaultMotor
	NEXTPHOTOEYE name photoeye1 type DefaultPhotoeye
	ALTERNATE NONE EXTRASECTIONWIDTH 0 Feet
CONVTOL minang 450 maxang 1350
CONVMOTORTYPE name DefaultMotor
CONVMOTOR name M_sec1 type DefaultMotor
CONVSECTIONTYPE name DefaultSection width 4 Feet color -1 motor M_sec1 vel 1 Feet Seconds acc 1 Feet Seconds Seconds dec 1 Feet Seconds Seconds accum load stopsize 1 0 Feet movesize 1 0 Feet inductsize 1 0 Feet nofixed align centered_in_interval attach rigid nav 1
CONVSECTION name sec2 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 10.5 begy 6 endx 7.5 endy 6 upz 1
CONVSECTION name sec10 type DefaultSection width 0.60 Meters vel 1 Meters Seconds piece begx 1 begy 6 endx -6 endy 6 upz 1
CONVSECTION name sec19 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 8 ceny 7 begx 8 begy 6 upz 1 angle -900
CONVSECTION name sec20 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 8 ceny 5 begx 8 begy 6 upz 1 angle 900
CONVSECTION name sec10_2 type DefaultSection width 0.60 Meters vel 1 Meters Seconds piece begx -7 begy 7 endx -7 endy 11.5 upz 1
CONVSECTION name sec19_1 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 7 begy 7 endx 7 endy 8 upz 1
CONVSECTION name sec19_2 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 6 ceny 8 begx 7 begy 8 upz 1 angle 900
CONVSECTION name sec19_3 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 6 begy 9 endx 1 endy 9 upz 1
CONVSECTION name sec19_4 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 1 ceny 8 begx 1 begy 9 upz 1 angle 900
CONVSECTION name sec19_5 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 0.0 begy 8 endx 0.0 endy 7 upz 1
CONVSECTION name sec19_6 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx -1 ceny 7 begy 7 upz 1 angle -900
CONVSECTION name sec2_1 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 7.5 begy 6 endx 0.0 endy 6 upz 1
CONVSECTION name sec20_1 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 7 begy 5 endx 7 endy 4 upz 1
CONVSECTION name sec20_2 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 6 ceny 4 begx 7 begy 4 upz 1 angle -900
CONVSECTION name sec20_3 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 6 begy 3 endx 1 endy 3 upz 1
CONVSECTION name sec20_4 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx 1 ceny 4 begx 1 begy 3 upz 1 angle -900
CONVSECTION name sec20_5 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx 0.0 begy 4 endx 0.0 endy 5 upz 1
CONVSECTION name sec20_6 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx -1 ceny 5 begy 5 upz 1 angle 900
CONVSECTION name sec22_1 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece begx -7 begy 5 endx -7 endy 3.5 upz 1
CONVSECTION name sec21 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx -6 ceny 7 begx -6 begy 6 upz 1 angle -900
CONVSECTION name sec22 type DefaultSection width 0.6 Meters vel 1 Meters Seconds piece cenx -6 ceny 5 begx -6 begy 6 upz 1 angle 900
CONVSTATIONTYPE name DefaultStation raise 0 Seconds lower 0 Seconds dist 0 Feet release norestriction align leading cap Infinite scale 1 color -1 nrot 0 nscale 1
CONVSTATION name sta_bread type DefaultStation at sec2 1
CONVSTATION name sta_first_ing_1 type DefaultStation at sec19_3 1
CONVSTATION name sta_second_ing_1 type DefaultStation at sec19_3 4
CONVSTATION name sta_first_ing_2 type DefaultStation at sec2_1 2.5
CONVSTATION name sta_second_ing_2 type DefaultStation at sec2_1 5.5
CONVSTATION name sta_first_ing_3 type DefaultStation at sec20_3 1
CONVSTATION name sta_second_ing_3 type DefaultStation at sec20_3 4
CONVSTATION name sta_room type DefaultStation at sec22_1 1
CONVSTATION name sta_drink type DefaultStation at sec10 6
CONVSTATION name sta_chips type DefaultStation at sec10 3.5
CONVSTATION name sta_car type DefaultStation at sec10_2 4
CONVPHOTOEYETYPE name DefaultPhotoeye blocktimeout 5 Seconds cleartimeout 5 Seconds
CONVTRANSFERTYPE name DefaultTransfer inductsize 1 0 Feet aheadinductsize 1 0 Feet speedadjust Origin starttime 0 Seconds finishtime 0 Seconds style double movemethod movesection
CONVTRANSFER name tran24 type DefaultTransfer from sec2 2.5 to sec19 0
CONVTRANSFER name tran25 type DefaultTransfer from sec2 3 to sec19 0.463647609000806
CONVTRANSFER name tran28 type DefaultTransfer from sec2 2.5 to sec20 0
CONVTRANSFER name tran29 type DefaultTransfer from sec2 3 to sec20 0.463647609000806
CONVTRANSFER name tran43 type DefaultTransfer from sec19 1.5707963267949 to sec19_1 0
CONVTRANSFER name tran42 type DefaultTransfer from sec19_1 1 to sec19_2 0
CONVTRANSFER name tran41 type DefaultTransfer from sec19_2 1.5707963267949 to sec19_3 0
CONVTRANSFER name tran40 type DefaultTransfer from sec19_3 5 to sec19_4 0
CONVTRANSFER name tran39 type DefaultTransfer from sec19_4 1.5707963267949 to sec19_5 0
CONVTRANSFER name tran12 type DefaultTransfer from sec19_6 1.5707963267949 to sec10 2
CONVTRANSFER name tran38 type DefaultTransfer from sec19_5 1 to sec19_6 0
CONVTRANSFER name tran58 type DefaultTransfer from sec2 3 to sec2_1 0
CONVTRANSFER name tran20 type DefaultTransfer from sec2_1 7.5 to sec10 1
CONVTRANSFER name tran21 type DefaultTransfer from sec2_1 6.5 to sec10 0
CONVTRANSFER name tran45 type DefaultTransfer from sec19 0.463647609000806 to sec2_1 0
CONVTRANSFER name tran46 type DefaultTransfer from sec20 0.463647609000806 to sec2_1 0
CONVTRANSFER name tran52 type DefaultTransfer from sec20 1.5707963267949 to sec20_1 0
CONVTRANSFER name tran51 type DefaultTransfer from sec20_1 1 to sec20_2 0
CONVTRANSFER name tran50 type DefaultTransfer from sec20_2 1.5707963267949 to sec20_3 0
CONVTRANSFER name tran49 type DefaultTransfer from sec20_3 5 to sec20_4 0
CONVTRANSFER name tran48 type DefaultTransfer from sec20_4 1.5707963267949 to sec20_5 0
CONVTRANSFER name tran14 type DefaultTransfer from sec20_6 1.5707963267949 to sec10 2
CONVTRANSFER name tran47 type DefaultTransfer from sec20_5 1 to sec20_6 0
CONVTRANSFER name tran54 type DefaultTransfer from sec10 7 to sec21 0
CONVTRANSFER name tran55 type DefaultTransfer from sec21 1.5707963267949 to sec10_2 0
CONVTRANSFER name tran56 type DefaultTransfer from sec10 7 to sec22 0
CONVTRANSFER name tran57 type DefaultTransfer from sec22 1.5707963267949 to sec22_1 0
