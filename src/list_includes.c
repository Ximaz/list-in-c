/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_includes.c
*/

#include "list.h"

static int list_includes_raw(list_elem_t *e, void const *elem)
{
    while (NULL != e) {
        if (e->elem == elem)
            return 1;
        e = e->next;
    }
    return 0;
}

int list_includes(list_t const *list, void const *elem, list_equal_cmp_t cmp)
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
