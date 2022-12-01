#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80) {
        char data[1];

        data[0] = (c >> 0 & 0x7F) | 0x00;
        
        write(1, data, 1);
    }
    else if (c < 0x0800) {
        char data[2];

        data[0] = (c >> 6 & 0x1F) | 0xC0;
        data[1] = (c >> 0 & 0x3F) | 0x80;

        write(1, data, 2);
    }
    else if (c < 0x010000) {
        char data[3];

        data[0] = (c >> 12 & 0x0F) | 0xE0;
        data[1] = (c >> 6 & 0x3F) | 0x80;
        data[2] = (c >> 0 & 0x3F) | 0x80;

        write(1, data, 3);
    }
    else if (c < 0x110000) {
        char data[4];

        data[0] = (c >> 18 & 0x07) | 0xF0;
        data[1] = (c >> 12 & 0x3F) | 0x80;
        data[2] = (c >> 6 & 0x3F) | 0x80;
        data[3] = (c >> 0 & 0x3F) | 0x80;

        write(1, data, 4);
    }
}


