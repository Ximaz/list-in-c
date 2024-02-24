#include "list.h"

int list_index_of(list_t const *list, void const *elem,
    list_index_of_cmp_t cmp)
{
    int i = 0;
    list_elem_t *e = list->elems_head;

    while (NULL != e) {
        if (0 == cmp(elem, e->elem))
            return i;
        ++i;
        e = e->next;
    }
    return -1;
}