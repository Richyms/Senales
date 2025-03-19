/*
 * File:   mainadc00.c
 * Author: Ricardo Mora Santillán
 *
 * Created on 6 de marzo de 2025, 12:41 PM
 */

#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include "configOSCadc00.h"
#include "configadc00.h"

void adc_int(void);

int main(){
    
    int adcval;
    //CLKDIVbits.PLLPOST=0x00;
    //CLKDIVbits.PLLPRE=0x00;
    
    adc_int();
    while(1){
        //DAR INICIO AL MUESTREO     
        AD1CON1bits.SAMP=1;
        __delay32 (100);
        AD1CON1bits.SAMP=0;
        AD1CON1bits.DONE=0;
        //AUTOMATICAMENTE SE INICIA LA CONVERSION
        while(!AD1CON1bits.DONE);
            //CONVERSION HECHA
            adcval=ADC1BUF0;
            LATB = adcval;
    }
    
    //Return ();
    //return (EXIT_SUCESS);
}

//Definir la funcion de adc_init()
void adc_init(void){
    //PARA LA CONFIGURACIÓN DE ADC DE DSPIC
    //RA0 COMO PIN ANALOGICO
    AD1PCFGL=0xFFFE;//ANALOGICO
    TRISB=0x000;
    //12 bits
    AD1CON1bits.AD12B=1;
    //Presentación de números enteros positivos
    AD1CON1bits.FORM=0b00;
    //El inicio del muestreo sea manual
    AD1CON1bits.ASAM=0;
    //El inicio de la conversión sea manual
    AD1CON1bits.SSRC=0b000;
    //Elegir canal
    AD1CON2bits.CHPS=0b00;
    //VREF+ = AVDD Y VREF- = AVSS
    AD1CON2bits.VCFG=0b000;
    //
    AD1CON3bits.ADRC=0;
    AD1CON3bits.ADCS=2;
    AD1CHS0bits.CH0NA=0;//VREF- ES EL PIN NEGATIVO
    AD1CHS0bits.CH0SA=0;//VREF+ ES EL PIN POSITIVO
    // Encender el adc
    AD1CON1bits.ADON=1;
}