/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_to_array.c
*/

#include <stdlib.h>
#include "list.h"

void **list_to_array(list_t const *list, unsigned long elem_size)
{
    long i = 0;
    void **array = NULL;
    list_elem_t *head = NULL;

    if (0 == elem_size)
        return NULL;
    array = calloc(list->count, elem_size);
    if (NULL == array)
        return NULL;
    head = list->elems_head;
    while (NULL != head) {
        array[i] = head->elem;
        head = head->next;
        ++i;
    }
    return array;
}
