#ifndef OBSERVER_H
#define OBSERVER_H
#include "common.h"

typedef struct __observer {
	void (*destroy)(struct __observer *);
	void* impl; // the concrete OBSERVER
	void (*notify)(struct __observer*, int, void *); // a method that any subject can trigger
	void (*notifyImpl)(void*, int, void*); // the actual function to be trigger
} Observer;

Observer * observerNew(void*, void (*)(void*, int, void*));

#endif
