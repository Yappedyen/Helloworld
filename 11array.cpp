#include<iostream>
using namespace std;

int main11()
{
	//一维数组   
	//1.数据类型 数组名[数组长度];
	//2.数据类型 数组名[数组长度] = {值1，值2...};
	//3.数据类型 数组名[] = {值1,值2...};
	// 
	//1.数据类型 数组名[数组长度];
	int sorce[10];   //没有值，好像是一串数字
	sorce[0] = 0;
	sorce[1] = 10;
	sorce[2] = 10;
	sorce[3] = 10;
	cout << sorce[4] << endl;

	//2.数据类型 数组名[数组长度] = {值1，值2...};
	//如果在初始化数据时，没有全部填写完，会用0来填补剩余值
	int arr[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5;i++)
	{
		cout << arr[i] << endl;
	}

	//3.数据类型 数组名[] = {值1,值2...};
	//定义数组时，必须有初始长度
	int arr1[] = { 0,1,2,3,4 };
	for (int i = 0; i < 5;i++)
	{
		cout << arr1[i] << endl;
	}

	//一维数组数组名
	//一维数组名称的用途
	//1.统计整个数组在内存中的长度
	//2.获取数组在内存中的首地址
	cout << "arr占用内存：" << sizeof(arr) << endl;
	cout << "arr[0]占用内存:" << sizeof(arr[0]) << endl;
	cout << "数组长度：" << sizeof(arr) / sizeof(arr[0]) << endl;
	
	cout << "数组首地址:"<< arr << endl;
	cout << "数组中第一个元素地址:" << &arr[0] << endl;
	cout << "数组中第二个元素地址:" << &arr[1] << endl;

	//数组名是常量，不可以进行赋值操作


	int max = arr[0];
	for (int i = 0;i < 5;i++)
	{
		max = arr[i] >= max ? arr[i] : max;
	}
	cout << max << endl;

	//数组元素逆置
	//1.记录起始下标位置
	//2.记录结束下标位置
	//3.起始下标和结束下标的元素互换
	//4.起始位置 ++  结束位置 --
	//5.循环执行1操作，直到起始位置>=结束位置

	//int start = 0;
	//int end = sizeof(arr) / sizeof(arr[0]) - 1;

	//while (start < end)
	//{
	//    //实现元素互换
	//	int temp = arr[start];
	//	arr[start] = arr[end];
	//	arr[end] = temp;

	//	//下标更新
	//	start++;
	//	end--;
	//}
	//
	//for (int i = 0; i < 5;i++)
	//{
	//	cout << arr[i] << endl;
	//}

	//冒泡排序
	//对数组内元素进行排序
	//1.比较相邻的元素，如果第一个比第二个大，就交换他们两个
	//2.对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值
	//3.重复以上的步骤，每次比较次数-1，直到不需要比较
	int arr2[] = { 4,2,8,0,7,1,5,3,9,6 };
	int start = 0;
	int end = sizeof(arr2) / sizeof(arr2[0]) - 1;

	for (int i = 0; i <= end;i++)
	{
		cout << arr2[i] << endl;
	}
	//总排序轮数  元素个数-1  每轮对比次数 = 元素个数 - 排序轮数 -1
	for (int i = 0;i < end ;i++) {
		for (int j = 0;j < end - i;j++)
		{
			if (arr2[j] > arr2[j + 1])
			{
				int temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i <= end;i++)
	{
		cout << arr2[i] << endl;
	}
	system("pause");
	return 0;
}