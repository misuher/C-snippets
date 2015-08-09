#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "format.h"
#include "format_test.h"

void test_dec2string(void){
	printf("\n\ttest_dec2string");
	//test1
	Test_h2s h2s ={.in=(u8)3232, .expected=(byte*)"3232"};
	byte * result;
	dec2string(h2s.in, result);
	assert(! strcmp(h2s.expected , result)); 	//con memcmp no funciona tan facilmente como con strcmp ya que
																			//checkea toda la memoria inclusive valores no escritos de las posiciones
																			//reservadas por el array
	//test2
	h2s.in = (u8)5;
	h2s.expected = (byte*)"5";
	dec2string(h2s.in, result);
	assert(! strcmp(h2s.expected , result));

	printf(":ok");
}

void test_string2dec(void){
	printf("\n\ttest_string2dec");
	//byte inn[4];
	//strcpy(inn, "3232");
	//u8 result;
	//string2dec(in, &result);
	//printf("%d\n", result);
	//printf("%d\n", expected);
	//assert(3232==result);
	//printf(":ok");
}

void test_hex2string(){
	printf("\n\ttest_hex2string");
	//test1
	Test_h2s h2s ={.in=(u8)0x323232, .expected=(byte*)"323232"};
	byte * result;
	hex2string(h2s.in, result);
	assert(! strcmp(h2s.expected , result)); 	//con memcmp no funciona tan facilmente como con strcmp ya que
																			//checkea toda la memoria inclusive valores no escritos de las posiciones
																			//reservadas por el array
	//test2
	h2s.in = (u8)0xABCDE;
	h2s.expected = (byte*)"ABCDE";
	hex2string(h2s.in, result);
	assert(! strcmp(h2s.expected , result));

	printf(":ok");
}

void test_string2hex(){
	printf("\n\ttest_string2hex");
	byte * in = "3232AF";
	u8 expected = 0x3232AF;
	u8 result;
	string2hex(in, &result);
	assert(expected==result);
	printf(":ok");
}

void test_stringArr2hexArr(){
	printf("\n\ttest_stringArr2hexArr");
	byte in[][40]={"30", "31", "30", "32", "35", "37"};
	u8 expected[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37};
	u8 out[NUM_ELEMS(in)];
	stringArr2hexArr(in, out, NUM_ELEMS(in));

	int i;
	for(i=0; i<NUM_ELEMS(in);i++){
		assert(out[i] == expected[i]);
	}
	printf(":ok");
}

void test_hexArr2stringArr(){
	printf("\n\ttest_hexArr2stringArr");
	u8 in[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37};
	byte * expected[]={"30", "31", "30", "32", "35", "37"};
	byte out[NUM_ELEMS(in)][40];
	memset(out, 0, sizeof(out[0][0])*NUM_ELEMS(in)*40);

	hexArr2stringArr(in, out, NUM_ELEMS(in));

	int i;
	for(i=0; i<NUM_ELEMS(in);i++){
		assert(! strcmp(out[i], expected[i]));
	}
	printf(":ok");
}

void test_splitStringBySpace(){
	printf("\n\ttest_splitStringBySpace");
	byte in[]="Monday 1987";
	byte strings[20];
	u8 decimals;
	splitStringBySpace(in,"%s %d", strings, &decimals);
	assert(! strcmp(strings, "Monday"));
	assert(decimals==1987);
	printf(":ok");
}

void test_hex2stringArr(){
	printf("\n\ttest_hex2stringArr");
	u8 in = 0x3132;
	byte out[2][40];
	byte expected[2][40]={"31", "32"};

	hex2stringArr(in, out);

	int i;
	for(i=0; i<NUM_ELEMS(out); i++){
		assert(! strcmp(out[i], expected[i]));
	}
	printf(":ok");
}

void test_bcdstring2string(){
	printf("\n\ttest_bcdstring2string");
	byte in[]="3130323537";
	byte out[NUM_ELEMS(in)];
	bcdstring2string(in,out);
	assert(! strcmp(out, "10257"));
	printf(":ok");
}

void things_must_know(void){
	printf("\nthings_must_know");//
	byte pruebadec[] = {49, 50, 0}; //dec-> equivalente ascii del decimal
	printf("\n\tpruebadec:%s", pruebadec); //12
	byte prueba2[] = "12"; //string literal(termina en\0), equivalente al de arriba
	printf("\n\tprueba2:%s", prueba2); //12

	byte pruebahex[]={0x32,0x33,0x34,0x35};
	printf("\n\tpruebahex:%x", pruebahex[1]); //33
	byte * pruebastring[]={"32", "33", "34", "35"};
	printf("\n\tpruebastring:%s", pruebastring[1]); //33
	byte pruebastring2[]="32333235";
	printf("\n\tpruebastring2:%c", pruebastring2[1]); //2
	printf("\n\tu8 maxsize:%lu bytes", sizeof(u8)); //puede ser 2bytes(0xFFFF) o 4 bytes(0xFFFFFFFF)
}
