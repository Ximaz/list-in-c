/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_apply.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <unistd.h>
#include "list.h"

typedef struct s_elem {
    void *elem;
    int status;
} elem_t;

static void apply(void *e)
{
    elem_t *elem = (elem_t *) e;

    write(STDOUT_FILENO, (char const *) elem->elem,
        strlen((char const *) elem->elem));
    elem->status = 1;
}

Test(list_apply, test_impl, .init = cr_redirect_stdout)
{
    list_t list = { 0 };
    elem_t elems[] = {
        { .elem = "A", 0 },
        { .elem = "AB", 0 },
        { .elem = "ABC", 0 },
    };

    cr_assert(eq(int, 0, list_push_back(&list, &elems[0])));
    cr_assert(eq(int, 0, list_push_back(&list, &elems[1])));
    cr_assert(eq(int, 0, list_push_back(&list, &elems[2])));
    list_apply(&list, apply);
    cr_assert(eq(int, 1, ((elem_t *) (list_value_at(&list, 0)))->status));
    cr_assert(eq(int, 1, ((elem_t *) (list_value_at(&list, 1)))->status));
    cr_assert(eq(int, 1, ((elem_t *) (list_value_at(&list, 2)))->status));
    list_clear(&list);
    cr_assert_stdout_eq_str("AABABC");
}
