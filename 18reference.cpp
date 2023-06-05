#include<iostream>
using namespace std;

//引用：给变量起别名
//语法：数据类型 &别名 = 原名
//引用注意事项
//*引用必须初始化
//*引用在初始化后，不可以改变

//交换函数
//1.值传递    实参不随形参改变
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2.地址传递
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3.引用传递 
void swap03(int& a, int& b) // 这里a,b是别名，修改就是修改外面的实参
{
	int temp = a;
	a = b;
	b = temp;
}

//引用作为函数的返回值
//1.不要返回局部变量的引用
int & test01()
{
	int a = 10;//局部变量存放在四区的栈区
	return a;
}
//2.函数的调用可以作为左值
int& test02()
{
	static int a = 10; //静态变量，存放在全局区，程序结束后系统释放
	return a;
}

//引用的本质
//引用的本质在c++内部实现是一个指针常量
//实现是引用，转换为int* const ref = &a;
void funct(int& ref)
{
	ref = 100;//ref 是引用，转换为*ref = 100;
}

//常量引用
//作用：常量引用主要用来修饰形参，防止误操作
//在函数形参列表中，可以加const修饰形参，防止形参改变实参
//打印数据函数
void showvalue(const int& value)
{
	//value = 1000;不可改
	cout << value << endl;
}

int main18()
{
	int a = 10;
	int& b = a; //初始化
	cout << a << endl;
	cout << b << endl;
	b = 100; //操纵的是同一块内存
	cout << a << endl;
	cout << b << endl;

	//引用必须初始化
	//int& b;  错误的
	//引用在初始化后，不可改变
	int c = 30;
	//b = c; //赋值操作，不是更改引用
	//int& b = c;错误
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//引用做函数参数
	//作用：函数传参时，可以利用引用的技术让形参修饰实参
	//优点：可以简化指针修改实参
	int num1 = 10;
	int num2 = 20;
	swap01(num1, num2);
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;
	swap02(&num1, &num2);
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;
	swap03(num1, num2);// 引用传递，形参会修饰实参
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;

	//引用做函数返回值
	//注意事项：
	//1.不要返回局部变量的引用
	//2.函数的调用可以作为左值
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;//第二次错误，内存已释放

	int& ref2 = test02(); //ref2就是a 是别名
	cout << ref2 << endl;
	cout << ref2 << endl;
	cout << ref2 << endl;

	test02() = 1000;  //test02()返回的是a的引用，就是a的变量
	cout << ref2 << endl;
	cout << ref2 << endl;

	//引用本质为指针常量
	//自动转换为 int * const ref3 = &a;指针常量是指针指向不可改，也说明为什么引用不可更改
	int ref3 = c;
	ref3 = 50;//内部发现ref3是引用，自动帮我们转换为*ref3 = 50;
	funct(c);
	cout << "c" << c << endl;

	//常量引用
	//int &ref = 10;引用必须引一块合法的内存空间
	//加上const之后 编译器将代码修改 int temp = 10; const int & ref4 = temp;
	//const int& ref4 = 10;
	//ref4 = 20;// 加入const之后变为只读，不可以修改
	int valu = 10;
	showvalue(valu);
	cout << valu << endl;
	system("pause");
	return 0;
}