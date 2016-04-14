#ifndef BITSET_H
#define BITSET_H

struct bitset {
	int bitSize;
	int byteSize;
	unsigned char *values;
};

struct bitset *bset_new(int size);
int bset_lookup(struct bitset *self, int item);
int bset_add(struct bitset *self, int item);
int bset_remove(struct bitset *self, int item);
void bset_union(struct bitset *dest, struct bitset *src1,
                  struct bitset *src2);
void bset_intersect(struct bitset *dest, struct bitset *src1,
                      struct bitset *src2);
void bset_free(struct bitset *set);

#endif
