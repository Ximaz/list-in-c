/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_value_at.c
*/

#include "list.h"

void *list_value_at(const list_t *list, long index)
{
    list_elem_t *elem = list->elems_head;

    if ((0 > index && 0 == list->count) || index >= list->count)
        return NULL;
    if (0 > index)
        index += list->count;
    while (0 < index) {
        elem = elem->next;
        --index;
    }
    return elem->elem;
}
