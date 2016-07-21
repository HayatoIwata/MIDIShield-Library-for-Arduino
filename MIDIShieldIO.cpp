/* ------------------------------------------------------------ */
/* MIDIShieldIO.cpp                                             */
/* This source only for Arduion Uno R3 + Sparkfun MIDI Shield.  */
/* Necessary to custom pull-up circuit on MIDI Shield board.    */
/* Coded by Hayato Iwata (2016/07/21)                           */
/* ------------------------------------------------------------ */

#include "arduino.h"
#include "MIDIShieldIO.h"


/* LED control class */

/* Constructor */
LED::LED(byte Pin)
{
	m_Pin = Pin;
}

/* Initialize */
void LED::initialize()
{
	pinMode(m_Pin, OUTPUT);
	digitalWrite(m_Pin, HIGH);
}

/* LED turn on */
void LED::on()
{
	digitalWrite(m_Pin, LOW);
}

/* LED turn off */
void LED::off()
{
	digitalWrite(m_Pin, HIGH);
}


/* Button control class */

/* Constructor */
BUTTON::BUTTON(byte Pin) :
	m_Status(0),
	m_Switch(1),
	m_Counter(0),
	m_LED(NULL)
{
	m_Pin = Pin;
}

/* Initialize */
void BUTTON::initialize()
{
	pinMode(m_Pin, INPUT);
	
	m_Counter = 0;
	m_Status = 0;
	m_Switch = 1;
}

/* Setup of LED link */
void BUTTON::linkLED(LED* led)
{
	if (led != NULL)
	{
		m_LED = led;

		if (m_Status == 1)	m_LED->on();
		else				m_LED->off();
	}
	else
	{
		m_LED = NULL;
	}
}

/* Update status */
void BUTTON::updateStatus()
{
	if (m_Counter == 0)
	{
		bool val = digitalRead(m_Pin);

		if (m_Switch == 1 && val == 0)
		{
			m_Switch = 0;
		}
		if (m_Switch == 0 && val == 1)
		{
			m_Status != m_Status;
			if (m_Status == 1)	m_LED->on();
			else				m_LED->off();

			m_Switch = 1;
			m_Counter = 0;// ANTI_CHATTERING;
		}
	}
	else
	{
		m_Counter--;
	}
}

/* Get current status */
bool BUTTON::getStatus()
{
	return m_Status;
}


/* Volume control class */

/* Constructor */
VOLUME::VOLUME(byte Pin)
{
	m_Pin = Pin;
}

/* Get value           */
/* The value is 0~1023 */
uint16_t VOLUME::getValue()
{
	return analogRead(m_Pin);
}