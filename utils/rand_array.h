#pragma once

#include "../algo_interface/algo_interface.h"
#include <stdlib.h>

/**
 * @brief create an array of random int
 *
 * @param size the size of the array
 * @return int* the produced array
 */
rand_array_t rand_array_init(const size_t size);

/**
 * @brief free the given rand_array
 *
 * @param ptr
 */
void rand_array_free(rand_array_t *ra);

/**
 * @brief Check if the given `rand_array_t` is sorted
 *
 * @param ra the array to check
 * @return int non-zero if sorted, 0 otherwise
 */
int rand_array_is_sorted(const rand_array_t ra);

/**
 * @brief Print the given rand_array_t (size and elements)
 *
 * @param ra the array to print
 */
void print_rand_array(const rand_array_t ra);
