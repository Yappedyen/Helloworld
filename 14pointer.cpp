#include<iostream>
using namespace std;

//冒泡排序函数
void bubblesort(int * arr, int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])//arr[j] 看做 *(arr+j)
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printarr(int* arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << endl;
	}
}

//地址传递
void swap01(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//指针作用：通过指针间接访问内存
//指针就是地址
int main14()
{
	//内存编号是从0开始记录的，一般用十六进制数字表示
	//可以利用指针变量保存地址
	//1.定义指针
	/*
	int a = 10;
	//指针定义的语法： 数据类型 * 指针变量名;
	int * p;
	//让指针记录变量a的地址
	p = &a;
	cout << "a的地址为" << &a << endl;
	cout << "p为" << p << endl;

	//2.使用指针
	//可以通过解引用的方式来找到指针指向的内存
	//指针前加 * 代表解引用，找到指针指向的内存中的数据,修改那块内存
	//*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	//指针也是数据类型   32位指针占用4个字节，只是存地址；64位8字节
	cout << "int * 内存：" << sizeof(p) << endl;
	cout << "float * 内存：" << sizeof(float *) << endl;
	cout << "double * 内存：" << sizeof(double *) << endl;
	cout << "char * 内存：" << sizeof(char *) << endl;
	cout << "int * 内存：" << sizeof(p) << endl;
	cout << "string * 内存：" << sizeof(string *) << endl;
    */
	//空指针：指针变量指向内存中编号为0的空间
	//用途：初始化指针变量
	//注意：空指针指向的内存是不可以访问的
	//0~255之间的内存为系统占用内存，不允许用户访问
	//int* p = NULL;
	//*p = 100; //会报错

	//野指针：指针变量指向非法的内存空间
	//指针变量p指向内存地址编号为0x1100的空间
	//int* p = (int*)0x1100;

	//访问野指针会报错
	//cout << *p << endl;

	//空指针和野指针都不是我们申请的空间，因此不要访问

	//const 修饰指针
	//1.const修饰指针 --常量指针
	//2.const修饰常量 --指针常量
	//3.const即修饰指针，又修饰常量

	//const 后面是什么，那它就不能修改

	//int a = 10, b = 20;
	////常量指针  const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	//const int * p = &a; 
	//p = &b;
	//cout << *p << endl;
	//*p = 100;  报错

	//指针常量  const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	/*int * const p1 = &a;
	*p1 = 20;
	cout << *p1 << endl;*/
	//p1 = &b;  错误

	//const 即修饰指针，又修饰常量
	//指针的指向和指针指向的值都不可以改

	/*const int* const p2 = &a;
	*p2 = 20;
	p2 = &b;*/

	//指针和数组
	//利用指针访问数组中元素
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int * p = arr;//arr就是数组首地址

	/*cout << "第一个元素"<<*p << endl;
	p++;
	cout << "第二个元素" << *p << endl;*/

	//利用指针遍历数组
	/*for (int i = 0;i < 10;i++)
	{
		cout << "第" << i << "个元素" << *p << endl;
		p++;
	}*/

	//指针和函数
	//1.值传递
	//将实参传给形参，实参不会变
	//2.地址传递
	int a = 10, b = 20;
	swap01(&a, &b);
	cout << a << endl;
	cout << b << endl;

	//指针、数组、函数
	//封装一个函数，利用冒泡排序，实现对整型数组的升序排序
	int arr1[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	bubblesort(arr1, len);
	printarr(arr1, len);
	/*for (int i = 0;i < len;i++)
	{
		cout << "第" << i << "个元素" << arr1[i] << endl;
	}*/
	system("pause");
	return 0;
}