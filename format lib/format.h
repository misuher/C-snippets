#ifndef FORMAT_H
#define FORMAT_H

typedef unsigned char byte;
typedef unsigned int u8;

#define NUM_ELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define INT2HEX(i) (i <= 9 : '0' + i ? 'A' - 10 + i)

//@input 303130323537
//@output "303130323537"
void dec2string(u8 in, byte * out);

//@input "303130323537"
//@output 303130323537
void string2dec(byte * in, u8 * out);

//@input 0x303130323537
//@output "303130323537"
void hex2string(u8 in, byte * out);

//@input "303130323537"
//@output 0x303130323537
void string2hex(byte * in, u8 * out);


//@input byte[]={"30", "31", "30", "32", "35", "37"}
//@output byte[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37}
void stringArr2hexArr(byte in[][40], u8 * out, u8 inLen);

//@input byte[]={0x30, 0x31, 0x30, 0x32, 0x35, 0x37}
//@output byte[]={"30", "31", "30", "32", "35", "37"}
void hexArr2stringArr(u8 * in, byte out[][40], u8 inLen);

//@input byte[]="Monday 1987"
//@output byte[]="Monday" &&  u8 = 1987
void splitStringBySpace(byte * in, byte * format, byte * strings, u8 * decimals);

//@input u8=0x3031
//@output * byte[]={"30", "31"}
void hex2stringArr(u8 in,byte out[][40]);

//@input "303130323537"
//@output "010257"
void bcdstring2string(byte in[], byte out[]);

#endif //FORMAT_H
