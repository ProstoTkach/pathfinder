#include "libmx.h"

char* mx_strcat(char* s1, const char* s2) {
    mx_strcpy(s1 + mx_strlen(s1), s2);
    return s1;
}

