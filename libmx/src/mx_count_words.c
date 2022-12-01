#include "../inc/libmx.h"

int mx_count_words(const char* str, char delimiter) {
    int words_count = 0;
    int temp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && temp == 0)
            temp = 1;

        if (str[i] == delimiter)
            temp = 0;
        else if (temp == 0) {
            temp = 1;
            words_count++;
        }
    }
    return words_count;
}

