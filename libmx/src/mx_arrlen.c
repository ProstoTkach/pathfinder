#include "../inc/libmx.h"

int mx_arrlen(char **arr) {
    int len = 0;

    while (*arr) {
        len++;
        arr++;
    }
    return len;
}


