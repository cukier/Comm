/*
 * stdcom.c
 *
 *  Created on: 06/11/2014
 *      Author: cuki
 */

typedef struct str_com {
	int addr;
	int cmd;
	long data;
} com_var;

typedef union un_com {
	com_var buff;
	int package[sizeof(com_var)];
} un_var;

int cont;

int getAddr(un_var in) {
	return in.buff.addr;
}

int getCmd(un_var in) {
	return in.buff.cmd;
}

long getData(un_var in) {
	return in.buff.data;
}

int setAddr(un_var *out, int addrIn) {
	out->buff.addr = addrIn;

	return 0;
}

int setCmd(un_var *out, int cmdIn) {
	out->buff.cmd = cmdIn;

	return 0;
}

int setData(un_var *out, long dataIn) {
	out->buff.data = dataIn;

	return 0;
}

int sendPackage(un_var out) {
	printf("%s\r", out.package);

	return 0;
}

int getPackage(int *p, un_var *out) {
	cont = 0;
	while (*p != '\r' && cont <= sizeof(p) + 1)
		out->package[cont++] = *(p++);
	return 0;
}