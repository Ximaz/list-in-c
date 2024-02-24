#include <stdlib.h>
#include "list.h"

void list_destroy(list_t *list)
{
    list_elems_destroy(list);
    free(list);
}
