#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len >= little_len && big_len > 0 && little_len > 0) {
        unsigned char *more = NULL;
        unsigned char *less = NULL;    
        
        more = (unsigned char *)big;
        less = (unsigned char *)little;
        while (*more) {
            if (mx_memcmp(more, less, little_len - 1) == 0)
                return more;
            more++;
        }
    }
    return NULL;
}


