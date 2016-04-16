#ifndef SEARCHES_H
#define SEARCHES_H

// Searches in the array between indices low and high, returning the index of
// the search key if found, or -1 otherwise.
// Also returns -1 if either low or high are less than 0, or array is null.
int searchesBinary(int *array, int low, int high, int key);

#endif
