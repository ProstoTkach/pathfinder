#include "libmx.h"

char* mx_strcpy(char* dst, const char* src) {
    if (dst == 0)
        return 0;

    int i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

