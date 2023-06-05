#include<iostream>
using namespace std;

//#include"person.cpp"

#include"person.hpp"
//类模板作用
// 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表

//类模板语法
//template<typename T>
//类
//解释：
//template -- 声明创建模板
//typename  --  表明其后面的符号是一种数据类型，可以用class代替
//T  -- 通用的数据类型，名称可以替换，通常为大写字母

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

//类模板与函数模板区别
//1.类模板没有自动类型推导的使用方式，只能用显示指定类型方式
//2.类模板在模板参数列表中可以有默认参数
void test_02()
{
	//Person_1 p("Tom", 20); 无法用自动类型推导
	Person_1<string, int>p1("Swift", 18);

	Person_1<string> p2("Tom", 180);  //template<class NameTpye, class AgeType = int> 直接默认int 

}

//类模板中成员函数创建时机
//类模板中成员函数和普通类中成员函数创建时机是有区别的：
//1.普通类中的成员函数一开始就可以创建
//2.类模板中的成员函数在调用时才创建

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
	//类模板中的成员函数
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
	//m.func2(); // 编译会出错，说明函数调用才会去创建成员函数
}

//类模板对象做函数参数
//类模板实例化出的对象，向函数传参的方式

//三种传入方式：
//1.指定传入的类型  --  直接显示对象的数据类型
//2.参数模板化  --  将对象中的参数变为模板进行传递
//3.整个类模板化  --  将这个对象类型 模板化进行传递
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
//1.指定传入的类型
void printPerson1(Person_2<string, int>& p)
{
	p.showPerson2();
}

void test1()
{
	Person_2<string, int>p("Taylor", 100);
	printPerson1(p);
}
//2.参数模板化
template<class T1, class T2>
void printPerson2(Person_2<T1, T2>& p)
{
	p.showPerson2();
	cout << "T1 的类型为：" << typeid(T1).name() << endl;
	cout << "T2 的类型为：" << typeid(T2).name() << endl;
}

void test2()
{
	Person_2<string, int>p("Swift", 200);
	printPerson2(p);
}

//3.将整个类模板化
template<class T>
void printPerson3(T& p)
{
	p.showPerson2();
	cout << "T 的数据类型：" << typeid(T).name() << endl;
}
void test3()
{
	Person_2<string, int>p("HUAWEI", 10);
	printPerson3(p);
}

//类模板与继承
//1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中的T的类型
//2.如果不指定，编译器无法给子类分配内存
//3.如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T>
class Base
{
public:
	T m;
};

//class Son :public Base   //错误，必须要知道父类中的T的类型，才能继承给子类
class Son :public Base<int>
{

};

void test4()
{
	Son s1;
	s1.m;
}
//如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1 的数据类型：" << typeid(T1).name() << endl;
		cout << "T2 的数据类型：" << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test5()
{
	Son2<int, char>S2;
}

//类模板中成员函数类外实现
template<class T1, class T2>
class Person_3
{
public:
	//成员函数类内声明
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

//类模板分文件编写
//类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//解决：
//1.直接包含.cpp源文件
//2.将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

void test7()
{
	Person_4<string, int> p("Tom", 20);
	p.showPerson();
}

//类模板与友元
//类模板配合友元函数的类内和类外实现
//全局函数类内实现  --  直接在类内声明友元即可
//全局函数类外实现  --  需要提前让编译器知道全局函数的存在

//提前让编译器知道Person_5类存在
template<class T1, class T2>
class Person_5;


//类外实现
template<class T1, class T2>
void printPerson_6(Person_5<T1, T2> p)
{
	cout << "类外实现" << p.m_Name << p.m_Age << endl;
}

template<class T1, class T2>
class Person_5
{
	//全局函数 类内实现
	friend void printPerson_5(Person_5<T1, T2> p)
	{
		cout << p.m_Name << p.m_Age << endl;
	}
	//全局函数  类外实现
	//加一个空模板参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
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