#include "libmx.h"

int mx_strncmp(const char* s1, const char* s2, int n) {
    int temp = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            temp = s1[i] - s2[i];
            break;
        }
    }

    return temp;
}

