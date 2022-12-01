#include "libmx.h"

t_list* mx_create_node(void* data) {
    if (!data) return NULL;
    t_list *temp = malloc(sizeof(t_list));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

