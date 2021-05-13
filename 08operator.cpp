#include<iostream>
#include<string>
using namespace std;

int main9() {
	//加减乘除
	int a1 = 10, b1 = 3;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;

	int a2 = 10, b2 = 20;
	cout << a2 / b2 << endl;

	int a3 = 10, b3 = 0;
	//两个数相除，除数不可为0

	//两个小数相除
	double d1 = 0.5;
	double d2 = 0.22;
	cout << d1 / d2 << endl;

	//取模运算（取余）
	//两个数相除除数不可以为0，所以做不了取模运算
	//两个小数是不可以做取模运算的
	cout << a1 % b1 << endl;
	cout << a2 % b2 << endl;
	//cout << d1 % d2 << endl;

	//递增递减运算
	//前置、后置
	//前置递增
	int a = 0;
	++a; //让变量+1
	//后置递增
	int b = 0;
	b++; //让变量+1

	//前置和后置区别
	//前置递增  先让变量+1，然后进行表达式运算
	int c = ++a2 * 10;
	//后置递增  先进行表达式运算，然后变量+1
	int d = b2++ * 10;
	//前置递减
	int c1 = --a2 * 10;
	int d3 = b2-- * 10;
	cout << c << endl;
	cout << d << endl;
	cout << c1 << endl;
	cout << d3 << endl;
	cout << a2 << endl;
	cout << b2 << endl;
	
	//赋值运算符
	//=、+=、-=、*=、/=、%=
	a += 2;
	a /= 2;
	a *= 2;
	a %= 2;
	cout << a << endl;

	//比较运算符   用于表达式的比较，返回一个真值或假值
	//==、!=、<、>、<=、>=

	cout << (c == d) << endl;
	cout << (c != d) << endl;
	cout << (c>=d) << endl;
	cout << (c <= d) << endl;

	//逻辑运算符
	//!非、&&与、||或
	cout << !a << endl;
	cout << (a && b) << endl;
	cout << (a || b) << endl;
	system("pause");
	return 0;
}