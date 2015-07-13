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
Sheet 4 11
Title "Motor Assembly"
Date "Wednesday, April 29, 2015"
Rev "1"
Comp "University of Washington"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Comp
L VNH5019 U7
U 1 1 5549E1D2
P 3950 3950
F 0 "U7" H 4450 4450 60  0000 R CNN
F 1 "VNH5019" H 3950 3950 60  0000 C CNN
F 2 "" H 3950 3950 60  0000 C CNN
F 3 "" H 3950 3950 60  0000 C CNN
	1    3950 3950
	1    0    0    -1  
$EndComp
$Comp
L VNH5019 U8
U 1 1 5549E223
P 7150 3950
F 0 "U8" H 7650 4450 60  0000 R CNN
F 1 "VNH5019" H 7150 3950 60  0000 C CNN
F 2 "" H 7150 3950 60  0000 C CNN
F 3 "" H 7150 3950 60  0000 C CNN
	1    7150 3950
	1    0    0    -1  
$EndComp
$Comp
L Motor M1
U 1 1 5549E459
P 5200 3950
F 0 "M1" H 5200 3950 60  0000 C CNN
F 1 "Motor" H 5200 3950 60  0001 C CNN
F 2 "" H 5200 3950 60  0000 C CNN
F 3 "" H 5200 3950 60  0000 C CNN
	1    5200 3950
	1    0    0    -1  
$EndComp
$Comp
L Motor M2
U 1 1 5549E4A2
P 8200 3950
F 0 "M2" H 8200 3950 60  0000 C CNN
F 1 "Motor" H 8200 3950 60  0001 C CNN
F 2 "" H 8200 3950 60  0000 C CNN
F 3 "" H 8200 3950 60  0000 C CNN
	1    8200 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3800 4650 3600
Wire Wire Line
	4650 3600 5200 3600
Wire Wire Line
	4650 4100 4650 4300
Wire Wire Line
	4650 4300 5200 4300
Wire Wire Line
	7850 3800 7850 3600
Wire Wire Line
	7850 3600 8200 3600
Wire Wire Line
	7850 4100 7850 4300
Wire Wire Line
	7850 4300 8200 4300
Text HLabel 3750 3200 1    60   Input ~ 0
VDD
Text HLabel 4150 3200 1    60   Input ~ 0
VIN
Text HLabel 2850 3600 0    60   Input ~ 0
LENA
Text HLabel 2850 3700 0    60   Input ~ 0
LENB
Text HLabel 2850 3850 0    60   Input ~ 0
LINA
Text HLabel 2850 3950 0    60   Input ~ 0
LINB
Text HLabel 2850 4100 0    60   Input ~ 0
LPWM
Text HLabel 6150 3600 0    60   Input ~ 0
RENA
Text HLabel 6150 3700 0    60   Input ~ 0
RENB
Text HLabel 6150 3850 0    60   Input ~ 0
RINA
Text HLabel 6150 3950 0    60   Input ~ 0
RINB
Text HLabel 6150 4100 0    60   Input ~ 0
RPWM
Wire Wire Line
	6150 4100 6450 4100
Wire Wire Line
	6150 3950 6450 3950
Wire Wire Line
	6150 3850 6450 3850
Wire Wire Line
	6150 3700 6450 3700
Wire Wire Line
	6150 3600 6450 3600
Wire Wire Line
	2850 3600 3250 3600
Wire Wire Line
	2850 3700 3250 3700
Wire Wire Line
	2850 3850 3250 3850
Wire Wire Line
	2850 3950 3250 3950
Wire Wire Line
	2850 4100 3250 4100
Wire Notes Line
	3150 2450 3150 5550
Wire Notes Line
	3150 5550 8450 5550
Wire Notes Line
	8450 5550 8450 2450
Wire Notes Line
	8450 2450 3150 2450
NoConn ~ 3950 3200
NoConn ~ 7150 3200
Wire Wire Line
	7150 3200 7150 3300
Wire Wire Line
	3950 3200 3950 3300
NoConn ~ 3200 4250
NoConn ~ 6400 4250
Wire Wire Line
	6400 4250 6450 4250
Wire Wire Line
	3200 4250 3250 4250
Text HLabel 3650 4700 3    60   Input ~ 0
GND
Text HLabel 3850 4700 3    60   Input ~ 0
GND
Text HLabel 4150 4700 3    60   Input ~ 0
GND
Text HLabel 6850 4700 3    60   Input ~ 0
GND
Text HLabel 7050 4700 3    60   Input ~ 0
GND
Text HLabel 7350 4700 3    60   Input ~ 0
GND
Wire Wire Line
	3650 4600 3650 4700
Wire Wire Line
	3850 4700 3850 4600
Wire Wire Line
	4150 4600 4150 4700
Wire Wire Line
	7350 4700 7350 4600
Wire Wire Line
	7050 4600 7050 4700
Wire Wire Line
	6850 4700 6850 4600
Wire Wire Line
	3750 3200 3750 3300
Wire Wire Line
	4150 3200 4150 3300
Text HLabel 6950 3200 1    60   Input ~ 0
VDD
Text HLabel 7350 3200 1    60   Input ~ 0
VIN
Wire Wire Line
	7350 3200 7350 3300
Wire Wire Line
	6950 3200 6950 3300
$EndSCHEMATC
