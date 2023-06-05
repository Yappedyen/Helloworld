#pragma once
#include<iostream>

using namespace std;
template<class T1, class T2>
class Person_4
{
public:
	//成员函数类内声明
	Person_4(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person_4<T1, T2>::Person_4(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person_4<T1, T2>::showPerson()
{
	cout << this->m_Name << this->m_Age << endl;
}