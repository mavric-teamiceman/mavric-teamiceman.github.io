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
Sheet 5 11
Title "Bumpers"
Date "Wednesday, April 29, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L RVAR R6
U 1 1 5548CB62
P 3850 4600
F 0 "R6" V 3930 4550 50  0000 C CNN
F 1 "RVAR" V 3770 4660 50  0000 C CNN
F 2 "" H 3850 4600 60  0000 C CNN
F 3 "" H 3850 4600 60  0000 C CNN
	1    3850 4600
	1    0    0    -1  
$EndComp
$Comp
L RVAR R8
U 1 1 5548CB9D
P 4450 4600
F 0 "R8" V 4530 4550 50  0000 C CNN
F 1 "RVAR" V 4370 4660 50  0000 C CNN
F 2 "" H 4450 4600 60  0000 C CNN
F 3 "" H 4450 4600 60  0000 C CNN
	1    4450 4600
	1    0    0    -1  
$EndComp
$Comp
L RVAR R10
U 1 1 5548CBED
P 5050 4600
F 0 "R10" V 5130 4550 50  0000 C CNN
F 1 "RVAR" V 4970 4660 50  0000 C CNN
F 2 "" H 5050 4600 60  0000 C CNN
F 3 "" H 5050 4600 60  0000 C CNN
	1    5050 4600
	1    0    0    -1  
$EndComp
$Comp
L RVAR R12
U 1 1 5548CC20
P 5650 4600
F 0 "R12" V 5730 4550 50  0000 C CNN
F 1 "RVAR" V 5570 4660 50  0000 C CNN
F 2 "" H 5650 4600 60  0000 C CNN
F 3 "" H 5650 4600 60  0000 C CNN
	1    5650 4600
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5548CC59
P 3850 4000
F 0 "R5" V 3930 4000 50  0000 C CNN
F 1 "22k" V 3850 4000 50  0000 C CNN
F 2 "" V 3780 4000 30  0000 C CNN
F 3 "" H 3850 4000 30  0000 C CNN
	1    3850 4000
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5548CCA9
P 4450 4000
F 0 "R7" V 4530 4000 50  0000 C CNN
F 1 "22k" V 4450 4000 50  0000 C CNN
F 2 "" V 4380 4000 30  0000 C CNN
F 3 "" H 4450 4000 30  0000 C CNN
	1    4450 4000
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5548CCD5
P 5050 4000
F 0 "R9" V 5130 4000 50  0000 C CNN
F 1 "22k" V 5050 4000 50  0000 C CNN
F 2 "" V 4980 4000 30  0000 C CNN
F 3 "" H 5050 4000 30  0000 C CNN
	1    5050 4000
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5548CD0D
P 5650 4000
F 0 "R11" V 5730 4000 50  0000 C CNN
F 1 "22k" V 5650 4000 50  0000 C CNN
F 2 "" V 5580 4000 30  0000 C CNN
F 3 "" H 5650 4000 30  0000 C CNN
	1    5650 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3850 3850 3600
Wire Wire Line
	3850 3600 5650 3600
Wire Wire Line
	5650 3600 5650 3850
Wire Wire Line
	5050 3850 5050 3600
Connection ~ 5050 3600
Wire Wire Line
	4450 3850 4450 3600
Connection ~ 4450 3600
Wire Wire Line
	3850 4150 3850 4350
Wire Wire Line
	4450 4150 4450 4350
Wire Wire Line
	5050 4150 5050 4350
Wire Wire Line
	5650 4150 5650 4350
Wire Wire Line
	3850 4850 3850 5100
Wire Wire Line
	3850 5100 5650 5100
Wire Wire Line
	5650 5100 5650 4850
Wire Wire Line
	5050 4850 5050 5100
Connection ~ 5050 5100
Wire Wire Line
	4450 4850 4450 5100
Connection ~ 4450 5100
Text HLabel 4750 5450 3    60   UnSpc ~ 0
GND
Wire Wire Line
	4750 5450 4750 5100
Connection ~ 4750 5100
Text HLabel 4750 3250 1    60   UnSpc ~ 0
VIN
Wire Wire Line
	4750 3250 4750 3600
Connection ~ 4750 3600
Text HLabel 3950 4250 2    60   Output ~ 0
OUT1
Text HLabel 4550 4250 2    60   Output ~ 0
OUT2
Text HLabel 5150 4250 2    60   Output ~ 0
OUT3
Text HLabel 5750 4250 2    60   Output ~ 0
OUT4
Wire Wire Line
	3950 4250 3850 4250
Connection ~ 3850 4250
Wire Wire Line
	4550 4250 4450 4250
Connection ~ 4450 4250
Wire Wire Line
	5150 4250 5050 4250
Connection ~ 5050 4250
Wire Wire Line
	5750 4250 5650 4250
Connection ~ 5650 4250
Wire Notes Line
	3600 4300 5900 4300
Wire Notes Line
	5900 4300 5900 4900
Wire Notes Line
	5900 4900 3600 4900
Wire Notes Line
	3600 4900 3600 4300
$EndSCHEMATC
