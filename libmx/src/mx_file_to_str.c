#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file) return NULL;

    int filename = open(file, O_RDONLY);
    if (filename == -1) return NULL;

    char ch;
    int size = 0;

    while (read(filename, &ch, 1) != 0)
        size++;

    close(filename);
    char *str = mx_strnew(size);

    filename = open(file, O_RDONLY);
    read(filename, str, size);
    //str[size] = '\0';
    close(filename);
    return str;
}

