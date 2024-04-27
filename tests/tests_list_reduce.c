/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** tests_list_reduce.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

static void *reduce(const void *acc, const void *current,
    long index __attribute__((unused)),
    const list_t *list __attribute__((unused)))
{
    unsigned long long a = (unsigned long long) acc;
    unsigned long long c = (unsigned long long) current;
    return (void *) a + c;
}

static void *reduce_str(const void *acc, const void *current,
    long index __attribute__((unused)),
    const list_t *list __attribute__((unused)))
{
    char const *a = acc;
    char const *c = current;
    char *reduced = calloc(strlen(a) + strlen(c) + 1, sizeof(char));
    strcpy(reduced, a);
    strcat(reduced, c);
    return reduced;
}

Test(list_reduce, test_impl)
{
    list_t list = { 0 };

    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 5)));
    cr_assert(eq(ptr, (void *) 15, list_reduce(&list, reduce, NULL, NULL)));
    list_clear(&list);
}

Test(list_reduce, test_impl_default_acc)
{
    list_t list = { 0 };

    cr_assert(eq(int, 0, list_push_back(&list, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 3)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 4)));
    cr_assert(eq(int, 0, list_push_back(&list, (void *) 5)));
    cr_assert(eq(ptr, (void *) 20, list_reduce(&list, reduce, (void *) 5, NULL)));
    list_clear(&list);
}

Test(list_reduce, test_impl_destroy)
{
    list_t list = { 0 };
    char *reduced = NULL;

    list.destroy = &free;
    cr_assert(eq(int, 0, list_push_back(&list, strdup("a"))));
    cr_assert(eq(int, 0, list_push_back(&list, strdup("b"))));
    cr_assert(eq(int, 0, list_push_back(&list, strdup("c"))));
    cr_assert(eq(int, 0, list_push_back(&list, strdup("d"))));
    cr_assert(eq(int, 0, list_push_back(&list, strdup("e"))));
    reduced = list_reduce(&list, reduce_str, NULL, free);
    cr_assert(eq(str, "abcde", reduced));
    list_clear(&list);
    free(reduced);
}

Test(list_reduce, test_impl_empty)
{
    list_t list = { 0 };

    cr_assert(eq(ptr, NULL, list_reduce(&list, reduce_str, NULL, free)));
    cr_assert(eq(ptr, (void *) 0xdeadbeef, list_reduce(&list, reduce, (void *) 0xdeadbeef, NULL)));
}