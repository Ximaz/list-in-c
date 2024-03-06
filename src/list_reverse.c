#include "list.h"

static void list_elem_swap(list_elem_t *head, list_elem_t *tail)
{
    list_elem_t *head_next = head->next;
    list_elem_t *head_prev = head->prev;

    head->next = tail->next;
    head->prev = tail->prev;
    tail->next = head_next;
    tail->prev = head_prev;
}

void list_reverse_itself(list_t *list)
{
    int i = 0;
    list_elem_t *next_head = NULL;
    list_elem_t *prev_tail = NULL;
    list_elem_t *head = list->elems_head;
    list_elem_t *tail = list->elems_tail;

    for (; i < list->count / 2; ++i) {
        next_head = head->next;
        prev_tail = tail->prev;
        list_elem_swap(head, tail);
        head = next_head;
        tail = prev_tail;
    }
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
