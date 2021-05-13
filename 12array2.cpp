#include<iostream>
#include<string>
using namespace std;

int main12()
{
	//二维数组
	/*
	1.数据类型 数组名[行数][列数];
	2.数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};
	3.数据类型 数组名[行数][列数] = {数据1，数据2，数据3，数据4};
	4.数据类型 数组名[][列数] = {数据1，数据2，数据3，数据4};
	*/

	//1.数据类型 数组名[行数][列数];
	/*int arr[2][3];
	arr[0][0] = 0;
	arr[0][1] = 1;

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0; j < 3;j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}*/
	//2.数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};


	//3.数据类型 数组名[行数][列数] = {数据1，数据2，数据3，数据4};
	//int arr[2][3] = { 1,2,3,4,5,6 };

	//4.数据类型 数组名[][列数] = { 数据1，数据2，数据3，数据4 };
	//int arr[][3] = { 1,2,3,4,5,6 };

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0; j < 3;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//第二种更加直观，提高代码可读性

	//二维数组数组名
	//查看占用内存空间大小
	//查看二维数组的首地址

	cout << "二维数组占用内存空间的大小：" << sizeof(arr) << endl;
	cout << "二维数组第一行占用内存：" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素占用内存：" << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数为：" << sizeof(arr[0])/sizeof(arr[0][0]) << endl;

	cout << "二位数组首地址为：" << arr << endl;
	cout << "二位数组第一行首地址为：" << arr[0] << endl;
	cout << "二位数组第二行首地址为：" << arr[0] << endl;
	cout << "二位数组第一个元素首地址为：" << &arr[0][0] << endl;

	//二维数组案例
	int sorces[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	int sorce[3] = { 0 };
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sorce[i] += sorces[i][j];
		}
	}
	string names[3] = { "张三","李思","王五" };
	for (int i = 0;i < 3;i++)
	{
		cout << names[i]<< sorce[i] << endl;
	}

	system("pause");
	return 0;
}