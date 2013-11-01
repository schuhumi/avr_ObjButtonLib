#ifndef _BUTTON_h_
#define _BUTTON_h_

typedef struct {
	volatile uint8_t		*port;
	volatile uint8_t		*pin;
	volatile uint8_t		*ddr;
	uint8_t				pinNr;
	uint8_t				internPullup;
	uint8_t				bounce_ms;
} type_BUTTON;

void BUTTON_INIT (type_BUTTON *device);
uint8_t BUTTON_GET (type_BUTTON *device);
uint8_t BUTTON_WAIT (type_BUTTON *device, uint8_t press_release, uint16_t timeout_ms);
uint8_t BUTTON_ACK (type_BUTTON *device, uint16_t timeout_ms);

#define	BUTTON_PRESS	False
#define BUTTON_RELEASE	True
#define NO_TIMEOUT		0

#define	Success	0			// Linux-like
#define	Error 	1

#define	False	0
#define	True	1

#endif
