/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_new.c
*/

#include <stdlib.h>
#include "list.h"

list_t *list_new(list_elem_destroy_t destroy)
{
    list_t *list = malloc(sizeof(list_t));

    if (NULL != list) {
        list->count = 0;
        list->destroy = destroy;
        list->elems_head = NULL;
        list->elems_tail = NULL;
    }
    return list;
}
