/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_sort.c
*/

#include <stdlib.h>
#include "list.h"

static void list_swap_elem(list_elem_t *a, list_elem_t *b)
{
    void *tmp = a->elem;

    a->elem = b->elem;
    b->elem = tmp;
}

static list_elem_t *list_seek_to(const list_t *list, int index)
{
    list_elem_t *head = list->elems_head;

    while (NULL != head && 0 < index) {
        head = head->next;
        --index;
    }
    if (0 == index)
        return head;
    return NULL;
}

static list_elem_t *list_seek_by(list_elem_t *ref, int by)
{
    list_elem_t *dest = ref;

    while (NULL != dest && 0 < by) {
        dest = dest->next;
        --by;
    }
    if (0 == by)
        return dest;
    return NULL;
}

static int partition(list_t *list, int low, int high, list_sort_t sort)
{
    int i = low - 1;
    list_elem_t *tmp_head = NULL;
    list_elem_t *low_head = list_seek_to(list, low);
    list_elem_t *high_head = list_seek_to(list, high);

    for (; low_head != high_head; low_head = low_head->next) {
        if (0 >= sort(high_head->elem, low_head->elem))
            continue;
        ++i;
        if (low == i)
            tmp_head = list_seek_to(list, i);
        else
            tmp_head = list_seek_by(tmp_head, 1);
        list_swap_elem(low_head, tmp_head);
    }
    ++i;
    tmp_head = list_seek_by(tmp_head, 1);
    list_swap_elem(tmp_head, high_head);
    return i;
}

static void quick_sort(list_t *list, int low, int high, list_sort_t sort)
{
    int p = 0;

    if (low < high) {
        p = partition(list, low, high, sort);
        quick_sort(list, low, p - 1, sort);
        quick_sort(list, p + 1, high, sort);
    }
}

void list_sort_into(const list_t *list, list_sort_t sort, list_t *output)
{
    list_copy_into(list, output);
    quick_sort(output, 0, output->count - 1, sort);
}

list_t *list_sort(const list_t *list, list_sort_t sort)
{
    list_t *output = list_new(list->destroy);

    if (NULL != output)
        list_sort_into(list, sort, output);
    return output;
}

void list_sort_itself(list_t *list, list_sort_t sort)
{
    quick_sort(list, 0, list->count - 1, sort);
}
