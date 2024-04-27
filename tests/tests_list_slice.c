/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_slice.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static void fake_destroy(void *e)
{
    (void)(e);
}

static int my_cmp(const void *e1, const void *e2)
{
    return e1 == e2 ? 0 : 1;
}

Test(list_slice, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *sliced = NULL;

    cr_assert(eq(int, 0, list_push_back(list, (int *) 1)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 2)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 3)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 4)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 6)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 7)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 6)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 7)));
    sliced = list_slice(list, 4, list->count);
    cr_assert(ne(ptr, NULL, sliced));
    cr_assert(eq(int, 1, list_equal(expected, sliced, my_cmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(sliced);
}

Test(list_slice, test_impl_negative_from)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *sliced = NULL;

    cr_assert(eq(int, 0, list_push_back(list, (int *) 1)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 2)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 3)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 4)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 6)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 7)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 6)));
    sliced = list_slice(list, -3, -1);
    cr_assert(ne(ptr, NULL, sliced));
    cr_assert(eq(int, 1, list_equal(expected, sliced, my_cmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(sliced);
}

Test(list_slice, test_impl_out_of_bounds)
{
    list_t *list = list_new(NULL);
    list_t *sliced = NULL;

    sliced = list_slice(list, 0, 1000);
    cr_assert(eq(ptr, NULL, sliced));
    sliced = list_slice(list, -10, -1000);
    cr_assert(eq(ptr, NULL, sliced));
    cr_assert(eq(int, -1, list_slice_into(list, 0, 1000, sliced)));
    cr_assert(eq(int, -1, list_slice_into(list, -10, -1000, sliced)));
    cr_assert(eq(int, -1, list_slice_itself(list, 0, 1000)));
    cr_assert(eq(int, -1, list_slice_itself(list, -10, -1000)));
    list_destroy(list);
}

Test(list_slice_itself, test_impl)
{
    list_t *list = list_new(fake_destroy);
    list_t *expected = list_new(NULL);

    cr_assert(eq(int, 0, list_push_back(list, (int *) 1)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 2)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 3)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 4)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 6)));
    cr_assert(eq(int, 0, list_push_back(list, (int *) 7)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 5)));
    cr_assert(eq(int, 0, list_push_back(expected, (int *) 6)));
    list_slice_itself(list, 4, list->count - 1);
    cr_assert(eq(int, 2, list_count(list)));
    cr_assert(eq(int, 1, list_equal(expected, list, my_cmp)));
    list_destroy(list);
    list_destroy(expected);
}
