#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <bcm2835.h>

#include "LCDisplay.h"


// Commands

#define	LCD_CLEAR	0x01
#define	LCD_HOME	0x02
#define	LCD_ENTRY	0x04
#define	LCD_ON_OFF	0x08
#define	LCD_CDSHIFT	0x10
#define	LCD_FUNC	0x20
#define	LCD_CGRAM	0x40
#define	LCD_DGRAM	0x80

#define	LCD_ENTRY_SH	0x01
#define	LCD_ENTRY_ID	0x02

#define	LCD_ON_OFF_B	0x01
#define	LCD_ON_OFF_C	0x02
#define	LCD_ON_OFF_D	0x04

#define	LCD_FUNC_F	0x04
#define	LCD_FUNC_N	0x08
#define	LCD_FUNC_DL	0x10

#define	LCD_CDSHIFT_RL	0x04


uint8_t rows, cols ;
uint8_t rsPin, strbPin ;
uint8_t dataPins [4] ;

char state;

void writePCF8574(uint8_t pin, uint8_t level)
{

  if(level)
    state |= 1 << pin;
  else
    state &= ~(1 << pin);

  bcm2835_i2c_write (&state, 1);
}


/*
 * strobe:
 *	Toggle the strobe (Really the "E") pin to the device.
 *	According to the docs, data is latched on the falling edge.
 *********************************************************************************
 */

static void strobe ()
{

// Note timing changes for new version of bcm2835_delayMicroseconds ()

  writePCF8574(strbPin, 1) ; bcm2835_delayMicroseconds (50) ;
  writePCF8574(strbPin, 0) ; bcm2835_delayMicroseconds (50) ;
}


/*
 * sentDataCmd:
 *	Send an data or command byte to the display.
 *********************************************************************************
 */

static void sendDataCmd (uint8_t data)
{
  uint8_t i, d4 ;


    d4 = (data >> 4) & 0x0F;
    for (i = 0 ; i < 4 ; ++i)
    {
      writePCF8574(dataPins [i], (d4 & 1)) ;
      d4 >>= 1 ;
    }
    strobe () ;

    d4 = data & 0x0F ;
    for (i = 0 ; i < 4 ; ++i)
    {
      writePCF8574(dataPins [i], (d4 & 1)) ;
      d4 >>= 1 ;
    }

  strobe () ;
}


/*
 * putCommand:
 *	Send a command byte to the display
 *********************************************************************************
 */

static void putCommand (uint8_t command)
{
  writePCF8574(rsPin,   0) ;
  sendDataCmd  (command) ;
}

static void put4Command (uint8_t command)
{
  uint8_t i ;

  writePCF8574(rsPin,   0) ;

  for (i = 0 ; i < 4 ; ++i)
  {
    writePCF8574(dataPins [i], (command & 1)) ;
    command >>= 1 ;
  }
  strobe () ;
}


/*
 *********************************************************************************
 * User Code below here
 *********************************************************************************
 */

/*
 * lcdHome: lcdClear:
 *	Home the cursor or clear the screen.
 *********************************************************************************
 */

void lcdHome ()
{
  putCommand (LCD_HOME) ;
}

void lcdClear ()
{
  putCommand (LCD_CLEAR) ;
}


/*
 * lcdSendCommand:
 *	Send any arbitary command to the display
 *********************************************************************************
 */

void lcdSendCommand (uint8_t command)
{
  putCommand (command) ;
}

/*
 * lcdPosition:
 *	Update the position of the cursor on the display
 *********************************************************************************
 */


void lcdPosition (int x, int y)
{
  static uint8_t rowOff [4] = { 0x00, 0x40, 0x14, 0x54 } ;

  putCommand (x + (LCD_DGRAM | rowOff [y])) ;
}


/*
 * lcdPutchar:
 *	Send a data byte to be displayed on the display
 *********************************************************************************
 */

void lcdPutchar (uint8_t data)
{
  writePCF8574 (rsPin, 1) ;
  sendDataCmd (data) ;
}


/*
 * lcdPuts:
 *	Send a string to be displayed on the display
 *********************************************************************************
 */

void lcdPuts (char *string)
{
  while (*string)
    lcdPutchar (*string++) ;
}


/*
 * lcdPrintf:
 *	Printf to an LCD display
 *********************************************************************************
 */

void lcdPrintf (char *message, ...)
{
  va_list argp ;
  char buffer [1024] ;

  va_start (argp, message) ;
    vsnprintf (buffer, 1023, message, argp) ;
  va_end (argp) ;

  lcdPuts (buffer) ;
}


/*
 * lcdInit:
 *	Take a lot of parameters and initialise the LCD, and return a handle to
 *	that LCD, or -1 if any error.
 *********************************************************************************
 */

int lcdInit (int rows, int cols, int rs, int strb,
	int d4, int d5, int d6, int d7)
{

  bcm2835_i2c_begin ();
  bcm2835_i2c_setSlaveAddress (0x3f);
  state = 0;
  bcm2835_i2c_write (&state, 1);

  uint8_t func ;
  int i ;


// Simple sanity checks
  if ((rows < 0) || (rows > 20))
    return -1 ;

  if ((cols < 0) || (cols > 20))
    return -1 ;

// Create a new LCD:

  rsPin   = rs ;
  strbPin = strb ;
  rows    = rows ;
  cols    = cols ;

  dataPins [0] = d4 ;
  dataPins [1] = d5 ;
  dataPins [2] = d6 ;
  dataPins [3] = d7 ;

  writePCF8574 ( rsPin,   0) ;
  writePCF8574 (strbPin, 0) ;

  for (i = 0 ; i < 4 ; ++i)
  {
    writePCF8574 (dataPins [i], 0) ;
  }
  bcm2835_delay (35) ; // mS

// 4-bit mode?
//	OK. This is a PIG and it's not at all obvious from the documentation I had,
//	so I guess some others have worked through either with better documentation
//	or more trial and error... Anyway here goes:
//
//	It seems that the controller needs to see the FUNC command at least 3 times
//	consecutively - in 8-bit mode. If you're only using 8-bit mode, then it appears
//	that you can get away with one func-set, however I'd not rely on it...
//
//	So to set 4-bit mode, you need to send the commands one nibble at a time,
//	the same three times, but send the command to set it into 8-bit mode those
//	three times, then send a final 4th command to set it into 4-bit mode, and only
//	then can you flip the switch for the rest of the library to work in 4-bit
//	mode which sends the commands as 2 x 4-bit values.

    func = LCD_FUNC | LCD_FUNC_DL ;			// Set 8-bit mode 3 times
    put4Command (func >> 4) ; bcm2835_delay (35) ;
    put4Command (func >> 4) ; bcm2835_delay (35) ;
    put4Command (func >> 4) ; bcm2835_delay (35) ;
    func = LCD_FUNC ;					// 4th set: 4-bit mode
    put4Command (func >> 4) ; bcm2835_delay (35) ;


  if (rows > 1)
  {
    func |= LCD_FUNC_N ;
    putCommand (func) ; bcm2835_delay (35) ;
  }

// Rest of the initialisation sequence

  putCommand (LCD_ON_OFF  | LCD_ON_OFF_D) ;   bcm2835_delay (2) ;
  putCommand (LCD_ENTRY   | LCD_ENTRY_ID) ;   bcm2835_delay (2) ;
  putCommand (LCD_CDSHIFT | LCD_CDSHIFT_RL) ; bcm2835_delay (2) ;
  putCommand (LCD_CLEAR) ;                    bcm2835_delay (5) ;
}

extern int lcdClose()
{
  lcdClear ();
  bcm2835_i2c_end ();
}
