#include<iostream>

using namespace std;

#include"MyArray.hpp"

//��ģ�尸����ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//1.���Զ��������������Լ��Զ�����������͵����ݽ��д洢
//2.�������е����ݴ洢������
//3.���캯���п��Դ������������
//4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//6.����ͨ���±�ķ�ʽ���������е�Ԫ��
//7.���Ի�ȡ�����е�ǰԪ�ظ��������������

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
		//����β�巨�������в�������
		arr1.back_push(i);
	}
	cout << "arr1�Ĵ�ӡ�����" << endl;
	printarray(arr1);
	cout << arr1.getCapacity() <<"  " << arr1.getSize() << endl;

	MyArray <int>arr4(arr1);
	cout << "arr4�Ĵ�ӡ�����" << endl;
	printarray(arr4);
	//βɾ
	arr4.back_pop();
	cout << "arr4βɾ��" << endl;
	cout << arr4.getCapacity() <<"  " << arr4.getSize() << endl;
}


//�Զ�����������
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

	//���ݲ���
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