/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_extend.c
*/

#include "list.h"

int list_extend(list_t *output, const list_t *input)
{
    list_elem_t *input_head = input->elems_head;

    if (output->destroy != input->destroy)
        return -1;
    while (NULL != input_head) {
        if (-1 == list_push_back(output, input_head->elem))
            return -1;
        input_head = input_head->next;
    }
    return 0;
}
