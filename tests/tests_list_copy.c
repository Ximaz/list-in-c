/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_copy.c
*/


#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"
#include <string.h>

static int my_strcmp(void const *e1, void const *e2)
{
    return strcmp((char const *) e1, (char const *) e2);
}

static void *my_strdup(void const *e)
{
    return (void *) strdup((char const *) e);
}

Test(list_copy, test_impl)
{
    list_t *original = list_new(NULL);
    list_t *copy = NULL;

    cr_assert(eq(int, 0, list_push_back(original, "first")));
    cr_assert(eq(int, 0, list_push_back(original, "second")));
    cr_assert(eq(int, 0, list_push_back(original, "third")));
    copy = list_copy(original);
    cr_assert(ne(ptr, NULL, copy));
    cr_assert(eq(int, 1, list_equal(original, copy, my_strcmp)));
    list_destroy(original);
    list_destroy(copy);
}

Test(list_deep_copy, test_impl)
{
    list_t *original = list_new(NULL);
    list_t *copy = NULL;

    cr_assert(eq(int, 0, list_push_back(original, "first")));
    cr_assert(eq(int, 0, list_push_back(original, "second")));
    cr_assert(eq(int, 0, list_push_back(original, "third")));
    copy = list_deep_copy(original, my_strdup, &free);
    cr_assert(ne(ptr, NULL, copy));
    cr_assert(eq(int, 1, list_equal(original, copy, my_strcmp)));
    list_destroy(original);
    list_destroy(copy);
}

Test(list_deep_copy, test_impl_no_copy_function)
{
    list_t *original = list_new(NULL);
    list_t *copy = NULL;

    cr_assert(eq(int, 0, list_push_back(original, "first")));
    cr_assert(eq(int, 0, list_push_back(original, "second")));
    cr_assert(eq(int, 0, list_push_back(original, "third")));
    copy = list_deep_copy(original, NULL, NULL);
    cr_assert(ne(ptr, NULL, copy));
    cr_assert(eq(int, 1, list_equal(original, copy, my_strcmp)));
    list_destroy(original);
    list_destroy(copy);
}
