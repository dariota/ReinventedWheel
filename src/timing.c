#include <time.h>
#include "timing.h"

void startTimer(struct timespec *time) { 
	clock_gettime(CLOCK_MONOTONIC, time);
}

long long endTimer(struct timespec *time) {
	struct timespec endTime;
	startTimer(&endTime);
	return (endTime.tv_sec - time->tv_sec) * NANOS_PER_SEC +
	       (endTime.tv_nsec - time->tv_nsec);
}

double millisSince(struct timespec *time) {
	return ((double)endTimer(time) / (NANOS_PER_SEC / 1000));
}
