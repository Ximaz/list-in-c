/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_extend.c
*/


#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"
#include <string.h>

static int my_strcmp(const void *e1, const void *e2)
{
    return strcmp((char const *) e1, (char const *) e2);
}

static void *my_strdup(const void *e)
{
    return (void *) strdup((char const *) e);
}

Test(list_extend, test_impl)
{
    list_t output = { 0 };
    list_t input = { 0 };
    list_t expected = { 0 };

    cr_assert(eq(int, 0, list_push_back(&output, "o-first")));
    cr_assert(eq(int, 0, list_push_back(&output, "o-second")));
    cr_assert(eq(int, 0, list_push_back(&output, "o-third")));
    cr_assert(eq(int, 0, list_push_back(&input, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&input, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&input, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-first")));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-second")));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_extend(&output, &input)));
    cr_assert(eq(int, 1, list_equal(&output, &expected, my_strcmp)));
    list_clear(&output);
    list_clear(&input);
    list_clear(&expected);
}

Test(list_extend, test_impl_bad_destroyer)
{
    list_t output = { 0 };
    list_t input = { 0 };

    input.destroy = &free;
    cr_assert(eq(int, -1, list_extend(&output, &input)));
}

Test(list_deep_extend, test_impl)
{
    list_t output = { 0 };
    list_t input = { 0 };
    list_t expected = { 0 };

    output.destroy = &free;
    input.destroy = &free;
    cr_assert(eq(int, 0, list_push_back(&output, my_strdup("o-first"))));
    cr_assert(eq(int, 0, list_push_back(&output, my_strdup("o-second"))));
    cr_assert(eq(int, 0, list_push_back(&output, my_strdup("o-third"))));
    cr_assert(eq(int, 0, list_push_back(&input, my_strdup("i-third"))));
    cr_assert(eq(int, 0, list_push_back(&input, my_strdup("i-third"))));
    cr_assert(eq(int, 0, list_push_back(&input, my_strdup("i-third"))));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-first")));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-second")));
    cr_assert(eq(int, 0, list_push_back(&expected, "o-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_push_back(&expected, "i-third")));
    cr_assert(eq(int, 0, list_deep_extend(&output, &input, my_strdup)));
    cr_assert(eq(int, 1, list_equal(&output, &expected, my_strcmp)));
    list_clear(&output);
    list_clear(&input);
    list_clear(&expected);
}

Test(list_deep_extend, test_impl_bad_destroyer)
{
    list_t output = { 0 };
    list_t input = { 0 };

    input.destroy = &free;
    cr_assert(eq(int, -1, list_deep_extend(&output, &input, my_strdup)));
    input.destroy = NULL;
    cr_assert(eq(int, 0, list_deep_extend(&output, &input, NULL)));
}
