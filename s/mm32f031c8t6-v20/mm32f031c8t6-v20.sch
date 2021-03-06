EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "MM32F031_C8T6"
Date "2021-03-12"
Rev "v2.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	9690 5435 9390 5435
Wire Wire Line
	6320 5740 6920 5740
$Comp
L power:GND #PWR03
U 1 1 6038CDA2
P 1645 1900
F 0 "#PWR03" H 1645 1650 50  0001 C CNN
F 1 "GND" V 1650 1772 50  0000 R CNN
F 2 "" H 1645 1900 50  0001 C CNN
F 3 "" H 1645 1900 50  0001 C CNN
	1    1645 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1695 1700 1645 1700
Wire Wire Line
	1645 1900 1645 2150
Wire Wire Line
	1645 2150 1695 2150
Connection ~ 1645 1900
Wire Wire Line
	1995 2150 2295 2150
Wire Wire Line
	2295 2050 2295 2150
Connection ~ 2295 2150
Wire Wire Line
	2295 1750 2295 1700
Connection ~ 2295 1700
Wire Wire Line
	2295 1700 1995 1700
Wire Wire Line
	1645 1700 1645 1900
Wire Wire Line
	2295 1700 2745 1700
Wire Wire Line
	2295 2150 2745 2150
Wire Wire Line
	2745 1800 2745 1700
Connection ~ 2745 1700
Wire Wire Line
	2745 2100 2745 2150
Connection ~ 2745 2150
Wire Wire Line
	12900 5730 12900 5870
$Comp
L power:GND #PWR024
U 1 1 60393E97
P 12200 6720
F 0 "#PWR024" H 12200 6470 50  0001 C CNN
F 1 "GND" H 12205 6547 50  0000 C CNN
F 2 "" H 12200 6720 50  0001 C CNN
F 3 "" H 12200 6720 50  0001 C CNN
	1    12200 6720
	1    0    0    -1  
$EndComp
Wire Wire Line
	2745 1700 3245 1700
Wire Wire Line
	2745 2150 3245 2150
Wire Wire Line
	6920 5825 6670 5825
Wire Wire Line
	6920 5915 6540 5915
Wire Wire Line
	6920 5670 6315 5670
Wire Wire Line
	6920 5995 6670 5995
Wire Wire Line
	12900 6170 12900 6270
Wire Wire Line
	12900 6270 12900 6320
Wire Wire Line
	12900 6620 12900 6670
Wire Wire Line
	12900 6670 12200 6670
Wire Wire Line
	12900 6270 13350 6270
Connection ~ 12900 6270
Wire Wire Line
	8200 1570 8050 1570
Wire Wire Line
	7750 1570 7550 1570
Wire Wire Line
	7150 1570 7150 1670
Connection ~ 7150 1570
Wire Wire Line
	7150 1970 7150 2195
Wire Wire Line
	7150 2195 7550 2195
Wire Wire Line
	7550 1970 7550 2195
Wire Wire Line
	7550 1570 7550 1670
Connection ~ 7550 1570
Wire Wire Line
	9390 5520 9730 5520
$Comp
L power:GND #PWR019
U 1 1 603F444C
P 7550 2270
F 0 "#PWR019" H 7550 2020 50  0001 C CNN
F 1 "GND" H 7555 2097 50  0000 C CNN
F 2 "" H 7550 2270 50  0001 C CNN
F 3 "" H 7550 2270 50  0001 C CNN
	1    7550 2270
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1570 8200 1720
Wire Wire Line
	8200 1570 8345 1570
Wire Wire Line
	8600 1570 8600 1745
Wire Wire Line
	8200 2020 8200 2195
Text Notes 12200 7215 0    118  ~ 0
rest-key
Text Notes 615  3320 0    102  ~ 0
External crystal
Wire Wire Line
	8620 7200 8620 6800
Wire Wire Line
	9695 5355 9390 5355
Wire Wire Line
	8600 1570 8600 1245
Connection ~ 8600 1570
Wire Wire Line
	9415 1570 9415 1745
Wire Wire Line
	9415 2045 9415 2195
Wire Wire Line
	9415 2195 9015 2195
Wire Wire Line
	9415 1570 9415 1245
Connection ~ 9415 1570
Wire Wire Line
	9390 5930 9640 5930
$Comp
L power:GND #PWR029
U 1 1 6054269C
P 14300 6745
F 0 "#PWR029" H 14300 6495 50  0001 C CNN
F 1 "GND" H 14305 6572 50  0000 C CNN
F 2 "" H 14300 6745 50  0001 C CNN
F 3 "" H 14300 6745 50  0001 C CNN
	1    14300 6745
	1    0    0    -1  
$EndComp
Wire Wire Line
	14300 6695 14300 6745
Text Notes 14025 7195 0    118  ~ 0
Rouse-key
Wire Wire Line
	14300 6345 15050 6345
Connection ~ 14300 6345
Wire Wire Line
	14300 6345 14300 6395
Wire Wire Line
	13170 1670 13420 1670
Wire Wire Line
	13720 1670 13970 1670
$Comp
L power:GND #PWR026
U 1 1 6076D8F8
P 13970 1670
F 0 "#PWR026" H 13970 1420 50  0001 C CNN
F 1 "GND" V 13975 1542 50  0000 R CNN
F 2 "" H 13970 1670 50  0001 C CNN
F 3 "" H 13970 1670 50  0001 C CNN
	1    13970 1670
	0    -1   -1   0   
$EndComp
Wire Wire Line
	12870 1670 12620 1670
Wire Wire Line
	13170 1945 13420 1945
Wire Wire Line
	13720 1945 13970 1945
$Comp
L power:GND #PWR027
U 1 1 6077CA9F
P 13970 1945
F 0 "#PWR027" H 13970 1695 50  0001 C CNN
F 1 "GND" V 13975 1817 50  0000 R CNN
F 2 "" H 13970 1945 50  0001 C CNN
F 3 "" H 13970 1945 50  0001 C CNN
	1    13970 1945
	0    -1   -1   0   
$EndComp
Wire Wire Line
	12870 1945 12620 1945
Text Notes 11685 3295 0    110  ~ 0
LED-Light
Wire Wire Line
	920  6370 1045 6370
Wire Wire Line
	1045 6370 1045 6270
Wire Wire Line
	1045 6270 920  6270
Wire Wire Line
	6535 9480 6535 9305
$Comp
L power:GND #PWR015
U 1 1 6088321D
P 6535 9480
F 0 "#PWR015" H 6535 9230 50  0001 C CNN
F 1 "GND" H 6540 9307 50  0000 C CNN
F 2 "" H 6535 9480 50  0001 C CNN
F 3 "" H 6535 9480 50  0001 C CNN
	1    6535 9480
	1    0    0    -1  
$EndComp
Connection ~ 6535 9480
Wire Wire Line
	6190 9005 5910 9005
Wire Wire Line
	5460 9405 5460 9480
Wire Wire Line
	5460 9480 5910 9480
Wire Wire Line
	5910 9005 5910 9080
Connection ~ 5910 9005
Wire Wire Line
	5910 9380 5910 9480
Connection ~ 5910 9480
Wire Wire Line
	5910 9480 6535 9480
Wire Wire Line
	5910 9005 5460 9005
Wire Wire Line
	5460 9005 5460 9105
Wire Wire Line
	1840 4190 1840 4370
Text Notes 5230 11080 0    118  ~ 0
3.3v Voltage output
Wire Wire Line
	8230 4810 8230 4335
Wire Wire Line
	7660 4810 7660 4335
Wire Wire Line
	7740 4810 7740 4335
Wire Wire Line
	7905 4810 7905 4335
Wire Wire Line
	7985 4810 7985 4335
Wire Wire Line
	8065 4810 8065 4335
Wire Wire Line
	8150 4810 8150 4335
Text Label 8065 4585 3    50   ~ 0
PB5
Text Label 8230 4560 3    50   ~ 0
PB3
Text Label 8150 4585 3    50   ~ 0
PB4
Text Label 7985 4590 3    50   ~ 0
PB6
Text Label 7905 4585 3    50   ~ 0
PB7
Text Label 7740 4585 3    50   ~ 0
PB8
Text Label 7660 4585 3    50   ~ 0
PB9
Wire Wire Line
	9390 5765 9655 5765
Wire Wire Line
	9390 5680 9865 5680
Wire Wire Line
	9390 5600 9865 5600
Text Label 9640 5765 2    50   ~ 0
PA10
Text Label 9665 5680 2    50   ~ 0
PA11
Text Label 9665 5600 2    50   ~ 0
PA12
Text Label 9590 5850 2    50   ~ 0
PA9
Text Label 13150 6270 0    50   ~ 0
NRST
Text Label 15050 6345 2    50   ~ 0
PA0_WAKEUP
Text Label 9415 5520 0    50   ~ 0
SWDIO
Wire Wire Line
	6445 6340 6920 6340
Wire Wire Line
	6445 6430 6920 6430
Wire Wire Line
	7650 7065 7650 6800
Wire Wire Line
	7765 7035 7765 6800
Wire Wire Line
	7860 7035 7860 6800
Wire Wire Line
	7950 7095 7950 6800
Wire Wire Line
	8045 7095 8045 6800
Text Label 8045 7020 1    50   ~ 0
PA7
Text Label 7950 7020 1    50   ~ 0
PA6
Text Label 7860 7035 1    50   ~ 0
PA5
Text Label 7765 7035 1    50   ~ 0
PA4
Text Label 7650 6990 1    50   ~ 0
PA3
Text Label 6520 6430 0    50   ~ 0
PA2
Text Label 6520 6340 0    50   ~ 0
PA1
Wire Wire Line
	6445 6240 6920 6240
Text Label 9590 5930 2    50   ~ 0
PA8
Text Label 3245 1700 2    50   ~ 0
OSC_IN
Text Label 3245 2150 2    50   ~ 0
OSC_OUT
Wire Wire Line
	8135 6800 8135 7275
Wire Wire Line
	8225 6800 8225 7275
Wire Wire Line
	8300 6800 8300 7275
Text Label 8135 6875 3    50   ~ 0
PB0
Text Label 8225 7025 1    50   ~ 0
PB1
Text Label 8300 7025 1    50   ~ 0
PB2
Wire Wire Line
	8380 6800 8380 7275
Wire Wire Line
	8465 6800 8465 7275
Wire Wire Line
	9390 6255 9865 6255
Text Label 8380 7075 1    50   ~ 0
PB10
Text Label 8465 7075 1    50   ~ 0
PB11
Text Label 9665 6255 2    50   ~ 0
PB12
Text Label 6670 5825 0    50   ~ 0
OSC_IN
Text Label 6670 5995 0    50   ~ 0
NRST
Text Label 8620 7100 1    50   ~ 0
VDD_1
Text Label 6645 6150 0    50   ~ 0
VDDA
Text Label 7490 4710 1    50   ~ 0
VDD_2
Text Label 8600 1495 1    50   ~ 0
VDD_1
Text Label 9415 1295 3    50   ~ 0
VDD_2
Text Label 12620 1670 0    50   ~ 0
PA11
Text Label 12620 1945 0    50   ~ 0
PA12
Wire Wire Line
	8395 4810 8395 4360
Text Label 8395 4435 3    50   ~ 0
SWCLK
Wire Wire Line
	8310 4810 8310 4360
Text Label 8310 4435 3    50   ~ 0
PA15
Wire Wire Line
	9390 6170 9865 6170
Wire Wire Line
	9390 6090 9865 6090
Wire Wire Line
	9390 6010 9865 6010
Text Label 9665 6170 2    50   ~ 0
PB13
Text Label 9665 6090 2    50   ~ 0
PB14
Text Label 9665 6010 2    50   ~ 0
PB15
Connection ~ 5460 9005
Wire Wire Line
	5460 8630 5460 9005
Text Notes 530  11100 0    102  ~ 0
micro-input-port
Text Label 6920 6240 2    50   ~ 0
PA0_WAKEUP
Wire Wire Line
	9390 5850 9640 5850
Connection ~ 8200 2195
Wire Wire Line
	7550 2195 7550 2270
Wire Wire Line
	7550 2195 8200 2195
$Comp
L power:PWR_FLAG #FLG03
U 1 1 60769115
P 8200 2370
F 0 "#FLG03" H 8200 2445 50  0001 C CNN
F 1 "PWR_FLAG" H 8200 2543 50  0000 C CNN
F 2 "" H 8200 2370 50  0001 C CNN
F 3 "~" H 8200 2370 50  0001 C CNN
	1    8200 2370
	-1   0    0    1   
$EndComp
Wire Wire Line
	6995 1335 6995 1570
Wire Wire Line
	7150 1570 6995 1570
Wire Wire Line
	7490 4410 7490 4810
Wire Wire Line
	6295 6150 6920 6150
$Comp
L power:PWR_FLAG #FLG02
U 1 1 6050FE63
P 8345 1425
F 0 "#FLG02" H 8345 1500 50  0001 C CNN
F 1 "PWR_FLAG" H 8345 1598 50  0000 C CNN
F 2 "" H 8345 1425 50  0001 C CNN
F 3 "~" H 8345 1425 50  0001 C CNN
	1    8345 1425
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8345 1425 8345 1570
Wire Wire Line
	8600 2045 8600 2195
Wire Notes Line
	4985 470  4985 11230
Wire Notes Line
	4985 11230 4995 11230
Wire Notes Line
	480  8265 16055 8265
Wire Notes Line
	16055 8265 16055 8255
Wire Notes Line
	465  3515 16080 3515
Wire Wire Line
	8200 2195 8200 2370
Wire Wire Line
	8200 2195 8600 2195
Text Label 6540 5915 0    50   ~ 0
OSC_OUT
Wire Wire Line
	6920 5605 6315 5605
Text Label 6315 5605 0    50   ~ 0
PC13_TAMPER_RTC
Text Label 6470 5740 0    50   ~ 0
OSC32_OUT
Text Label 6495 5670 0    50   ~ 0
OSC32_IN
Text Notes 550  8135 0    110  ~ 0
OutPut port
Wire Wire Line
	920  6170 1045 6170
Wire Wire Line
	1045 6170 1045 6070
Wire Wire Line
	1045 6070 920  6070
$Comp
L power:GND #PWR01
U 1 1 610881BB
P 1045 6070
F 0 "#PWR01" H 1045 5820 50  0001 C CNN
F 1 "GND" V 1050 5942 50  0000 R CNN
F 2 "" H 1045 6070 50  0001 C CNN
F 3 "" H 1045 6070 50  0001 C CNN
	1    1045 6070
	0    -1   -1   0   
$EndComp
Wire Wire Line
	920  5770 1395 5770
Wire Wire Line
	920  5870 1395 5870
Wire Wire Line
	920  5970 1395 5970
Text Label 1145 5870 2    50   ~ 0
PB1
Text Label 1145 5970 2    50   ~ 0
PB2
Text Label 995  5270 0    50   ~ 0
PA3
Text Label 995  5370 0    50   ~ 0
PA4
Text Label 995  5470 0    50   ~ 0
PA5
Text Label 995  5570 0    50   ~ 0
PA6
Text Label 995  5670 0    50   ~ 0
PA7
Text Label 995  5770 0    50   ~ 0
PB0
Wire Wire Line
	920  5670 1395 5670
Wire Wire Line
	920  5570 1395 5570
Wire Wire Line
	920  5470 1395 5470
Wire Wire Line
	920  5370 1395 5370
Wire Wire Line
	920  5270 1395 5270
Wire Wire Line
	1045 6370 1195 6370
Wire Wire Line
	3670 5215 3795 5215
Wire Wire Line
	3795 5215 3795 5315
Wire Wire Line
	3795 5315 3670 5315
Wire Wire Line
	3795 5015 3670 5015
Wire Wire Line
	3795 5015 3795 5115
Wire Wire Line
	3795 5115 3670 5115
Wire Wire Line
	3795 5115 3945 5115
Connection ~ 3795 5115
$Comp
L power:GND #PWR08
U 1 1 611AB98D
P 3795 5315
F 0 "#PWR08" H 3795 5065 50  0001 C CNN
F 1 "GND" V 3800 5187 50  0000 R CNN
F 2 "" H 3795 5315 50  0001 C CNN
F 3 "" H 3795 5315 50  0001 C CNN
	1    3795 5315
	0    -1   1    0   
$EndComp
Wire Wire Line
	2325 7540 2800 7540
Wire Wire Line
	2325 7440 2800 7440
Wire Wire Line
	2325 7340 2800 7340
Text Label 2600 7540 2    50   ~ 0
PB10
Text Label 2600 7440 2    50   ~ 0
PB11
Text Label 2600 7340 2    50   ~ 0
PB12
Text Label 2600 7240 2    50   ~ 0
PB13
Wire Wire Line
	2325 7240 2800 7240
Text Label 3925 6415 2    50   ~ 0
PD3
Wire Wire Line
	3670 6415 4145 6415
Wire Wire Line
	3670 6515 4145 6515
Text Label 2700 6640 2    50   ~ 0
SWDIO
Wire Wire Line
	2325 6640 2775 6640
Connection ~ 2240 4340
Wire Wire Line
	2640 4465 2640 4000
Wire Wire Line
	2540 4465 2540 4000
Text Label 2940 4465 1    50   ~ 0
PC13_TAMPER_RTC
Wire Wire Line
	2940 4465 2940 3990
Wire Wire Line
	2840 3990 2840 4465
Text Label 2740 3990 3    50   ~ 0
OSC32_OUT
Text Label 2840 3990 3    50   ~ 0
OSC32_IN
Wire Wire Line
	2740 3990 2740 4465
$Comp
L power:GND #PWR05
U 1 1 6105C8FE
P 2240 4340
F 0 "#PWR05" H 2240 4090 50  0001 C CNN
F 1 "GND" V 2245 4212 50  0000 R CNN
F 2 "" H 2240 4340 50  0001 C CNN
F 3 "" H 2240 4340 50  0001 C CNN
	1    2240 4340
	-1   0    0    1   
$EndComp
Text Label 2540 4355 1    50   ~ 0
PA2
Text Label 2640 4315 1    50   ~ 0
PA1
Wire Wire Line
	2240 4340 2240 4465
Wire Wire Line
	2340 4340 2240 4340
Wire Wire Line
	2340 4465 2340 4340
Wire Wire Line
	1940 4465 1940 4370
Wire Wire Line
	1840 4370 1840 4465
Text Label 2445 7740 0    50   ~ 0
GND
Wire Wire Line
	2155 9800 2895 9800
Wire Wire Line
	2895 9530 2895 9800
Wire Wire Line
	2895 9800 3345 9800
Connection ~ 2895 9800
Wire Wire Line
	3345 9800 3345 9425
Wire Wire Line
	1145 9175 2155 9175
Wire Wire Line
	1145 9075 1920 9075
Wire Wire Line
	2155 9175 2155 9800
Wire Wire Line
	2895 9075 3345 9075
Connection ~ 2895 9075
Wire Wire Line
	2895 9230 2895 9075
Wire Wire Line
	2220 9075 2895 9075
Wire Wire Line
	3345 9075 3345 9125
Wire Wire Line
	2325 7640 2785 7640
Wire Wire Line
	2325 7740 2760 7740
Text Label 2430 7640 0    50   ~ 0
in5V
Text Label 1215 9175 0    50   ~ 0
GND
Text Label 3800 6515 0    50   ~ 0
PD2
Wire Wire Line
	7035 9480 7460 9480
Connection ~ 7035 9480
Wire Wire Line
	7035 9405 7035 9480
Wire Wire Line
	6535 9480 7035 9480
Wire Wire Line
	7960 9005 8110 9005
Connection ~ 7460 9005
Wire Wire Line
	7460 9005 7660 9005
Wire Wire Line
	7460 9480 8410 9480
Connection ~ 7460 9480
Wire Wire Line
	7460 9380 7460 9480
Wire Wire Line
	7035 9005 7460 9005
Wire Wire Line
	7460 9005 7460 9080
Wire Wire Line
	7035 9105 7035 9005
Connection ~ 7035 9005
Wire Wire Line
	8410 9005 8410 9480
Wire Wire Line
	6190 8855 6130 8855
Wire Wire Line
	6130 8855 6130 9230
Wire Wire Line
	6130 9230 6920 9230
Wire Wire Line
	6920 9230 6920 9005
Wire Wire Line
	6920 9005 7035 9005
Wire Wire Line
	6190 8755 6070 8755
Wire Wire Line
	6070 8755 6070 9305
Wire Wire Line
	6070 9305 6535 9305
Wire Wire Line
	6890 8905 6920 8905
Wire Wire Line
	6920 8905 6920 9005
Connection ~ 6920 9005
Connection ~ 1840 4370
Connection ~ 1045 6070
Connection ~ 1045 6370
Wire Wire Line
	2895 8950 2895 9075
$Comp
L power:PWR_FLAG #FLG01
U 1 1 607CE0D8
P 2895 8950
F 0 "#FLG01" H 2895 9025 50  0001 C CNN
F 1 "PWR_FLAG" H 2895 9123 50  0000 C CNN
F 2 "" H 2895 8950 50  0001 C CNN
F 3 "~" H 2895 8950 50  0001 C CNN
	1    2895 8950
	1    0    0    -1  
$EndComp
Text Label 1200 9075 0    50   ~ 0
in5V
Text Label 2250 9075 0    50   ~ 0
+5V
Wire Notes Line
	11535 525  11535 11220
Text Label 9425 5355 0    50   ~ 0
PD3
Text Label 9390 5435 0    50   ~ 0
PD2
$Comp
L Device:R R3
U 1 1 60868F77
P 7810 9005
F 0 "R3" V 7603 9005 50  0000 C CNN
F 1 "1k" V 7694 9005 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7740 9005 50  0001 C CNN
F 3 "~" H 7810 9005 50  0001 C CNN
	1    7810 9005
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 60875DD7
P 8260 9005
F 0 "D1" H 8253 8750 50  0000 C CNN
F 1 "LED" H 8253 8841 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 8260 9005 50  0001 C CNN
F 3 "~" H 8260 9005 50  0001 C CNN
	1    8260 9005
	-1   0    0    1   
$EndComp
$Comp
L Device:C C11
U 1 1 60911CF9
P 7460 9230
F 0 "C11" H 7575 9276 50  0000 L CNN
F 1 "100nf" H 7575 9185 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7498 9080 50  0001 C CNN
F 3 "~" H 7460 9230 50  0001 C CNN
	1    7460 9230
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C9
U 1 1 6097A633
P 7035 9255
F 0 "C9" H 7153 9301 50  0000 L CNN
F 1 "10uf" H 7153 9210 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7073 9105 50  0001 C CNN
F 3 "~" H 7035 9255 50  0001 C CNN
	1    7035 9255
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 6038CDA8
P 1845 1700
F 0 "C1" V 1695 1700 50  0000 C CNN
F 1 "20pf" V 1795 1825 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1883 1550 50  0001 C CNN
F 3 "~" H 1845 1700 50  0001 C CNN
	1    1845 1700
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 6038CDAE
P 1845 2150
F 0 "C2" V 1695 2150 50  0000 C CNN
F 1 "20pf" V 1795 2275 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1883 2000 50  0001 C CNN
F 3 "~" H 1845 2150 50  0001 C CNN
	1    1845 2150
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 6038CDB4
P 2295 1900
F 0 "Y1" V 2249 2031 50  0000 L CNN
F 1 "8m" V 2340 2031 50  0000 L CNN
F 2 "Crystal:Resonator-2Pin_W10.0mm_H5.0mm" H 2295 1900 50  0001 C CNN
F 3 "~" H 2295 1900 50  0001 C CNN
	1    2295 1900
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 60390E05
P 2745 1950
F 0 "R1" H 2815 1996 50  0000 L CNN
F 1 "1m" H 2815 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2675 1950 50  0001 C CNN
F 3 "~" H 2745 1950 50  0001 C CNN
	1    2745 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60392269
P 12900 6020
F 0 "R4" H 12970 6066 50  0000 L CNN
F 1 "10k" H 12970 5975 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 12830 6020 50  0001 C CNN
F 3 "~" H 12900 6020 50  0001 C CNN
	1    12900 6020
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 603A84F6
P 12900 6470
F 0 "C17" H 13015 6516 50  0000 L CNN
F 1 "100nf" H 13015 6425 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 12938 6320 50  0001 C CNN
F 3 "~" H 12900 6470 50  0001 C CNN
	1    12900 6470
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 603B1500
P 7900 1570
F 0 "L1" V 8000 1570 50  0000 C CNN
F 1 "3.3uH" V 7850 1570 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 7900 1570 50  0001 C CNN
F 3 "~" H 7900 1570 50  0001 C CNN
	1    7900 1570
	0    1    -1   0   
$EndComp
$Comp
L Device:C C8
U 1 1 603B1DB4
P 7150 1820
F 0 "C8" H 7265 1866 50  0000 L CNN
F 1 "10nF" H 7265 1775 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7188 1670 50  0001 C CNN
F 3 "~" H 7150 1820 50  0001 C CNN
	1    7150 1820
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 603F529E
P 8200 1870
F 0 "C13" H 8315 1916 50  0000 L CNN
F 1 "1uF" H 8315 1825 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8238 1720 50  0001 C CNN
F 3 "~" H 8200 1870 50  0001 C CNN
	1    8200 1870
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 603F55F6
P 8600 1895
F 0 "C14" H 8715 1941 50  0000 L CNN
F 1 "10nF" H 8715 1850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8638 1745 50  0001 C CNN
F 3 "~" H 8600 1895 50  0001 C CNN
	1    8600 1895
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 60459ADF
P 9415 1895
F 0 "C16" H 9530 1941 50  0000 L CNN
F 1 "10nF" H 9530 1850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9453 1745 50  0001 C CNN
F 3 "~" H 9415 1895 50  0001 C CNN
	1    9415 1895
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 604606FE
P 7550 1820
F 0 "C7" H 7665 1866 50  0000 L CNN
F 1 "1uF" H 7665 1775 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7588 1670 50  0001 C CNN
F 3 "~" H 7550 1820 50  0001 C CNN
	1    7550 1820
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 60542695
P 14300 6545
F 0 "R7" H 14370 6591 50  0000 L CNN
F 1 "10k" H 14370 6500 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 14230 6545 50  0001 C CNN
F 3 "~" H 14300 6545 50  0001 C CNN
	1    14300 6545
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 60754C70
P 13570 1670
F 0 "D2" H 13595 1520 50  0000 C CNN
F 1 "LED" H 13570 1595 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 13570 1670 50  0001 C CNN
F 3 "~" H 13570 1670 50  0001 C CNN
	1    13570 1670
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 607558F2
P 13020 1670
F 0 "R5" V 12945 1595 50  0000 C CNN
F 1 "1k" V 12945 1745 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 12950 1670 50  0001 C CNN
F 3 "~" H 13020 1670 50  0001 C CNN
	1    13020 1670
	0    1    1    0   
$EndComp
$Comp
L Device:LED D3
U 1 1 6077CA91
P 13570 1945
F 0 "D3" H 13595 1795 50  0000 C CNN
F 1 "LED" H 13570 1870 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 13570 1945 50  0001 C CNN
F 3 "~" H 13570 1945 50  0001 C CNN
	1    13570 1945
	-1   0    0    1   
$EndComp
$Comp
L Device:R R6
U 1 1 6077CA97
P 13020 1945
F 0 "R6" V 12945 1870 50  0000 C CNN
F 1 "1k" V 12945 2020 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 12950 1945 50  0001 C CNN
F 3 "~" H 13020 1945 50  0001 C CNN
	1    13020 1945
	0    1    1    0   
$EndComp
$Comp
L Device:CP C5
U 1 1 6095EDAC
P 5460 9255
F 0 "C5" H 5578 9301 50  0000 L CNN
F 1 "10uf" H 5578 9210 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5498 9105 50  0001 C CNN
F 3 "~" H 5460 9255 50  0001 C CNN
	1    5460 9255
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 609A1DCD
P 5910 9230
F 0 "C6" H 6025 9276 50  0000 L CNN
F 1 "100nf" H 6025 9185 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5948 9080 50  0001 C CNN
F 3 "~" H 5910 9230 50  0001 C CNN
	1    5910 9230
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J4
U 1 1 60A5DDC4
P 3470 5715
F 0 "J4" H 3388 6632 50  0000 C CNN
F 1 "Conn_01x16" H 3388 6541 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 3470 5715 50  0001 C CNN
F 3 "~" H 3470 5715 50  0001 C CNN
	1    3470 5715
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60490A2D
P 2895 9380
F 0 "C3" H 3010 9426 50  0000 L CNN
F 1 "1uF" H 3010 9335 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2933 9230 50  0001 C CNN
F 3 "~" H 2895 9380 50  0001 C CNN
	1    2895 9380
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 60AD4F01
P 3345 9275
F 0 "C4" H 3460 9321 50  0000 L CNN
F 1 "10nF" H 3460 9230 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3383 9125 50  0001 C CNN
F 3 "~" H 3345 9275 50  0001 C CNN
	1    3345 9275
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 60AD1E7A
P 2070 9075
F 0 "F1" V 1845 9075 50  0000 C CNN
F 1 "Polyfuse" V 1936 9075 50  0000 C CNN
F 2 "Fuse:Fuse_1206_3216Metric" H 2120 8875 50  0001 L CNN
F 3 "~" H 2070 9075 50  0001 C CNN
	1    2070 9075
	0    1    1    0   
$EndComp
$Comp
L MyTanSy:MyAMS1117-3.3V U1
U 1 1 603D74A1
P 6590 8755
F 0 "U1" H 6540 9020 50  0000 C CNN
F 1 "MyAMS1117-3.3V" H 6540 8929 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 6590 8955 50  0001 C CNN
F 3 "" H 6590 8955 50  0001 C CNN
	1    6590 8755
	1    0    0    -1  
$EndComp
Wire Wire Line
	12200 6670 12200 6720
$Comp
L MyTanSy:switch_4p1t sw1
U 1 1 605CC934
P 11965 6640
F 0 "sw1" H 12022 6770 50  0000 C CNN
F 1 "switch_4p1t" H 12022 6679 50  0000 C CNN
F 2 "MyPackaging:SW_Push_1P1T_NO_6x6mm_H9.5mm" H 12015 6615 50  0001 C CNN
F 3 "" H 12015 6615 50  0001 C CNN
	1    11965 6640
	-1   0    0    1   
$EndComp
Wire Wire Line
	12200 6670 12200 6545
Wire Wire Line
	12200 6545 12085 6545
Connection ~ 12200 6670
Wire Wire Line
	12900 6270 12075 6270
Wire Wire Line
	12075 6270 12075 6400
NoConn ~ 11730 6400
NoConn ~ 11735 6545
Wire Wire Line
	14135 6360 14135 6175
NoConn ~ 13785 6175
NoConn ~ 13780 6030
$Comp
L MyTanSy:switch_4p1t sw2
U 1 1 6071A730
P 14015 6270
F 0 "sw2" H 14073 5835 50  0000 C CNN
F 1 "switch_4p1t" H 14073 5926 50  0000 C CNN
F 2 "MyPackaging:SW_Push_1P1T_NO_6x6mm_H9.5mm" H 14065 6245 50  0001 C CNN
F 3 "" H 14065 6245 50  0001 C CNN
	1    14015 6270
	-1   0    0    1   
$EndComp
Wire Wire Line
	14300 6030 14125 6030
Wire Wire Line
	14300 6030 14300 6345
Connection ~ 3795 5315
$Comp
L Device:R R2
U 1 1 60664F6A
P 4370 5615
F 0 "R2" V 4440 5661 50  0000 L CNN
F 1 "10k" V 4445 5440 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4300 5615 50  0001 C CNN
F 3 "~" H 4370 5615 50  0001 C CNN
	1    4370 5615
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3670 6115 4145 6115
Wire Wire Line
	3670 6215 4145 6215
Wire Wire Line
	3670 5615 4220 5615
Wire Wire Line
	4520 5615 4845 5615
Wire Wire Line
	3670 6315 4120 6315
Wire Wire Line
	3670 5415 4145 5415
Wire Wire Line
	3670 5515 4145 5515
Wire Wire Line
	3670 5715 4145 5715
Wire Wire Line
	3670 5815 4145 5815
Wire Wire Line
	3670 5915 4145 5915
Wire Wire Line
	3670 6015 4145 6015
Text Label 3895 5915 2    50   ~ 0
PB5
Text Label 3920 6115 2    50   ~ 0
PB3
Text Label 3895 6015 2    50   ~ 0
PB4
Text Label 3895 5815 2    50   ~ 0
PB6
Text Label 3895 5715 2    50   ~ 0
PB7
Text Label 3895 5515 2    50   ~ 0
PB8
Text Label 3895 5415 2    50   ~ 0
PB9
Text Label 4795 5615 2    50   ~ 0
BOOT0
Text Label 3995 6215 2    50   ~ 0
PA15
Text Label 4045 6315 2    50   ~ 0
SWCLK
$Comp
L Connector_Generic:Conn_01x12 J2
U 1 1 60613949
P 2125 7140
F 0 "J2" H 2043 7857 50  0000 C CNN
F 1 "Conn_01x12" H 2043 7766 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 2125 7140 50  0001 C CNN
F 3 "~" H 2125 7140 50  0001 C CNN
	1    2125 7140
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2040 4370 2040 4465
Wire Wire Line
	1840 4370 1940 4370
Connection ~ 1940 4370
Wire Wire Line
	1940 4370 2040 4370
Wire Wire Line
	2140 4465 2140 4340
Wire Wire Line
	2140 4340 2240 4340
$Comp
L Connector_Generic:Conn_01x12 J3
U 1 1 6074C3BB
P 2340 4665
F 0 "J3" V 2465 4611 50  0000 C CNN
F 1 "Conn_01x12" V 2556 4611 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 2340 4665 50  0001 C CNN
F 3 "~" H 2340 4665 50  0001 C CNN
	1    2340 4665
	0    -1   1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J1
U 1 1 6074D814
P 720 5770
F 0 "J1" H 638 6487 50  0000 C CNN
F 1 "Conn_01x12" H 638 6396 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 720 5770 50  0001 C CNN
F 3 "~" H 720 5770 50  0001 C CNN
	1    720  5770
	-1   0    0    -1  
$EndComp
$Comp
L MyTanSy:MM32F031C8T6 U2
U 1 1 608B0327
P 8395 5795
F 0 "U2" H 9335 4945 50  0000 L CNN
F 1 "MM32F031C8T6" H 9315 5050 50  0000 L CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 7185 6535 50  0001 C CNN
F 3 "" H 7185 6535 50  0001 C CNN
	1    8395 5795
	1    0    0    -1  
$EndComp
Wire Wire Line
	8545 6800 8545 7310
$Comp
L power:GND #PWR0101
U 1 1 604BEDFD
P 8545 7310
F 0 "#PWR0101" H 8545 7060 50  0001 C CNN
F 1 "GND" V 8550 7182 50  0000 R CNN
F 2 "" H 8545 7310 50  0001 C CNN
F 3 "" H 8545 7310 50  0001 C CNN
	1    8545 7310
	1    0    0    -1  
$EndComp
Text Label 7820 4560 3    50   ~ 0
BOOT0
Wire Wire Line
	7820 4810 7820 4560
Wire Wire Line
	7580 4810 7580 4300
$Comp
L power:GND #PWR0102
U 1 1 607A0EA9
P 7580 4300
F 0 "#PWR0102" H 7580 4050 50  0001 C CNN
F 1 "GND" V 7585 4172 50  0000 R CNN
F 2 "" H 7580 4300 50  0001 C CNN
F 3 "" H 7580 4300 50  0001 C CNN
	1    7580 4300
	-1   0    0    1   
$EndComp
Wire Wire Line
	6920 6075 6410 6075
$Comp
L power:GND #PWR0103
U 1 1 6082908E
P 6410 6075
F 0 "#PWR0103" H 6410 5825 50  0001 C CNN
F 1 "GND" V 6415 5947 50  0000 R CNN
F 2 "" H 6410 6075 50  0001 C CNN
F 3 "" H 6410 6075 50  0001 C CNN
	1    6410 6075
	0    1    1    0   
$EndComp
NoConn ~ 6920 5530
Wire Wire Line
	7035 8680 7035 9005
Wire Wire Line
	8200 1570 8200 1355
Connection ~ 8200 1570
Wire Wire Line
	8595 1570 8600 1570
Wire Wire Line
	8600 1570 9015 1570
$Comp
L Device:C C15
U 1 1 60459AD9
P 9015 1870
F 0 "C15" H 9130 1916 50  0000 L CNN
F 1 "1uF" H 9130 1825 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9053 1720 50  0001 C CNN
F 3 "~" H 9015 1870 50  0001 C CNN
	1    9015 1870
	1    0    0    -1  
$EndComp
Wire Wire Line
	9015 1720 9015 1570
Connection ~ 9015 1570
Wire Wire Line
	9015 1570 9415 1570
Wire Wire Line
	9015 2020 9015 2195
Wire Wire Line
	8600 2195 9015 2195
Connection ~ 8600 2195
Connection ~ 9015 2195
Connection ~ 7550 2195
Connection ~ 8345 1570
Wire Wire Line
	8345 1570 8600 1570
Wire Wire Line
	7150 1570 7550 1570
Text Label 8200 1505 1    50   ~ 0
3V3
Text Label 7035 8810 1    50   ~ 0
3V3
Text Label 6995 1525 1    50   ~ 0
VDDA
Text Label 1840 4310 1    50   ~ 0
3V3
Text Label 14135 6360 1    50   ~ 0
3V3
Text Label 3830 5115 0    50   ~ 0
3V3
Text Label 12900 5855 1    50   ~ 0
3V3
$Comp
L power:+5V #PWR012
U 1 1 6071D5EB
P 5460 8630
F 0 "#PWR012" H 5460 8480 50  0001 C CNN
F 1 "+5V" H 5475 8803 50  0000 C CNN
F 2 "" H 5460 8630 50  0001 C CNN
F 3 "" H 5460 8630 50  0001 C CNN
	1    5460 8630
	1    0    0    -1  
$EndComp
Text Label 1110 6370 0    50   ~ 0
in5V
Text Label 2440 4115 3    50   ~ 0
NRST
Wire Wire Line
	2440 4465 2440 4115
Text Label 2400 6940 0    50   ~ 0
PA8
Wire Wire Line
	2325 6940 2800 6940
Text Label 2535 6740 2    50   ~ 0
PA10
Text Label 2345 6840 0    50   ~ 0
PA9
Wire Wire Line
	2325 6740 2535 6740
Wire Wire Line
	2325 6840 2540 6840
Text Label 2600 7040 2    50   ~ 0
PB15
Text Label 2600 7140 2    50   ~ 0
PB14
Wire Wire Line
	2325 7040 2800 7040
Wire Wire Line
	2325 7140 2800 7140
$EndSCHEMATC
