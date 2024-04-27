/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_filter.c
*/

#include <stdlib.h>
#include "list.h"

void list_filter_into(const list_t *list, list_predicate_t predicate,
    list_t *output)
{
    void *data = NULL;
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        data = elem->elem;
        elem = elem->next;
        if (1 == predicate(data))
            list_push_back(output, data);
    }
}

list_t *list_filter(const list_t *list, list_predicate_t predicate)
{
    list_t *output = list_new(list->destroy);

    if (NULL == output)
        return NULL;
    list_filter_into(list, predicate, output);
    return output;
}

void list_filter_itself(list_t *list, list_predicate_t predicate)
{
    list_elem_t *prev = NULL;
    list_elem_t *next = NULL;
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        if (1 == predicate(elem->elem)) {
            elem = elem->next;
            continue;
        }
        if (NULL != list->destroy)
            list->destroy(elem->elem);
        prev = elem->prev;
        next = elem->next;
        free(elem);
        if (NULL != prev)
            prev->next = next;
        if (NULL != next)
            next->prev = prev;
        elem = next;
    }
}
