/*
 * File:   mainOsc01.c
 * Author: ricar
 *
 * Created on 24 de febrero de 2025, 01:22 PM
 */

#include <stdio.h>
#include "xc.h"
#include "configOsc01.h"
#include "osc01.h"

#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#endif;


int main(void) {
    OSCCONbits.NOSC = 0b000;
    TRISB = 0x0000;
    while(1){
        LATBbits.LATB15 = 1;
        LATBbits.LATB0 = 1;
        __delay32(400000);
        LATBbits.LATB15 = 0;
        LATBbits.LATB0 = 0;
        __delay32(400000);
    }
    return 0;
}
