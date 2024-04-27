/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_index_of.c
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

Test(list_index_of, test_impl)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list, "This is my head !", 0)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail !", 1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2-1 !", -1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(long, 0, list_index_of(list, "This is my head !", my_strcmp)));
    cr_assert(eq(long, 1, list_index_of(list, "This is my tail !", my_strcmp)));
    cr_assert(eq(long, 2, list_index_of(list, "This is my tail 2 !", my_strcmp)));
    cr_assert(eq(long, 3, list_index_of(list, "This is my tail 2-1 !", my_strcmp)));
    cr_assert(eq(long, -1, list_index_of(list, "Invalid Element", my_strcmp)));
    list_destroy(list);
}
