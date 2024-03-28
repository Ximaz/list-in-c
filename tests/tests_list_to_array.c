/*
** EPITECH PROJECT, 2024
** Tests of Lists in C
** File description:
** list_to_array.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

Test(list_to_array, test_impl)
{
    int i = 0;
    list_t list = { 0 };
    void **array = NULL;

    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 5)));
    array = list_to_array(&list, sizeof(long));
    for (; i < list.count; ++i)
        cr_assert(eq(long, (long) array[i], (long) list_value_at(&list, i)));
    free(array);
    list_clear(&list);
}
