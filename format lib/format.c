#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "format.h"

void dec2string(u8 in, byte * out){
	sprintf(out, "%0d", in);
}

void string2dec(byte * in, u8 * out){
	char * string;
	*out = (u8)strtol(in, &string, 10);
}

void hex2string(u8 in, byte * out){
	sprintf(out, "%X", in);
}

void string2hex(byte * in, u8 * out){
	char * string;
	*out = (u8)strtol(in, &string, 16);
}


//@input byte[]={"30", "31", "30", "32", "35", "37"}
//@output byte[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37}
void stringArr2hexArr(byte in[][40], u8 * out, u8 inLen){
	int i;
	for(i=0; i<inLen ;i++){
		string2hex(in[i], &out[i]);
	}
}

//@input byte[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37}
//@output byte[]={"30", "31", "30", "32", "35", "37"}
void hexArr2stringArr(u8 * in, byte out[][40], u8 inLen){
	int i;
	for(i=0; i<inLen ;i++){
		hex2string(in[i], out[i]);
	}
}

//@input byte[]="Monday 1987"
//@output byte[]="Monday" &&  u8 = 1987
void splitStringBySpace(byte * in, byte * format, byte * strings, u8 * decimals){
	sscanf(in, format, strings, decimals);
}

//@input u8=0x303130323537
//@output * byte[]={"30", "31", "30", "32", "35", "37"}
void hex2stringArr(u8 in, byte out[][40]){
	hex2string((in>>8) & 0xFF, out[0]);
	hex2string((in) & 0xFF, out[1]);
}

//@input "303130323537"
//@output "010257"
void bcdstring2string(byte in[], byte out[]){
	int len=strlen(in)-1;
	u8 aux;
	int aux2=0;
	int i;
	for(i=0; i < len; i=i+2){
		aux = (in[i]-'0')*10 + in[i+1]-'0';
		aux -= 30; //-'0' cuando restas a la representación hexadecimal
		aux2 = aux2*10+aux;
	}
		dec2string(aux2, out);
}
