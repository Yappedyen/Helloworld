#include<iostream>

using namespace std;
//�������
// ����Ĭ�ϲ���
//�﷨������ֵ���� ���������β� = Ĭ��ֵ��{}

int fun1(int a, int b = 10, int c = 20)
{
	return a + b + c;
}

//ע������
//1.���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�������Ĭ��ֵ
//int fun2(int a = 10, int b, int c, int d)
//{
//	return a + b + c + d;
//}
//2.���������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ��Ĭ�ϲ���
int fun3(int a = 10, int b = 20);
int fun3(int a, int b)
{
	return a + b;
}

//����ռλ����
//C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��
//����ֵ���� ������(��������){}
//Ŀǰ�ò�����������
//ռλ������������Ĭ�ϲ���
void fun4(int a, int = 10)
{
	cout << a << endl;
}

//��������
//���ã�������������ͬ����߸�����
//������������������
//*ͬһ��������
//*����������ͬ
//*�����������Ͳ�ͬ���߸�����ͬ����˳��ͬ
//ע�⣺�����ķ���ֵ��������Ϊ�������ص�����

void func1()
{
	cout << "func1()�ĵ���" << endl;
}

void func1(int a)
{
	cout << "func1(int a)�ĵ���" << endl;
}

void func1(double a)
{
	cout << "func1(double a)�ĵ���" << endl;
}

void func1(int a, double b)
{
	cout << "func1(int a,double b)�ĵ���" << endl;
}

void func1(double a, int b)
{
	cout << "func1(double a,int b)�ĵ���" << endl;
}

//�����ķ���ֵ��������Ϊ�������ص�����

//int func1(double a, int b)
//{
//	cout << "func1(double a,int b)�ĵ���" << endl;
//}

//��������ע������
//*������Ϊ��������
void func2(int& a)  //int &a = 10;���Ϸ�
{
	cout << "func2(int &a)����" << endl;
}

void func2(const int& a)  //const int &a = 10;�Ϸ�
{
	cout << "func2(const int &a)����" << endl;
}
//*����������������Ĭ�ϲ���
void func3(int a, int b = 10)
{
	cout << "func3(int a,int b = 10)����" << endl;
}

void func3(int a)
{
	cout << "func3(int a)�ĵ���" << endl;
}
int main19()
{
	cout << fun1(10) << endl;
	cout << fun3() << endl;
	fun4(10);
	func1();
	func1(10);
	func1(3.14);
	func1(10, 3.14);
	func1(3.14, 10);

	int a = 10;
	func2(a);//����func2(int& a)

	func2(10);//����func2(const int& a)
	//func3(a);//��������������Ĭ�ϲ��������ֶ����ԣ��������������������
	system("pause");
	return 0;
}