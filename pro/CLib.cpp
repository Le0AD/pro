#include "CLib.h"
#include <iostream>
#include <cassert>
using namespace std;

const int increment = 100;

void initialize(CStash* s, int sz)
{
	s->size = sz;
	s->quantity = 0;
	s->storage = 0;
	s->next = 0; 
}

void cleanup(CStash* s);

int add(CStash* s, const void* element);

void* fetch(CStash* s, int index);

int count(CStash* s);

void inflate(CStash* s, int increase);
