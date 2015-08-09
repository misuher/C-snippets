#include <stdio.h>
#include "format.h"
#include "format_test.h"

int main(){
	printf("Init test");
	test_dec2string();
	test_string2dec();
	test_hex2string();
	test_string2hex();

	test_stringArr2hexArr();
	test_hexArr2stringArr();
	test_splitStringBySpace();

	test_hex2stringArr();
	test_bcdstring2string();

	things_must_know();

	return 0;
}
