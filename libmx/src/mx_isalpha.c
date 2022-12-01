#include "libmx.h"

bool mx_isalpha(int c) {
    if ((c >= 'A' && c <= 'Z')
        || ('a' <= c && c <= 'z'))
        return 1;
    else
        return 0;
}

