#ifndef TIMING_H
#define TIMING_H

#define NANOS_PER_SEC 1000000000LL

void startTimer(struct timespec *time);
long long endTimer(struct timespec *time);
double millisSince(struct timespec *time);

#endif
