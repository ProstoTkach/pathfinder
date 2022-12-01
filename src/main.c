#include "../inc/header.h"

void createListOfIslands(t_island **islands, char *text, int num_island) {
    char *temp = text;
    char **array_islands = create_arr_of_islands(temp);

    for (int i = 0; i < num_island; i++) {
        (*islands)[i].name = mx_strdup(array_islands[i]);
    }
    mx_del_strarr(&array_islands);
}

int findIndex(t_island *list, void * value){
    int index = 0;
	for (; list[index].name != NULL; index++)
		if (mx_strcmp(value, list[index].name) == 0) return index;
	return -1;
}

int main(int argc, char* argv[]) {
    check_errors(argc, argv);

    char *text = mx_file_to_str(argv[1]);
    int names_count = mx_count_islands(text);
    int lines_count = mx_count_substr(text, "\n") - 1;

    t_island islands[names_count];
    t_island *isl = islands;
    createListOfIslands(&isl, text, names_count);
    char *temp_text = text;

    while(*temp_text != '\n') temp_text++;
    temp_text++;
    char **array_file = (char **)malloc((lines_count + 1) * sizeof(char*));
    array_file[lines_count] = NULL;
    int line = 0;

    while (line < lines_count) {
        array_file[line] = mx_strndup(temp_text, mx_get_char_index(temp_text, '\n'));
        while (*temp_text != '\n') temp_text++;
        temp_text++;
        line++;
    }

    int **matrix = malloc(names_count*sizeof(int *));
	for (int i = 0; i < names_count; i++) {
		matrix[i] = malloc(names_count*sizeof(int));
		for (int j = 0; j < names_count; j++)
			matrix[i][j] = -1;
    }

    for (int i = 0; array_file[i] != NULL; i++) {
        char **island = mx_strsplit(array_file[i], ',');
        char **name_island = mx_strsplit(island[0], '-');
        char *name_1 = name_island[0];
        char *name_2 = name_island[1];
        int num = mx_atoi(island[1]);
        int ind_from = findIndex(islands, name_1);
        int ind_to = findIndex(islands, name_2);
        matrix[ind_from][ind_to] = num;
        matrix[ind_to][ind_from] = num;
        mx_del_strarr(&island);
        mx_del_strarr(&name_island);
    }

    for (int start_ind = 0; start_ind < names_count; start_ind++) {
        for (int end_ind = start_ind + 1; end_ind < names_count; end_ind++) {
            mx_pathfinder(end_ind, islands, (int**)matrix, names_count);

            t_list *route = NULL;
            t_list *distances = NULL;
            t_data data;
            data.start = start_ind;
            data.end = end_ind;
            data.distance = islands[start_ind].len;
            mx_printstr("========================================\nPath: ");
            mx_printstr(islands[start_ind].name);
            mx_printstr(" -> ");
            mx_printstr(islands[data.end].name);
            mx_printstr("\nRoute: ");
            mx_printstr(islands[start_ind].name);
            mx_push_back(&route, islands[start_ind].name);
            print_route(start_ind, islands, &distances, &route, (int**)matrix, data, names_count, matrix);

            mx_clear_list(&distances, true);
            mx_clear_list(&route, false);
        }
    }

    for (int j = 0; j < names_count; j++)
		free(islands[j].name);
    
    for (int j = 0; j < names_count; j++)
		free(matrix[j]);
	free(matrix);

    mx_del_strarr(&array_file);
    mx_strdel(&text);
}

