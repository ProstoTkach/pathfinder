#include "../inc/libmx.h"

static int num_len(unsigned long num) {
    int len = 0;

    while (num) {
        num /= 16;
        len++;
    }
    return len;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *number = NULL;
    unsigned long num = nbr;
    int len = num_len(nbr);
    int temp;

    number = malloc(len);
    if (nbr == 0)
        return mx_strcpy(number, "0");
    while (num) {
        temp = num % 16;
        if (temp < 10)
            number[--len] = 48 + temp;
        if (temp >= 10)
            number[--len] = 87 + temp;
        num = num / 16;
    }
    return number;
}


