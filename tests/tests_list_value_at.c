#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static void destroy_elem(void *elem)
{
    free(elem);
}

Test(list_value_at, test_impl)
{
    list_t *list = list_new(&destroy_elem);

    cr_assert(eq(ptr, NULL, list_value_at(list, -1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my head !"), 0)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail !"), 1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail 2-1 !"), -1)));
    cr_assert(eq(int, 0, list_insert_at(list, strdup("This is my tail 2 !"), 2)));
    cr_assert(eq(int, 4, list_count(list)));
    cr_assert(eq(str, "This is my head !", list_value_at(list, 0)));
    cr_assert(eq(str, "This is my tail !", list_value_at(list, 1)));
    cr_assert(eq(str, "This is my tail 2 !", list_value_at(list, 2)));
    cr_assert(eq(str, "This is my tail 2-1 !", list_value_at(list, 3)));
    cr_assert(eq(str, "This is my tail 2-1 !", list_value_at(list, -1)));
    cr_assert(eq(ptr, NULL, list_value_at(list, 4)));
    list_destroy(list);
}
