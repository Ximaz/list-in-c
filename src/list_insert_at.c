#include <stdlib.h>
#include "list.h"

static int list_elem_insert(list_elem_t *e, void *elem)
{
    list_elem_t *new_elem = malloc(sizeof(list_elem_t));

    if (NULL == new_elem)
        return -1;
    new_elem->elem = elem;
    new_elem->next = e->next;
    new_elem->prev = e;
    e->next = new_elem;
    return 0;
}

int list_insert_at(list_t *list, void *elem, int index)
{
    list_elem_t *e = list->elems_head;

    if ((0 > index && 0 == list->count) || index > list->count)
        return -1;
    if (0 > index)
        index += list->count + 1;
    if (0 == index)
        return list_push_front(list, elem);
    if (index == list->count)
        return list_push_back(list, elem);
    while (0 < index) {
        e = e->next;
        --index;
    }
    return list_elem_insert(e->prev, elem);
}
