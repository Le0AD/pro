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

void cleanup(CStash* s)
{
	if (s->storage != 0)
	{
		cout << "freing storage" << endl;
		delete[] s->storage;
	}
}

int add(CStash* s, const void* element)
{
	if ((s->next) >= (s->quantity))
	{
		inflate(s, increment);
	}
	int start_bytes = s->next *s->size;
	unsigned char* e = (unsigned char*)element;
	for (int i = 0; i < s->size; i++)
	{
		s->storage[start_bytes + i] = e[i];
	}
	s->next++;
	return(s->next, 1);
}

void* fetch(CStash* s, int index)
{
	assert(0 <= index);
	if (index >= s->next)
	{
		return 0;
	}
	return &(s->storage[index*s->size]);
}

int count(CStash* s)
{
	return s->next;
}

void inflate(CStash* s, int increase)
{
	assert(increase > 0);
	int new_quantity = s->quantity + increase;
	int new_bytes = new_quantity * s->size;
	int old_bytes = s->quantity * s->size;
	unsigned char* b = new unsigned char[new_bytes];
	for (int i = 0; i < old_bytes; i++)
	{
		b[i] = s->storage[i];
	}
	delete[](s->storage);
	s->storage = b;
	s->quantity = new_quantity;
	cout << "new_quantity:" << new_quantity
		<< " new_bytes:" << new_bytes
		<< " old_bytes:" << old_bytes
		<< " s->size:" << s->size
		<< endl;
}