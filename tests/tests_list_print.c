/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** tests_list_print.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "list.h"

Test(list_print, test_impl, .init = cr_redirect_stdout)
{
    list_t list = { 0 };
    char expected[1024] = { 0 };

    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    sprintf(expected, "{[%p](%p)}->{[%p](%p)}->{[%p](%p)}\n",
        list.elems_head->elem, (void *) list.elems_head,
        list.elems_head->next->elem, (void *) list.elems_head->next,
        list.elems_head->next->next->elem, (void *) list.elems_head->next->next
    );
    list_print(&list);
    cr_assert_stdout_eq_str(expected);
    list_clear(&list);
}
