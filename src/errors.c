#include "../inc/header.h"

void printError(int line) {
    char *str = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(str);
    mx_printerr(" is not valid\n");
    mx_strdel(&str);
}

int mx_count_islands(char *text) {
    char *temp_text = text;
    char **num_str = mx_strsplit(temp_text, '\n');
    int num_island = mx_atoi(num_str[0]);

    mx_del_strarr(&num_str);
    return num_island;
}

int isNumberOfIslandsCorrect(char **islands, int num_island) {
    int i = 0;

    for (; islands[i] != NULL; i++);
    if (i != num_island) {
        mx_printerr("error: invalid number of islands\n");
        return -1;
    }
    return 0;
}

char *make_reverse(char *temp_arr_islands) {
    char *str_reverse = mx_strnew(mx_strlen(temp_arr_islands));
    char *str_temp = mx_strdup(temp_arr_islands);
    char *s = str_temp;

    while (*s != '-') s++;
    s++;
    str_reverse = mx_strcat(str_reverse, s);  
    str_reverse = mx_strcat(str_reverse, "-");
    s = str_temp;
    s = mx_strncpy(s, s, mx_get_char_index(s, '-'));
    mx_strcat(str_reverse, s);
    mx_strdel(&str_temp);  
    return str_reverse;
}

int hasDublicateBridges(char *text) {
    int err = 0;
    char *temp = text;

    while (*temp != '\n') temp++;
    temp++;
    int line_count = mx_count_substr(temp, "\n");
    char **temp_arr_islands = (char **)malloc((line_count + 1) * sizeof(char*));
    int temp_count = 0;

    while (temp_count < line_count) {
        temp_arr_islands[temp_count] = mx_strndup(temp, (size_t)mx_get_char_index(temp, ','));
        while (*temp != '\n') temp++;
        temp++;
        temp_count++;
    }
    temp_arr_islands[line_count] = NULL;

    t_list* list = mx_create_node(temp_arr_islands[0]);
    for (int j = 1; temp_arr_islands[j] != NULL; j++) {
        char *str_reverse = make_reverse(temp_arr_islands[j]);

        if (!mx_is_node(list, temp_arr_islands[j]) && !mx_is_node(list, str_reverse)) {
            mx_push_back(&list, temp_arr_islands[j]);
            mx_strdel(&str_reverse);
        }
        else {
            err = -1;
            mx_printerr("error: duplicate bridges\n");
            mx_strdel(&str_reverse);
            break;
        }
    }
    mx_clear_list(&list, false);
    mx_del_strarr(&temp_arr_islands);

    return err;
}

int isTooBigSum(char *text) {
    int err = 0;
    char *temp = text;

    while (*temp != '\n') temp++;
    temp++;
    int line_count = mx_count_substr(temp, "\n");
    long *arr_distance = create_arr_of_distances(temp, line_count);
    long all_distance = 0;

    for (int i = 0; i < line_count; i++) {
        long temp = arr_distance[i];
        all_distance += temp;
    } 
    if (all_distance > MAX_INT) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        err = -1;
    } 
	free(arr_distance);
    return err;
}

void check_errors(int argc, char* argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    bool is_error = false;
    char* file_name = argv[1]; 
    int file = open(file_name, O_RDONLY);
    char *text = NULL;
    int line_count = 0;
    char **list_islands = NULL;

    if (file == -1) {
        mx_printerr("error: file ");
        mx_printerr(file_name);
        mx_printerr(" does not exist\n");
        exit(-1);
    }
    text = mx_file_to_str(file_name);
    line_count = mx_count_substr(text, "\n");

    if (mx_strlen(text) == 0) {
        mx_printerr("error: file ");
        mx_printerr(file_name);
        mx_printerr(" is empty\n");
        mx_strdel(&text);
        exit(-1);
    }
    char *temp = text;
    int i = 0;

    while (temp[i] != '\n') {
        if (!mx_isdigit(temp[i])) {
            mx_printerr("error: line 1 is not valid\n");
            mx_strdel(&text);
            exit(-1);
        }
        i++;
    }
    char *tmp = text;

    while(*tmp != '\n') tmp++;
    int line = 1;

    while (line_count != line) {
        line++;
        tmp++;

        if (*tmp == '-') {
            printError(line);
            mx_strdel(&text);
            exit(-1);
        }
        char **island1 = mx_strsplit(tmp, '-');

        while (*tmp != '-') {
            if (*tmp == '\n' || !mx_isalpha(*tmp))  {
                printError(line);
                mx_del_strarr(&island1);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            tmp++;
        }
        char **island2 = mx_strsplit(tmp, ',');

        if (mx_strcmp(island1[0], island2[0] + 1) == 0) {
            printError(line);
            mx_del_strarr(&island1);
            mx_del_strarr(&island2);
            mx_strdel(&text);
            exit(-1);
            return;
        }
        tmp++;
        mx_del_strarr(&island1);
        mx_del_strarr(&island2);
        while (*tmp != ',') {
            if (*tmp == '\n' || !mx_isalpha(*tmp)) {
                printError(line);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            tmp++;
        }
        tmp++;
        while (*tmp != '\n') {
            if (!mx_isdigit(*tmp)) {
                printError(line);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            tmp++;
        }
    }
    list_islands = create_arr_of_islands(text);
    char *temp_text = text;
    char **num_str = mx_strsplit(temp_text, '\n');
    int num_island = mx_atoi(num_str[0]);

    mx_del_strarr(&num_str);
    if (isNumberOfIslandsCorrect(list_islands, num_island) == -1) is_error = true;
    if (!is_error)
        if (hasDublicateBridges(text) == -1) is_error = true;
    if (!is_error)
        if (isTooBigSum(text) == -1) is_error = true;
    mx_del_strarr(&list_islands);
    mx_strdel(&text); 
    if (is_error) exit(-1);
}


