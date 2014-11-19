/*
 * stdcom.c
 *
 *  Created on: 06/11/2014
 *      Author: cuki
 */

#include "stdcom.h"

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

	return sizeof(com_var);
}

int getPackage(int *p, un_var *out) {
	int cont = 0;

	while (*p != '\r' && cont <= sizeof(p) + 1)
		out->package[cont++] = *(p++);

	if (cont > sizeof(p) + 1)
		return -1;

	return cont;
}
