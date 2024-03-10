/*
** EPITECH PROJECT, 2024
** Tests of List in C
** File description:
** tests_list_destroy.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "list.h"

Test(list_destroy, no_list)
{
    list_destroy(NULL);
}

Test(list_destroy, destroy_elem)
{
    list_t *list = list_new(&free);

    list_destroy(list);
}
