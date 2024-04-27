/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_any.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int any(const void *e1)
{
    return 2 == (unsigned long long) e1;
}

static int not_any(const void *e1)
{
    return 5 == (unsigned long long) e1 % 3;
}

Test(list_any, test_impl_no_f)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list, (void *) 0, 0)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 1, 1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 2, -1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 3, 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(int, 1, list_any(list, any)));
    cr_assert(eq(int, 0, list_any(list, not_any)));
    list_destroy(list);
}
