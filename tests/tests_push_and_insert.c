/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_push_and_insert.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int my_strcmp(const void *e1, const void *e2)
{
    return strcmp((char const *) e1, (char const *) e2);
}

Test(list_push_back, test_impl)
{
    list_t *list = list_new(&free);

    cr_assert(eq(int, 0, list_push_back(list, strdup("Hello, World !"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("This is my tail !"))));
    cr_assert(eq(long, 2, list_count(list)));
    cr_assert(eq(str, "Hello, World !", list->elems_head->elem));
    cr_assert(eq(str, "This is my tail !", list->elems_tail->elem));
    list_destroy(list);
}

Test(list_push_front, test_impl)
{
    list_t *list = list_new(&free);

    cr_assert(eq(int, 0, list_push_front(list, strdup("Hello, World !"))));
    cr_assert(eq(int, 0, list_push_front(list, strdup("This is my head !"))));
    cr_assert(eq(long, 2, list_count(list)));
    cr_assert(eq(str, "This is my head !", list->elems_head->elem));
    cr_assert(eq(str, "Hello, World !", list->elems_tail->elem));
    list_destroy(list);
}

Test(list_insert_at, test_impl)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);

    cr_assert(eq(int, -1, list_insert_at(list, NULL, -1)));
    cr_assert(eq(int, -1, list_insert_at(list, NULL, 1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my head !", 0)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail !", 1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2-1 !", -1)));
    cr_assert(eq(int, 0, list_insert_at(list, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 0, list_push_back(expected, "This is my head !")));
    cr_assert(eq(int, 0, list_push_back(expected, "This is my tail !")));
    cr_assert(eq(int, 0, list_push_back(expected, "This is my tail 2-1 !")));
    cr_assert(eq(int, 0, list_insert_at(expected, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 1, list_equal(list, expected, my_strcmp)));
    list_destroy(list);
    list_destroy(expected);
}
