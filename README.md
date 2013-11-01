avr_ObjButtonLib
================

This is a more object-orientated button-library for AVR Microcontrollers written in C.

This library consits of:
 - LCD.h
 - LCD.c
and offers:
 - control infinite number of LCDs with no duplicate code
 - 2x4Bit data-transfer + EN-Pin + RS-Pin = Only 6 pins wasted for LCD
 - functions:
    - LCD_INIT: Init a LCD
    - LCD_CLEAR: Clear the screen
    - LCD_HOME: Put the cursor to 0/0
    - LCD_INT: Print integer variables
    - LCD_INTX: Print integer variables with your choice of base + TODO: fixed number of digits
    - LCD_FLOAT: Print float variables
    - LCD_FLOATX: Print float variables with fixed number of digts behind commata + TODO: fixed number in front of commata
    - LCD_STRING: Print strings
    - LCD_POS: Put the cursor on any position
    - LCD_GENERATECHAR: Easily create your very own characters

There's a example in main.c, which shows the basics.

Known issues:
 - For some reason some LCDs don't init properly at every second atempt

TODO:
 - Fixed number of digits for INTX
 - Fixed number of digits in front of commata for FLOATX
