/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_map.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <unistd.h>
#include "list.h"

typedef struct s_string {
    char *str;
    size_t len;
} string_t;

static void *map(const void *e)
{
    char const *s = e;
    unsigned long long length = write(STDOUT_FILENO, e, strlen(s));
    return (void *) length;
}

static int my_strcmp(const void *e1, const void *e2)
{
    string_t const *s1 = e1;
    string_t const *s2 = e2;
    return strncmp(s1->str, s2->str, s1->len);
}

static void *map_str(const void *e)
{
    char const *s = e;
    string_t *string = calloc(1, sizeof(string_t));
    string->str = strdup(s);
    string->len = strlen(string->str);
    return string;
}

static void free_str(void *e)
{
    string_t *s = e;
    free(s->str);
    free(s);
}

static int my_cmp(const void *a, const void *b)
{
    return !(a == b);
}

Test(list_map, test_impl, .init = cr_redirect_stdout)
{
    list_t *list = list_new(NULL);
    list_t *expected = list_new(NULL);
    list_t *mapped = NULL;

    cr_assert(eq(int, 0, list_push_back(list, "A")));
    cr_assert(eq(int, 0, list_push_back(list, "AB")));
    cr_assert(eq(int, 0, list_push_back(list, "ABC")));
    cr_assert(eq(int, 0, list_push_back(expected, (void *) 1)));
    cr_assert(eq(int, 0, list_push_back(expected, (void *) 2)));
    cr_assert(eq(int, 0, list_push_back(expected, (void *) 3)));
    mapped = list_map(list, map, NULL);
    cr_assert(ne(ptr, NULL, mapped));
    cr_assert(eq(int, 1, list_equal(expected, mapped, my_cmp)));
    list_destroy(list);
    list_destroy(expected);
    list_destroy(mapped);
    cr_assert_stdout_eq_str("AABABC");
}

Test(list_map_itself, test_impl)
{
    list_t *list = list_new(&free);
    list_t *expected = list_new(NULL);
    string_t strings[] = {
        { .str = "A", 1 },
        { .str = "AB", 2 },
        { .str = "ABC", 3 },
    };

    cr_assert(eq(int, 0, list_push_back(list, strdup("A"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("AB"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("ABC"))));
    cr_assert(eq(int, 0, list_push_back(expected, &strings[0])));
    cr_assert(eq(int, 0, list_push_back(expected, &strings[1])));
    cr_assert(eq(int, 0, list_push_back(expected, &strings[2])));
    list_map_itself(list, map_str, free_str);
    cr_assert(eq(int, 1, list_equal(expected, list, my_strcmp)));
    cr_assert(eq(ptr, free_str, list->destroy));
    list_destroy(list);
    list_destroy(expected);
}
