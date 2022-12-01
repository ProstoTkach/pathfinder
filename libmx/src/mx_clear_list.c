#include "../inc/libmx.h"

void mx_clear_list(t_list** list, bool is_clear) {
    if (!(*list)) return;

	while (*list){
		t_list *node = (*list)->next;
		if (is_clear) free((*list)->data);
		free(*list);
		*list = node;
	}
}

