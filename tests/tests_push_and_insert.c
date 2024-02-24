#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static void destroy_elem(void *elem)
{
    free(elem);
}

Test(list_push_back, test_impl)
{
    list_t *list = list_new(&destroy_elem);

    cr_assert(eq(int, 0, list_push_back(list, strdup("Hello, World !"))));
    cr_assert(eq(int, 0, list_push_back(list, strdup("This is my tail !"))));
    cr_assert(eq(int, 2, list_count(list)));
    cr_assert(eq(str, "Hello, World !", list->elems_head->elem));
    cr_assert(eq(str, "This is my tail !", list->elems_tail->elem));
    list_destroy(list);
}

Test(list_push_front, test_impl)
{
    list_t *list = list_new(&destroy_elem);

    cr_assert(eq(int, 0, list_push_front(list, strdup("Hello, World !"))));
    cr_assert(eq(int, 0, list_push_front(list, strdup("This is my head !"))));
    cr_assert(eq(int, 2, list_count(list)));
    cr_assert(eq(str, "This is my head !", list->elems_head->elem));
    cr_assert(eq(str, "Hello, World !", list->elems_tail->elem));
    list_destroy(list);
}

Test(list_insert_at, test_impl)
{
    list_t *list = list_new(&destroy_elem);

    cr_assert(eq(int, -1, list_insert_at(list, NULL, -1)));
    cr_assert(eq(int, -1, list_insert_at(list, NULL, 1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my head !"), 0)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail !"), 1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail 2-1 !"), -1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail 2 !"), 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(str, "This is my head !", list->elems_head->elem));
    cr_assert(eq(str, "This is my tail !", list->elems_head->next->elem));
    cr_assert(eq(str, "This is my tail 2 !", list->elems_head->next->next->elem));
    cr_assert(eq(str, "This is my tail 2-1 !", list->elems_head->next->next->next->elem));
    list_destroy(list);
}
