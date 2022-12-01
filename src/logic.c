#include "../inc/header.h"

void mx_pathfinder(int end_ind, t_island *islands, int **matrix, int names_count) {
    bool wasVisited[names_count];

    for (int i = 0; i <  names_count; i++) {
        islands[i].len = MAX_INT;
        wasVisited[i] = false;
    }
    islands[end_ind].len = 0;
    int current = end_ind;

    for (int i = 0; i < names_count; i++) {
        wasVisited[current] = true;
        for (int i = 0; i < names_count; i++) {
            if (matrix[i][current] != -1) {
                if (islands[i].len > matrix[i][current] + islands[current].len && !wasVisited[i]) {
                    islands[i].len = matrix[i][current] + islands[current].len;
                }
            }
        }
        int min = MAX_INT;

        for (int j = 0; j < names_count; j++) {
            if (islands[j].len < min && !wasVisited[j]) {
                current = j;
                min = islands[j].len;
            }
        }
    }
}

void print_route(int start_ind, t_island *islands, t_list **distances, t_list **route, int **map, t_data data, int names_count, int **matrix) {
    if (data.start == data.end) {
        print_distance(*distances, *route, matrix, islands, data);
        return;
    }
    bool beforePrint = true;

    for (int i = 0; i < names_count; i++) {
        if (islands[data.start].len - islands[i].len == map[i][data.start]
            && map[i][data.start] != -1) {
            if (!beforePrint) {
                mx_clear_list(route, false);
                mx_printstr("========================================\nPath: ");
                mx_printstr(islands[start_ind].name);
                mx_printstr(" -> ");
                mx_printstr(islands[data.end].name);
                mx_printstr("\nRoute: ");
                mx_printstr(islands[start_ind].name);
                mx_push_back(route, islands[start_ind].name);
            }
            mx_printstr(" -> ");
            mx_printstr(islands[i].name);
            mx_push_back(route, islands[i].name);

            int temp = map[i][data.start];
            char *str = mx_itoa(temp);

            mx_push_back(distances, mx_strdup(str));
            mx_strdel(&str);

            t_data new_data;
            new_data.distance = data.distance;
            new_data.start = i;
            new_data.end = data.end;
            print_route(start_ind, islands, distances, route, map, new_data, names_count, matrix);
            beforePrint = false;
        }
    }
}

int search_ind_in_island(t_island *list, char *name) {
    for (int i = 0; list[i].name != NULL; i++) {
        if (mx_strcmp(list[i].name, name) == 0) return i;
    }
    return -1;
}

void print_distance(t_list *distances, t_list *route, int **matrix, t_island *list_islands, t_data data) {
    mx_printstr("\nDistance: ");
    int sum = 0;
    for (t_list *temp = distances; temp != NULL; temp = temp->next)
        sum += mx_atoi(temp->data);
    if(sum == 0)
        mx_printstr("");
    for (t_list *node = route; node->next != NULL; node = node->next) {
        if (mx_list_size(route) == 2) break;
        int ind_from = search_ind_in_island(list_islands, node->data);
        int ind_to = search_ind_in_island(list_islands, node->next->data);
        
        mx_printint(matrix[ind_from][ind_to]);
        if (node->next->next != NULL) mx_printstr(" + ");
    }
    if (mx_list_size(route) > 2) mx_printstr(" = ");
    mx_printint(data.distance);
    
    mx_printstr("\n========================================\n");
}

long *create_arr_of_distances(char *text, int line_count) {
    long *arr_distance = malloc((line_count) * sizeof(long));
    int line = 0;

    while (line < line_count) {
        while (*text != ',') text++;
        text++;
        char **str = mx_strsplit(text, '\n');

        arr_distance[line] = mx_atoi((str[0]));
        mx_del_strarr(&str);
        line++;
    }
    return arr_distance;
}

char **create_arr_of_islands(char *text) {
    char *temp = text;

    while (*temp != '\n') temp++;
    temp++;

    int line_count = mx_count_substr(temp, "\n");
    int count_names = line_count * 2;
    char **tmpArr = (char **)malloc((count_names + 1) * sizeof(char*));

    int temp_count = 0;
    while (temp_count < count_names) {
        tmpArr[temp_count] = mx_strndup(temp, (size_t)mx_get_char_index(temp, '-'));
        while (*temp != '-') temp++;
        temp++;
        tmpArr[temp_count + 1] = mx_strndup(temp, (size_t)mx_get_char_index(temp, ','));
        while (*temp != '\n') temp++;
        temp++;
        temp_count += 2;
    }
    tmpArr[count_names] = NULL;

    t_list* list = mx_create_node(tmpArr[0]);
    for (int i = 0; tmpArr[i] != NULL; i++) {
        char *dublicate_name = tmpArr[i];

        for (int j = i + 1; tmpArr[j] != NULL; j++) {
            if (!mx_is_node(list, tmpArr[j])) {
                if (mx_strcmp(dublicate_name, tmpArr[j]) == 0) 
                continue;
                mx_push_back(&list, tmpArr[j]);
            }
        }
    }
    
    t_list* temp_list = list;
    int orig_count = mx_list_size(list);
    char **arr_islands = (char **)malloc((orig_count + 1) * sizeof(char*));

    arr_islands[orig_count] = NULL;
    for (int i = 0; i < orig_count; i++) {
        arr_islands[i] = mx_strdup(temp_list->data);
        temp_list = temp_list->next;
    }
    mx_clear_list(&list, false); 
    mx_del_strarr(&tmpArr);
    return arr_islands;
}

