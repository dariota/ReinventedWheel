#ifndef BITBUFFER_H
#define BITBUFFER_H

struct bitBuffer {
	unsigned char *store;
	int bitLength;
	int bitWidth;
	int bitWritePos;
	int bitReadPos;
	unsigned char mask;
};

// Create and initialises a buffer, using the character array for the store
// (assumes it's large enough to hold symbolLen symbols).
// Returns a pointer to the created buffer. Forcibly exits if malloc fails.
struct bitBuffer *bufferFromStore(unsigned char *store, int symbolLen,
                                  int width);
// Creates and initialises a buffer, mallocing enough memory for the store.
// Returns a pointer to the created buffer. Forcibly exits if malloc fails.
struct bitBuffer *bufferNew(int symbolLen, int width);

// Frees the bitBuffer struct and the store.
void bufferFree(struct bitBuffer *buffer);
// Frees the bitBuffer struct but not the store (useful to pass the store to
// something else after the bitBuffer is no longer needed).
void bufferFreeNotStore(struct bitBuffer *buffer);

// Appends the bitWidth least significant bits of bits to the contents of the
// buffer, advancing the write position.
// Returns 0 and writes nothing if the buffer is null or the write would exceed
// the length of the buffer. Otherwise writes the symbol and returns 1.
int bufferAppend(struct bitBuffer *buffer, unsigned char bits);
// Reads the next symbol into the least significant bits of result, advancing
// the read position.
// Returns 0 if the buffer is null or there are no more symbols. Otherwise
// reads the symbol and returns 1.
int bufferRead(struct bitBuffer *buffer, unsigned char *result);

// Resets the read and write positions.
void bufferReset(struct bitBuffer *buffer);
// Resets the read position.
void bufferReadReset(struct bitBuffer *buffer);
// Resets the write position.
void bufferWriteReset(struct bitBuffer *buffer);

#endif
