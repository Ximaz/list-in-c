#ifndef __LIST_H_
    #define __LIST_H_
    #include <stddef.h>

typedef struct s_list_elem {
    void *elem;
    struct s_list *prev;
    struct s_list *next;
} list_elem_t;

typedef struct s_list {
    size_t count;
    list_elem_t *elems;
} list_t;

/* Constructor & Destructor */

list_t *list_new(void);

void list_destroy(void);

/* Getters */

/**
 * @brief Returns the number of elements inside the list
 *
 * @param[in] list
 */
size_t list_count(list_t const *list);

/**
 * @brief This function type will be used to compare two elements
 *
 * Two elements will be considered equals if a call to this function returns
 * 0.
 *
 * @param[in] expected the element to find the index of
 * @param[in] elem the current element
 */
typedef int (*list_index_of_cmp_t)(void *expected, void *elem);

/**
 * @brief Returns the index of an element
 *
 * @param[in] list
 * @param[in] elem
 * @param[in] cmp the function to compare elements with
 */
size_t list_index_of(list_t const *list, void *elem, list_index_of_cmp_t cmp);

/**
 * @brief Returns the element for the given index, or NULL if Out-Of-Range
 *
 * @param[in] list
 * @param[in] index
 */
void *list_value_at(list_t const *list, size_t index);

/* Insertion */

/**
 * @brief Pushes an element at the front of the list
 *
 * O-o-o-o-o-o
 *
 * @param[in] list
 * @param[in] elem
 */
void list_push_front(list_t *list, void *elem);

/**
 * @brief Pushes an element at the given index of the list.
 *
 * O-o-o-o-o-o
 *
 * @param[in] list
 * @param[in] elem
 * @return 0 on success, -1 on error (Out-Of-Range)
 */
int list_insert_at(list_t *list, void *elem, size_t index);

/**
 * @brief Pushes an element at the back of the list
 *
 * o-o-o-o-o-O
 *
 * @param[in] list
 * @param[in] elem
 */
void list_push_back(list_t *list, void *elem);

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
void *list_remove_at(list_t *list, size_t index);

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
 * @brief Function used to deallocate an element of the list
 */
typedef void (*list_clear_t)(void *elem);

/**
 * @brief Removes all the elements of the list
 *
 * @param[in] list
 * @param[in] clear [OPT] if specified, called on all elements
 */
void list_clear(list_t *list, list_clear_t clear);

/**
 * @brief Reverse the current list by allocating a new one
 *
 * @param[in] list
 */
list_t *list_reverse(list_t const *list);

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
 */
void list_reverse_into(list_t const *list, list_t *output);

/**
 * @brief Slices a list from 'from' to 'to' (excluded) into a new allocated one
 *
 * @param[in] list
 * @param[in] from
 * @param[in] to (excluded)
 */
list_t *list_slice(list_t const *list, size_t from, size_t to);

/**
 * @brief Slices a list from 'from' to 'to' (excluded) into the output list
 *
 * @param[in] list
 * @param[in] from
 * @param[in] to (excluded)
 * @param[out] output
 */
void list_slice_into(list_t const *list, size_t from, size_t to,
    list_t *output);

/**
 * @brief Function usd to duplicate the memory of an element
 */
typedef void *(*list_copy_t)(void const *elem);

/**
 * @brief Copies the current list into a new allocated one
 *
 * @param[in] list
 */
list_t *list_copy(list_t const *list);

/**
 * @brief Copies the current list into the output one
 *
 * @param[in] list
 * @param[out] output
 */
void list_copy_into(list_t const *list, list_t *output);

/**
 * @brief Deeply copies the current list into a new allocated one
 *
 * @param[in] list
 * @param[in] copy the copy function used to duplicate elements
 */
list_t *list_deep_copy(list_t const *list, list_copy_t copy);

/**
 * @brief Deeply copies the current list into the output one
 *
 * @param[in] list
 * @param[in] copy the copy function used to duplicate elements
 * @param[out] output
 */
void list_deep_copy_into(list_t const *list, list_copy_t copy, list_t *output);

/* Functionnal functions */

/**
 * @brief This function shoud be able to transform (or not) an element
 *
 * @param[in] elem
 * @return The new element
 */
typedef void *(*list_map_t)(void const *elem);

/**
 * @brief Maps each elements of the list into a new allocated one
 *
 * @param[in] list
 * @param[in] map
 */
list_t *list_map(list_t const *list, list_map_t map);

/**
 * @brief Maps each elements of the list into itself
 *
 * @param[in] list
 * @param[in] map
 */
void list_map_itself(list_t *list, list_map_t map);

/**
 * @brief Maps each elements of the list into output
 *
 * @param[in] list
 * @param[in] map
 * @param[out] output
 */
void list_map_into(list_t const *list, list_map_t map, list_t *output);

/**
 * @brief This function shoud be able to filter elements
 *
 * @param[in] elem
 * @return 0 (exclude) or 1 (include)
 */
typedef int (*list_filter_t)(void *elem);

/**
 * @brief This function filters all the elements of the list into a new one
 *
 * @param[in] list
 * @param[in] filter
 */
list_t *list_filter(list_t const *list, list_filter_t filter);

/**
 * @brief This function filters all the elements of the list into itself
 *
 * @param[in] list
 * @param[in] filter
 */
void list_filter_itself(list_t *list, list_filter_t filter);

/**
 * @brief This function filters all the elements of the list into output
 *
 * @param[in] list
 * @param[in] filter
 * @param[out] output
 */
void list_filter_into(list_t const *list, list_filter_t filter,
    list_t *output);

/**
 * @brief This function shoud be able to reduce two elements in one
 *
 * @param[in] acc the accumulator
 * @param[in] elem the element to reduce
 * @return The new accumulator / last value to store
 */
typedef void *(*list_reduce_t)(void *acc, void *elem);

/**
 * @brief This function reduces all the elements of a list into a single one
 *
 * @param[in] list
 * @param[in] filter
 * @param[in] acc [OPT] the starting accumulator. if NULL, 1st elem of the list
 */
void *list_reduce(list_t const *list, list_reduce_t reduce);

/* Algorithm */

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
typedef int (*list_sort_t)(void *elem_a, void *elem_b);

/**
 * @brief Sorts all the elements of the list into a new allocated one
 *
 * @param[in] list
 * @param[in] sort
 */
list_t *list_sort(list_t const *list, list_sort_t sort);

/**
 * @brief Sorts all the elements of the list into itself
 *
 * @param[in] list
 * @param[in] sort
 */
void list_sort_itself(list_t *list, list_sort_t sort);

/**
 * @brief Sorts all the elements of the list into output
 *
 * @param[in] list
 * @param[in] sort
 * @param[out] output
 */
void list_sort_into(list_t const *list, list_sort_t sort, list_t *output);

#endif /* __LIST_H_ */
