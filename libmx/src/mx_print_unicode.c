#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80) { // 0x80 means int 128
		char byte[1];

		byte[0] = (c >> 0 & 0x7F) | 0x00; // 0x7F - 0111_1111 (127) // 0x00 - integral literal

		write(1, byte, 1);
	} 

    else if (c < 0x0800) { // means int 2048
		char byte[2]; 

		byte[0] = (c >> 6 & 0x1F) | 0xC0; // 0x1F - divider
		byte[1] = (c >> 0 & 0x3F) | 0x80; // 0x3F = 63

		write(1, byte, 2);
	} 
    else if (c < 0x010000) { // means int 65536
		char byte[3]; 

		byte[0] = (c >> 12 & 0x0F) | 0xE0; // 0x0F - hex meaning of byte
		byte[1] = (c >> 6 & 0x3F) | 0x80;
		byte[2] = (c >> 0 & 0x3F) | 0x80;

		write(1, byte, 3);
	} 

    else if (c < 0x110000) { // means int 1114112
		char byte[4]; 

		byte[0] = (c >> 18 & 0x07) | 0xF0;
		byte[1] = (c >> 12 & 0x3F) | 0x80;
		byte[2] = (c >> 6 & 0x3F) | 0x80;
		byte[3] = (c >> 0 & 0x3F) | 0x80;

		write(1, byte, 4);
	}
}

