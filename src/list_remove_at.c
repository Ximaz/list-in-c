/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_remove_at.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void list_elem_remove(list_elem_t *e)
{
    if (NULL != e->prev)
        e->prev->next = e->next;
    if (NULL != e->next)
        e->next->prev = e->prev;
    free(e);
}

void *list_remove_at(list_t *list, long index)
{
    void *data = NULL;
    list_elem_t *e = list->elems_head;

    if (0 == list->count || index >= list->count)
        return NULL;
    if (0 > index)
        index += list->count;
    if (0 == index)
        return list_pop_front(list);
    if (index == list->count - 1)
        return list_pop_back(list);
    while (0 < index) {
        e = e->next;
        --index;
    }
    data = e->elem;
    list_elem_remove(e);
    --list->count;
    return data;
}
