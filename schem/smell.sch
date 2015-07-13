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
Sheet 7 11
Title "Filtered Light Sensors"
Date "Wednesday, April 29, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L TSL235 U12
U 1 1 55492289
P 5950 2650
F 0 "U12" H 6100 2950 60  0000 C CNN
F 1 "TSL235" H 6150 2350 60  0000 C CNN
F 2 "" H 6000 2650 60  0000 C CNN
F 3 "" H 6000 2650 60  0000 C CNN
	1    5950 2650
	1    0    0    -1  
$EndComp
$Comp
L TSL235 U11
U 1 1 5549231B
P 4750 2650
F 0 "U11" H 4900 2950 60  0000 C CNN
F 1 "TSL235" H 4950 2350 60  0000 C CNN
F 2 "" H 4800 2650 60  0000 C CNN
F 3 "" H 4800 2650 60  0000 C CNN
	1    4750 2650
	1    0    0    -1  
$EndComp
$Comp
L TSL235 U10
U 1 1 554923A3
P 3550 2650
F 0 "U10" H 3700 2950 60  0000 C CNN
F 1 "TSL235" H 3750 2350 60  0000 C CNN
F 2 "" H 3600 2650 60  0000 C CNN
F 3 "" H 3600 2650 60  0000 C CNN
	1    3550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3100 3550 3650
Wire Wire Line
	3550 3350 5950 3350
Wire Wire Line
	5950 3350 5950 3100
Wire Wire Line
	4750 3100 4750 3350
Connection ~ 4750 3350
Text HLabel 3550 3650 3    60   UnSpc ~ 0
GND
Wire Wire Line
	3550 1600 3550 2200
Wire Wire Line
	3550 1950 5950 1950
Wire Wire Line
	5950 1950 5950 2200
Wire Wire Line
	4750 2200 4750 1950
Connection ~ 4750 1950
Text HLabel 3550 1600 1    60   UnSpc ~ 0
VDD
Connection ~ 3550 1950
Connection ~ 3550 3350
Text HLabel 2900 2650 0    60   Output ~ 0
ROUT
Text HLabel 4150 2650 0    60   Output ~ 0
GOUT
Text HLabel 5350 2650 0    60   Output ~ 0
BOUT
Wire Wire Line
	2900 2650 3150 2650
Wire Wire Line
	4150 2650 4350 2650
Wire Wire Line
	5350 2650 5550 2650
Wire Notes Line
	3050 1800 6400 1800
Wire Notes Line
	6400 1800 6400 3500
Wire Notes Line
	6400 3500 3050 3500
Wire Notes Line
	3050 3500 3050 1800
$EndSCHEMATC
