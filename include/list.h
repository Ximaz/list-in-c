/*
** EPITECH PROJECT, 2024
** List in C
** File description:
** list.h
*/

#ifndef __LIST_H_
    #define __LIST_H_

    #include <stddef.h>

/**
 * @brief Function used upon element destruction for custom memory release
 *
 * @param[in] elem
 */
typedef void (*list_destroy_t)(void *elem);

typedef struct s_list_elem {
    void *elem;
    struct s_list_elem *prev;
    struct s_list_elem *next;
} list_elem_t;

typedef struct s_list {
    long count;
    list_destroy_t destroy;
    list_elem_t *elems_head;
    list_elem_t *elems_tail;
} list_t;

/**
 * @brief Predicate functions to act on the element depending on the context
 *
 * @param[in] elem
 * @return 0 to operate, non-0 to ignore
 */
typedef int (*list_predicate_t)(const void *elem);

/**
 * @brief Function usd to duplicate the memory of an element
 *
 * @param[in] elem
 */
typedef void *(*list_copy_t)(const void *elem);

/**
 * @brief This function type will be used to compare two elements
 *
 * Two elements will be considered equals if a call to this function returns
 * 0.
 *
 * @param[in] expected the element to find the index of
 * @param[in] elem the current element
 */
typedef int (*list_cmp_t)(const void *expected, const void *elem);

/**
 * @brief This function shoud be able to transform (or not) an element
 *
 * @param[in] elem
 * @return The new element
 */
typedef void *(*list_map_t)(const void *elem);

/**
 * @brief This function should be able to reduce two elements in one
 *
 * @param[in] acc the accumulator
 * @param[in] elem the element to reduce
 * @param[in] index the index of the 'elem'
 * @param[in] list the list that holds the 'elem' at 'index'
 * @return The new accumulator / last value to store
 */
typedef void *(*list_reduce_t)(const void *acc, const void *elem, long index,
    const list_t *list);

/**
 * @brief Modifies the existing element
 */
typedef void (*list_apply_t)(void *elem);

/**
 * @brief This function should return the difference between elem_a and elem_b.
 *
 * If (elem_a - elem_b) < 0 then elem_a is considered < to elem_b
 * If (elem_a - elem_b) == 0 then elem_a is considered == to elem_b
 * If (elem_a - elem_b) > 0 then elem_a is considered > to elem_b
 *
 * @param[in] elem_a
 * @param[in] elem_b
 * @return elem_a - elem_b
*/
typedef int (*list_sort_t)(const void *elem_a, const void *elem_b);

/* Constructor & Destructor */

list_t *list_new(list_destroy_t destroy);

void list_destroy(list_t *list);

/**
 * @brief Transforms a generic array to a list
 *
 * @param[in] array
 * @param[in] size The size of the array
 * @param[in] destroy [OPT] The destructor for array's elem (may be NULL)
 * @return The new list on success, NULL on error
 */
list_t *array_to_list(void *const *const array, long size,
    list_destroy_t destroy);

/**
 * @brief Transforms a list to a generic array
 *
 * @param[in] list The list to convert to an array
 * @return heap-allocated array on success, NULL otherwise
 */
void **list_to_array(const list_t *list, unsigned long elem_size);

/* Getters */

/**
 * @brief Returns the number of elements inside the list
 *
 * @param[in] list
 */
long list_count(const list_t *list);

/**
 * @brief Returns the index of an element
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] cmp the function to compare elements with
 */
long list_index_of(const list_t *list, const void *elem, list_cmp_t cmp);

/**
 * @brief Returns the element for the given index
 *
 * @param[in] list
 * @param[in] index
 * @return the element on success, NULL on error (Out-Of-Range)
 */
void *list_value_at(const list_t *list, long index);

/* Operators */

/**
 * @brief Compares the element of each list to check if they are the same.
 *
 * If the compare function is equal to NULL, then elements will be determined
 * equal based on their memory address.
 *
 * @param[in] list1
 * @param[in] list2
 * @param[in] cmp the function to compare elements with (may be NULL)
 * @return 1 if equal, 0 otherwise
 */
int list_equal(const list_t *list1, const list_t *list2, list_cmp_t cmp);

/* Insertion */

/**
 * @brief Pushes an element at the front of the list
 *
 * O-o-o-o-o-o
 *
 * @param[in] list
 * @param[in] elem
 * @return 0 on success, -1 on error
 */
int list_push_front(list_t *list, void *elem);

/**
 * @brief Pushes an element at the given index of the list.
 *
 * O-o-o-o-o-o
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] index
 * @return 0 on success, -1 on error (Out-Of-Range)
 */
int list_insert_at(list_t *list, void *elem, long index);

/**
 * @brief Pushes an element at the back of the list
 *
 * o-o-o-o-o-O
 *
 * @param[in] list
 * @param[in] elem
 * @return 0 on success, -1 on error
 */
int list_push_back(list_t *list, void *elem);

/* Suppression */

/**
 * @brief Pops an element from the front of the list
 *
 * X-o-o-o-o-o
 *
 * @param[in] list
 * @param[in] elem
 * @return the pop'd element if any, NULL otherwise
 */
void *list_pop_front(list_t *list);

/**
 * @brief Pops an element from the given index of the list
 *
 * o-o-o-X-o-o
 *
 * @param[in] list
 * @param[in] elem
 * @return the pop'd element if any, NULL otherwise
 */
void *list_remove_at(list_t *list, long index);

/**
 * @brief Pops an element from the back of the list
 *
 * o-o-o-o-o-X
 *
 * @param[in] list
 * @param[in] elem
 * @return the pop'd element if any, NULL otherwise
 */
void *list_pop_back(list_t *list);

/* Operations */

/**
 * @brief Removes all the elements of the list
 *
 * Uses the list_destroy_t function passed upon initialization
 *
 * @param[in] list
 */
void list_clear(list_t *list);

/**
 * @brief Reverse the current list by allocating a new one
 *
 * @param[in] list
 * @return the reversed list in success, NULL otherwise
 */
list_t *list_reverse(const list_t *list);

/**
 * @brief Reverse the current list itself, no allocation of any kind
 *
 * @param[in] list
 */
void list_reverse_itself(list_t *list);

/**
 * @brief Reverse the current list into the output one
 *
 * @param[in] list
 * @param[out] output
 * @return 0 on success, -1 otherwise
 */
int list_reverse_into(const list_t *list, list_t *output);

/**
 * @brief Slices a list from 'from' to 'to' (excluded) into a new allocated one
 *
 * @param[in] list
 * @param[in] from
 * @param[in] to (excluded)
 */
list_t *list_slice(const list_t *list, long from, long to);

/**
 * @brief Slices the current list itself, no allocation of any kind. All
 * Out-Of-Range items that are not part of the list anymore are free'd using
 * the destroy function if provided.
 *
 * @param[in] list
 * @param[in] from
 * @param[in] to (excluded)
 * @return 0 on success, -1 otherwise, the list is unchanged (Out-Of-Range)
 */
int list_slice_itself(list_t *list, long from, long to);

/**
 * @brief Slices a list from 'from' to 'to' (excluded) into the output list
 *
 * @param[in] list
 * @param[in] from
 * @param[in] to (excluded)
 * @param[out] output
 * @return 0 on success, -1 otherwise (Out-Of-Range)
 */
int list_slice_into(const list_t *list, long from, long to, list_t *output);

/**
 * @brief Copies the current list into a new allocated one
 *
 * @param[in] list
 */
list_t *list_copy(const list_t *list);

/**
 * @brief Copies the current list into the output one
 *
 * @param[in] list
 * @param[out] output
 * @return 0 on success, -1 otherwise
 */
int list_copy_into(const list_t *list, list_t *output);

/**
 * @brief Deeply copies the current list into a new allocated one
 *
 * if the destroy function is NULL, the destroy function of `list` is passed
 * to the new list.
 *
 * @param[in] list
 * @param[in] copy the copy function used to duplicate elements
 * @param[in] destroy the destroy element function to pass to the new list
 */
list_t *list_deep_copy(const list_t *list, list_copy_t copy,
    list_destroy_t destroy);

/**
 * @brief Deeply copies the current list into the output one
 *
 * if the `copy` argument is NULL, the result of this function is the same as
 * `list_copy_into`.
 *
 * @param[in] list
 * @param[in] copy the copy function used to duplicate elements
 * @param[out] output
 * @return 0 on success, -1 otherwise
 */
int list_deep_copy_into(const list_t *list, list_copy_t copy,
    list_t *output);

/* Functionnal functions */

/**
 * @brief Maps each elements of the list into a new allocated one
 *
 * @param[in] list
 * @param[in] map
 * @param[in] destroy the function to destroy generated map elements
 */
list_t *list_map(const list_t *list, list_map_t map,
    list_destroy_t destroy);

/**
 * @brief Maps each elements of the list into itself
 *
 * @param[in] list
 * @param[in] map
 * @param[in] destroy the function to destroy generated map elements
 */
void list_map_itself(list_t *list, list_map_t map, list_destroy_t destroy);

/**
 * @brief Maps each elements of the list into output
 *
 * @param[in] list
 * @param[in] map
 * @param[out] output
 */
void list_map_into(const list_t *list, list_map_t map, list_t *output);

/**
 * @brief This function filters all the elements of the list into a new one
 *
 * @param[in] list
 * @param[in] predicate
 */
list_t *list_filter(const list_t *list, list_predicate_t predicate);

/**
 * @brief This function filters all the elements of the list into itself
 *
 * @param[in] list
 * @param[in] predicate
 */
void list_filter_itself(list_t *list, list_predicate_t predicate);

/**
 * @brief This function filters all the elements of the list into output
 *
 * @param[in] list
 * @param[in] predicate
 * @param[out] output
 */
void list_filter_into(const list_t *list, list_predicate_t predicate,
    list_t *output);

/**
 * @brief This function reduces all the elements of a list into a single one
 *
 * @param[in] list
 * @param[in] reduce
 * @param[in] acc [OPT] the starting accumulator. if NULL, 1st elem of the list
 * @param[in] acc_destroy [OPT] the previous accumulator destroyer
 */
void *list_reduce(const list_t *list, list_reduce_t reduce, void *acc,
    list_destroy_t acc_destroy);

/* Algorithm */

/**
 * @brief Sorts all the elements of the list into output
 *
 * @param[in] list
 * @param[in] sort
 * @param[out] output
 */
void list_sort_into(const list_t *list, list_sort_t sort, list_t *output);

/**
 * @brief Sorts all the elements of the list into a new allocated one
 *
 * @param[in] list
 * @param[in] sort
 */
list_t *list_sort(const list_t *list, list_sort_t sort);

/**
 * @brief Sorts all the elements of the list into itself
 *
 * @param[in] list
 * @param[in] sort
 */
void list_sort_itself(list_t *list, list_sort_t sort);

/**
 * @brief Prints the current list to the STDOUT in the following format :
 * {[ELEM_ADDR](NODE_ADDR)}-><next>
 *
 * @param[in] list
 */
void list_print(const list_t *list);

/**
 * @brief Returns whether or not the list includes an element.
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] cmp the function to compare elements with (may be NULL)
 * @return 1 if list includes the elem, 0 otherwise
 */
int list_includes(const list_t *list, const void *elem, list_cmp_t cmp);

/**
 * @brief Returns whether or not all elements respect a certain condition
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] predicate
 * @return 1 if all elements are validated, 0 otherwise
 */
int list_all(const list_t *list, list_predicate_t predicate);

/**
 * @brief Returns whether or not any element respects a certain condition
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] predicate
 * @return 1 if any element is validated, 0 otherwise
 */
int list_any(const list_t *list, list_predicate_t predicate);

/**
 * @brief Extends the output list from the input list
 *
 * Both output and input must have the same destroyer function. Else, -1 will
 * be returned.
 *
 * @param[out] output
 * @param[in] input
 * @returns 0 on success, -1 on error
 */
int list_extend(list_t *output, const list_t *input);

/**
 * @brief Deeply extends the output list from the input list
 *
 * Both output and input must have the same destroyer function. Else, -1 will
 * be returned.
 *
 * @param[out] output
 * @param[in] input
 * @param[in] copy may be NULL, calling list_extend instead
 * @returns 0 on success, -1 on error
 */
int list_deep_extend(list_t *output, const list_t *input, list_copy_t copy);

/**
 * @brief Applies a function to each elements of the list
 *
 * @param[in] list
 * @param[in] apply
 */
void list_apply(list_t *list, list_apply_t apply);

#endif /* __LIST_H_ */
