#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

static void destroy_elem(void *elem)
{
    free(elem);
}

Test(list_destroy, no_list)
{
    list_destroy(NULL);
}

Test(list_destroy, destroy_elem)
{
    list_t *list = list_new(&destroy_elem);

    list_destroy(list);
}
