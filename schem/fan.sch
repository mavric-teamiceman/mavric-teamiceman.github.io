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
Sheet 11 11
Title "Fan"
Date "Thursday, April 30, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
Text HLabel 4100 4250 0    60   Input ~ 0
IN
Text HLabel 5100 4950 3    60   UnSpc ~ 0
GND
Text HLabel 5100 3700 1    60   UnSpc ~ 0
VIN
$Comp
L TIP120 Q3
U 1 1 5556EC24
P 5000 4250
F 0 "Q3" H 5250 4325 50  0000 L CNN
F 1 "TIP120" H 5250 4250 50  0000 L CNN
F 2 "TO-220" H 5250 4175 50  0000 L CIN
F 3 "" H 5000 4250 50  0000 L CNN
	1    5000 4250
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5556EC56
P 4500 4250
F 0 "R19" V 4580 4250 50  0000 C CNN
F 1 "1k" V 4500 4250 50  0000 C CNN
F 2 "" V 4430 4250 30  0000 C CNN
F 3 "" H 4500 4250 30  0000 C CNN
	1    4500 4250
	0    1    1    0   
$EndComp
$Comp
L Motor M3
U 1 1 5556ECDD
P 6550 4250
F 0 "M3" H 6550 4250 60  0000 C CNN
F 1 "Motor" H 6550 4250 60  0001 C CNN
F 2 "" H 6550 4250 60  0000 C CNN
F 3 "" H 6550 4250 60  0000 C CNN
	1    6550 4250
	1    0    0    -1  
$EndComp
$Comp
L C C18
U 1 1 5556ED4B
P 6200 4250
F 0 "C18" H 6225 4350 50  0000 L CNN
F 1 "1uF" H 6225 4150 50  0000 L CNN
F 2 "" H 6238 4100 30  0000 C CNN
F 3 "" H 6200 4250 60  0000 C CNN
	1    6200 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4600 6550 4600
Wire Wire Line
	6200 4400 6200 4600
Wire Wire Line
	5100 3900 6550 3900
Wire Wire Line
	6200 4100 6200 3900
Wire Wire Line
	5100 4450 5100 4950
Wire Wire Line
	5100 3700 5100 4050
Wire Wire Line
	4650 4250 4800 4250
Wire Wire Line
	4350 4250 4100 4250
Connection ~ 5100 3900
Connection ~ 6200 3900
$Comp
L D D1
U 1 1 5556EDF8
P 5750 4250
F 0 "D1" H 5750 4350 50  0000 C CNN
F 1 "D" H 5750 4150 50  0000 C CNN
F 2 "" H 5750 4250 60  0000 C CNN
F 3 "" H 5750 4250 60  0000 C CNN
	1    5750 4250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 4100 5750 3900
Connection ~ 5750 3900
Wire Wire Line
	5750 4400 5750 4600
Connection ~ 5100 4600
Connection ~ 6200 4600
Connection ~ 5750 4600
Wire Notes Line
	6350 3800 6350 4650
Wire Notes Line
	6350 4650 6750 4650
Wire Notes Line
	6750 4650 6750 3800
Wire Notes Line
	6750 3800 6350 3800
$EndSCHEMATC
