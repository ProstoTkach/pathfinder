#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size <= 0)
        return -2;
    char *buffer = mx_strnew(buf_size);
    int len = 0;
    int index = 0;
    while (read(fd, buffer, buf_size)){
        len += buf_size;
        if ((index = mx_get_char_index(buffer, delim)) >= 0){
            for (size_t i = index; i < buf_size; i++){
                buffer[i] = '\0';
                len--;
            }
            *lineptr = mx_strjoin(*lineptr, buffer);
            return len;
        }
        *lineptr = mx_strjoin(*lineptr, buffer);
    }
    return len;
}


