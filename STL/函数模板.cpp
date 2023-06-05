#include<iostream>

using namespace std;

//函数模板
//C++另一种编程思想  泛型编程  ，主要利用模板
//C++提供两种模板机制：函数模板和类模板

//函数模板语法
//函数模板作用：
//建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟类型表示

//语法
//template<typename T>
//函数声明或定义

//解释;
//template  -- 声明创建模板
//typename --  表明其后面的符号是一种数据类型，可以用class代替
//T --  通用数据类型，名称可以替换，通常为大写字母
// T func(T a);

template<typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型

void Swapdata(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//利用函数模板交换
	//两种方式使用函数模板
	//1、自动类型推导
	//Swapdata(a, b);

	//2、显示指定类型
	Swapdata<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

//案例
//利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//排序规则从大到小，排序算法为选择排序
//分别利用char数组和int数组进行测试
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //认定最大值下标
		for (int j = i + 1;j < len;j++)
		{
			//认定的最大值 比 遍历出的数值要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j; // 更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i下标的元素
			Swapdata(arr[max], arr[i]);
		}
		
	}
}
//打印数组模板
template<class T>
void printarr(T arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test02()
{
	//测试char数组
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(char);
	mySort(chararr, num);
	printarr(chararr, num);
}

void test03()
{
	//测试int数组
	int intarr[] = { 7, 5, 1, 3,9,2,4,6,8 };
	int num = sizeof(intarr) / sizeof(int);
	mySort(intarr, num);
	printarr(intarr, num);
}

//普通函数与函数模板区别：
// 普通函数调用时可以发生自动类型转换（隐式类型转换）
// 函数模板调用时，如果利用自动类型推倒，不会发生隐式类型转换
// 如果利用显示指定类型的方式，可以发生隐式类型转换

//普通函数
int myadd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myadd02(T a, T b)
{
	return a + b;
}

void test04()
{
	int a = 10;
	int b = 20;
	char c = 'c'; // a - 97  c - 99
	cout << myadd01(a, c) << endl; // 发生了隐式类型转换
	//cout << myadd02(a, c) << endl; //自动推导，不会发生隐式类型转换
	cout << myadd02<int>(a, c) << endl;//显示指定类型，发生隐式类型转换
}

// 普通函数与函数模板的调用规则
//调用规则如下：
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配，优先调用普通函数

//普通函数和模板函数一般不同时出现，防止二义性
void myprint(int a, int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void myprint(T a, T b)
{
	cout << "模板函数" << endl;
}
//函数模板重载
template<class T>
void myprint(T a, T b, T c)
{
	cout << "重载的模板函数" << endl;
}
void test05()
{
	int a = 10;
	int b = 30;
	myprint(a, b); // 优先调用普通函数

	myprint<>(a, b); // 强制调用函数模板

	myprint(a, b, 100); //调用重载的函数模板

	//如果函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1, c2);
}

//模板局限性
//局限性：
//模板的通用性并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

// 如果a,b 传入的是数组，无法实现；或者传入的是自定义的数据类型可能也无法正常进行
//void f(T a, T b)
//{
//	a = b;
// if(a>b)..
//}
//提供模板的重载，为这些特定的类型提供具体化的模板

//对比两个数据是否相等函数
//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

template<class T>
bool mycompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else {
		return false;
	}
}

//利用具体化是版本实现代码，具体化优先调用
template<> bool mycompare(Person& a, Person& b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else {
		return false;
	}
}
void test06()
{
	int a = 10;
	int b = 20;
	bool ret = mycompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else {
		cout << "a!=b" << endl;
	}
}

void test07()
{
	Person p1("Tom", 18);
	Person p2("Taylor", 20);

	bool ret = mycompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p1 != p2" << endl;
	}
}
int main1()
{
	//test01(); 
	//test02();
	//cout<<(!4)<<endl;
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
	return 0;
}