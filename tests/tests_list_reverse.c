/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_reverse.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int my_strcmp(const void *s1, const void *s2)
{
    return strcmp((char const *) s1, (char const *) s2);
}

Test(list_reverse, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *reversed = NULL;

    cr_assert(eq(int, 0, list_push_back(list, "a")));
    cr_assert(eq(int, 0, list_push_back(list, "b")));
    cr_assert(eq(int, 0, list_push_back(list, "c")));
    cr_assert(eq(int, 0, list_push_back(list, "d")));
    cr_assert(eq(int, 0, list_push_back(list, "e")));
    cr_assert(eq(int, 0, list_push_front(expected, "a")));
    cr_assert(eq(int, 0, list_push_front(expected, "b")));
    cr_assert(eq(int, 0, list_push_front(expected, "c")));
    cr_assert(eq(int, 0, list_push_front(expected, "d")));
    cr_assert(eq(int, 0, list_push_front(expected, "e")));
    reversed = list_reverse(list);
    cr_assert(ne(ptr, NULL, reversed));
    cr_assert(eq(int, 1, list_equal(expected, reversed, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(reversed);
}

Test(list_reverse_into, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *reversed = list_new(NULL);

    cr_assert(eq(int, 0, list_push_back(list, "a")));
    cr_assert(eq(int, 0, list_push_back(list, "b")));
    cr_assert(eq(int, 0, list_push_back(list, "c")));
    cr_assert(eq(int, 0, list_push_back(list, "d")));
    cr_assert(eq(int, 0, list_push_back(list, "e")));
    cr_assert(eq(int, 0, list_push_front(expected, "a")));
    cr_assert(eq(int, 0, list_push_front(expected, "b")));
    cr_assert(eq(int, 0, list_push_front(expected, "c")));
    cr_assert(eq(int, 0, list_push_front(expected, "d")));
    cr_assert(eq(int, 0, list_push_front(expected, "e")));
    cr_assert(eq(int, 0, list_reverse_into(list, reversed)));
    cr_assert(eq(int, 1, list_equal(expected, reversed, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(reversed);
}

Test(list_reverse_itself, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);

    cr_assert(eq(int, 0, list_push_back(list, "a")));
    cr_assert(eq(int, 0, list_push_back(list, "b")));
    cr_assert(eq(int, 0, list_push_back(list, "c")));
    cr_assert(eq(int, 0, list_push_back(list, "d")));
    cr_assert(eq(int, 0, list_push_back(list, "e")));
    cr_assert(eq(int, 0, list_push_front(expected, "a")));
    cr_assert(eq(int, 0, list_push_front(expected, "b")));
    cr_assert(eq(int, 0, list_push_front(expected, "c")));
    cr_assert(eq(int, 0, list_push_front(expected, "d")));
    cr_assert(eq(int, 0, list_push_front(expected, "e")));
    list_reverse_itself(list);
    cr_assert(eq(int, 1, list_equal(expected, list, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
}
