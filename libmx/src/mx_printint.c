#include "libmx.h"

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar(48);
        return;
    }
    long temp = n;
    if (temp < 0) {
        temp += (-temp) * 2;
        mx_printchar('-');
    }
    int arr[30];
    int i = 0;

    while (temp != 0) {
        arr[i] = temp % 10;
        i++;
        temp /= 10;
    }
    for (i--; i >= 0; i--)
        mx_printchar(arr[i] + 48);
}

