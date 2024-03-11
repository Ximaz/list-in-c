/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_copy.c
*/

#include "list.h"

int list_copy_into(list_t const *list, list_t *output)
{
    list_elem_t *tmp = list->elems_head;

    while (NULL != tmp) {
        if (-1 == list_push_back(output, tmp->elem))
            return -1;
        tmp = tmp->next;
    }
    return 0;
}

list_t *list_copy(list_t const *list)
{
    list_t *output = list_new(list->destroy);

    if (NULL != output && -1 == list_copy_into(list, output))
        list_destroy(output);
    return output;
}

int list_deep_copy_into(list_t const *list, list_copy_t copy,
    list_t *output)
{
    list_elem_t *tmp = list->elems_head;

    if (NULL == copy)
        return list_copy_into(list, output);
    while (NULL != tmp) {
        if (-1 == list_push_back(output, copy(tmp->elem)))
            return -1;
        tmp = tmp->next;
    }
    return 0;
}

list_t *list_deep_copy(list_t const *list, list_copy_t copy,
    list_elem_destroy_t destroy)
{
    list_t *output = list_new(NULL == destroy ? list->destroy : destroy);

    if (NULL != output && -1 == list_deep_copy_into(list, copy, output))
        list_destroy(output);
    return output;
}
