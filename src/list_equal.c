/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_equal.c
*/

#include "list.h"

static int list_equal_address(list_elem_t const *head1,
    list_elem_t const *head2)
{
    while (NULL != head1 && NULL != head2) {
        if (head1->elem != head2->elem)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 != head2)
        return 0;
    return 1;
}

int list_equal(const list_t *list1, const list_t *list2, list_cmp_t cmp)
{
    list_elem_t const *head1 = list1->elems_head;
    list_elem_t const *head2 = list2->elems_head;

    if (list1 == list2)
        return 1;
    if (NULL == cmp)
        return list_equal_address(head1, head2);
    while (NULL != head1 && NULL != head2) {
        if (0 != cmp(head1->elem, head2->elem))
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (NULL == head1 && NULL == head2);
}
