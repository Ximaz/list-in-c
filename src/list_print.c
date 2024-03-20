/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_print.c
*/

#include <stdio.h>
#include "list.h"

void list_print(list_t const *list)
{
    list_elem_t *head = list->elems_head;

    while (NULL != head) {
        printf("{[%p](%p)}", head->elem, (void *) head);
        if (NULL != head->next)
            printf("->");
        head = head->next;
    }
    printf("\n");
    fflush(stdout);
}
