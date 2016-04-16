#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

void errorOutOfMemory(void) {
	fprintf(stderr, "Out of memory, exiting.\n");
	exit(1);
}

#endif
