#include<iostream>
using namespace std;

//ð��������
void bubblesort(int * arr, int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])//arr[j] ���� *(arr+j)
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

//��ַ����
void swap01(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//ָ�����ã�ͨ��ָ���ӷ����ڴ�
//ָ����ǵ�ַ
int main14()
{
	//�ڴ����Ǵ�0��ʼ��¼�ģ�һ����ʮ���������ֱ�ʾ
	//��������ָ����������ַ
	//1.����ָ��
	/*
	int a = 10;
	//ָ�붨����﷨�� �������� * ָ�������;
	int * p;
	//��ָ���¼����a�ĵ�ַ
	p = &a;
	cout << "a�ĵ�ַΪ" << &a << endl;
	cout << "pΪ" << p << endl;

	//2.ʹ��ָ��
	//����ͨ�������õķ�ʽ���ҵ�ָ��ָ����ڴ�
	//ָ��ǰ�� * ��������ã��ҵ�ָ��ָ����ڴ��е�����,�޸��ǿ��ڴ�
	//*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	//ָ��Ҳ����������   32λָ��ռ��4���ֽڣ�ֻ�Ǵ��ַ��64λ8�ֽ�
	cout << "int * �ڴ棺" << sizeof(p) << endl;
	cout << "float * �ڴ棺" << sizeof(float *) << endl;
	cout << "double * �ڴ棺" << sizeof(double *) << endl;
	cout << "char * �ڴ棺" << sizeof(char *) << endl;
	cout << "int * �ڴ棺" << sizeof(p) << endl;
	cout << "string * �ڴ棺" << sizeof(string *) << endl;
    */
	//��ָ�룺ָ�����ָ���ڴ��б��Ϊ0�Ŀռ�
	//��;����ʼ��ָ�����
	//ע�⣺��ָ��ָ����ڴ��ǲ����Է��ʵ�
	//0~255֮����ڴ�Ϊϵͳռ���ڴ棬�������û�����
	//int* p = NULL;
	//*p = 100; //�ᱨ��

	//Ұָ�룺ָ�����ָ��Ƿ����ڴ�ռ�
	//ָ�����pָ���ڴ��ַ���Ϊ0x1100�Ŀռ�
	//int* p = (int*)0x1100;

	//����Ұָ��ᱨ��
	//cout << *p << endl;

	//��ָ���Ұָ�붼������������Ŀռ䣬��˲�Ҫ����

	//const ����ָ��
	//1.const����ָ�� --����ָ��
	//2.const���γ��� --ָ�볣��
	//3.const������ָ�룬�����γ���

	//const ������ʲô�������Ͳ����޸�

	//int a = 10, b = 20;
	////����ָ��  const���ε���ָ�룬ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը���
	//const int * p = &a; 
	//p = &b;
	//cout << *p << endl;
	//*p = 100;  ����

	//ָ�볣��  const���ε��ǳ�����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը���
	/*int * const p1 = &a;
	*p1 = 20;
	cout << *p1 << endl;*/
	//p1 = &b;  ����

	//const ������ָ�룬�����γ���
	//ָ���ָ���ָ��ָ���ֵ�������Ը�

	/*const int* const p2 = &a;
	*p2 = 20;
	p2 = &b;*/

	//ָ�������
	//����ָ�����������Ԫ��
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int * p = arr;//arr���������׵�ַ

	/*cout << "��һ��Ԫ��"<<*p << endl;
	p++;
	cout << "�ڶ���Ԫ��" << *p << endl;*/

	//����ָ���������
	/*for (int i = 0;i < 10;i++)
	{
		cout << "��" << i << "��Ԫ��" << *p << endl;
		p++;
	}*/

	//ָ��ͺ���
	//1.ֵ����
	//��ʵ�δ����βΣ�ʵ�β����
	//2.��ַ����
	int a = 10, b = 20;
	swap01(&a, &b);
	cout << a << endl;
	cout << b << endl;

	//ָ�롢���顢����
	//��װһ������������ð������ʵ�ֶ������������������
	int arr1[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	bubblesort(arr1, len);
	printarr(arr1, len);
	/*for (int i = 0;i < len;i++)
	{
		cout << "��" << i << "��Ԫ��" << arr1[i] << endl;
	}*/
	system("pause");
	return 0;
}