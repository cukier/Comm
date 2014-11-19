/*
 * stdcom.h
 *
 *  Created on: 19/11/2014
 *      Author: cuki
 */

#ifndef STDCOM_H_
#define STDCOM_H_

typedef struct str_com {
	int addr;
	int cmd;
	long data;
} com_var;

typedef union un_com {
	com_var buff;
	int package[sizeof(com_var)];
} un_var;

typedef enum comandos {
	cmd_parar, cmd_subir, cmd_descer
} comandos_var;

int getAddr(un_var in);
int getCmd(un_var in);
long getData(un_var in);
int setAddr(un_var *out, int addrIn);
int setCmd(un_var *out, int cmdIn);
int setData(un_var *out, long dataIn);
int sendPackage(un_var out);
int getPackage(int *p, un_var *out);

#endif /* STDCOM_H_ */
