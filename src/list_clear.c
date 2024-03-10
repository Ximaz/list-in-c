/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_clear.c
*/

#include <stdlib.h>
#include "list.h"

void list_clear(list_t *list)
{
    list_elem_t *next = NULL;

    if (NULL == list)
        return;
    while (NULL != list->elems_head) {
        next = list->elems_head->next;
        if (NULL != list->destroy)
            list->destroy(list->elems_head->elem);
        free(list->elems_head);
        list->elems_head = next;
    }
    list->elems_head = NULL;
    list->elems_tail = NULL;
    list->count = 0;
}
