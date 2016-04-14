#include <stdio.h>

int L, R;

void sortsPartition(int* array, int leftInd, int rightInd, int pivotVal) {
	printf("Partitioning index %d to %d on %d.\nBefore: ", leftInd, rightInd, pivotVal);

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
	int highInd = rightInd;
	for (int i = leftInd; i <= highInd;) {
		if (array[i] <= pivotVal) {
			i++;
		} else {
			int tmp = array[highInd];
			array[highInd--] = array[i];
			array[i] = tmp;
		}
	}

	printf("After: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	getchar();

	R = highInd;
	L = R - 1;
}

void sortsQuicksort(int *array, int left, int right) {
	sortsPartition(array, left, right, array[(left + right + 1) / 2]);
	int myR = R;
	printf("Left %d\n", L);
	if (left < L) {
		sortsQuicksort(array, left, L);
	}
	printf("Right %d %d\n", myR, R);
	if (right > myR) {
		sortsQuicksort(array, myR, right);
	}
}

int main(void) {
	int array[10] = {2, 5, 0, 6, 3, 4, 1, 9, 8, 7};
	sortsQuicksort(array, 0, 9);
	return 0;
}
