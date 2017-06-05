/* Libreria de retardos que emplea el Timer 2 del PIC18 */

#include "pic.h"

void DelayUs(unsigned char x) {
unsigned int cuenta;

if (x<20) return;  //no temporiza menos de 20 useg ni 
 // usamos TIMER3 de PIC18
 T3RD16=0;  //selecciona contador 
 TMR3CS=0; //selecciona reloj interno
 T3CKPS0=T3CKPS1=0;  //desactiva preescaler
//cada 5 ticks un microseg a 20MHz 
 cuenta=(65536-(((unsigned int)x)*5)); 
 TMR3ON=0;  //desactiva contador
 TMR3IF=0;			//baja bandera
 TMR3H=(cuenta>>8);
 TMR3L=(cuenta&0x00FF);
 TMR3ON=1;  //activa contador
 while(!TMR3IF);	//espera a que suba
 TMR3ON=0;  //desactiva contador
//	for (cuenta=0;cuenta<50;cuenta++);
 }

void DelayBigUs(unsigned int cnt) {
	unsigned char	i;

	i = (unsigned char)(cnt>>8);
	while(i>=1) 
	{
		i--;		
		DelayUs(253);
	} 
	DelayUs((unsigned char)(cnt & 0xFF));
}

void DelayMs(unsigned char cnt) {
	unsigned char	i;
	do {
		i = 4;
		do {
			DelayUs(250);
		} while(--i);
	} while(--cnt);
}

void DelayBigMs(unsigned int cnt) {
	unsigned char	i;
	do {
		i = 4;
		do {
			DelayUs(250);
		} while(--i);
	} while(--cnt);
}

void DelayS(unsigned char cnt) {
	unsigned char i;
	do {
		i = 4;
		do {
			DelayMs(250);
		} while(--i);
	} while(--cnt);
}

