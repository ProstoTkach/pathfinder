#include "../inc/libmx.h"

char* mx_strncpy(char* dst, const char* src, int len) {
    if (dst == 0 || len <= 0)
        return 0;

    char* temp = dst;
    int i = 0;

    while (i < len && *src != '\0') {
        *dst = *src;
        src++;
        dst++;
        i++;
    }

    *dst++ = '\0';
    return temp;
}

