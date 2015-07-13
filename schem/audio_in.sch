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
Sheet 3 11
Title "Audio Input"
Date "Wednesday, April 29, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L MSGEQ7 U4
U 1 1 5547C366
P 2900 4300
F 0 "U4" H 3100 4600 50  0000 C CNN
F 1 "MSGEQ7" H 2900 4300 50  0000 C CNN
F 2 "" V 2830 4300 30  0000 C CNN
F 3 "" H 3000 4300 30  0000 C CNN
	1    2900 4300
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5547C46E
P 1750 4150
F 0 "R1" V 1830 4150 50  0000 C CNN
F 1 "22k" V 1750 4150 50  0000 C CNN
F 2 "" V 1680 4150 30  0000 C CNN
F 3 "" H 1750 4150 30  0000 C CNN
	1    1750 4150
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 5547C4B3
P 2150 4150
F 0 "C2" H 2175 4250 50  0000 L CNN
F 1 "C" H 2175 4050 50  0000 L CNN
F 2 "" H 2188 4000 30  0000 C CNN
F 3 "" H 2150 4150 60  0000 C CNN
	1    2150 4150
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 5547C4F4
P 3350 5100
F 0 "C4" H 3375 5200 50  0000 L CNN
F 1 "33pF" H 3375 5000 50  0000 L CNN
F 2 "" H 3388 4950 30  0000 C CNN
F 3 "" H 3350 5100 60  0000 C CNN
	1    3350 5100
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5547C532
P 3000 5100
F 0 "R2" V 3080 5100 50  0000 C CNN
F 1 "220k" V 3000 5100 50  0000 C CNN
F 2 "" V 2930 5100 30  0000 C CNN
F 3 "" H 3000 5100 30  0000 C CNN
	1    3000 5100
	-1   0    0    1   
$EndComp
$Comp
L C C5
U 1 1 5547C588
P 3550 4650
F 0 "C5" H 3575 4750 50  0000 L CNN
F 1 ".1uF" H 3575 4550 50  0000 L CNN
F 2 "" H 3588 4500 30  0000 C CNN
F 3 "" H 3550 4650 60  0000 C CNN
	1    3550 4650
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5547C5E9
P 3350 3700
F 0 "C3" H 3375 3800 50  0000 L CNN
F 1 ".1uF" H 3375 3600 50  0000 L CNN
F 2 "" H 3388 3550 30  0000 C CNN
F 3 "" H 3350 3700 60  0000 C CNN
	1    3350 3700
	-1   0    0    1   
$EndComp
Text HLabel 3450 3950 2    60   UnSpc ~ 0
GND
Text HLabel 3700 5400 2    60   UnSpc ~ 0
GND
Text HLabel 2900 3050 1    60   UnSpc ~ 0
VDD
Text HLabel 2900 5400 0    60   UnSpc ~ 0
VDD
Text HLabel 1500 4300 0    60   Input ~ 0
LSTROBE
Text HLabel 1500 4450 0    60   Input ~ 0
LRESET
Text HLabel 2700 4950 0    60   UnSpc ~ 0
GND
$Comp
L MSGEQ7 U6
U 1 1 5547F99A
P 7500 4300
F 0 "U6" H 7700 4600 50  0000 C CNN
F 1 "MSGEQ7" H 7500 4300 50  0000 C CNN
F 2 "" V 7430 4300 30  0000 C CNN
F 3 "" H 7600 4300 30  0000 C CNN
	1    7500 4300
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5547FA87
P 7950 3700
F 0 "C7" H 7975 3800 50  0000 L CNN
F 1 ".1uF" H 7975 3600 50  0000 L CNN
F 2 "" H 7988 3550 30  0000 C CNN
F 3 "" H 7950 3700 60  0000 C CNN
	1    7950 3700
	-1   0    0    1   
$EndComp
Text HLabel 7500 3100 1    60   UnSpc ~ 0
VDD
Text HLabel 8050 3950 2    60   UnSpc ~ 0
GND
$Comp
L R R4
U 1 1 5547FE1A
P 7600 5100
F 0 "R4" V 7680 5100 50  0000 C CNN
F 1 "200k" V 7600 5100 50  0000 C CNN
F 2 "" V 7530 5100 30  0000 C CNN
F 3 "" H 7600 5100 30  0000 C CNN
	1    7600 5100
	-1   0    0    1   
$EndComp
$Comp
L C C8
U 1 1 5547FEC0
P 8050 5100
F 0 "C8" H 8075 5200 50  0000 L CNN
F 1 "33pF" H 8075 5000 50  0000 L CNN
F 2 "" H 8088 4950 30  0000 C CNN
F 3 "" H 8050 5100 60  0000 C CNN
	1    8050 5100
	-1   0    0    1   
$EndComp
$Comp
L C C9
U 1 1 5548015D
P 8250 4650
F 0 "C9" H 8275 4750 50  0000 L CNN
F 1 ".1uF" H 8275 4550 50  0000 L CNN
F 2 "" H 8288 4500 30  0000 C CNN
F 3 "" H 8250 4650 60  0000 C CNN
	1    8250 4650
	1    0    0    -1  
$EndComp
Text HLabel 8450 5400 2    60   UnSpc ~ 0
GND
Text HLabel 7450 5400 0    60   UnSpc ~ 0
VDD
Text HLabel 7250 4900 0    60   UnSpc ~ 0
GND
$Comp
L C C6
U 1 1 5548033A
P 6750 4150
F 0 "C6" H 6775 4250 50  0000 L CNN
F 1 "C" H 6775 4050 50  0000 L CNN
F 2 "" H 6788 4000 30  0000 C CNN
F 3 "" H 6750 4150 60  0000 C CNN
	1    6750 4150
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5548039A
P 6350 4150
F 0 "R3" V 6430 4150 50  0000 C CNN
F 1 "22k" V 6350 4150 50  0000 C CNN
F 2 "" V 6280 4150 30  0000 C CNN
F 3 "" H 6350 4150 30  0000 C CNN
	1    6350 4150
	0    1    1    0   
$EndComp
Text HLabel 6050 4300 0    60   Input ~ 0
RSTROBE
Text HLabel 6050 4450 0    60   Input ~ 0
RRESET
Text HLabel 8200 4200 2    60   Output ~ 0
ROUT
$Comp
L MAX4466 U3
U 1 1 55482F5C
P 2000 3650
F 0 "U3" H 2000 3900 60  0000 C CNN
F 1 "MAX4466" H 2000 3400 60  0000 C CNN
F 2 "" H 2000 3650 60  0000 C CNN
F 3 "" H 2000 3650 60  0000 C CNN
	1    2000 3650
	1    0    0    -1  
$EndComp
$Comp
L MAX4466 U5
U 1 1 55482FD7
P 6600 3650
F 0 "U5" H 6600 3900 60  0000 C CNN
F 1 "MAX4466" H 6600 3400 60  0000 C CNN
F 2 "" H 6600 3650 60  0000 C CNN
F 3 "" H 6600 3650 60  0000 C CNN
	1    6600 3650
	1    0    0    -1  
$EndComp
Text HLabel 3500 4200 2    60   Output ~ 0
LOUT
Text HLabel 1450 3650 0    60   UnSpc ~ 0
GND
Text HLabel 6050 3650 0    60   UnSpc ~ 0
GND
Wire Wire Line
	2300 4150 2400 4150
Wire Wire Line
	2000 4150 1900 4150
Wire Wire Line
	3400 4400 3550 4400
Wire Wire Line
	3550 4400 3550 4500
Wire Wire Line
	3350 3850 3350 3950
Wire Wire Line
	3350 3950 3450 3950
Wire Wire Line
	3000 4800 3000 4950
Wire Wire Line
	3550 4800 3550 5400
Wire Wire Line
	3350 5400 3700 5400
Wire Wire Line
	3350 5250 3350 5400
Connection ~ 3550 5400
Wire Wire Line
	2900 5400 3000 5400
Wire Wire Line
	3000 5400 3000 5250
Wire Wire Line
	1500 4300 2400 4300
Wire Wire Line
	1500 4450 2400 4450
Wire Wire Line
	2700 4950 2800 4950
Wire Wire Line
	2800 4950 2800 4800
Wire Wire Line
	8050 3950 7950 3950
Wire Wire Line
	7950 3950 7950 3850
Wire Wire Line
	7600 4950 7600 4800
Wire Wire Line
	7600 4850 8050 4850
Wire Wire Line
	8050 4850 8050 4950
Connection ~ 7600 4850
Wire Wire Line
	3000 4850 3350 4850
Wire Wire Line
	3350 4850 3350 4950
Connection ~ 3000 4850
Wire Wire Line
	8250 4500 8250 4400
Wire Wire Line
	8250 4400 8000 4400
Wire Wire Line
	8050 5250 8050 5400
Wire Wire Line
	8050 5400 8450 5400
Wire Wire Line
	8250 4800 8250 5400
Connection ~ 8250 5400
Wire Wire Line
	7450 5400 7600 5400
Wire Wire Line
	7600 5400 7600 5250
Wire Wire Line
	7250 4900 7400 4900
Wire Wire Line
	7400 4900 7400 4800
Wire Wire Line
	6900 4150 7000 4150
Wire Wire Line
	6500 4150 6600 4150
Wire Wire Line
	6050 4300 7000 4300
Wire Wire Line
	6050 4450 7000 4450
Wire Wire Line
	8200 4200 8000 4200
Wire Wire Line
	3500 4200 3400 4200
Wire Wire Line
	6200 3750 6100 3750
Wire Wire Line
	6100 3750 6100 4150
Wire Wire Line
	6100 4150 6200 4150
Wire Wire Line
	1600 3750 1500 3750
Wire Wire Line
	1500 3750 1500 4150
Wire Wire Line
	1500 4150 1600 4150
Wire Wire Line
	2900 3800 2900 3050
Wire Wire Line
	3350 3550 2900 3550
Connection ~ 2900 3550
Wire Wire Line
	1600 3550 1600 3300
Wire Wire Line
	1600 3300 2900 3300
Connection ~ 2900 3300
Wire Wire Line
	7500 3100 7500 3800
Wire Wire Line
	7950 3550 7950 3450
Wire Wire Line
	7950 3450 7500 3450
Connection ~ 7500 3450
Wire Wire Line
	6200 3550 6200 3300
Wire Wire Line
	6200 3300 7500 3300
Connection ~ 7500 3300
Wire Wire Line
	6050 3650 6200 3650
Wire Wire Line
	1450 3650 1600 3650
Wire Notes Line
	2400 3950 1100 3950
Wire Notes Line
	1100 3950 1100 3150
Wire Notes Line
	1100 3150 2400 3150
Wire Notes Line
	2400 3150 2400 3950
Wire Notes Line
	7000 4000 5750 4000
Wire Notes Line
	5750 4000 5750 3200
Wire Notes Line
	5750 3200 7000 3200
Wire Notes Line
	7000 3200 7000 4000
$EndSCHEMATC
