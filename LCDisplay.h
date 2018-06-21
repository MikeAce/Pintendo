/*
 * File:   LCDisplay.h
 * Author: Andreas
 *
 * Created on 4. Oktober 2015, 14:27
 */

#ifndef LCDISPLAY_H
#define	LCDISPLAY_H

extern void lcdHome        () ;
extern void lcdClear       () ;
extern void lcdSendCommand (uint8_t command) ;
extern void lcdPosition    (int x, int y) ;
extern void lcdPutchar     (uint8_t data) ;
extern void lcdPuts        ( char *string) ;
extern void lcdPrintf      (char *message, ...) ;

extern int  lcdInit (int rows, int cols, int rs, int strb,
	int d4, int d5, int d6, int d7) ;
extern int lcdClose();

#endif	/* LCDISPLAY_H */

