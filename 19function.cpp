#include<iostream>

using namespace std;
//函数提高
// 函数默认参数
//语法：返回值类型 函数名（形参 = 默认值）{}

int fun1(int a, int b = 10, int c = 20)
{
	return a + b + c;
}

//注意事项
//1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//int fun2(int a = 10, int b, int c, int d)
//{
//	return a + b + c + d;
//}
//2.如果函数的声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个默认参数
int fun3(int a = 10, int b = 20);
int fun3(int a, int b)
{
	return a + b;
}

//函数占位参数
//C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
//返回值类型 函数名(数据类型){}
//目前用不到，后面用
//占位参数还可以有默认参数
void fun4(int a, int = 10)
{
	cout << a << endl;
}

//函数重载
//作用：函数名可以相同，提高复用性
//函数重载满足条件：
//*同一作用域下
//*函数名称相同
//*函数参数类型不同或者个数不同或者顺序不同
//注意：函数的返回值不可以作为函数重载的条件

void func1()
{
	cout << "func1()的调用" << endl;
}

void func1(int a)
{
	cout << "func1(int a)的调用" << endl;
}

void func1(double a)
{
	cout << "func1(double a)的调用" << endl;
}

void func1(int a, double b)
{
	cout << "func1(int a,double b)的调用" << endl;
}

void func1(double a, int b)
{
	cout << "func1(double a,int b)的调用" << endl;
}

//函数的返回值不可以作为函数重载的条件

//int func1(double a, int b)
//{
//	cout << "func1(double a,int b)的调用" << endl;
//}

//函数重载注意事项
//*引用作为重载条件
void func2(int& a)  //int &a = 10;不合法
{
	cout << "func2(int &a)调用" << endl;
}

void func2(const int& a)  //const int &a = 10;合法
{
	cout << "func2(const int &a)调用" << endl;
}
//*函数重载碰到函数默认参数
void func3(int a, int b = 10)
{
	cout << "func3(int a,int b = 10)调用" << endl;
}

void func3(int a)
{
	cout << "func3(int a)的调用" << endl;
}
int main19()
{
	cout << fun1(10) << endl;
	cout << fun3() << endl;
	fun4(10);
	func1();
	func1(10);
	func1(3.14);
	func1(10, 3.14);
	func1(3.14, 10);

	int a = 10;
	func2(a);//调用func2(int& a)

	func2(10);//调用func2(const int& a)
	//func3(a);//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
	system("pause");
	return 0;
}