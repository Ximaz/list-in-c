/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_push_front.c
*/

#include <stdlib.h>
#include "list.h"

int list_push_front(list_t *list, void *elem)
{
    list_elem_t *e = malloc(sizeof(list_elem_t));

    if (NULL == e)
        return -1;
    e->elem = elem;
    e->prev = NULL;
    if (NULL == list->elems_head) {
        e->next = NULL;
        list->elems_head = e;
        list->elems_tail = list->elems_head;
    } else {
        e->next = list->elems_head;
        list->elems_head->prev = e;
        list->elems_head = e;
    }
    ++list->count;
    return 0;
}
