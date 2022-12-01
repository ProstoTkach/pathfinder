#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int length = 0;
    unsigned long hex2 = 0;
    unsigned long size = 1;

    if (hex != NULL)
        while (hex[length])
            length++;
    else
        return hex2;
    for (int i = 0; i <= length; i++) {
        if (hex[length - i] >= '0' && hex[length - i] <= '9') {
            hex2 = hex2 + (hex[length - i] - 48) * size;
            size = size * 16;
        }
        if (hex[length - i] >= 'A' && hex[length - i] <= 'F') {
            hex2 = hex2 + (hex[length - i] - 55) * size;
            size = size * 16;
        }
        if (hex[length - i] >= 'a' && hex[length - i] <= 'f') {
            hex2 = hex2 + (hex[length - i] - 87) * size;
            size = size * 16;
        }
    }
    return hex2;
}


