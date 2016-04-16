#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrays.h"
#include "bitBuffer.h"

unsigned char *compressNan(char *input, int *resultLength){
	if (!input || !resultLength) return NULL;

	*resultLength = strlen(input);
	struct bitBuffer *buffer = bufferNew(*resultLength, 2);

	for (int i = 0; i < *resultLength; i++) {
		switch (input[i]) {
			case 'A':
				bufferAppend(buffer, 0);
				break;
			case 'C':
				bufferAppend(buffer, 1);
				break;
			case 'G':
				bufferAppend(buffer, 2);
				break;
			case 'T':
				bufferAppend(buffer, 3);
				break;
		}
	}

	unsigned char *result = buffer->store;
	freeBufferNotStore(buffer);

	return result;
}

char *uncompressNan(unsigned char *input, int inputLength) {
	if (!input) return NULL;

	struct bitBuffer *buffer = bufferFromStore(input, inputLength, 2);
	char *uncompressed = malloc(inputLength + 1);

	for (int i = 0; i < inputLength; i++) {
		unsigned char c;
		if (bufferRead(buffer, &c)) {
			switch (c) {
				case 0:
					uncompressed[i] = 'A';
					break;
				case 1:
					uncompressed[i] = 'C';
					break;
				case 2:
					uncompressed[i] = 'G';
					break;
				case 3:
					uncompressed[i] = 'T';
					break;
			}
		} else {
			fprintf(stderr, "Unexpected end of buffer. Exiting.\n");
			exit(1);
		}
	}
	uncompressed[inputLength] = '\0';

	freeBufferNotStore(buffer);

	return uncompressed;
}

int main() {
	char code[8] = "GATTACA";
	int len;

	unsigned char *compressed = compressNan(code, &len);
	printf("%d", len / CHAR_BIT + (len % CHAR_BIT ? 1 : 0) - 1);
	arraysPrintUC(compressed, 0, 1);//len / CHAR_BIT + (len % CHAR_BIT ? 1 : 0) - 1);

	char *uncompressed = uncompressNan(compressed, len);
	printf("%s\n", uncompressed);

	return 0;
}

