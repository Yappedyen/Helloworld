#include<iostream>

using namespace std;

#include"MyArray.hpp"

//类模板案例：实现一个通用的数组类，要求如下：
//1.可以对内置数据类型以及自定义的数据类型的数据进行存储
//2.将数组中的数据存储到堆区
//3.构造函数中可以传入数组的容量
//4.提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//5.提供尾插法和尾删法对数组中的数据进行增加和删除
//6.可以通过下标的方式访问数组中的元素
//7.可以获取数组中当前元素个数和数组的容量

void printarray(MyArray<int> &p)
{
	for (int i = 0;i < p.getSize();i++)
	{
		cout << p[i] << endl;
	}
}
void test10()
{
	MyArray<int> arr1(5);
	/*MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);

	arr3 = arr1;*/

	for (int i = 0;i < 5;i++)
	{
		//利用尾插法向数组中插入数据
		arr1.back_push(i);
	}
	cout << "arr1的打印输出：" << endl;
	printarray(arr1);
	cout << arr1.getCapacity() <<"  " << arr1.getSize() << endl;

	MyArray <int>arr4(arr1);
	cout << "arr4的打印输出：" << endl;
	printarray(arr4);
	//尾删
	arr4.back_pop();
	cout << "arr4尾删后：" << endl;
	cout << arr4.getCapacity() <<"  " << arr4.getSize() << endl;
}


//自定义数据类型
class Person5
{
public:
	Person5() {};
	Person5(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printpersonarray(MyArray<Person5>& p)
{
	for (int i = 0;i < p.getSize();i++)
	{
		cout << p[i].m_Name << "  " << p[i].m_Age << endl;
	}
}
void test11()
{
	MyArray<Person5>arr(10);
	Person5 p1("Taylor", 20);
	Person5 p2("Swift", 18);
	Person5 p3("Spring", 17);
	Person5 p4("Fall", 16);
	Person5 p5("Winter", 15);
	Person5 p6("AOC", 14);

	//数据插入
	arr.back_push(p1);
	arr.back_push(p2);
	arr.back_push(p3);
	arr.back_push(p4);
	arr.back_push(p5);
	arr.back_push(p6);
	printpersonarray(arr);

	cout << arr.getCapacity() << "  " << arr.getSize() << endl;
}
int main_example()
{
	//test10();
	test11();
	system("pause");
	return 0;
}