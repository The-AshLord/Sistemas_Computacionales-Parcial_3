#ifndef CANARY_H
#define CANARY_H
#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "cat.h"

typedef struct __canary
{
	char* name;
	void (*destroy)(struct __canary*);
	void (*see)(struct __canary*, Cat*);
	Observer* observer;
} Canary;

Canary* CANARY_create(char *);

#endif