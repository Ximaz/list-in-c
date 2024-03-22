/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** array_to_list.c
*/

#include "list.h"

list_t *array_to_list(void *const *const array, long size,
    list_elem_destroy_t destroy)
{
    list_t *list = NULL;

    if (0 >= size)
        return NULL;
    list = list_new(destroy);
    if (NULL == list)
        return NULL;
    do {
        --size;
        list_push_front(list, array[size]);
    } while (0 < size);
    return list;
}
