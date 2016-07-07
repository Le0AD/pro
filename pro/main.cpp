#include <iostream>
#include <string> 
#include <fstream>
#include <vector>

using namespace std;

int *func(int c)
{
	cout << "fn" << endl;
	return new int(31);
}
void func2()
{

}
int **func3(int)
{

}
int main()
{
	int (*(*pf1)(int));// int *func(int c)
	void (*pf2)();// void func2()
	int(*(*pf3)(int))[10];
	pf3 = &func3;


	cin.get(); cin.get();
	return 0;
}