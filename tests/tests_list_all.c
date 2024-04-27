/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_all.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int all(const void *e1)
{
    return 0 == (unsigned long long) e1 % 2;
}

static int not_all(const void *e1)
{
    return 0 == (unsigned long long) e1 % 3;
}

Test(list_all, test_impl_no_f)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list, (void *) 2, 0)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 4, 1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 6, -1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 8, 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(int, 1, list_all(list, all)));
    cr_assert(eq(int, 0, list_all(list, not_all)));
    list_destroy(list);
}
