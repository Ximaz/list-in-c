/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_reverse.c
*/

#include "list.h"

int list_reverse_into(list_t const *list, list_t *output)
{
    int abort = 0;
    list_elem_t *tail = list->elems_tail;

    while (NULL != tail && 0 == abort) {
        abort = list_push_back(output, tail->elem);
        tail = tail->prev;
    }
    return abort;
}

list_t *list_reverse(list_t const *list)
{
    list_t *new_list = list_new(list->destroy);

    if (NULL == new_list)
        return NULL;
    if (-1 == list_reverse_into(list, new_list)) {
        list_destroy(new_list);
        return NULL;
    }
    return new_list;
}

void list_reverse_itself(list_t *list)
{
    int i = 0;
    void *elem = NULL;
    list_elem_t *head = list->elems_head;
    list_elem_t *tail = list->elems_tail;

    for (; i < list->count / 2; ++i) {
        elem = head->elem;
        head->elem = tail->elem;
        tail->elem = elem;
        head = head->next;
        tail = tail->prev;
    }
}
