#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char* temp =  mx_strtrim(str);
    char* ans = mx_strnew(mx_strlen(temp));
    int j = 0;
    for (int i = 0; i < mx_strlen(temp); i++) {
        if (mx_isspace(temp[i]) && mx_isspace(temp[i+1]))
            continue;
        if (mx_isspace(temp[i]) && !mx_isspace(temp[i + 1]) 
            && !mx_isspace(temp[i - 1])) {
            ans[j] = ' ';
            j++;
            continue;
        }
        ans[j] = temp[i];
        j++;
    }
    ans[mx_strlen(ans)] = '\0';
    mx_strdel(&temp);
    return ans;
}

