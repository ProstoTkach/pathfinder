#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int counter = 0;

    if (!arr) return -1;
    
    if (left < right) {
        int newLeft = left;
        int newRight = right;
        char *cursor = arr[(newRight + newLeft) / 2];

        while (newLeft <= newRight) {
            while (mx_strlen(arr[newLeft]) < mx_strlen(cursor)) newLeft++;
            while (mx_strlen(arr[newRight]) > mx_strlen(cursor)) newRight--;

            if (newLeft <= newRight) {
                if (mx_strlen(arr[newRight]) != mx_strlen(arr[newLeft])) {
                    char *temp = arr[newLeft];
                    
                    arr[newLeft] = arr[newRight];
                    arr[newRight] = temp;
                    counter++;
                }
                newRight--;
                newLeft++;
            }
        }

        counter += mx_quicksort(arr, left, newRight);
        counter += mx_quicksort(arr, newLeft, right);
    }    
    return counter;
}


