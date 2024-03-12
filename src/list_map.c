/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_map.c
*/

#include "list.h"

void list_map_into(list_t const *list, list_map_t map, list_t *output)
{
    void *data = NULL;
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        data = elem->elem;
        elem = elem->next;
        list_push_back(output, map(data));
    }
}

list_t *list_map(list_t const *list, list_map_t map,
    list_map_destroy_t destroy)
{
    list_t *output = list_new(destroy);

    if (NULL == output)
        return NULL;
    list_map_into(list, map, output);
    return output;
}

void list_map_itself(list_t *list, list_map_t map, list_map_destroy_t destroy)
{
    void *data = NULL;
    list_elem_t *elem = list->elems_head;

    while (NULL != elem) {
        data = elem->elem;
        elem->elem = map(elem->elem);
        if (NULL != list->destroy)
            list->destroy(data);
        elem = elem->next;
    }
    list->destroy = destroy;
}
