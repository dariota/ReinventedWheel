#ifndef ARRAYS_H
#define ARRAYS_H

// Prints the given array in the range given. Does nothing if end < start or 
// array is null. Adds a newline after the array is printed.
void arraysPrintD(double *array, int start, int end);
void arraysPrintI(int *array, int start, int end);
void arraysPrintUC(unsigned char *array, int start, int end);

// Sums the range from start to end, attempting to avoid floating point
// rounding errors on addition of large numbers to small.
// Returns NaN if end is smaller than start, either one is negative, or array 
// is null. Returns 0 if the range is 0.
// Uses auxiliary space equal to the size of the range.
//
// NOTE: Check for NaN by checking for inequality with isnan(double).
// (x == NAN) DOES NOT WORK
double arraysSumD(double *array, int start, int end);

#endif
