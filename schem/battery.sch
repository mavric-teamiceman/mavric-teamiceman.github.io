EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:msgeq7
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 6 11
Title "Battery Assembly"
Date "Thursday, April 30, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L Battery BT1
U 1 1 5548FBC8
P 2550 4350
F 0 "BT1" H 2650 4400 50  0000 L CNN
F 1 "Battery" H 2650 4300 50  0000 L CNN
F 2 "" V 2550 4390 60  0000 C CNN
F 3 "" V 2550 4390 60  0000 C CNN
	1    2550 4350
	1    0    0    -1  
$EndComp
Text HLabel 2550 4750 3    60   Output ~ 0
GND
Text HLabel 2550 3800 1    60   Output ~ 0
12V
$Comp
L 7805 U9
U 1 1 5548FC58
P 3650 4000
F 0 "U9" H 3800 3804 60  0000 C CNN
F 1 "7805" H 3650 4200 60  0000 C CNN
F 2 "" H 3650 4000 60  0000 C CNN
F 3 "" H 3650 4000 60  0000 C CNN
	1    3650 4000
	1    0    0    -1  
$EndComp
Text HLabel 4550 3950 2    60   Output ~ 0
5V
$Comp
L C C11
U 1 1 5548FCD9
P 4150 4350
F 0 "C11" H 4175 4450 50  0000 L CNN
F 1 "C" H 4175 4250 50  0000 L CNN
F 2 "" H 4188 4200 30  0000 C CNN
F 3 "" H 4150 4350 60  0000 C CNN
	1    4150 4350
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 5548FD22
P 3150 4350
F 0 "C10" H 3175 4450 50  0000 L CNN
F 1 "C" H 3175 4250 50  0000 L CNN
F 2 "" H 3188 4200 30  0000 C CNN
F 3 "" H 3150 4350 60  0000 C CNN
	1    3150 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3800 2550 4200
Wire Wire Line
	2550 4500 2550 4750
Wire Wire Line
	3250 3950 2550 3950
Connection ~ 2550 3950
Wire Wire Line
	3150 4200 3150 3950
Connection ~ 3150 3950
Wire Wire Line
	4150 4200 4150 3950
Wire Wire Line
	4050 3950 4550 3950
Wire Wire Line
	3150 4500 3150 4600
Wire Wire Line
	2550 4600 4150 4600
Connection ~ 2550 4600
Wire Wire Line
	4150 4600 4150 4500
Connection ~ 3150 4600
Wire Wire Line
	3650 4250 3650 4600
Connection ~ 3650 4600
Connection ~ 4150 3950
Text HLabel 6400 4450 0    60   Input ~ 0
REN
Text HLabel 8900 4450 2    60   Output ~ 0
OUT
Wire Notes Line
	3050 3400 3050 5100
Wire Notes Line
	3050 5100 2250 5100
Wire Notes Line
	2250 5100 2250 3400
Wire Notes Line
	2250 3400 3050 3400
$Comp
L Q_NPN_BCE Q1
U 1 1 555959A5
P 7100 4450
F 0 "Q1" H 7400 4500 50  0000 R CNN
F 1 "Q_NPN_BCE" H 7700 4400 50  0000 R CNN
F 2 "" H 7300 4550 29  0000 C CNN
F 3 "" H 7100 4450 60  0000 C CNN
	1    7100 4450
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 555959E7
P 6700 4450
F 0 "R13" V 6780 4450 50  0000 C CNN
F 1 "2k" V 6700 4450 50  0000 C CNN
F 2 "" V 6630 4450 30  0000 C CNN
F 3 "" H 6700 4450 30  0000 C CNN
	1    6700 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 4450 6550 4450
Wire Wire Line
	6850 4450 6900 4450
Text HLabel 7200 4900 3    60   Output ~ 0
GND
Wire Wire Line
	7200 4900 7200 4650
$Comp
L R R14
U 1 1 55595C6D
P 7200 3500
F 0 "R14" V 7280 3500 50  0000 C CNN
F 1 "100k" V 7200 3500 50  0000 C CNN
F 2 "" V 7130 3500 30  0000 C CNN
F 3 "" H 7200 3500 30  0000 C CNN
	1    7200 3500
	1    0    0    -1  
$EndComp
$Comp
L R 47k1
U 1 1 55595CB2
P 8550 4200
F 0 "47k1" V 8630 4200 50  0000 C CNN
F 1 "R" V 8550 4200 50  0000 C CNN
F 2 "" V 8480 4200 30  0000 C CNN
F 3 "" H 8550 4200 30  0000 C CNN
	1    8550 4200
	1    0    0    -1  
$EndComp
$Comp
L R 15k1
U 1 1 55595CEE
P 8550 4700
F 0 "15k1" V 8630 4700 50  0000 C CNN
F 1 "R" V 8550 4700 50  0000 C CNN
F 2 "" V 8480 4700 30  0000 C CNN
F 3 "" H 8550 4700 30  0000 C CNN
	1    8550 4700
	1    0    0    -1  
$EndComp
Text HLabel 8550 4900 3    60   Output ~ 0
GND
Wire Wire Line
	8550 4900 8550 4850
Wire Wire Line
	8550 4550 8550 4350
$Comp
L Q_PMOS_DSG Q2
U 1 1 55595F08
P 8450 3750
F 0 "Q2" H 8750 3800 50  0000 R CNN
F 1 "Q_PMOS_DSG" H 9100 3700 50  0000 R CNN
F 2 "" H 8650 3850 29  0000 C CNN
F 3 "" H 8450 3750 60  0000 C CNN
	1    8450 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3950 8550 4050
Wire Wire Line
	8250 3750 7200 3750
Wire Wire Line
	7200 3650 7200 4250
$Comp
L C C12
U 1 1 55595FB4
P 7900 3500
F 0 "C12" H 7925 3600 50  0000 L CNN
F 1 "100pF" H 7925 3400 50  0000 L CNN
F 2 "" H 7938 3350 30  0000 C CNN
F 3 "" H 7900 3500 60  0000 C CNN
	1    7900 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3650 7900 3750
Connection ~ 7900 3750
Connection ~ 7200 3750
Wire Wire Line
	7200 3350 7200 3250
Wire Wire Line
	7200 3250 8550 3250
Wire Wire Line
	7900 3250 7900 3350
Wire Wire Line
	8550 3050 8550 3550
Connection ~ 7900 3250
Wire Wire Line
	8550 4450 8900 4450
Connection ~ 8550 4450
Text HLabel 8550 3050 1    60   Output ~ 0
12V
Connection ~ 8550 3250
$EndSCHEMATC
