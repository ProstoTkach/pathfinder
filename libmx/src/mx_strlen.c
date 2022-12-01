#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int count = 0;

    for (const char* i = s;; i++) {
        if (*i != '\0') count++;
        else break;
    }
    return count;
}

