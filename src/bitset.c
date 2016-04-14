#include <stdlib.h>
#include "bitset.h"

struct bitset *bset_new(int size) {
	struct bitset *myBitset = malloc(sizeof(struct bitset));
	myBitset->bitSize = size;
	size = size % 8 == 0 ? size : size + 8 - size % 8;
	myBitset->byteSize = size/8;
	myBitset->values = malloc(size/8);
	return my_bitset;
}

// LSB is bit 0
int bset_lookup(struct bitset *self, int item) {
	if (item < 0 || item >= self->bitSize)
		return -1;
	return (self->values[item/8] >> (item % 8)) & 1;
}

int bset_add(struct bitset *self, int item) {
	if (item < 0 || item >= self->bitSize)
		return 0;
	self->values[item/8] = self->values[item/8] | (1 << (item % 8));
	return 1;
}

int bset_remove(struct bitset *self, int item) {
	if (item < 0 || item >= self->bitSize)
		return 0;
	self->values[item/8] = self->values[item/8] & ~(1 << (item % 8));
	return 1;
}

// assume dest is the same length as src1 and src2
void bset_union(struct bitset * dest, struct bitset * src1,
                  struct bitset * src2) {
	for (int i = 0; i < dest->byteSize; i++) {
		dest->values[i] = src1->values[i] | src2->values[i];
	}
}

void bset_intersect(struct bitset * dest, struct bitset * src1,
                      struct bitset * src2) {
	for (int i = 0; i < dest->byteSize; i++) {
		dest->values[i] = src1->values[i] & src2->values[i];
	}
}

void bset_free(struct bitset *set) {
	free(set->values);
	free(set);
}
