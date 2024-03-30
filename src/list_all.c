/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_all.c
*/

#include "list.h"

int list_all(list_t const *list, list_filter_t filter)
{
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        if (0 == filter(elem->elem))
            return 0;
        elem = elem->next;
    }
    return 1;
}
