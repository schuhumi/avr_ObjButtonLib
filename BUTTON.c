#include <avr/io.h>
#include <util/delay.h>
#include "BUTTON.h"

void BUTTON_INIT (type_BUTTON *device)
{
	*device->ddr &= ~(1<<(device->pinNr));								// buttonpin -> input
	if(device->internPullup)											// avtivate internal pullups?
		*device->port |= (1<<(device->pinNr));
	else
		*device->port &= ~(1<<(device->pinNr));
}


uint8_t BUTTON_GET (type_BUTTON *device)
{
	return( ~(*device->pin)&(1<<(device->pinNr)) ? True:False);
}

uint8_t BUTTON_WAIT (type_BUTTON *device, uint8_t press_release, uint16_t timeout_ms)
{
	uint8_t timeoutisoff = !timeout_ms;
	
	while( press_release ? (~(*device->pin)&(1<<device->pinNr)) : !(~(*device->pin)&(1<<device->pinNr)) )
	{
		_delay_ms(1);
		timeout_ms--;
		if(!(timeout_ms || timeoutisoff))
			return Error;
	}
	
	/** _delay_ms(device->bounce_ms) not possible because _delay_ms
	 *  expects constant integer (otherwise it won't work with
	 *  compiler optimization enabled) **/
	uint8_t timeCtr = device->bounce_ms;
	while(timeCtr--)
		_delay_ms(1);
	return Success;
}

uint8_t BUTTON_ACK (type_BUTTON *device, uint16_t timeout_ms)
{
	if(BUTTON_WAIT(device, BUTTON_RELEASE, timeout_ms) != Success)
		return Error;
	if(BUTTON_WAIT(device, BUTTON_PRESS, timeout_ms) != Success)
		return Error;
	if(BUTTON_WAIT(device, BUTTON_RELEASE, timeout_ms) != Success)
		return Error;
	return Success;
}
