#include "arrays.h"

int L, R;

void sortsSwap(int *array, int i, int j) {
	if (!array || i < 0 || j < 0) return;

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

void sortsQuick(int *array, int left, int right) {
	if (right - left <= 0 || !array) return;

	sortsPartition(array, left, right, left / 2 + right / 2 + (left % 2 + right % 2) / 2);

	int myR = R;
	sortsQuick(array, left, L);
	sortsQuick(array, myR, right);
}
