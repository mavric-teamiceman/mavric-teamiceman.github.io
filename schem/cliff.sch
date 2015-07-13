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
$Descr A4 11693 8268
encoding utf-8
Sheet 10 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATTINY85-P IC1
U 1 1 554AEFCD
P 5650 3750
F 0 "IC1" H 4500 4150 40  0000 C CNN
F 1 "ATTINY85-P" H 6650 3350 40  0000 C CNN
F 2 "DIP8" H 6650 3750 35  0000 C CIN
F 3 "" H 5650 3750 60  0000 C CNN
	1    5650 3750
	1    0    0    -1  
$EndComp
$Comp
L HC-SR04 U14
U 1 1 554AF10C
P 3300 2550
F 0 "U14" H 3550 2800 60  0000 R CNN
F 1 "HC-SR04" H 3300 2700 60  0000 C CNN
F 2 "" H 3300 2550 60  0000 C CNN
F 3 "" H 3300 2550 60  0000 C CNN
	1    3300 2550
	1    0    0    -1  
$EndComp
Text HLabel 7100 3100 1    60   UnSpc ~ 0
VCC
Wire Wire Line
	7100 3100 7100 3600
Wire Wire Line
	7100 3500 7000 3500
Text HLabel 7100 4300 3    60   UnSpc ~ 0
GND
Wire Wire Line
	7100 3900 7100 4300
Wire Wire Line
	7100 4000 7000 4000
Text HLabel 3450 3050 3    60   UnSpc ~ 0
GND
Text HLabel 3150 3050 3    60   UnSpc ~ 0
VCC
Wire Wire Line
	3150 3050 3150 2900
Wire Wire Line
	3450 3050 3450 2900
$Comp
L R R18
U 1 1 554AF239
P 4050 4000
F 0 "R18" V 4130 4000 50  0000 C CNN
F 1 "4.7k" V 4050 4000 50  0000 C CNN
F 2 "" V 3980 4000 30  0000 C CNN
F 3 "" H 4050 4000 30  0000 C CNN
	1    4050 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 4000 4300 4000
Text HLabel 3750 4000 0    60   UnSpc ~ 0
VCC
Wire Wire Line
	3750 4000 3900 4000
Text HLabel 4150 3500 0    60   Output ~ 0
OUT
Wire Wire Line
	4150 3500 4300 3500
Wire Wire Line
	4300 3600 3250 3600
Wire Wire Line
	3250 3600 3250 2900
Wire Wire Line
	4300 3700 3350 3700
Wire Wire Line
	3350 3700 3350 2900
$Comp
L C C17
U 1 1 554AF2EF
P 7100 3750
F 0 "C17" H 7125 3850 50  0000 L CNN
F 1 ".1uF" H 7125 3650 50  0000 L CNN
F 2 "" H 7138 3600 30  0000 C CNN
F 3 "" H 7100 3750 60  0000 C CNN
	1    7100 3750
	1    0    0    -1  
$EndComp
Connection ~ 7100 3500
Connection ~ 7100 4000
Wire Notes Line
	3700 3200 7350 3200
Wire Notes Line
	3700 3200 3700 2100
Wire Notes Line
	3700 2100 2850 2100
Wire Notes Line
	2850 2100 2850 4250
Wire Notes Line
	2850 4250 7350 4250
Wire Notes Line
	7350 4250 7350 3200
$EndSCHEMATC
