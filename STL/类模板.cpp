#include<iostream>
using namespace std;

//#include"person.cpp"

#include"person.hpp"
//��ģ������
// ����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ�����������������

//��ģ���﷨
//template<typename T>
//��
//���ͣ�
//template -- ��������ģ��
//typename  --  ���������ķ�����һ���������ͣ�������class����
//T  -- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

template<class NameTpye, class AgeType = int>
class Person_1
{
public:
	Person_1(NameTpye name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name = " << this->m_Name << endl;
		cout << "age = " << this->m_Age << endl;
	}
	NameTpye m_Name;
	AgeType m_Age;
};

void test_01()
{
	Person_1<string, int> p1("Taylor", 18);
	p1.showPerson();
}

//��ģ���뺯��ģ������
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ��ֻ������ʾָ�����ͷ�ʽ
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
void test_02()
{
	//Person_1 p("Tom", 20); �޷����Զ������Ƶ�
	Person_1<string, int>p1("Swift", 18);

	Person_1<string> p2("Tom", 180);  //template<class NameTpye, class AgeType = int> ֱ��Ĭ��int 

}

//��ģ���г�Ա��������ʱ��
//��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
//1.��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//2.��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

class Person1
{
public:

	void showPerson1()
	{
		cout << "showPerson1" << endl;
	}
};

class Person2
{
public:

	void showPerson2()
	{
		cout << "showPerson2" << endl;
	}
};

template<class T>
class Myclass
{
public:
	T obj;
	//��ģ���еĳ�Ա����
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test_03()
{
	Myclass<Person1>m;
	m.func1();
	//m.func2(); // ��������˵���������òŻ�ȥ������Ա����
}

//��ģ���������������
//��ģ��ʵ�������Ķ����������εķ�ʽ

//���ִ��뷽ʽ��
//1.ָ�����������  --  ֱ����ʾ�������������
//2.����ģ�廯  --  �������еĲ�����Ϊģ����д���
//3.������ģ�廯  --  ������������� ģ�廯���д���
template<class T1, class T2>
class Person_2
{
public:
	Person_2(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson2()
	{
		cout << this->m_Name << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//1.ָ�����������
void printPerson1(Person_2<string, int>& p)
{
	p.showPerson2();
}

void test1()
{
	Person_2<string, int>p("Taylor", 100);
	printPerson1(p);
}
//2.����ģ�廯
template<class T1, class T2>
void printPerson2(Person_2<T1, T2>& p)
{
	p.showPerson2();
	cout << "T1 ������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2 ������Ϊ��" << typeid(T2).name() << endl;
}

void test2()
{
	Person_2<string, int>p("Swift", 200);
	printPerson2(p);
}

//3.��������ģ�廯
template<class T>
void printPerson3(T& p)
{
	p.showPerson2();
	cout << "T ���������ͣ�" << typeid(T).name() << endl;
}
void test3()
{
	Person_2<string, int>p("HUAWEI", 10);
	printPerson3(p);
}

//��ģ����̳�
//1.������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ���������е�T������
//2.�����ָ�����������޷�����������ڴ�
//3.��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T>
class Base
{
public:
	T m;
};

//class Son :public Base   //���󣬱���Ҫ֪�������е�T�����ͣ����ܼ̳и�����
class Son :public Base<int>
{

};

void test4()
{
	Son s1;
	s1.m;
}
//��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1 ���������ͣ�" << typeid(T1).name() << endl;
		cout << "T2 ���������ͣ�" << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test5()
{
	Son2<int, char>S2;
}

//��ģ���г�Ա��������ʵ��
template<class T1, class T2>
class Person_3
{
public:
	//��Ա������������
	Person_3(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person_3<T1, T2>::Person_3(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person_3<T1, T2>::showPerson()
{
	cout << this->m_Name << this->m_Age << endl;
}

void test6()
{
	Person_3<string, int> p("Tom", 20);
	p.showPerson();
}

//��ģ����ļ���д
//��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
//�����
//1.ֱ�Ӱ���.cppԴ�ļ�
//2.��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

void test7()
{
	Person_4<string, int> p("Tom", 20);
	p.showPerson();
}

//��ģ������Ԫ
//��ģ�������Ԫ���������ں�����ʵ��
//ȫ�ֺ�������ʵ��  --  ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ��  --  ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

//��ǰ�ñ�����֪��Person_5�����
template<class T1, class T2>
class Person_5;


//����ʵ��
template<class T1, class T2>
void printPerson_6(Person_5<T1, T2> p)
{
	cout << "����ʵ��" << p.m_Name << p.m_Age << endl;
}

template<class T1, class T2>
class Person_5
{
	//ȫ�ֺ��� ����ʵ��
	friend void printPerson_5(Person_5<T1, T2> p)
	{
		cout << p.m_Name << p.m_Age << endl;
	}
	//ȫ�ֺ���  ����ʵ��
	//��һ����ģ������б�
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPerson_6<>(Person_5<T1, T2> p);

public:
	Person_5(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};



void test8()
{
	Person_5<string, int>p("Tom", 20);
	printPerson_5(p);

}
void test9()
{
	Person_5<string, int>p("QWE", 10);
	printPerson_6(p);
}




int main_template()
{
	//test_02();
	//test_03();
	//test1();
	//test2();
	//test3();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	system("pause");
	return 0;
};