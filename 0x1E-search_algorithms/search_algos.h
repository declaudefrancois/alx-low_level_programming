#ifndef SEARCH_ALGO_H
#define SEARCH_ALGO_H

#include <stdio.h>
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int binary_search_bound(int *array, size_t min, size_t max, int value);
void print_array(int *array, size_t start, size_t end);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGO_H */
