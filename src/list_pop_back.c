/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_pop_back.c
*/

#include <stdlib.h>
#include "list.h"

void *list_pop_back(list_t *list)
{
    void *data = NULL;
    list_elem_t *prev = NULL;

    if (0 == list->count)
        return NULL;
    if (1 == list->count)
        return list_pop_front(list);
    data = list->elems_tail->elem;
    prev = list->elems_tail->prev;
    free(list->elems_tail);
    list->elems_tail = prev;
    if (NULL != list->elems_tail)
        list->elems_tail->next = NULL;
    --list->count;
    return data;
}
