#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void arraysPrintD(double *array, int start, int end) {
	if (!array || end - start <= 0 || start < 0 || end < 0) return;

	for (int i = start; i <= end; i++) {
		printf("%f ", array[i]);
	}
	printf("\n");
}

void arraysPrintI(int *array, int start, int end) {
	if (!array || end - start <= 0 || start < 0 || end < 0) return;

	for (int i = start; i <= end; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void arraysPrintUC(unsigned char *array, int start, int end) {
	if (!array || end - start <= 0 || start < 0 || end < 0) return;

	for (int i = start; i <= end; i++) {
		printf("%x ", array[i]);
	}
	printf("\n");
}

double arraysSumD(double *array, int start, int end) {
	if (!array ||  end - start < 0 || start < 0 || end < 0) return NAN;

	int len = end - start + 1;
	double *copy = malloc(sizeof(double) * len);
	for (int i = 0; i < len; i++) {
		copy[i] = array[i + start];
	}

	for (int gap = 1; gap < len; gap *= 2) {
		arraysPrintD(copy, 0, len);
		for (int i = 0; i + gap < len; i += gap * 2) {
			printf("Adding pos %d (%f) to pos %d (%f)\n", i, copy[i], i + gap, copy[i + gap]);
			copy[i] += copy[i + gap];
		}
	}

	double result = copy[0];
	free(copy);

	return result;
}
