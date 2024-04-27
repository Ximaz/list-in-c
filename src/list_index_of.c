/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_index_of.c
*/

#include "list.h"

long list_index_of(const list_t *list, const void *elem, list_cmp_t cmp)
{
    long i = 0;
    list_elem_t *e = list->elems_head;

    while (NULL != e) {
        if (0 == cmp(elem, e->elem))
            return i;
        ++i;
        e = e->next;
    }
    return -1;
}
