/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_pop_front.c
*/

#include <stdlib.h>
#include "list.h"

void *list_pop_front(list_t *list)
{
    void *data = NULL;
    list_elem_t *e = NULL;

    if (0 == list->count)
        return NULL;
    e = list->elems_head;
    data = e->elem;
    list->elems_head = list->elems_head->next;
    if (NULL != list->elems_head)
        list->elems_head->prev = NULL;
    free(e);
    --list->count;
    return data;
}
