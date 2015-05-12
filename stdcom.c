/*
 * stdcom.c
 *
 *  Created on: 06/11/2014
 *      Author: cuki
 */

#include "stdcom.h"

int getAddr(un_var in) {
	return in.data.addr;
}

int getCmd(un_var in) {
	return in.data.cmd;
}

long getData(un_var in) {
	return in.data.data;
}

int setAddr(un_var *out, int addrIn) {
	out->data.addr = addrIn;

	return 0;
}

int setCmd(un_var *out, int cmdIn) {
	out->data.cmd = cmdIn;

	return 0;
}

int setData(un_var *out, long dataIn) {
	out->data.data = dataIn;

	return 0;
}

int sendPackage(un_var out) {
	printf("%s\r", out.str);

	return sizeof(com_var);
}

int getstr(int *p, un_var *out) {
	int cont = 0;

	while (*p != '\r' && cont <= sizeof(p) + 1)
		out->str[cont++] = *(p++);

	if (cont > sizeof(p) + 1)
		return -1;

	return cont;
}
