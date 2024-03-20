/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_reduce.c
*/

#include "list.h"

static int list_reduce_setup(list_elem_t **head, void **acc, int *i)
{
    if (NULL == (*head))
        return -1;
    if (NULL == (*acc)) {
        (*acc) = (*head)->elem;
        (*head)->elem = NULL;
        (*head) = (*head)->next;
        ++(*i);
    }
    return 0;
}

void *list_reduce(list_t const *list, list_reduce_t reduce, void *acc,
    list_reduce_destroy_t acc_destroy)
{
    int i = 0;
    void *tmp_acc = NULL;
    list_elem_t *head = list->elems_head;

    if (-1 == list_reduce_setup(&head, &acc, &i))
        return acc;
    if (NULL == acc_destroy)
        acc_destroy = list->destroy;
    while (NULL != head) {
        tmp_acc = reduce(acc, head->elem, i, list);
        if (NULL != acc_destroy)
            acc_destroy(acc);
        acc = tmp_acc;
        head = head->next;
        ++i;
    }
    return acc;
}
