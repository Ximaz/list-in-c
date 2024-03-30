/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_any.c
*/

#include "list.h"

int list_any(list_t const *list, list_filter_t filter)
{
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        if (1 == filter(elem->elem))
            return 1;
        elem = elem->next;
    }
    return 0;
}
