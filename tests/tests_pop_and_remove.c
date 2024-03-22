/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_pop_and_remove.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

Test(list_pop_back, test_impl)
{
    char *s1 = NULL;
    char *s2 = NULL;
    list_t *list = list_new(&free);

    cr_assert(eq(int, 0, list_push_back(list, strdup("Hello, World !"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("This is my tail !"))));
    cr_assert(eq(long, 2, list_count(list)));
    s2 = list_pop_back(list);
    cr_assert(eq(long, 1, list_count(list)));
    s1 = list_pop_back(list);
    cr_assert(eq(long, 0, list_count(list)));
    cr_assert(eq(str, "Hello, World !", s1));
    cr_assert(eq(str, "This is my tail !", s2));
    free(s2);
    free(s1);
    list_destroy(list);
}

Test(list_pop_front, test_impl)
{
    char *s1 = NULL;
    char *s2 = NULL;
    list_t *list = list_new(&free);

    cr_assert(eq(int, 0, list_push_back(list, strdup("This is my head !"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("Hello, World !"))));
    cr_assert(eq(long, 2, list_count(list)));
    s1 = list_pop_front(list);
    cr_assert(eq(long, 1, list_count(list)));
    s2 = list_pop_front(list);
    cr_assert(eq(long, 0, list_count(list)));
    cr_assert(eq(str, "This is my head !", s1));
    cr_assert(eq(str, "Hello, World !", s2));
    free(s2);
    free(s1);
    list_destroy(list);
}

Test(list_remove_at, test_impl)
{
    char *s1 = NULL;
    char *s2 = NULL;
    char *s3 = NULL;
    char *s4 = NULL;
    char *s5 = NULL;
    list_t *list = list_new(&free);

    cr_assert(eq(ptr, NULL, list_remove_at(list, -1)));
    cr_assert(eq(ptr, NULL, list_remove_at(list, 1)));
    cr_assert(eq(int, 0, list_push_back(list, strdup("String 1"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("String 2"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("String 3"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("String 4"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("String 5"))));
    s4 = list_remove_at(list, 3);
    s3 = list_remove_at(list, 2);
    s1 = list_remove_at(list, 0);
    s2 = list_remove_at(list, 0);
    s5 = list_remove_at(list, -1);
    cr_assert(eq(str, "String 1", s1));
    cr_assert(eq(str, "String 2", s2));
    cr_assert(eq(str, "String 3", s3));
    cr_assert(eq(str, "String 4", s4));
    cr_assert(eq(str, "String 5", s5));
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
    list_destroy(list);
}
