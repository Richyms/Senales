/*
 * File:   mainOsc02.c
 * Author: Ricardo Mora Santillan Ricardo
 *
 * Created on 5 de marzo de 2025, 12:15 PM
 */
#include <stdio.h>
#include "xc.h"
#include "configOsc02.h"
#include "Osc02.h"

#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#endif;


int main(void) {
    OSCCONbits.NOSC = 0b000;
    TRISB = 0x0000;
    while(1){
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        __delay32(400000);
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 0;
        __delay32(400000);
    }
    return 0;
}
