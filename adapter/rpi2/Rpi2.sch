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
LIBS:Rpi2-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RPi2 adapter"
Date "2015-10-08"
Rev "0.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_02X20 RPi2
U 1 1 560C1B1B
P 2500 3900
F 0 "RPi2" H 2500 4950 50  0000 C CNN
F 1 "CONN_02X20" V 2500 3900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20" H 2500 2950 60  0001 C CNN
F 3 "" H 2500 2950 60  0000 C CNN
	1    2500 3900
	1    0    0    -1  
$EndComp
Text GLabel 2250 3650 0    60   Output ~ 0
A
Text GLabel 2250 3550 0    60   Output ~ 0
[1]G0
Text GLabel 2250 3450 0    60   Output ~ 0
CLK
Text GLabel 2250 3250 0    60   Output ~ 0
STB
Text GLabel 2250 3850 0    60   Output ~ 0
[1]B1
Text GLabel 2250 3950 0    60   Output ~ 0
[1]G1
Text GLabel 2250 4050 0    60   Output ~ 0
[1]R0
Text GLabel 2750 3250 2    60   Input ~ 0
SNES_DATA0
Text GLabel 2250 4350 0    60   Output ~ 0
[2]G0
Text GLabel 2250 4450 0    60   Output ~ 0
[2]B0
Text GLabel 2250 4550 0    60   Output ~ 0
[2]G1
Text GLabel 2250 4650 0    60   Output ~ 0
[2]R1
Text GLabel 2250 4750 0    60   Output ~ 0
SNES_LATCH
Text GLabel 2750 4750 2    60   Output ~ 0
[2]B1
Text GLabel 2750 4650 2    60   Output ~ 0
SNES_CLK
Text GLabel 2750 4450 2    60   Output ~ 0
[2]R0
Text GLabel 2750 3350 2    60   Input ~ 0
SNES_DATA1
Text GLabel 2750 4150 2    60   Output ~ 0
[1]B0
Text GLabel 2750 4050 2    60   Output ~ 0
[1]R1
Text GLabel 2750 3950 2    60   Output ~ 0
D
Text GLabel 2750 3750 2    60   Output ~ 0
C
Text GLabel 2750 3650 2    60   Output ~ 0
B
Text GLabel 2750 3450 2    60   Output ~ 0
/OE
$Comp
L GND #PWR01
U 1 1 560D61C0
P 2750 3150
F 0 "#PWR01" H 2750 2900 50  0001 C CNN
F 1 "GND" H 2750 3000 50  0000 C CNN
F 2 "" H 2750 3150 60  0000 C CNN
F 3 "" H 2750 3150 60  0000 C CNN
	1    2750 3150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 560D6248
P 2750 4350
F 0 "#PWR02" H 2750 4100 50  0001 C CNN
F 1 "GND" H 2750 4200 50  0000 C CNN
F 2 "" H 2750 4350 60  0000 C CNN
F 3 "" H 2750 4350 60  0000 C CNN
	1    2750 4350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR03
U 1 1 560D625E
P 2750 4550
F 0 "#PWR03" H 2750 4300 50  0001 C CNN
F 1 "GND" H 2750 4400 50  0000 C CNN
F 2 "" H 2750 4550 60  0000 C CNN
F 3 "" H 2750 4550 60  0000 C CNN
	1    2750 4550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR04
U 1 1 560D6274
P 2250 3350
F 0 "#PWR04" H 2250 3100 50  0001 C CNN
F 1 "GND" H 2250 3200 50  0000 C CNN
F 2 "" H 2250 3350 60  0000 C CNN
F 3 "" H 2250 3350 60  0000 C CNN
	1    2250 3350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR05
U 1 1 560D628A
P 2250 4150
F 0 "#PWR05" H 2250 3900 50  0001 C CNN
F 1 "GND" H 2250 4000 50  0000 C CNN
F 2 "" H 2250 4150 60  0000 C CNN
F 3 "" H 2250 4150 60  0000 C CNN
	1    2250 4150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 560D62A0
P 2250 4850
F 0 "#PWR06" H 2250 4600 50  0001 C CNN
F 1 "GND" H 2250 4700 50  0000 C CNN
F 2 "" H 2250 4850 60  0000 C CNN
F 3 "" H 2250 4850 60  0000 C CNN
	1    2250 4850
	0    1    1    0   
$EndComp
Text GLabel 2250 2950 0    60   Output ~ 0
3V3
Text GLabel 2750 2950 2    60   Output ~ 0
5V
Text GLabel 2750 3050 2    60   Output ~ 0
5V
$Comp
L CONN_02X08 Display2
U 1 1 560D63B1
P 5350 4500
F 0 "Display2" H 5350 4950 50  0000 C CNN
F 1 "CONN_02X08" V 5350 4500 50  0000 C CNN
F 2 "Pin_Headers_SMD:Pin_Header_SMD_02x08" H 5350 3300 60  0001 C CNN
F 3 "" H 5350 3300 60  0000 C CNN
	1    5350 4500
	1    0    0    -1  
$EndComp
Text GLabel 3850 4150 0    60   Input ~ 0
[1]R0
Text GLabel 4350 4150 2    60   Input ~ 0
[1]G0
Text GLabel 3850 4250 0    60   Input ~ 0
[1]B0
Text GLabel 3850 4350 0    60   Input ~ 0
[1]R1
Text GLabel 4350 4350 2    60   Input ~ 0
[1]G1
Text GLabel 3850 4450 0    60   Input ~ 0
[1]B1
Text GLabel 3850 4550 0    60   Input ~ 0
A
Text GLabel 4350 4550 2    60   Input ~ 0
B
Text GLabel 3850 4650 0    60   Input ~ 0
C
Text GLabel 4350 4650 2    60   Input ~ 0
D
Text GLabel 3850 4750 0    60   Input ~ 0
CLK
Text GLabel 4350 4750 2    60   Input ~ 0
STB
Text GLabel 3850 4850 0    60   Input ~ 0
/OE
Text GLabel 5100 4150 0    60   Input ~ 0
[2]R0
Text GLabel 5100 4250 0    60   Input ~ 0
[2]B0
Text GLabel 5600 4150 2    60   Input ~ 0
[2]G0
Text GLabel 5600 4350 2    60   Input ~ 0
[2]G1
Text GLabel 5100 4350 0    60   Input ~ 0
[2]R1
Text GLabel 5100 4450 0    60   Input ~ 0
[2]B1
Text GLabel 5100 4550 0    60   Input ~ 0
A
Text GLabel 5100 4650 0    60   Input ~ 0
C
Text GLabel 5600 4550 2    60   Input ~ 0
B
Text GLabel 5600 4650 2    60   Input ~ 0
D
Text GLabel 5100 4750 0    60   Input ~ 0
CLK
Text GLabel 5600 4750 2    60   Input ~ 0
STB
Text GLabel 5100 4850 0    60   Input ~ 0
/OE
$Comp
L CONN_02X05 SNES1
U 1 1 560D6693
P 5350 3550
F 0 "SNES1" H 5350 3850 50  0000 C CNN
F 1 "CONN_02X05" V 5350 3550 50  0000 C CNN
F 2 "Pin_Headers_SMD:Pin_Header_SMD_02x05" H 5350 2350 60  0001 C CNN
F 3 "" H 5350 2350 60  0000 C CNN
	1    5350 3550
	1    0    0    -1  
$EndComp
Text GLabel 5100 3350 0    60   Input ~ 0
3V3
Text GLabel 5100 3550 0    60   Input ~ 0
3V3
Text GLabel 5600 3350 2    60   Input ~ 0
SNES_CLK
Text GLabel 5100 3450 0    60   Input ~ 0
SNES_LATCH
Text GLabel 5600 3450 2    60   Output ~ 0
SNES_DATA0
Text GLabel 5600 3550 2    60   Input ~ 0
SNES_CLK
Text GLabel 5100 3650 0    60   Input ~ 0
SNES_LATCH
Text GLabel 5600 3650 2    60   Output ~ 0
SNES_DATA1
$Comp
L GND #PWR07
U 1 1 560D67C1
P 5100 3750
F 0 "#PWR07" H 5100 3500 50  0001 C CNN
F 1 "GND" H 5100 3600 50  0000 C CNN
F 2 "" H 5100 3750 60  0000 C CNN
F 3 "" H 5100 3750 60  0000 C CNN
	1    5100 3750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 560D67DD
P 5600 3750
F 0 "#PWR08" H 5600 3500 50  0001 C CNN
F 1 "GND" H 5600 3600 50  0000 C CNN
F 2 "" H 5600 3750 60  0000 C CNN
F 3 "" H 5600 3750 60  0000 C CNN
	1    5600 3750
	0    -1   -1   0   
$EndComp
$Comp
L CONN_02X08 Display1
U 1 1 560D62F4
P 4100 4500
F 0 "Display1" H 4100 4950 50  0000 C CNN
F 1 "CONN_02X08" V 4100 4500 50  0000 C CNN
F 2 "Pin_Headers_SMD:Pin_Header_SMD_02x08" H 4100 3300 60  0001 C CNN
F 3 "" H 4100 3300 60  0000 C CNN
	1    4100 4500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5616B74D
P 4350 4250
F 0 "#PWR09" H 4350 4000 50  0001 C CNN
F 1 "GND" H 4350 4100 50  0000 C CNN
F 2 "" H 4350 4250 60  0000 C CNN
F 3 "" H 4350 4250 60  0000 C CNN
	1    4350 4250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5616B76B
P 4350 4450
F 0 "#PWR010" H 4350 4200 50  0001 C CNN
F 1 "GND" H 4350 4300 50  0000 C CNN
F 2 "" H 4350 4450 60  0000 C CNN
F 3 "" H 4350 4450 60  0000 C CNN
	1    4350 4450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5616B78A
P 4350 4850
F 0 "#PWR011" H 4350 4600 50  0001 C CNN
F 1 "GND" H 4350 4700 50  0000 C CNN
F 2 "" H 4350 4850 60  0000 C CNN
F 3 "" H 4350 4850 60  0000 C CNN
	1    4350 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 5616B7A1
P 5600 4850
F 0 "#PWR012" H 5600 4600 50  0001 C CNN
F 1 "GND" H 5600 4700 50  0000 C CNN
F 2 "" H 5600 4850 60  0000 C CNN
F 3 "" H 5600 4850 60  0000 C CNN
	1    5600 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5616B7B8
P 5600 4450
F 0 "#PWR013" H 5600 4200 50  0001 C CNN
F 1 "GND" H 5600 4300 50  0000 C CNN
F 2 "" H 5600 4450 60  0000 C CNN
F 3 "" H 5600 4450 60  0000 C CNN
	1    5600 4450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5616B7CF
P 5600 4250
F 0 "#PWR014" H 5600 4000 50  0001 C CNN
F 1 "GND" H 5600 4100 50  0000 C CNN
F 2 "" H 5600 4250 60  0000 C CNN
F 3 "" H 5600 4250 60  0000 C CNN
	1    5600 4250
	0    -1   -1   0   
$EndComp
NoConn ~ 2250 4250
NoConn ~ 2750 4250
$Comp
L GND #PWR015
U 1 1 5616B8E1
P 750 850
F 0 "#PWR015" H 750 600 50  0001 C CNN
F 1 "GND" H 750 700 50  0000 C CNN
F 2 "" H 750 850 60  0000 C CNN
F 3 "" H 750 850 60  0000 C CNN
	1    750  850 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG016
U 1 1 5616B8FD
P 750 850
F 0 "#FLG016" H 750 945 50  0001 C CNN
F 1 "PWR_FLAG" H 750 1030 50  0000 C CNN
F 2 "" H 750 850 60  0000 C CNN
F 3 "" H 750 850 60  0000 C CNN
	1    750  850 
	1    0    0    -1  
$EndComp
$Comp
L PCF8574 U1
U 1 1 5622BEDC
P 4100 2300
F 0 "U1" H 3750 2900 50  0000 L CNN
F 1 "PCF8574" H 4200 2900 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 4100 2300 60  0001 C CNN
F 3 "" H 4100 2300 60  0000 C CNN
	1    4100 2300
	1    0    0    -1  
$EndComp
Text GLabel 4100 1450 1    60   Input ~ 0
3V3
$Comp
L GND #PWR017
U 1 1 5622C053
P 4100 3000
F 0 "#PWR017" H 4100 2750 50  0001 C CNN
F 1 "GND" H 4100 2850 50  0000 C CNN
F 2 "" H 4100 3000 60  0000 C CNN
F 3 "" H 4100 3000 60  0000 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 3150 1900 3150
Wire Wire Line
	1900 3150 1900 1900
Wire Wire Line
	1900 1900 3600 1900
Wire Wire Line
	2250 3050 1950 3050
Wire Wire Line
	1950 3050 1950 2000
Wire Wire Line
	1950 2000 3600 2000
$Comp
L CONN_02X05 P1
U 1 1 5622CBAD
P 5400 2100
F 0 "P1" H 5400 2400 50  0000 C CNN
F 1 "CONN_02X05" H 5400 1800 50  0000 C CNN
F 2 "Pin_Headers_SMD:Pin_Header_SMD_02x05" H 5400 900 60  0001 C CNN
F 3 "" H 5400 900 60  0000 C CNN
	1    5400 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1900 5150 1900
Wire Wire Line
	4600 2100 4750 2100
Wire Wire Line
	4750 2100 4750 2000
Wire Wire Line
	4750 2000 5150 2000
Wire Wire Line
	4600 2300 4850 2300
Wire Wire Line
	4850 2300 4850 2100
Wire Wire Line
	4850 2100 5150 2100
Wire Wire Line
	4600 2500 4950 2500
Wire Wire Line
	4950 2500 4950 2200
Wire Wire Line
	4950 2200 5150 2200
Wire Wire Line
	4700 2000 4600 2000
Wire Wire Line
	4700 1550 4700 2000
Wire Wire Line
	4800 2200 4600 2200
Wire Wire Line
	4800 1600 4800 2200
Wire Wire Line
	4900 2400 4600 2400
Wire Wire Line
	4900 1650 4900 2400
Wire Wire Line
	5000 2600 4600 2600
Wire Wire Line
	5000 1700 5000 2600
Wire Wire Line
	5000 1700 5700 1700
Wire Wire Line
	5700 1700 5700 2200
Wire Wire Line
	5700 2200 5650 2200
Wire Wire Line
	4900 1650 5750 1650
Wire Wire Line
	4800 1600 5800 1600
Wire Wire Line
	4700 1550 5850 1550
Wire Wire Line
	5850 1550 5850 1900
Wire Wire Line
	5850 1900 5650 1900
Wire Wire Line
	5800 1600 5800 2000
Wire Wire Line
	5800 2000 5650 2000
Wire Wire Line
	5750 1650 5750 2100
Wire Wire Line
	5750 2100 5650 2100
$Comp
L GND #PWR018
U 1 1 5622CE1E
P 5650 2300
F 0 "#PWR018" H 5650 2050 50  0001 C CNN
F 1 "GND" H 5650 2150 50  0000 C CNN
F 2 "" H 5650 2300 60  0000 C CNN
F 3 "" H 5650 2300 60  0000 C CNN
	1    5650 2300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 1450 4100 1600
Wire Wire Line
	3550 1500 5050 1500
Wire Wire Line
	5050 1500 5050 2300
Wire Wire Line
	5050 2300 5150 2300
Connection ~ 4100 1500
Wire Wire Line
	3600 2700 3450 2700
Wire Wire Line
	3450 2700 3450 4850
Wire Wire Line
	3450 4850 2750 4850
Wire Wire Line
	3600 2200 3550 2200
Wire Wire Line
	3550 1500 3550 2400
Wire Wire Line
	3550 2300 3600 2300
Connection ~ 3550 2200
Wire Wire Line
	3550 2400 3600 2400
Connection ~ 3550 2300
NoConn ~ 2250 3750
NoConn ~ 2750 3550
NoConn ~ 2750 3850
Text GLabel 1250 750  2    60   Input ~ 0
3V3
$Comp
L PWR_FLAG #FLG019
U 1 1 5622DE12
P 1250 750
F 0 "#FLG019" H 1250 845 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 930 50  0000 C CNN
F 2 "" H 1250 750 60  0000 C CNN
F 3 "" H 1250 750 60  0000 C CNN
	1    1250 750 
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
