/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_apply.c
*/

#include "list.h"

void list_apply(list_t *list, list_apply_t apply)
{
    list_elem_t *e = list->elems_head;

    while (NULL != e) {
        apply(e->elem);
        e = e->next;
    }
}
