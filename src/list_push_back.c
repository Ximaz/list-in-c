/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_push_back.c
*/

#include <stdlib.h>
#include "list.h"

int list_push_back(list_t *list, void *elem)
{
    list_elem_t *e = NULL;

    if (NULL == list->elems_head)
        return list_push_front(list, elem);
    e = malloc(sizeof(list_elem_t));
    if (NULL == e)
        return -1;
    e->elem = elem;
    e->next = NULL;
    e->prev = list->elems_tail;
    list->elems_tail->next = e;
    list->elems_tail = list->elems_tail->next;
    ++list->count;
    return 0;
}
