#ifndef DOG_H
#define DOG_H
#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "cat.h"

typedef struct __dog
{
	char* name;
	void (*destroy)(struct __dog*);
	void (*smell)(struct __dog*, Cat*);
	Observer* observer;
} Dog;

Dog* DOG_create(char *);

#endif
