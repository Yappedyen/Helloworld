#include<iostream>
using namespace std;
#include "swap.h"


int add(int a, int b)  //�����a,bΪ�β�
{
	int sum;
	sum = a + b;
	return sum;
}

//ֵ���ݣ����Ǻ�������ʱʵ�ν���ֵ�����β�
//ֵ����ʱ������βη����ı䣬������Ӱ��ʵ��
//�����������Ҫ����ֵ��������ʱ�����дvoid

void swap1(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	//return; ����ֵ����Ҫ���Բ�дreturn
}

//������ʽ
//�޲��޷�
void test01()
{
	cout << "�޲��޷�" << endl;
}
//�в��޷�
void test02(int a)
{
	cout << "�в��޷�" << endl;
}
//�޲��з�
int test03()
{
	cout << "�޲��з�" << endl;
	return 1;
}
//�в��з�
int test04(int num1)
{
	cout << "�в��з�" << endl;
	return num1;
}

//����������
// ���߱������������Ƽ���ε��ú�����������ʵ��������Ե�������
// �������������Զ�Σ����Ǻ����Ķ���ֻ����һ�Σ������󣬶���Ϳ���д��main()֮��
//�ȽϺ�����ʵ�������������ֽ��бȽϣ����ؽϴ��ֵ
//����
int max(int num1, int num2);
//����
int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}


//�����ķ��ļ���д
//�ô���ṹ����
//1.������׺��Ϊ.h��ͷ�ļ�
//2.������׺��Ϊ.cpp��Դ�ļ�
//3.��ͷ�ļ���д����������
//4.��Դ�ļ���д�����Ķ���

//ʵ�������ֽ���
//int swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	return a, b;
//}

int main13()
{

	/*����ֵ����  ������(�����б�)
	{
		���������;
		return���ʽ
	}*/
	//ʵ��һ���ӷ����������������������ݣ�����������ӵĽ�������ҷ���
	//���������﷨ ����������(����)
	//a��bΪʵ�ʲ��������ʵ��
	//�����ú���ʱ��ʵ�ε�ֵ�ᴫ�ݸ��β�
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

