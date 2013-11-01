avr_ObjButtonLib
=============

This is a more object-orientated button-library for AVR Microcontrollers written in C.

This library consits of:
 - BUTTON.h
 - BUTTON.c

and offers:
 - handle infinite number of buttons with no duplicate code
 - functions:
    - BUTTON_INIT: Init a button
    - BUTTON_GET: get status of a button (pressed/released)
    - BUTTON_WAIT: wait for a button to be pressed or released with timeout
    - BUTTON_ACK: let the user acknowledge something with timeout

There are examples in main.c, which show the basics.
