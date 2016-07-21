/* ------------------------------------------------------------ */
/* MIDIShieldIO.h                                               */
/* This source only for Arduion Uno R3 + Sparkfun MIDI Shield.  */
/* Necessary to custom pull-up circuit on MIDI Shield board.    */
/* Coded by Hayato Iwata (2016/07/21)                           */
/* ------------------------------------------------------------ */

#pragma once

#include "arduino.h"

const byte ANTI_CHATTERING = 200;

/* LED control class */
class LED
{
public:

	LED(byte Pin);			/* Constructor */

	void initialize();		/* Initialize method */
	void on();				/* LED turn on method */
	void off();				/* LED turn off method */

private:

	byte m_Pin;

};

/* Button control class */
class BUTTON
{
public:
	
	BUTTON(byte Pin);		/* Constructor */
	
	void initialize();		/* Initialize method */
	void updateStatus();	/* Status update method - necessary to call every time */
	void linkLED(LED* led);	/* Setup LED link (argument: pointer of LED instance) */
	bool getStatus();		/* Get status method */

private:

	byte m_Pin;
	byte m_Counter;
	bool m_Status;
	bool m_Switch;
	LED* m_LED;

};

/* Volume control class */
class VOLUME
{
public:

	VOLUME(byte Pin);		/* Constructor */

	uint16_t getValue();	/* Get value method */

private:

	byte m_Pin;

};