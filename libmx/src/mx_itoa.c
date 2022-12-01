#include "../inc/libmx.h"

char *mx_itoa(int number) {
    long temp = number;
    int size = 0;
    while ((temp /= 10) > 0) size++;
    temp = number;
    char *str = mx_strnew(size + 1);
    if (number == 0) return "0";
    char *reverse_str = mx_strnew(size + 1);
    if (temp < 0) temp = -temp;
    int i = 0;
    while (temp != 0) {
        str[i++] = temp % 10 + 48;
        temp /= 10;
    }
    int len = mx_strlen(str);
    if (number < 0) {
        str[i++] = '-';
        len++;
    }
    int j = len - 1;
    for (int ind = 0; ind < len; ind++) 
        reverse_str[ind] = str[j--];
    mx_strdel(&str);
    return reverse_str;
}

