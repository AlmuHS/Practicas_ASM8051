/* libreria de refresco LED de SURE */
#include "pic.h"
#include "delay.h"  


void led_init(void){
TRISB = 0x0F;
TRISD=0;
}


unsigned char tabla_7seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void refresca(unsigned char hor,unsigned char min) {
unsigned char tmp1,tmp2,tmp3,tmp4;

tmp3=PORTB;
PORTB=0;  // Apago todo
tmp4=PORTD;
PORTD=0x00; //Apago todos los displays
tmp1=TRISB;
TRISB=0x00;
tmp2=TRISD;
TRISD=0x00;

//comienzo por las unidades más a la izq
PORTD=tabla_7seg[min%10]; //pongo unidades
RB4=1; //activo transistor
DelayMs(5); //espero
RB4=0;
//sigo con las decenas
PORTD=tabla_7seg[min/10]; //pongo decenas
RB5=1; //activo unidades
DelayMs(5); //espero
RB5=0;
//sigo con las unidades del secadero 1 siguiente a la izq
PORTD=tabla_7seg[hor%10]; //pongo unidades
RB6=1; //activo transistor
DelayMs(5); //espero
RB6=0;
//sigo con las decenas
PORTD=tabla_7seg[hor/10]; //pongo decenas
RB7=1; //activo unidades	
DelayMs(5); //espero
RB7=0;
TRISB=tmp1;
TRISD=tmp2;
PORTB=tmp3;
PORTD=tmp4;
}
