/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_insert_at.c
*/

#include <stdlib.h>
#include "list.h"

static list_elem_t *list_elem_insert(list_elem_t *e, void *elem)
{
    list_elem_t *new_elem = malloc(sizeof(list_elem_t));

    if (NULL != new_elem) {
        new_elem->elem = elem;
        new_elem->next = e;
        new_elem->prev = e->prev;
    }
    return new_elem;
}

static int list_insert(list_t *list, void *elem, long index)
{
    list_elem_t *new_e = NULL;
    list_elem_t *e = list->elems_head;

    while (0 < index) {
        e = e->next;
        --index;
    }
    new_e = list_elem_insert(e, elem);
    if (NULL == new_e)
        return -1;
    e->prev->next = new_e;
    e->prev = new_e;
    ++list->count;
    return 0;
}

int list_insert_at(list_t *list, void *elem, long index)
{
    if ((0 > index && 0 == list->count) || index > list->count)
        return -1;
    if (0 > index)
        index += list->count + 1;
    if (0 == index)
        return list_push_front(list, elem);
    if (index == list->count)
        return list_push_back(list, elem);
    return list_insert(list, elem, index);
}
