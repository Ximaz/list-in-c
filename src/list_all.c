/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_all.c
*/

#include "list.h"

int list_all(const list_t *list, list_predicate_t predicate)
{
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        if (0 == predicate(elem->elem))
            return 0;
        elem = elem->next;
    }
    return 1;
}
