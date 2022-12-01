#include "libmx.h"

bool mx_isspace(int c) {
    if (c == ' ' 
        || c == '\n' 
        || c == '\t'
        || c == '\v'
        || c == '\r'
        || c == '\f')
        return 1;
    else
        return 0;
}

