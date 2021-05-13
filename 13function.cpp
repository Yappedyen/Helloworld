#include<iostream>
using namespace std;
#include "swap.h"


int add(int a, int b)  //定义的a,b为形参
{
	int sum;
	sum = a + b;
	return sum;
}

//值传递，就是函数调用时实参将数值传给形参
//值传递时，如果形参发生改变，并不会影响实参
//如果函数不需要返回值，声明的时候可以写void

void swap1(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	//return; 返回值不需要可以不写return
}

//函数样式
//无参无返
void test01()
{
	cout << "无参无返" << endl;
}
//有参无返
void test02(int a)
{
	cout << "有参无返" << endl;
}
//无参有返
int test03()
{
	cout << "无参有返" << endl;
	return 1;
}
//有参有返
int test04(int num1)
{
	cout << "有参有返" << endl;
	return num1;
}

//函数的声明
// 告诉编译器函数名称及如何调用函数，函数的实际主体可以单独定义
// 函数的声明可以多次，但是函数的定义只能有一次，声明后，定义就可以写在main()之后
//比较函数，实现两个整型数字进行比较，返回较大的值
//声明
int max(int num1, int num2);
//定义
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}


//函数的分文件编写
//让代码结构清晰
//1.创建后缀名为.h的头文件
//2.创建后缀名为.cpp的源文件
//3.在头文件中写函数的声明
//4.在源文件中写函数的定义

//实现两数字交换
//int swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	return a, b;
//}

int main13()
{

	/*返回值类型  函数名(参数列表)
	{
		函数体语句;
		return表达式
	}*/
	//实现一个加法函数，传入两个整型数据，计算数据相加的结果，并且返回
	//函数调用语法 ：函数名称(参数)
	//a和b为实际参数，简称实参
	//当调用函数时，实参的值会传递给形参
	int sum;
	int a = 10, b = 4;
	sum = add(a, b);
	cout << sum << endl;

	cout << "a" << a << endl;
	cout << "b" << b << endl;
	//int c = 0, d = 0;
	swap(a, b);

	//cout << "a" << c << endl;
	//cout << "b" << d << endl;

	test01();
	test02(a);
	int num = test03();
	cout << num << endl;
	int num2 = test04(a);
	cout << num2 << endl;

	cout << max(a, b) << endl;
	system("pause");
	return 0;
}

