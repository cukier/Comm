#include<18F252.h>

#fuses HS
#use delay(clock=8MHz)
#use rs232(xmit=PIN_C6, rcv=PIN_C7, baud=9600)

#include "stdcom.c"

typedef enum comandos {
	cmd_parar, cmd_subir, cmd_descer
} comando_type;

un_var dat;
int buff[20];
int i;

int main(void) {

	while (TRUE) {
		gets(buff);
		getPackage(buff, &dat);
		printf("End: %d\n\r", dat.buff.addr);
		printf("Cmd: %d\n\r", dat.buff.cmd);
		printf("Dat: %ld\n\r", dat.buff.data);
		for (i = 0; i < sizeof(buff); ++i)
			buff[i] = 0;
		delay_ms(300);
	}

	return 0;
}
