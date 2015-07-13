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
Sheet 8 11
Title "Audio Amplifier"
Date "Thursday, April 30, 2015"
Rev "1"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
Text HLabel 5600 3050 1    60   UnSpc ~ 0
VCC
Text HLabel 5000 4050 3    60   UnSpc ~ 0
GND
Text HLabel 4100 3400 0    60   Input ~ 0
IN
$Comp
L LM386 U13
U 1 1 554C48B8
P 5700 3750
F 0 "U13" H 5850 3950 60  0000 C CNN
F 1 "LM386" H 5850 4050 60  0000 C CNN
F 2 "" H 5700 3750 60  0000 C CNN
F 3 "" H 5700 3750 60  0000 C CNN
	1    5700 3750
	1    0    0    -1  
$EndComp
Text HLabel 5600 4650 3    60   UnSpc ~ 0
GND
$Comp
L C C14
U 1 1 554C48FB
P 5850 4350
F 0 "C14" V 5700 4350 50  0000 L CNN
F 1 "10uF" V 6000 4250 50  0000 L CNN
F 2 "" H 5888 4200 30  0000 C CNN
F 3 "" H 5850 4350 60  0000 C CNN
	1    5850 4350
	0    1    -1   0   
$EndComp
$Comp
L C C15
U 1 1 554C4954
P 6300 4000
F 0 "C15" H 6325 4100 50  0000 L CNN
F 1 "0.05uF" H 6400 4000 50  0000 L CNN
F 2 "" H 6338 3850 30  0000 C CNN
F 3 "" H 6300 4000 60  0000 C CNN
	1    6300 4000
	1    0    0    1   
$EndComp
$Comp
L R R15
U 1 1 554C4977
P 6300 4400
F 0 "R15" V 6380 4400 50  0000 C CNN
F 1 "10" V 6300 4400 50  0000 C CNN
F 2 "" V 6230 4400 30  0000 C CNN
F 3 "" H 6300 4400 30  0000 C CNN
	1    6300 4400
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 554C49A8
P 6550 3750
F 0 "C16" V 6450 3800 50  0000 L CNN
F 1 "250uF" V 6700 3650 50  0000 L CNN
F 2 "" H 6588 3600 30  0000 C CNN
F 3 "" H 6550 3750 60  0000 C CNN
	1    6550 3750
	0    1    -1   0   
$EndComp
Text HLabel 6300 4650 3    60   UnSpc ~ 0
GND
$Comp
L SPEAKER SP1
U 1 1 554C4A16
P 7100 3850
F 0 "SP1" H 7000 4100 50  0000 C CNN
F 1 "SPEAKER" H 7000 3600 50  0000 C CNN
F 2 "" H 7100 3850 60  0000 C CNN
F 3 "" H 7100 3850 60  0000 C CNN
	1    7100 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4650 6300 4550
Wire Wire Line
	6800 3750 6700 3750
Wire Wire Line
	6300 4150 6300 4250
Connection ~ 6350 3750
Wire Wire Line
	6300 3750 6350 3750
Wire Wire Line
	6300 3850 6300 3750
Wire Wire Line
	6200 3750 6400 3750
Wire Wire Line
	6000 4150 6000 4350
Wire Wire Line
	5800 4150 6000 4150
Wire Wire Line
	5700 4350 5700 4150
Wire Wire Line
	5600 4650 5600 4150
Text HLabel 6800 4650 3    60   UnSpc ~ 0
GND
Wire Wire Line
	6800 4650 6800 3950
Wire Wire Line
	5600 3050 5600 3350
Wire Wire Line
	5000 3850 5200 3850
Wire Wire Line
	5000 4050 5000 3850
$Comp
L POT RV1
U 1 1 554C4D5D
P 4750 3650
F 0 "RV1" H 4750 3550 50  0000 C CNN
F 1 "10k" H 4750 3650 50  0000 C CNN
F 2 "" H 4750 3650 60  0000 C CNN
F 3 "" H 4750 3650 60  0000 C CNN
	1    4750 3650
	0    1    1    0   
$EndComp
Text HLabel 4750 4050 3    60   UnSpc ~ 0
GND
Wire Wire Line
	5200 3650 4900 3650
$Comp
L C C13
U 1 1 554C4E63
P 4400 3400
F 0 "C13" H 4425 3500 50  0000 L CNN
F 1 "10uF" H 4425 3300 50  0000 L CNN
F 2 "" H 4438 3250 30  0000 C CNN
F 3 "" H 4400 3400 60  0000 C CNN
	1    4400 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4250 3400 4100 3400
Wire Wire Line
	4550 3400 4750 3400
Wire Wire Line
	4750 3900 4750 4050
$EndSCHEMATC
