#include "CLib.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
	CStash int_stash, string_stash;
	int i;
	char* cp;
	ifstream in;
	string line;
	const int bufsize = 80;
	initialize(&int_stash, sizeof(int));
	for (i = 0; i < 100; i++)
	{
		add(&int_stash, &i);
	}
	for (i = 0; i < count(&int_stash); i++)
	{
		cout << "fetch(&int_stash, " << i << ")="
			<< *(int*)fetch(&int_stash, i)
			<< endl;
	}
	initialize(&string_stash, sizeof(char)*bufsize);
	in.open("main.cpp");
	assert(in);
	while (getline(in, line))
		add(&string_stash, line.c_str());
	i = 0;
	while ((cp = (char*)fetch(&string_stash, i++)) != 0)
		cout << "fetch(&string_stash, " << i << ")="
		<< cp << endl;
	cleanup(&int_stash);
	cleanup(&string_stash);
	cin.get(); cin.get();
	return 0;
}