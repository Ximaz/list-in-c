/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_slice.c
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

static list_elem_t *move_to(list_elem_t *node, long range)
{
    while (NULL != node && 0 < range) {
        node = node->next;
        --range;
    }
    return node;
}

static int convert_indexes(list_t const *list, long *from, long *to)
{
    if (0 > *from)
        *from += list->count;
    if (0 > *to)
        *to += list->count;
    if (*from > list->count || *to > list->count || *from >= *to)
        return -1;
    return 0;
}

int list_slice_into(list_t const *list, long from, long to, list_t *output)
{
    list_elem_t *head = list->elems_head;

    if (-1 == convert_indexes(list, &from, &to))
        return -1;
    head = move_to(head, from);
    while (NULL != head && from < to) {
        list_push_back(output, head->elem);
        head = head->next;
        ++from;
    }
    return 0;
}

list_t *list_slice(list_t const *list, long from, long to)
{
    list_t *sliced = NULL;

    if (-1 == convert_indexes(list, &from, &to))
        return NULL;
    sliced = list_new(list->destroy);
    if (NULL == sliced)
        return NULL;
    if (-1 == list_slice_into(list, from, to, sliced)) {
        list_destroy(sliced);
        return NULL;
    }
    return sliced;
}

static void destroy_list_tail(list_t *list, long range)
{
    list_elem_t *tmp = NULL;

    while (NULL != list->elems_tail && range < list->count) {
        tmp = list->elems_tail->prev;
        if (NULL != list->destroy)
            list->destroy(list->elems_tail->elem);
        free(list->elems_tail);
        list->elems_tail = tmp;
        --list->count;
    }
    list->elems_tail->next = NULL;
}

static void destroy_list_head(list_t *list, long range)
{
    list_elem_t *tmp = NULL;

    while (NULL != list->elems_head && range < list->count) {
        tmp = list->elems_head->next;
        if (NULL != list->destroy)
            list->destroy(list->elems_head->elem);
        free(list->elems_head);
        list->elems_head = tmp;
        --list->count;
    }
    list->elems_head->prev = NULL;
}

int list_slice_itself(list_t *list, long from, long to)
{
    if (-1 == convert_indexes(list, &from, &to))
        return -1;
    destroy_list_tail(list, to);
    destroy_list_head(list, to - from);
    return 0;
}
