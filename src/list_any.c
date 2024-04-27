/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_any.c
*/

#include "list.h"

int list_any(const list_t *list, list_predicate_t predicate)
{
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        if (1 == predicate(elem->elem))
            return 1;
        elem = elem->next;
    }
    return 0;
}
