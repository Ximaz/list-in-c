/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_array_to_list.c
*/

#include "list.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

Test(array_to_list, test_impl)
{
    void *array[] = { (void *) 1, (void *) 2, (void *) 3, (void *) 4, (void *) 5 };
    long size = 5;
    list_t expected = { 0 };
    list_t *list = array_to_list(array, size, NULL);

    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 5)));
    cr_assert(ne(ptr, NULL, list));
    cr_assert(eq(int, 1, list_equal(&expected, list, NULL)));
    list_destroy(list);
    list_clear(&expected);
}

Test(array_to_list, test_bad_inputs)
{
    void *array[] = { (void *) 1, (void *) 2, (void *) 3, (void *) 4, (void *) 5 };

    cr_assert(eq(ptr, NULL, array_to_list(array, 0, NULL)));
    cr_assert(eq(ptr, NULL, array_to_list(array, -1, NULL)));
}
