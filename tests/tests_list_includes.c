/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_includes.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int my_strcmp(const void *s1, const void *s2)
{
    return strcmp((char const *) s1, (char const *) s2);
}

Test(list_includes, test_impl)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list, "This is my head !", 0)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail !", 1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2-1 !", -1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(int, 1, list_includes(list, "This is my tail 2-1 !", my_strcmp)));
    cr_assert(eq(int, 0, list_includes(list, "Invalid Element", my_strcmp)));
    list_destroy(list);
}

Test(list_includes, test_impl_no_f)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list, (void *) 1, 0)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 2, 1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 3, -1)));
    cr_assert(eq(int, 0, list_insert_at(list, (void *) 4, 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(int, 1, list_includes(list, (const void *) 3, NULL)));
    cr_assert(eq(int, 0, list_includes(list, (const void *) 0, NULL)));
    list_destroy(list);
}
