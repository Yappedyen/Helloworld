#include "swap.h"


int swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << a << endl;
	cout << b << endl;
	return 0;
}