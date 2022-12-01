#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) return NULL;
    if (mx_count_substr(str, sub) == 0) return (char*)str;

    int count_sub = mx_count_substr(str, sub);
    int new_size = mx_strlen(str) - count_sub * (mx_strlen(sub) - mx_strlen(replace));
    char* temp = mx_strnew(new_size);
    int temp_count_sub = 0;
    int ind = 0;

    for (int i = 0; *str; ) {
        int sub_ind = mx_get_substr_index(str, sub) + ind;
        if (sub_ind != i) {
            char* sub_str_temp = mx_strnew(sub_ind);
            sub_str_temp = mx_strncpy(sub_str_temp, str, sub_ind - ind);
            mx_strcat(temp, sub_str_temp);
            mx_strdel(&sub_str_temp);
        }
        mx_strcat(temp, replace);
        temp_count_sub++;
        if (temp_count_sub == count_sub) {
            mx_strcat(temp, str);
            break;
        }
        while(i < sub_ind) {
            str++;
            i++;
            ind++;
        }
        int j = 0;
        while (j < mx_strlen(sub)) {
            str++;
            i++;
            ind++;
            j++;
        }
    }
    temp[new_size] = '\0';
    return temp;
}

