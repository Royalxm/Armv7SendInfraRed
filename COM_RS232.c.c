
#define uartPORTnum	1
#define txPACKETsize 	1


void PPI_Init(void);
void EXPORT_Init(void);


void delay(int time){
	
	int i;
	i = 0x1a*time;
	while(i--);
}

void UART_transmit(void){
	unsigned char infraRed_signal;
		while(1){
		DebugClear();
		infraRed_signal = HeapRdChar(0);
		DebugCHAR(infraRed_signal, DEC);
		UartWrite(uartPORTnum, infraRed_signal);
		delay(20);
	
	}


}


void main(void){

	int i;

	PPI_Init();
	EXPORT_Init();
	
	RtcOn();

	UartSetBaud(uartPORTnum, 9600);
	UartOn(uartPORTnum);
	UartSetPacketSize(uartPORTnum, txPACKETsize );

	UART_transmit();

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






