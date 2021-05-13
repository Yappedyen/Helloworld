#include <iostream>
using namespace std;
// 常量定义方式  不可更改
//1.#define 宏常量
//2.const 修饰的变量

#define day 7 

int main4()
{
	int sum = 0, val = 0;
	//int val3 = 10;
	//int val1 = 0, val2 = 0;
	/*
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	while (val3 <= 10 && val3 >= 0)
	{
		cout << val3 << endl;
		--val3;
	}
	*/
	//cout << "Enter two int number:" << endl;
	//cin >> val1 >> val2;
	/*
	if (val1 <= val2)
	{
		while (val1 <= val2)
		{
			cout << val1 << endl;
			++val1;
		}
	}
	else {
		while (val2 <= val1)
		{
			cout << val1 << endl;
			--val1;
		}
	}
	*/
	/*
	for (int i = 50; i <= 100; ++i)
	{
		sum += i;
	}
	for (int j = 10; j <= 10 && j >= 0;--j)
	{
		cout << j << endl;
	}

	for (int i = 0; i <= abs(val1 - val2); ++i)
	{
		if (val1 <= val2)
		{
            cout << val1 + i << endl;
		}
		else {
			cout << val1 - i << endl;
		}
		
	}*/
	
	/*
	while (cin >> val)
	{
		sum += val;
	}
	cout << "sum is :" << sum << endl;
	*/
	int currVal = 0;
	if (cin >> currVal) {
		int cnt = 1;
		while (cin >> val) {
			if (val == currVal) {
				++cnt;
			}
			else {
				cout << currVal << "occurs" << cnt << "times" << endl;
				currVal = val;
				cnt = 1;
			}
		}
		cout << currVal << "occcurs" << cnt << "times" << endl;
	}
	//cout << "The sum of 50 to 100 is " << sum << endl;
	
	//day = 14; //error,day 是常量，不能修改
	cout << day << endl;
	// const 修饰的变量
	const int month = 12;
	// month = 24; //error,const修饰的变量也称为常量
	system("pause");
	return 0;
}