#include "../inc/libmx.h"

bool mx_is_node(t_list *list, char *data) {
    if (!(list)) return false;

    if (!data) return false;

    t_list *temp = list;

    while (temp != NULL) {
        char *str = temp->data;
        if (mx_strcmp(str, data) == 0) return true;
        temp = temp->next;
    }
    return false;
}

