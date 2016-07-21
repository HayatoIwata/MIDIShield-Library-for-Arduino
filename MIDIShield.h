/* ------------------------------------------------------------ */
/* MIDIShield.h                                                 */
/* This source only for Arduion Uno R3 + Sparkfun MIDI Shield.  */
/* Necessary to custom pull-up circuit on MIDI Shield board.    */
/* Coded by Hayato Iwata (2016/07/21)                           */
/* ------------------------------------------------------------ */

#pragma once

/* Include files */
#include<MIDI.h>
#include<SoftwareSerial.h>

#include "MIDIShieldIO.h"

/* Hardware instance generation */
LED LED_G(6);
LED LED_R(7);
BUTTON button1(4);
BUTTON button2(3);
BUTTON button3(2);
VOLUME volume1(0);
VOLUME volume2(1);

/* Setup of SoftwareSerial MIDI */
SoftwareSerial SoftSerial(8, 9);
MIDI_CREATE_INSTANCE(SoftwareSerial, SoftSerial, MIDI);

/* IO initialize function */
void initializeMIDIShield()
{
	LED_G.initialize();
	LED_R.initialize();
	button1.initialize();
	button2.initialize();
	button3.initialize();

	MIDI.begin();
}

/* Update button status function */
void buttonUpdate()
{
	button1.updateStatus();
	button2.updateStatus();
	button3.updateStatus();
}