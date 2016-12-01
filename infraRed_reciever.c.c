
void PPI_Init(void);
void EXPORT_Init(void);


void delay(int time){
	
	int i;
	i = 0x1a*time;
	while(i--);
}

void read_infraRed(void){
	unsigned char infraRed_signal;
	int pushed;
	
	
	
	char * iSTR;	
AlcdInit(0);
		

	while(1){
		DebugClear();
		infraRed_signal = PPI_In(PA);
		



		UartSetBaud(0,115200); // Configure vitesse UART0 à 115200 BPS.
		UartOn(0); // Active l’UART0.

		switch(infraRed_signal){
			case 1:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"bas");
				break;
	
			case 2:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"droite");
				break;

			case 3:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"gauche");
				break;
			case 8:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"off");
				break;
			case 16:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"haut");
				break;
			case 17:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"Internet");
				break;
			case 68:
				AlcdClear(0);
				AlcdLocate(0, 0, 0);
				AlcdPrint(0,"entre");

				break;

		default:
			break;		
			}
		


		DebugCHAR(infraRed_signal, DEC);
		HeapWrChar(0, infraRed_signal);
		delay(10);
		
	
	}



}


void main(void){

	int i;
	
	PPI_Init();
	EXPORT_Init();
	
	RtcOn();

	read_infraRed();

}

void PPI_Init(void){ //Initialisation des ports PA, PB et PC en entree

	PPI_SetMode(PA,0xff); PPI_Out(PA, 0xff);
	PPI_SetMode(PB,0xff); PPI_Out(PB, 0xff);
	PPI_SetMode(PC,0xff); PPI_Out(PC, 0xff);


	// Initialisation du port PD en sortie et extinction des leds de la platione

	PPI_SetMode(PD,0x00);
	PPI_Out(PD, 0xff);
}

void EXPORT_Init(void){

	//Initialisation des ports EXPA, EXPB et EXPD en entree (haute impedance)

	PortSetMode(EXPA, 0xff);
	PortSetMode(EXPB, 0xff);
	PortSetMode(EXPC, 0xff);
	PortSetMode(EXPD, 0xff);

	PortOut(EXPA, 0x00);
	PortOut(EXPB, 0x00);
	PortOut(EXPC, 0x00);
	PortOut(EXPD, 0x00);

}






