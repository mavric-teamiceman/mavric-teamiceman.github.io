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
$Descr USLetter 8500 11000 portrait
encoding utf-8
Sheet 1 11
Title "MAVRIC Main Board"
Date "Wednesday, April 29, 2015"
Rev "2"
Comp "University of Washington Tacoma"
Comment1 "Institute of Technology"
Comment2 "Team Iceman"
Comment3 "Chad Condon"
Comment4 ""
$EndDescr
$Sheet
S 2750 700  700  8400
U 55419082
F0 "tiva" 60
F1 "tiva.sch" 60
F2 "3V3" I L 2750 7950 60 
F3 "PE4" O R 3450 4200 60 
F4 "PC4" O R 3450 2250 60 
F5 "PC5" O R 3450 2350 60 
F6 "PC6" O R 3450 2450 60 
F7 "PE5" O R 3450 2050 60 
F8 "PD3" I R 3450 4300 60 
F9 "PC7" O R 3450 4100 60 
F10 "PB2" I R 3450 1450 60 
F11 "PB3" O R 3450 1950 60 
F12 "5V" I L 2750 7850 60 
F13 "GND" I L 2750 8050 60 
F14 "PE0" I R 3450 5450 60 
F15 "PE1" I R 3450 5350 60 
F16 "PE2" I R 3450 5250 60 
F17 "PE3" I R 3450 3950 60 
F18 "PD7" I L 2750 2600 60 
F19 "PA6" I R 3450 8300 60 
F20 "PM4" O R 3450 3750 60 
F21 "PM5" O R 3450 3850 60 
F22 "PD2" I L 2750 2200 60 
F23 "PP0" I L 2750 6750 60 
F24 "PP1" I L 2750 6850 60 
F25 "PD4" I L 2750 2400 60 
F26 "PD5" I L 2750 2500 60 
F27 "PQ0" I L 2750 7350 60 
F28 "PP4" I L 2750 7150 60 
F29 "PN5" I L 2750 6650 60 
F30 "PN4" I L 2750 6550 60 
F31 "PB4" I R 3450 3250 60 
F32 "PB5" O R 3450 3150 60 
F33 "PK0" I R 3450 7600 60 
F34 "PK1" I R 3450 7700 60 
F35 "PK2" I R 3450 7800 60 
F36 "PK3" I R 3450 7900 60 
F37 "PA4" I L 2750 800 60 
F38 "PA5" I L 2750 900 60 
F39 "PF1" O R 3450 6000 60 
F40 "PF2" O R 3450 7050 60 
F41 "PF3" O R 3450 6700 60 
F42 "PG0" I L 2750 3500 60 
F43 "PL4" I L 2750 5350 60 
F44 "PL5" I L 2750 5450 60 
F45 "PL0" O R 3450 6850 60 
F46 "PL1" O R 3450 6950 60 
F47 "PL2" O R 3450 6500 60 
F48 "PL3" O R 3450 6600 60 
F49 "PM3" I L 2750 5750 60 
F50 "PH2" I L 2750 3950 60 
F51 "PH3" I L 2750 4050 60 
F52 "~RESET" I L 2750 7750 60 
F53 "PD1" I R 3450 4800 60 
F54 "PD0" I R 3450 4700 60 
F55 "PN2" I L 2750 6350 60 
F56 "PN3" I L 2750 6450 60 
F57 "PP2" I L 2750 6950 60 
F58 "PG1" O R 3450 8800 60 
F59 "PK4" I L 2750 4550 60 
F60 "PK5" I L 2750 4650 60 
F61 "PM0" I R 3450 1000 60 
F62 "PM1" I R 3450 1100 60 
F63 "PM2" I R 3450 1200 60 
F64 "PH0" I L 2750 3750 60 
F65 "PH1" I L 2750 3850 60 
F66 "PK6" I L 2750 4750 60 
F67 "PK7" I L 2750 4850 60 
F68 "PM7" I L 2750 6250 60 
F69 "PP5" I L 2750 7250 60 
F70 "PA7" I R 3450 1300 60 
F71 "PA3" I R 3450 900 60 
F72 "PA2" I R 3450 800 60 
F73 "PP3" I L 2750 7050 60 
F74 "PQ1" I L 2750 7450 60 
F75 "PM6" I L 2750 5850 60 
$EndSheet
$Sheet
S 4200 3650 850  750 
U 5547C1A1
F0 "audio in" 60
F1 "audio_in.sch" 60
F2 "GND" U R 5050 4300 60 
F3 "VDD" U R 5050 3750 60 
F4 "LSTROBE" I L 4200 3750 60 
F5 "LRESET" I L 4200 3850 60 
F6 "RSTROBE" I L 4200 4100 60 
F7 "RRESET" I L 4200 4200 60 
F8 "ROUT" O L 4200 4300 60 
F9 "LOUT" O L 4200 3950 60 
$EndSheet
$Sheet
S 4200 6400 850  900 
U 5548BDE0
F0 "motors" 60
F1 "motors.sch" 60
F2 "VDD" U R 5050 6500 60 
F3 "VIN" U R 5050 6600 60 
F4 "GND" U R 5050 7200 60 
F5 "LENA" I R 5050 6750 60 
F6 "LENB" I R 5050 6850 60 
F7 "LINA" I L 4200 6500 60 
F8 "LINB" I L 4200 6600 60 
F9 "LPWM" I L 4200 6700 60 
F10 "RENA" I R 5050 6950 60 
F11 "RENB" I R 5050 7050 60 
F12 "RINA" I L 4200 6850 60 
F13 "RINB" I L 4200 6950 60 
F14 "RPWM" I L 4200 7050 60 
$EndSheet
$Sheet
S 4200 7500 800  500 
U 5548CB59
F0 "bumpers" 60
F1 "bumpers.sch" 60
F2 "GND" U R 5000 7900 60 
F3 "VIN" U R 5000 7600 60 
F4 "OUT1" O L 4200 7600 60 
F5 "OUT2" O L 4200 7700 60 
F6 "OUT3" O L 4200 7800 60 
F7 "OUT4" O L 4200 7900 60 
$EndSheet
$Sheet
S 4200 3050 800  400 
U 5548FBBF
F0 "battery" 60
F1 "battery.sch" 60
F2 "GND" U R 5000 3350 60 
F3 "12V" U R 5000 3150 60 
F4 "5V" U R 5000 3250 60 
F5 "REN" I L 4200 3150 60 
F6 "OUT" O L 4200 3250 60 
$EndSheet
$Sheet
S 4250 700  800  400 
U 55492144
F0 "smell" 60
F1 "smell.sch" 60
F2 "GND" U R 5050 1000 60 
F3 "VDD" U R 5050 800 60 
F4 "ROUT" O L 4250 800 60 
F5 "GOUT" O L 4250 900 60 
F6 "BOUT" O L 4250 1000 60 
$EndSheet
$Sheet
S 4200 8700 750  300 
U 554946A4
F0 "audio out" 60
F1 "audio_out.sch" 60
F2 "VCC" U R 4950 8800 60 
F3 "GND" U R 4950 8900 60 
F4 "IN" I L 4200 8800 60 
$EndSheet
$Sheet
S 4250 4600 850  300 
U 554A6809
F0 "temperature" 60
F1 "temp.sch" 60
F2 "VIN" U R 5100 4700 60 
F3 "GND" U R 5100 4800 60 
F4 "OUT1" O L 4250 4700 60 
F5 "OUT2" O L 4250 4800 60 
$EndSheet
$Sheet
S 4200 8200 700  300 
U 554AEFC4
F0 "cliff" 60
F1 "cliff.sch" 60
F2 "VCC" U R 4900 8300 60 
F3 "GND" U R 4900 8400 60 
F4 "OUT" O L 4200 8300 60 
$EndSheet
$Comp
L SONAR U2
U 1 1 554C572B
P 4650 2200
F 0 "U2" H 5000 2600 60  0000 R CNN
F 1 "SONAR" H 4650 2200 60  0000 C CNN
F 2 "" H 6150 2950 60  0000 C CNN
F 3 "" H 6150 2950 60  0000 C CNN
	1    4650 2200
	1    0    0    -1  
$EndComp
$Comp
L ADXL335 U1
U 1 1 554E7FF8
P 4450 5400
F 0 "U1" H 4650 5750 60  0000 R CNN
F 1 "ADXL335" V 4550 5450 60  0000 C CNN
F 2 "" H 4450 5400 60  0000 C CNN
F 3 "" H 4450 5400 60  0000 C CNN
	1    4450 5400
	1    0    0    -1  
$EndComp
$Sheet
S 4200 5900 600  300 
U 554F78E0
F0 "fan" 60
F1 "fan.sch" 60
F2 "IN" I L 4200 6000 60 
F3 "GND" U R 4800 6100 60 
F4 "VIN" U R 4800 6000 60 
$EndSheet
Text GLabel 5300 1000 2    60   UnSpc ~ 0
GND
Text GLabel 4950 2800 2    60   UnSpc ~ 0
GND
Text GLabel 5200 3350 2    60   UnSpc ~ 0
GND
Text GLabel 5250 4300 2    60   UnSpc ~ 0
GND
Text GLabel 5300 4800 2    60   UnSpc ~ 0
GND
Text GLabel 3700 5550 0    60   UnSpc ~ 0
GND
Text GLabel 4900 6100 2    60   UnSpc ~ 0
GND
Text GLabel 5250 7200 2    60   UnSpc ~ 0
GND
Text GLabel 5200 7900 2    60   UnSpc ~ 0
GND
Text GLabel 5200 3150 2    60   UnSpc ~ 0
12V
Text GLabel 5250 6600 2    60   UnSpc ~ 0
12V
Text GLabel 5500 3250 2    60   UnSpc ~ 0
5V
Text GLabel 4900 1600 2    60   UnSpc ~ 0
5V
Text GLabel 5150 6000 2    60   UnSpc ~ 0
5V
Text GLabel 5500 6500 2    60   UnSpc ~ 0
3V3
Text GLabel 5250 3750 2    60   UnSpc ~ 0
3V3
Text GLabel 5300 800  2    60   UnSpc ~ 0
5V
$Comp
L +12V #PWR1
U 1 1 5556004C
P 7100 900
F 0 "#PWR1" H 7100 750 50  0001 C CNN
F 1 "+12V" H 7100 1040 50  0000 C CNN
F 2 "" H 7100 900 60  0000 C CNN
F 3 "" H 7100 900 60  0000 C CNN
	1    7100 900 
	1    0    0    -1  
$EndComp
Text GLabel 7100 1100 3    60   UnSpc ~ 0
12V
Text GLabel 7300 1100 3    60   UnSpc ~ 0
5V
Text GLabel 7500 1100 3    60   UnSpc ~ 0
3V3
Text GLabel 7700 1100 1    60   UnSpc ~ 0
GND
$Comp
L +3.3V #PWR3
U 1 1 55561C8E
P 7500 900
F 0 "#PWR3" H 7500 750 50  0001 C CNN
F 1 "+3.3V" H 7500 1040 50  0000 C CNN
F 2 "" H 7500 900 60  0000 C CNN
F 3 "" H 7500 900 60  0000 C CNN
	1    7500 900 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR2
U 1 1 55561FE3
P 7300 900
F 0 "#PWR2" H 7300 750 50  0001 C CNN
F 1 "+5V" H 7300 1040 50  0000 C CNN
F 2 "" H 7300 900 60  0000 C CNN
F 3 "" H 7300 900 60  0000 C CNN
	1    7300 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 55562339
P 7700 1250
F 0 "#PWR4" H 7700 1000 50  0001 C CNN
F 1 "GND" H 7700 1100 50  0000 C CNN
F 2 "" H 7700 1250 60  0000 C CNN
F 3 "" H 7700 1250 60  0000 C CNN
	1    7700 1250
	1    0    0    -1  
$EndComp
Text GLabel 3700 5850 0    60   UnSpc ~ 0
3V3
$Comp
L C C1
U 1 1 5557BBF1
P 3850 5700
F 0 "C1" H 3875 5800 50  0000 L CNN
F 1 ".1nF" H 3875 5600 50  0000 L CNN
F 2 "" H 3888 5550 30  0000 C CNN
F 3 "" H 3850 5700 60  0000 C CNN
	1    3850 5700
	1    0    0    -1  
$EndComp
NoConn ~ 3950 5150
Text GLabel 5200 7600 2    60   UnSpc ~ 0
3V3
Wire Wire Line
	3450 5250 4050 5250
Wire Wire Line
	3450 5350 4050 5350
Wire Wire Line
	3450 5450 4050 5450
Wire Wire Line
	4550 1650 4550 1600
Wire Wire Line
	4550 1600 4900 1600
Wire Wire Line
	4750 1600 4750 1650
Wire Wire Line
	4550 2750 4550 2800
Wire Wire Line
	4550 2800 4950 2800
Wire Wire Line
	4750 2800 4750 2750
Wire Wire Line
	5050 7200 5250 7200
Wire Wire Line
	5100 4800 5300 4800
Wire Wire Line
	5050 4300 5250 4300
Wire Wire Line
	5000 3350 5200 3350
Connection ~ 4750 2800
Wire Wire Line
	5050 1000 5300 1000
Wire Wire Line
	5250 6600 5050 6600
Wire Wire Line
	5200 3150 5000 3150
Wire Wire Line
	5500 3250 5000 3250
Connection ~ 4750 1600
Wire Notes Line
	3950 2900 5400 2900
Wire Notes Line
	5400 2900 5400 1350
Wire Notes Line
	5400 1350 3950 1350
Wire Notes Line
	3950 1350 3950 2900
Wire Wire Line
	4800 6100 4900 6100
Wire Wire Line
	5500 6500 5050 6500
Wire Wire Line
	5250 3750 5050 3750
Wire Wire Line
	5050 800  5300 800 
Wire Wire Line
	7100 900  7100 1100
Wire Wire Line
	7500 900  7500 1100
Wire Wire Line
	7300 900  7300 1100
Wire Wire Line
	7700 1100 7700 1250
Wire Wire Line
	4800 6000 5150 6000
Wire Wire Line
	3700 5550 4050 5550
Connection ~ 3850 5550
Wire Wire Line
	4050 5850 4050 5650
Wire Wire Line
	3700 5850 4050 5850
Connection ~ 3850 5850
Wire Wire Line
	3950 5150 4050 5150
Wire Wire Line
	5200 1450 5200 2100
Wire Wire Line
	5000 7900 5200 7900
Wire Wire Line
	5000 7600 5200 7600
Text GLabel 5050 8300 2    60   UnSpc ~ 0
5V
Text GLabel 5250 8400 2    60   UnSpc ~ 0
GND
Wire Wire Line
	5250 8400 4900 8400
Wire Wire Line
	4900 8300 5050 8300
Wire Wire Line
	4200 3950 4200 4100
Wire Wire Line
	4250 4700 3450 4700
Wire Wire Line
	3450 4800 4250 4800
Wire Wire Line
	5200 1450 3450 1450
Wire Wire Line
	3450 8800 4200 8800
Wire Wire Line
	4150 1000 4250 1000
Wire Wire Line
	4150 1000 4150 1300
Wire Wire Line
	4150 1300 3450 1300
Wire Wire Line
	3450 1200 4150 1200
Connection ~ 4150 1200
Wire Wire Line
	4250 900  4050 900 
Wire Wire Line
	4050 900  4050 1100
Wire Wire Line
	4050 1100 3450 1100
Wire Wire Line
	3450 1000 4050 1000
Connection ~ 4050 1000
Wire Wire Line
	3450 800  4250 800 
Wire Wire Line
	3450 900  3950 900 
Wire Wire Line
	3950 900  3950 800 
Connection ~ 3950 800 
Text Label 3550 800  0    60   ~ 0
CCP
Text Label 3550 900  0    60   ~ 0
CCP
Text Label 3550 1000 0    60   ~ 0
CCP
Text Label 3550 1100 0    60   ~ 0
CCP
Text Label 3550 1200 0    60   ~ 0
CCP
Text Label 3550 1300 0    60   ~ 0
CCP
Wire Wire Line
	3450 1950 4100 1950
Wire Wire Line
	3450 2250 4100 2250
Wire Wire Line
	4100 2050 3450 2050
Wire Wire Line
	3450 2350 4100 2350
Wire Wire Line
	4100 2450 3450 2450
Text Label 3550 1450 0    60   ~ 0
CCP
Text Label 3550 1950 0    60   ~ 0
GPIO
Text Label 3550 2050 0    60   ~ 0
GPIO
Text Label 3550 2250 0    60   ~ 0
GPIO
Text Label 3550 2350 0    60   ~ 0
GPIO
Text Label 3550 2450 0    60   ~ 0
GPIO
Wire Wire Line
	3450 3150 4200 3150
Wire Wire Line
	4200 3250 3450 3250
Text Label 3550 3150 0    60   ~ 0
GPIO
Text Label 3550 3250 0    60   ~ 0
ADC
Wire Wire Line
	3450 3750 4200 3750
Wire Wire Line
	4200 3850 3450 3850
Wire Wire Line
	3450 3950 4200 3950
Wire Wire Line
	4200 4100 3450 4100
Wire Wire Line
	3450 4200 4200 4200
Wire Wire Line
	4200 4300 3450 4300
Text Label 3550 3750 0    60   ~ 0
GPIO
Text Label 3550 3850 0    60   ~ 0
GPIO
Text Label 3550 3950 0    60   ~ 0
ADC
Text Label 3550 4100 0    60   ~ 0
GPIO
Text Label 3550 4200 0    60   ~ 0
GPIO
Text Label 3550 4300 0    60   ~ 0
ADC
Text Label 3550 4700 0    60   ~ 0
ADC
Text Label 3550 4800 0    60   ~ 0
ADC
Text Label 3550 5250 0    60   ~ 0
ADC
Text Label 3550 5350 0    60   ~ 0
ADC
Text Label 3550 5450 0    60   ~ 0
ADC
Wire Wire Line
	3450 6000 4200 6000
Text Label 3550 6000 0    60   ~ 0
PWM
Wire Wire Line
	3450 6500 4200 6500
Wire Wire Line
	4200 6600 3450 6600
Wire Wire Line
	3450 6700 4200 6700
Wire Wire Line
	4200 6850 3450 6850
Wire Wire Line
	3450 6950 4200 6950
Wire Wire Line
	4200 7050 3450 7050
Text Label 3550 6500 0    60   ~ 0
GPIO
Text Label 3550 6600 0    60   ~ 0
GPIO
Text Label 3550 6850 0    60   ~ 0
GPIO
Text Label 3550 6700 0    60   ~ 0
PWM
Text Label 3550 6950 0    60   ~ 0
GPIO
Text Label 3550 7050 0    60   ~ 0
PWM
Wire Wire Line
	3450 7600 4200 7600
Wire Wire Line
	3450 7700 4200 7700
Wire Wire Line
	4200 7800 3450 7800
Wire Wire Line
	3450 7900 4200 7900
Wire Wire Line
	4200 8300 3450 8300
Text Label 3550 7600 0    60   ~ 0
ADC
Text Label 3550 7700 0    60   ~ 0
ADC
Text Label 3550 7800 0    60   ~ 0
ADC
Text Label 3550 7900 0    60   ~ 0
ADC
Text Label 3550 8300 0    60   ~ 0
GPIO
Text Label 3550 8800 0    60   ~ 0
PWM
$EndSCHEMATC
