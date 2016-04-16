#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

#include "bitBuffer.h"
#include "error.h"

#include <stdio.h>

struct bitBuffer *bufferFromStore(unsigned char *store, int symbolLen,
                                  int width) {
	struct bitBuffer *buffer = malloc(sizeof(struct bitBuffer));
	if (!buffer) errorOutOfMemory(); 

	buffer->store = store;
	buffer->bitLength = symbolLen * width;
	buffer->bitWidth = width;
	bufferReset(buffer);

	buffer->mask = 0;
	for (int i = 0; i < width; i++) {
		buffer->mask <<= 1;
		buffer->mask |= 1;
	}

	return buffer;
}

struct bitBuffer *bufferNew(int symbolLen, int width) {
	int bits = symbolLen * width;
	unsigned char *store = malloc(bits / CHAR_BIT +
	                              (bits % CHAR_BIT ? 1 : 0));
	if (!store) errorOutOfMemory();
	
	return bufferFromStore(store, symbolLen, width);
}

void bufferFree(struct bitBuffer *buffer) {
	if (!buffer) return;

	free(buffer->store);
	free(buffer);
}

void bufferFreeNotStore(struct bitBuffer *buffer) {
	free(buffer);
}

int bufferAppend(struct bitBuffer *buffer, unsigned char bits) {
	if (!buffer || buffer->bitLength < buffer->bitWritePos + buffer->bitWidth) {
		return 0;
	}

	bits = bits && buffer->mask;

	int charInd = buffer->bitWritePos / CHAR_BIT;
	int bitInd = CHAR_BIT - buffer->bitWritePos % CHAR_BIT;

	if (bitInd < buffer->bitWidth) {
		int rShift = (buffer->bitWidth - bitInd);
		buffer->store[charInd] &= ~(buffer->mask >> rShift);
		buffer->store[charInd] |= bits >> rShift;

		int lShift = (CHAR_BIT - buffer->bitWidth);
		buffer->store[charInd + 1] &= ~(buffer->mask << lShift);
		buffer->store[charInd + 1] |= bits << lShift;
	} else {
		int lShift = bitInd - buffer->bitWidth;
		buffer->store[charInd] &= ~(buffer->mask << lShift);
		buffer->store[charInd] |= bits << lShift;
	}

	buffer->bitWritePos += buffer->bitWidth;
	
	return 1;
}

int bufferRead(struct bitBuffer *buffer, unsigned char *result) {
	if (!buffer || buffer->bitLength < buffer->bitReadPos + buffer->bitWidth) {
		return 0;
	}

	*result = 0;
	int charInd = buffer->bitReadPos / CHAR_BIT;
	int bitInd = CHAR_BIT - buffer->bitReadPos % CHAR_BIT;

	if (charInd != (buffer->bitReadPos + buffer->bitWidth - 1) / CHAR_BIT) {
		*result = (buffer->store[charInd] << (buffer->bitWidth - bitInd))
		          & buffer->mask;
		*result |= (buffer->store[charInd + 1] >> (buffer->bitWidth + bitInd))
		           & buffer->mask;
	} else {
		*result = (buffer->store[charInd] >> (bitInd - buffer->bitWidth))
		          & buffer->mask;
	}
	
	buffer->bitReadPos += buffer->bitWidth;

	return 1;
}


void bufferReset(struct bitBuffer *buffer) {
	if (!buffer) return;

	buffer->bitWritePos = buffer->bitReadPos = 0;
}

void bufferReadReset(struct bitBuffer *buffer) {
	if (!buffer) return;

	buffer->bitReadPos = 0;
}

void bufferWriteReset(struct bitBuffer *buffer) {
	if (!buffer) return;

	buffer->bitWritePos = 0;
}
