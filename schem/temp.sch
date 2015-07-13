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
Sheet 9 11
Title "Temperature"
Date "Wednesday, April 29, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L THERMISTOR TH1
U 1 1 554A6812
P 4250 3700
F 0 "TH1" V 4350 3750 50  0000 C CNN
F 1 "THERMISTOR" V 4150 3700 50  0000 C BNN
F 2 "" H 4250 3700 60  0000 C CNN
F 3 "" H 4250 3700 60  0000 C CNN
	1    4250 3700
	1    0    0    -1  
$EndComp
$Comp
L THERMISTOR TH2
U 1 1 554A68A2
P 5650 3700
F 0 "TH2" V 5750 3750 50  0000 C CNN
F 1 "THERMISTOR" V 5550 3700 50  0000 C BNN
F 2 "" H 5650 3700 60  0000 C CNN
F 3 "" H 5650 3700 60  0000 C CNN
	1    5650 3700
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 554A68EE
P 4250 2950
F 0 "R16" V 4330 2950 50  0000 C CNN
F 1 "R" V 4250 2950 50  0000 C CNN
F 2 "" V 4180 2950 30  0000 C CNN
F 3 "" H 4250 2950 30  0000 C CNN
	1    4250 2950
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 554A693F
P 5650 3000
F 0 "R17" V 5730 3000 50  0000 C CNN
F 1 "R" V 5650 3000 50  0000 C CNN
F 2 "" V 5580 3000 30  0000 C CNN
F 3 "" H 5650 3000 30  0000 C CNN
	1    5650 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3100 4250 3450
Wire Wire Line
	5650 3150 5650 3450
Wire Wire Line
	4250 2800 4250 2550
Wire Wire Line
	4250 2550 5650 2550
Wire Wire Line
	5650 2550 5650 2850
Wire Wire Line
	5650 3950 5650 4200
Wire Wire Line
	5650 4200 4250 4200
Wire Wire Line
	4250 4200 4250 3950
Text HLabel 4900 2200 1    60   UnSpc ~ 0
VIN
Text HLabel 4950 4500 3    60   UnSpc ~ 0
GND
Wire Wire Line
	4950 4500 4950 4200
Connection ~ 4950 4200
Wire Wire Line
	4900 2200 4900 2550
Connection ~ 4900 2550
Text HLabel 4550 3300 2    60   Output ~ 0
OUT1
Text HLabel 5950 3300 2    60   Output ~ 0
OUT2
Wire Wire Line
	5950 3300 5650 3300
Connection ~ 5650 3300
Wire Wire Line
	4550 3300 4250 3300
Connection ~ 4250 3300
Wire Notes Line
	3900 3400 3900 4050
Wire Notes Line
	3900 4050 5850 4050
Wire Notes Line
	5850 4050 5850 3400
Wire Notes Line
	5850 3400 3900 3400
$EndSCHEMATC
