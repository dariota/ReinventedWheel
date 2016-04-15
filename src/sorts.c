#include <stdio.h>
#include <stdlib.h>

int L, R;

void sortsPrintArray(int* array, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void sortsSwap(int *array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void sortsPartition(int* array, int leftInd, int rightInd, int pivotInd) {
	int pivotVal = array[pivotInd];
	sortsSwap(array, leftInd, pivotInd);
	int split = leftInd + 1;

	for (int i = leftInd + 1; i <= rightInd; i++) {
		if (array[i] <= pivotVal) {
			split++;
			sortsSwap(array, i, split - 1);
		}
	}
	sortsSwap(array, leftInd, split-1);
	R = split;
	L = split - 2;
}

void sortsQuicksort(int *array, int left, int right) {
	if (right - left <= 0) return;

	sortsPartition(array, left, right, (left + right + 1) / 2);
	int myR = R;
	sortsQuicksort(array, left, L);
	sortsQuicksort(array, myR, right);
}

int main(void) {
	int array[10] = {2, 5 , 4 , 1, 3, 4, 9, 8, 10, 11};
	sortsQuicksort(array, 0, 9);
	sortsPrintArray(array, 10);
	return 0;
}
