/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_filter.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <unistd.h>
#include "list.h"

static int filter(const void *e)
{
    return strlen((char const *) e) < 10;
}

static int my_strcmp(const void *a, const void *b)
{
    return strcmp((char const *) a, (char const *) b);
}

Test(list_filter, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *filtered = NULL;

    cr_assert(eq(int, 0, list_push_back(list, "AA")));
    cr_assert(eq(int, 0, list_push_back(list, "")));
    cr_assert(eq(int, 0, list_push_back(list, "ABCDEFGHIJ")));
    cr_assert(eq(int, 0, list_push_back(list, "ABCDEFGHI")));
    cr_assert(eq(int, 0, list_push_back(expected, "AA")));
    cr_assert(eq(int, 0, list_push_back(expected, "")));
    cr_assert(eq(int, 0, list_push_back(expected, "ABCDEFGHI")));
    filtered = list_filter(list, filter);
    cr_assert(ne(ptr, NULL, filtered));
    cr_assert(eq(int, 1, list_equal(expected, filtered, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(filtered);
}

Test(list_filter_itself, test_impl)
{
    list_t *list = list_new(&free);
    list_t *expected = list_new(NULL);

    cr_assert(eq(int, 0, list_push_back(list, strdup("AA"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup(""))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("ABCDEFGHIJ"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("ABCDEFGHI"))));
    cr_assert(eq(int, 0, list_push_back(expected, "AA")));
    cr_assert(eq(int, 0, list_push_back(expected, "")));
    cr_assert(eq(int, 0, list_push_back(expected, "ABCDEFGHI")));
    list_filter_itself(list, filter);
    cr_assert(eq(int, 1, list_equal(expected, list, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
}
