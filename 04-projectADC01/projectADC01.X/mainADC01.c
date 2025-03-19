/*
 * File:   mainADC01.c
 * Author: pedro
 *
 * Created on 12 de marzo de 2025, 01:16 PM
 */

//06 MARZO 2025
//Esta practica esta realizada con
//el oscilador interno

#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "configADC01.h"
#include "configOSCadc01.h"


void adc_init(void);

int main()
{

    int adcval;
    //CLKDIVbits.PLLPOST=0x00;
    //CLKDIVbits.PLLPRE=0x00;
    adc_init();
    while(1)
    {
    // DAR INICIO AL MUESTREO
        AD1CON1bits.SAMP=1;
        __delay32(100);
        AD1CON1bits.SAMP=0;
        AD1CON1bits.DONE=0;
        //AUTOMATICAMENTE SE INICIA LA CONVERSION
        while(!AD1CON1bits.DONE);
        //CONVERCION HECHA
        adcval=ADC1BUF0;
        LATB=adcval;
    }
    //return ();
    //return (EXIT_SUCCESS);
}
//Definir la funci�n adc_init()
void adc_init(void)
{//PARA LA CONFIGURACION DE ADC DE DSPIC
  //RA0 COMO PIN ANAL�GICO
    AD1PCFGL=0XFFFE;//ANALOGICO
    TRISB=0x0000;
    //12 bits
    AD1CON1bits.AD12B=1;
    // Representaci�n de n�meros enteros positivos
    AD1CON1bits.FORM=0b00;
    // El inicio de muestreo sea manual
    AD1CON1bits.ASAM=0;
    // El inicio de la conversi�n sea manual
    AD1CON1bits.SSRC=0b000;
    // Elegir canal
    AD1CON2bits.CHPS=0b00;
    // VREF+ = AVDD Y VREF- = AVSS
    AD1CON2bits.VCFG=0b000;
    //
    AD1CON3bits.ADRC=0;
    AD1CON3bits.ADCS=2;
    AD1CHS0bits.CH0NA=0;// VREF- ES EL PIN NEGATIVO
    AD1CHS0bits.CH0SA=0;// VREF+ ES EL PIN POSITIVO
    // Encender el ADC
    AD1CON1bits.ADON=1;
    
}