#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char* temp = mx_strnew(n);
    temp = mx_strncpy(temp, s1, n);
    return temp;
}

