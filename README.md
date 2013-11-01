avr_ObjLcdLib
=============

This is a more object-orientated HD44780 LCD-library for AVR Microcontrollers written in C.

This library consits of:
 - BUTTON.h
 - BUTTON.c
and offers:
 - handle infinite number of buttons with no duplicate code
 - functions:
    - BUTTON_INIT: Init a button
    - BUTTON_GET: get status of a button (pressed/released)
    - BUTTON_WAIT: wait for a button to be pressed or released with timeout

There's a example in main.c, which shows the basics.