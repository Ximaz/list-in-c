/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_new.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

Test(list_new, no_destroy_elem)
{
    list_t *list = list_new(NULL);

    cr_assert(eq(int, 0, list_count(list)));
    cr_assert(eq(ptr, NULL, list->destroy));
    cr_assert(eq(ptr, NULL, list->elems_head));
    cr_assert(eq(ptr, NULL, list->elems_tail));
    list_destroy(list);
}

Test(list_new, destroy_elem)
{
    list_t *list = list_new(&free);

    cr_assert(eq(int, 0, list_count(list)));
    cr_assert(eq(ptr, &free, list->destroy));
    cr_assert(eq(ptr, NULL, list->elems_head));
    cr_assert(eq(ptr, NULL, list->elems_tail));
    list_destroy(list);
}
