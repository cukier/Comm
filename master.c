#include<18F252.h>

#fuses HS
#use delay(clock=8MHz)
#use rs232(xmit=PIN_C6, rcv=PIN_C7, baud=9600)

#include "stdcom.c"

un_var dat;

int main(void) {

	delay_ms(1000);

	setAddr(&dat, 1);
	setCmd(&dat, cmd_descer);
	setData(&dat, 13580);

	sendPackage(dat);

	return 0;
}
