/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list_destroy.c
*/

#include <stdlib.h>
#include "list.h"

void list_destroy(list_t *list)
{
    list_clear(list);
    free(list);
}
