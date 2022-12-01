#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"

#define MAX_INT 2147483647

void check_errors(int argc, char* argv[]);
char **create_arr_of_islands(char *text);
long *create_arr_of_distances(char *text, int line_count);
int mx_count_islands(char *text);

typedef struct s_island {
    char *name;
    int len;
} t_island;

typedef struct s_data {
    int start;
    int end;
    int distance;
} t_data;

void mx_pathfinder(int end_ind, t_island *islands, int **matrix, int names_count);
void print_route(int start_ind, t_island *islands, t_list **distances, t_list **route, int **map, t_data data, int names_count, int **matrix);
int **create_matrix(int names_count, t_island list_islands[names_count], char **array_file);
void print_results(t_island *islands, int **matrix, int names_count, int start_ind);
void print_distance(t_list *distances, t_list *route, int **matrix, t_island *list_islands, t_data data);

#endif
