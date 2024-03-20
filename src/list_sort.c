/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_sort.c
*/

#include <stdlib.h>
#include "list.h"

static list_elem_t *get_list_elem(void **elem)
{
    list_elem_t e = { 0 };
    unsigned long offset = ((unsigned long *) &e.elem - (unsigned long *) &e);
    unsigned long p = ((unsigned long) elem - (unsigned long) offset);
    list_elem_t *x = (list_elem_t *) p;

    return x;
}

static void list_swap_elem(list_elem_t *a, list_elem_t *b)
{
    void *tmp = a->elem;
    a->elem = b->elem;
    b->elem = tmp;
}

static int partition(list_t *list, int low, int high, list_sort_t sort)
{
    int j = low;
    int i = j - 1;
    void *elem_curr = NULL;
    void *elem_piv = list_value_at(list, high);
    list_elem_t *current = NULL;
    list_elem_t *pivot = get_list_elem(&elem_piv);

    for (; j < high; ++j) {
        elem_curr = list_value_at(list, j);
        current = get_list_elem(&elem_curr);
        if (0 < sort(current->elem, pivot->elem)) {
            ++i;
            list_swap_elem(current, pivot);
        }
    }
    ++i;
    elem_curr = list_value_at(list, i);
    list_swap_elem(get_list_elem(&elem_curr), pivot);
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

void list_sort_into(list_t const *list, list_sort_t sort, list_t *output)
{
    list_copy_into(list, output);
    quick_sort(output, 0, output->count - 1, sort);
}

list_t *list_sort(list_t const *list, list_sort_t sort)
{
    list_t *output = list_new(list->destroy);

    if (NULL == output)
        return NULL;
    list_sort_into(list, sort, output);
    return output;
}

void list_sort_itself(list_t *list, list_sort_t sort)
{
    quick_sort(list, 0, list->count - 1, sort);
}
