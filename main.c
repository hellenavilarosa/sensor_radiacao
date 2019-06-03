#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "lib/bits.h"
#include "lib/avr_gpio.h"
#include "lib/avr_timer.h"
#include "lib/avr_extirq.h"
#include "sensor.h"
#include <util/delay.h>
#include "lib/avr_adc.h"
#include "lib/avr_usart.h"
#include "lib/avr_spi.h"
#include "globalDefines.h"
#include "ATmega328.h"
#include "ff.h"
#include "sensor.h"
#include "ds1307.h"
#include <string.h>


#define HORA		10
#define MINUTO		56
#define SEGUNDO		00

#define ANO			19
#define MES			6
#define DIA			3
#define DIA_SEMANA	1


#define LED_PIN	PB0
// AD0-a0(sensor radiacao)

//cartao SD
// CS - Pino 4
//MOSI - PINO 11
//SCK - PINO 13
//MISO - PINO 12

//rtc
//SCL - PINO 28
//SDA - PINO 27
//DS - PINO 
 
// System definitions ----------------------------------------------------------
#define DRV_MMC

int main(){
	/* Inicializa o converor AD (sensor radiacao)*/
	adcEtimer_init();

	//cartao

	// Variable declaration
	FRESULT res;
	FATFS card;
	FIL file;
	char string[64];
	uint16 bytesWritten,result=0,n=0;
	//sensor efeito hall
	uint16_t tens_hall=0,corrente_hall;

	memset(string, 0, sizeof(string));

	// TWI Init
	twiMasterInit(10000);

	// UART configuration
	usartConfig(USART_MODE_ASYNCHRONOUS, USART_BAUD_9600, USART_DATA_BITS_8, USART_PARITY_NONE, USART_STOP_BIT_SINGLE);
	usartEnableReceiver();
	usartEnableTransmitter();
	usartStdio();
	printf("SD Card Example\n \r");

	// Enable Global Interrupts
	sei();
	printf("sai interrupt");

	// RTC Configuration
	ds1307SetControl(DS1307_COUNTING_RESUME, DS1307_CLOCK_1HZ, DS1307_FORMAT_24_HOURS);
//	ds1307SetDate(ANO, MES, DIA, DIA_SEMANA);
//	ds1307SetTime(HORA, MINUTO, SEGUNDO, DS1307_24);
	printf("sai ds");

	// Mounting SD card
	res = f_mount(0, &card);
	if(res != FR_OK){
		printf("->SD card not mounted => error = %d\n \r", res);
	}else{
		printf("->SD card successfully mounted\n \r");
	}

	ds1307SetControl(DS1307_COUNTING_NO_CHANGE,DS1307_CLOCK_NO_CHANGE, DS1307_FORMAT_24_HOURS );
	printf("antes res ");

	res = f_open(&file, "Radiacao.csv", FA_WRITE | FA_CREATE_ALWAYS);
	printf("depois res");

	if(res != FR_OK){
		printf("->File not created => error = %d \n \r", res);
	}
	else{
		printf("->File created successfully \n \r ");

	}


	while(1){

			ds1307GetTime(&(dados_t.tempo_t.hora),&(dados_t.tempo_t.minuto) ,&(dados_t.tempo_t.segundo),&(dados_t.tempo_t.am_pm)); // define  funfa??
			tens_hall=(5*(dados_t.dado_corrente>>3))*10/1024;
			corrente_hall=(tens_hall/0.066);

			// Creating a file
			n = snprintf(string, 64, "%d; %d.%d ; %d:%d:%d\n", (dados_t.dado_radiacao>>3),corrente_hall/10,corrente_hall%10, dados_t.tempo_t.hora,dados_t.tempo_t.minuto, dados_t.tempo_t.segundo);

			printf("SNPRINTF: %s\n", string);
			result = f_write(&file, string, strlen(string), &bytesWritten);
			_delay_ms(30000); // a cada 30 segundos

			if(result!=0){
				printf("fr_ok = %d",result);
			}
			f_sync(&file);

	}

}




