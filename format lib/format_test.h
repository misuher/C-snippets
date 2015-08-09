#ifndef FORMAT_TEST_H
#define  FORMAT_TEST_H

typedef struct test_h2s{
	u8 in;
	byte * expected;
}Test_h2s;

void test_dec2string(void);
void test_string2dec(void);
void test_hex2string(void);
void test_string2hex(void);

void test_stringArr2hexArr(void);
void test_hexArr2stringArr(void);
void test_splitStringBySpace(void);

void test_hex2stringArr(void);
void test_bcdstring2string(void);

void things_must_know(void);
#endif //FORMAT_TEST_H
