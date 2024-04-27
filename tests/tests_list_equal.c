/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_equal.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static int my_strcmp(const void *s1, const void *s2)
{
    return strcmp((char const *) s1, (char const *) s2);
}

Test(list_equal, test_impl)
{
    list_t *list1 = list_new(NULL);
    list_t *list2 = list_new(&free);

    cr_assert(eq(int, 0, list_insert_at(list1, "This is my head !", 0)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail !", 1)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail 2-1 !", -1)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 0, list_equal(list1, list2, NULL)));
    cr_assert(eq(int, 1, list_equal(list1, list1, NULL)));
    cr_assert(eq(int, 1, list_equal(list2, list2, NULL)));
    cr_assert(eq(int, 0, list_equal(list1, list2, my_strcmp)));
    cr_assert(eq(int, 0, list_insert_at(list2, strdup("This is my head !"), 0)));
    cr_assert(eq(int, 0, list_insert_at(list2, strdup("This is my tail !"), 1)));
    cr_assert(eq(int, 0, list_insert_at(list2, strdup("This is my tail 2-1 !"), -1)));
    cr_assert(eq(int, 0, list_insert_at(list2, strdup("This is my tail 2 !"), 2)));
    cr_assert(eq(int, 0, list_equal(list1, list2, NULL)));
    cr_assert(eq(int, 1, list_equal(list1, list1, NULL)));
    cr_assert(eq(int, 1, list_equal(list2, list2, NULL)));
    cr_assert(eq(int, 1, list_equal(list1, list2, my_strcmp)));
    free(list_remove_at(list2, -1));
    cr_assert(eq(int, 3, list_count(list2)));
    list_destroy(list1);
    list_destroy(list2);
}

Test(list_equal, test_impl_address_cmp)
{
    list_t *list1 = list_new(NULL);
    list_t *list2 = list_new(NULL);

    cr_assert(eq(int, 0, list_insert_at(list1, "This is my head !", 0)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail !", 1)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail 2-1 !", -1)));
    cr_assert(eq(int, 0, list_insert_at(list1, "This is my tail 2 !", 2)));
    cr_assert(eq(int, 0, list_push_back(list2, list_value_at(list1, 0))));
    cr_assert(eq(int, 0, list_push_back(list2, list_value_at(list1, 1))));
    cr_assert(eq(int, 0, list_push_back(list2, list_value_at(list1, 2))));
    cr_assert(eq(int, 0, list_push_back(list2, list_value_at(list1, 3))));
    cr_assert(eq(int, 1, list_equal(list1, list2, NULL)));
    cr_assert(eq(int, 1, list_equal(list1, list2, my_strcmp)));
    list_destroy(list1);
    list_destroy(list2);
}
