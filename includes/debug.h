#ifndef DEBUG_H
#define DEBUG_H

#ifdef DBG
#define DEBUG(X) X
#include <stdio.h>
#else
#define DEBUG(X)  
#endif

#endif
