#include "pic.h"

//Pulsadores 
#define N1 RB0
#define N2 RA4

//Electrovalvulas
#define XV1 RB1
#define XV2 RB2

void imprimir(){
	int i;	

	PORTD=0x73; //pongo unidades
	RB4=1; //activo transistor
	for(i=0; i<200;i++); //espero
	RB4=0;
	
	PORTD=0x38; 
	RB5=1; 
	for(i=0; i<200;i++); //espero	
	RB5=0;

	PORTD=0x79;
	RB6=1; //activo transistor
	for(i=0; i<200;i++); //espero
	RB6=0;
	
	PORTD=0x76;
	RB7=1; //activo unidades	
	for(i=0; i<200;i++); //espero
	RB7=0;

}

void __init (void)
{
	 // Lo primero, configurar los pines
	ADCON1 = 0x0D; // Se configura RB0 como entrada digital
	 // RA4 ya está configurado por defecto como entrada digital
	TRISA = 0x10;
	TRISB = 0x01;
	
	 //Condición inicial, nivel por debajo de N1 y ambos LEDs apagados
	XV1 = 1;
	XV2 = 1;
	RB3 = 1;	// Se apaga el LED de la placa para facilitar su uso
	
}

void main(void){
	//Entradas
	TRISA4 = 0; //N2 
	TRISB0 = 0; //N1

	//Salidas
	TRISB1 = 1; //XV1
	TRISB2 = 1; //XV2

	while(1){
		//Condicion inicial
		XV1 = 1;
		XV2 = 1;

		//Nivel llega a N1
		if(!N1){
			while(!N2 && !N1) XV1 = 0;
		};
	
		//Nivel llega a N2
		if(N2){		
			while(!N2 && !N1){
				XV1 = 0;
				XV2 = 0;
			}
		}
		else if(N2 && !N1){
			//Situacion error	
			while(!N1){
				XV1 = 1;
				XV2 = 1;
				imprimir();//Mostrar mensaje HELP
			}//Fin while
		}//Fin else if
			
		//Otra situacion error
		if(XV1==0 && XV1==0 && !N1){
			XV1 = 1;
			XV2 = 1;
			imprimir();//Mostrar mensaje HELP
		}

	}//Fin while(1)
	

} 
