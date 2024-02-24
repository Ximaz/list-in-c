#include <stdlib.h>
#include "list.h"

__PRIVATE void list_elems_destroy(list_t *list)
{
    list_elem_t *next = NULL;

    if (NULL == list)
        return;
    while (NULL != list->elems_head) {
        next = list->elems_head->next;
        if (NULL != list->destroy)
            list->destroy(list->elems_head->elem);
        free(list->elems_head);
        list->elems_head = next;
    }
    list->elems_head = NULL;
    list->elems_tail = NULL;
    list->count = 0;
}
