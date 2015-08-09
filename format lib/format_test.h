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
#endif //FORMAT_TEST_H
