#ifndef SORTS_H
#define SORTS_H

// Swaps the items at index i and j if they are both non-negative and array is
// not null. Otherwise does nothing.
void sortsSwap(int *array, int i, int j);

// Sorts the array using quicksort if array is not null. It is assumed right is
// bigger than left, and nothing will happen if it is not. Can handle very
// large arrays (prevents index overflow).
void sortsQuick(int *array, int left, int right);

#endif
