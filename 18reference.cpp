#include<iostream>
using namespace std;

//���ã������������
//�﷨���������� &���� = ԭ��
//����ע������
//*���ñ����ʼ��
//*�����ڳ�ʼ���󣬲����Ըı�

//��������
//1.ֵ����    ʵ�β����βθı�
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2.��ַ����
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3.���ô��� 
void swap03(int& a, int& b) // ����a,b�Ǳ������޸ľ����޸������ʵ��
{
	int temp = a;
	a = b;
	b = temp;
}

//������Ϊ�����ķ���ֵ
//1.��Ҫ���ؾֲ�����������
int & test01()
{
	int a = 10;//�ֲ����������������ջ��
	return a;
}
//2.�����ĵ��ÿ�����Ϊ��ֵ
int& test02()
{
	static int a = 10; //��̬�����������ȫ���������������ϵͳ�ͷ�
	return a;
}

//���õı���
//���õı�����c++�ڲ�ʵ����һ��ָ�볣��
//ʵ�������ã�ת��Ϊint* const ref = &a;
void funct(int& ref)
{
	ref = 100;//ref �����ã�ת��Ϊ*ref = 100;
}

//��������
//���ã�����������Ҫ���������βΣ���ֹ�����
//�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��
//��ӡ���ݺ���
void showvalue(const int& value)
{
	//value = 1000;���ɸ�
	cout << value << endl;
}

int main18()
{
	int a = 10;
	int& b = a; //��ʼ��
	cout << a << endl;
	cout << b << endl;
	b = 100; //���ݵ���ͬһ���ڴ�
	cout << a << endl;
	cout << b << endl;

	//���ñ����ʼ��
	//int& b;  �����
	//�����ڳ�ʼ���󣬲��ɸı�
	int c = 30;
	//b = c; //��ֵ���������Ǹ�������
	//int& b = c;����
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	//��������������
	//���ã���������ʱ�������������õļ������β�����ʵ��
	//�ŵ㣺���Լ�ָ���޸�ʵ��
	int num1 = 10;
	int num2 = 20;
	swap01(num1, num2);
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;
	swap02(&num1, &num2);
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;
	swap03(num1, num2);// ���ô��ݣ��βλ�����ʵ��
	cout << "num1" << num1 << endl;
	cout << "num2" << num2 << endl;

	//��������������ֵ
	//ע�����
	//1.��Ҫ���ؾֲ�����������
	//2.�����ĵ��ÿ�����Ϊ��ֵ
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;//�ڶ��δ����ڴ����ͷ�

	int& ref2 = test02(); //ref2����a �Ǳ���
	cout << ref2 << endl;
	cout << ref2 << endl;
	cout << ref2 << endl;

	test02() = 1000;  //test02()���ص���a�����ã�����a�ı���
	cout << ref2 << endl;
	cout << ref2 << endl;

	//���ñ���Ϊָ�볣��
	//�Զ�ת��Ϊ int * const ref3 = &a;ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int ref3 = c;
	ref3 = 50;//�ڲ�����ref3�����ã��Զ�������ת��Ϊ*ref3 = 50;
	funct(c);
	cout << "c" << c << endl;

	//��������
	//int &ref = 10;���ñ�����һ��Ϸ����ڴ�ռ�
	//����const֮�� �������������޸� int temp = 10; const int & ref4 = temp;
	//const int& ref4 = 10;
	//ref4 = 20;// ����const֮���Ϊֻ�����������޸�
	int valu = 10;
	showvalue(valu);
	cout << valu << endl;
	system("pause");
	return 0;
}