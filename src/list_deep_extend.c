/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_deep_extend.c
*/

#include <stdio.h>
#include "list.h"

int list_deep_extend(list_t *output, list_t const *input, list_copy_t copy)
{
    list_elem_t *input_head = input->elems_head;

    if (NULL == copy)
        return list_extend(output, input);
    if (output->destroy != input->destroy)
        return -1;
    while (NULL != input_head) {
        if (-1 == list_push_back(output, copy(input_head->elem)))
            return -1;
        input_head = input_head->next;
    }
    return 0;
}
