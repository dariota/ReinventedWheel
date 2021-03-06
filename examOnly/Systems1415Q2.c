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
	bufferFreeNotStore(buffer);

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

	bufferFreeNotStore(buffer);

	return uncompressed;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <NAN sequence>\n", argv[0]);
		return 1;
	}
	int len;

	char *uncompressed = uncompressNan(compressNan(argv[1], &len), len);
	printf("%s\n", uncompressed);

	return 0;
} 
