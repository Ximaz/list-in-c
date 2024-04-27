/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** tests_list_sort.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

static int sort(const void *e1, const void *e2)
{
    return (long long) e1 - (long long) e2;
}

Test(list_sort, test_impl)
{
    list_t list = { 0 };
    list_t expected = { 0 };
    list_t *sorted = NULL;

    cr_assert(eq(int, 0, list_push_back(&list, (void *) 5)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 5)));
    sorted = list_sort(&list, &sort);
    cr_assert(eq(int, 1, list_equal(sorted, &expected, NULL)));
    list_clear(&list);
    list_clear(&expected);
    list_destroy(sorted);
}

Test(list_sort_itself, test_impl)
{
    list_t list = { 0 };
    list_t expected = { 0 };

    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&expected, (void *) 5)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 5)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    list_sort_itself(&list, &sort);
    cr_assert(eq(int, 1, list_equal(&list, &expected, NULL)));
    list_clear(&list);
    list_clear(&expected);
}
