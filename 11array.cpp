#include<iostream>
using namespace std;

int main11()
{
	//һά����   
	//1.�������� ������[���鳤��];
	//2.�������� ������[���鳤��] = {ֵ1��ֵ2...};
	//3.�������� ������[] = {ֵ1,ֵ2...};
	// 
	//1.�������� ������[���鳤��];
	int sorce[10];   //û��ֵ��������һ������
	sorce[0] = 0;
	sorce[1] = 10;
	sorce[2] = 10;
	sorce[3] = 10;
	cout << sorce[4] << endl;

	//2.�������� ������[���鳤��] = {ֵ1��ֵ2...};
	//����ڳ�ʼ������ʱ��û��ȫ����д�꣬����0���ʣ��ֵ
	int arr[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5;i++)
	{
		cout << arr[i] << endl;
	}

	//3.�������� ������[] = {ֵ1,ֵ2...};
	//��������ʱ�������г�ʼ����
	int arr1[] = { 0,1,2,3,4 };
	for (int i = 0; i < 5;i++)
	{
		cout << arr1[i] << endl;
	}

	//һά����������
	//һά�������Ƶ���;
	//1.ͳ�������������ڴ��еĳ���
	//2.��ȡ�������ڴ��е��׵�ַ
	cout << "arrռ���ڴ棺" << sizeof(arr) << endl;
	cout << "arr[0]ռ���ڴ�:" << sizeof(arr[0]) << endl;
	cout << "���鳤�ȣ�" << sizeof(arr) / sizeof(arr[0]) << endl;
	
	cout << "�����׵�ַ:"<< arr << endl;
	cout << "�����е�һ��Ԫ�ص�ַ:" << &arr[0] << endl;
	cout << "�����еڶ���Ԫ�ص�ַ:" << &arr[1] << endl;

	//�������ǳ����������Խ��и�ֵ����


	int max = arr[0];
	for (int i = 0;i < 5;i++)
	{
		max = arr[i] >= max ? arr[i] : max;
	}
	cout << max << endl;

	//����Ԫ������
	//1.��¼��ʼ�±�λ��
	//2.��¼�����±�λ��
	//3.��ʼ�±�ͽ����±��Ԫ�ػ���
	//4.��ʼλ�� ++  ����λ�� --
	//5.ѭ��ִ��1������ֱ����ʼλ��>=����λ��

	//int start = 0;
	//int end = sizeof(arr) / sizeof(arr[0]) - 1;

	//while (start < end)
	//{
	//    //ʵ��Ԫ�ػ���
	//	int temp = arr[start];
	//	arr[start] = arr[end];
	//	arr[end] = temp;

	//	//�±����
	//	start++;
	//	end--;
	//}
	//
	//for (int i = 0; i < 5;i++)
	//{
	//	cout << arr[i] << endl;
	//}

	//ð������
	//��������Ԫ�ؽ�������
	//1.�Ƚ����ڵ�Ԫ�أ������һ���ȵڶ����󣬾ͽ�����������
	//2.��ÿһ������Ԫ����ͬ���Ĺ�����ִ����Ϻ��ҵ���һ�����ֵ
	//3.�ظ����ϵĲ��裬ÿ�αȽϴ���-1��ֱ������Ҫ�Ƚ�
	int arr2[] = { 4,2,8,0,7,1,5,3,9,6 };
	int start = 0;
	int end = sizeof(arr2) / sizeof(arr2[0]) - 1;

	for (int i = 0; i <= end;i++)
	{
		cout << arr2[i] << endl;
	}
	//����������  Ԫ�ظ���-1  ÿ�ֶԱȴ��� = Ԫ�ظ��� - �������� -1
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