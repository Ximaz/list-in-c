/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_includes.c
*/

#include "list.h"

static int list_includes_raw(list_elem_t *e, const void *elem)
{
    while (NULL != e) {
        if (e->elem == elem)
            return 1;
        e = e->next;
    }
    return 0;
}

int list_includes(const list_t *list, const void *elem, list_cmp_t cmp)
{
    list_elem_t *e = list->elems_head;

    if (NULL == cmp)
        return list_includes_raw(e, elem);
    while (NULL != e) {
        if (0 == cmp(elem, e->elem))
            return 1;
        e = e->next;
    }
    return 0;
}
