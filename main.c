#include <avr/io.h>
#include "BUTTON.h"			// Don't forget "BUTTON.c" in makefile!! (SRC = $(TARGET).c BUTTON.c)

int main (void)
{	
	type_BUTTON button_A;
	type_BUTTON button_B;
	
	/// Configure Devices //////////////////////////////////////
	// Buttion A configuration
		button_A.ddr = &DDRC;
		button_A.port = &PORTC;
		button_A.pin = &PINC;
		button_A.pinNr = PC7;
		button_A.internPullup = True;
		button_A.bounce_ms = 40;
		
	// Buttion B configuration
		button_B.ddr = &DDRC;
		button_B.port = &PORTC;
		button_B.pin = &PINC;
		button_B.pinNr = PC4;
		button_B.internPullup = True;
		button_B.bounce_ms = 40;		
	/// END Configure Devices //////////////////////////////////
	
	/// INIT Devices ///////////////////////////////////////////
	// INIT buttons	
		BUTTON_INIT(&button_A);
		BUTTON_INIT(&button_B);
	/// END INIT Devices ///////////////////////////////////////
	
	while (1)	/// MAIN LOOP
	{
		if(BUTTON_GET(&button_A))
		{
			// Do this or that
		}
		
		if(BUTTON_WAIT(&button_B, BUTTON_RELEASE, 2000) == Success)
		{
			// button was released within 2000ms
		}
		else
		{
			// timeout of 2000ms ran out
		}
		
	}

	return 0;
}
