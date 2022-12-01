#include "libmx.h"

int mx_count_substr(const char* str, const char* sub) {
    int count = 0;

    const char *temp = str;
    while (*temp) {
        if (temp == mx_strchr(temp, sub[0])) {
            if (mx_strncmp(temp, sub, mx_strlen(sub)) == 0) {
                count++;
            }
        }
        temp++;
    }
    return count;
}

