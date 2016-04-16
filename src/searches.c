int searchesBinary(int *array, int low, int high, int key) {
	if (!array || low < 0 || high < 0) return -1;
	
	if (low >= high) {
		if (array[low] == key) {
			return low;
		} else {
			return -1;
		}
	}

	int ind = (low + high) / 2;

	if (array[ind] == key) {
		return ind;
	} else if (key > array[ind]) {
		return searchesBinary(array, ind + 1, high, key);
	} else {
		return searchesBinary(array, low, ind - 1, key);
	}
}
