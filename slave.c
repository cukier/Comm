#include<18F252.h>

#fuses HS
#use delay(clock=8MHz)
#use rs232(xmit=PIN_C6, rcv=PIN_C7, baud=9600)

#include "stdcom.c"

un_var dat;
int data[20];
int i;

int main(void) {

	while (TRUE) {
//		gets(data);
//		getstr(data, &dat);
		gets(dat.str);
		printf("End: %d\n\r", dat.data.addr);
		printf("Cmd: %d\n\r", dat.data.cmd);
		printf("Dat: %ld\n\r", dat.data.data);
		for (i = 0; i < sizeof(data); ++i)
			data[i] = 0;
		delay_ms(300);
	}

	return 0;
}
