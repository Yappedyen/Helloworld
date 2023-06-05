#include<iostream>

using namespace std;

//对象的初始化和清理
//1  构造函数和析构函数

//一个对象或者变量没有初始状态，对其使用后果是未知的
//使用完一个对象或变量，没有及时清理，会造成一定的安全问题
//编译器自动调用构造和析构函数完成对象的初始化和清理，对象的初始化和清理是编译器强制的，
//如果我们不提供构造和析构，编译器会提供空实现的构造和析构

//构造函数：作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
//析构函数：作用在于对象销毁前系统自动调用，执行一些清理工作

//构造函数 语法: 类名(){}
//1.构造函数，没有返回值也不写void
//2.函数名称与类名相同
//3.构造函数可以有参数，因此可以发生重载
//4.程序在创建对象时会自动调用构造，无需手动调用，而且只会调用一次

//析构函数语法：~类名(){}
//1.没有返回值也不写void
//2.函数名称与类名相同，在名称前加上符号~
//3.析构函数不可以有参数，因此不可以发生重载
//4.程序在对象销毁前会自动调用析构，无需手动调用，而且只会调用一次


class Person
{
public:
//1.构造函数  进行初始化操作
	//按参数分类  无参构造（默认构造）和 有参构造
	//按类型分类  普通构造  和 拷贝构造
	//普通构造
	Person()
	{
		cout << "无参构造函数的调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "有参构造函数调用" << endl;
	}
	//拷贝构造
	Person( const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "拷贝构造函数调用" << endl;

	}

//2.析构函数  进行清理操作
	~Person()
	{
		cout << "析构函数的调用" << endl;
	}
	int age;
};

void test()
{
	Person p;  //在栈上的数据，test执行完毕后，释放这个对象
}

//2   构造函数的分类及调用
//两种分类方式
//按参数分类：有参构造和无参构造
//按类型分类：普通构造和拷贝构造

//三种调用方式：
//括号法
//显示法
//隐式转换法

//调用
void test21()
{
	//1.括号法
	//Person p1;//默认构造函数调用
	//Person p2(10);//有参构造函数
	//Person p3(p2);//拷贝构造函数

	//注意事项
	//调用默认构造函数时，不要加()
	//因为下面这行代码，编译器会认为是一个函数的声明,不会认为在创建对象
	//Person p1();
	//void func();

	//2.显示法
	Person p1;
	Person p2 = Person(10);//有参构造
	Person p3 = Person(p2);//拷贝构造

	//Person(10); //匿名对象 特点：当前行执行结束后，系统会立即回收掉匿名对象
	
	//注意事项2
	// 不要利用拷贝构造函数初始化匿名对象  编译器会认为Person(p2) ==Person p2; 是对象的声明
	//Person(p2);
	//3.隐式转换法
	Person p4 = 10; //相当于写了 Person p4 = Person(10);
	Person p5 = p4; //拷贝构造

	cout << "p2年龄为：" << p2.age << endl;
	cout << "p3年龄为：" << p3.age << endl;
}

//3   拷贝构造函数调用时机
//调用时机通常有三种情况
//*使用一个已经创建完毕的对象来初始化一个新对象
void test21_2()
{
	Person p1(20);
	Person p2(p1);
} 
//*值传递的方式给函数参数传值
void dowork(Person p)
{

}
void test21_3()
{
	Person p;
	dowork(p);
}
//*以值方式返回局部对象
Person dowork1()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;  //不会返回p1，会拷贝p1返回给外面
}
void test21_4()
{
	Person p = dowork1();
	cout << (int*)&p << endl;
}

//4   构造函数调用规则
//默认情况下，c++编译器至少给一个类添加3个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝构造函数，对属性进行值拷贝
void test21_5()
{
	Person p;
	p.age = 18;
	Person p2(p);   //若没有自定义拷贝构造函数，属性值会自动拷贝
	cout << "p2的年龄为：" << p2.age << endl;
}
//构造函数调用规则如下：
//*如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
//*如果用户定义拷贝构造函数，c++不会再提供其他构造函数


//5   深拷贝与浅拷贝
//深浅拷贝 面试经典问题，常见的坑
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作 
//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
class Per
{
public:
	Per()
	{
		cout << "无参构造函数的调用" << endl;
	}
	Per(int page,int pheight)
	{
		age = page;
		height = new int(pheight);
		cout << "有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数来解决浅拷贝带来的问题
	
	Per(const Per& p)
	{
		age = p.age;
		//height = p.height;编译器默认实现的代码
		//深拷贝操作
		height = new int(*p.height);
		cout << "拷贝构造函数调用" << endl;

	}

	//2.析构函数  进行清理操作
	~Per()
	{
		//析构代码，将堆区开辟的数据做释放操作
		if (height != NULL)
		{
			delete height;
			height = NULL;
		}
		cout << "析构函数的调用" << endl;
	}
	int age;
	int* height;
};

void test21_6()
{
	Per p1(18, 160);
	cout << "p1的年龄为：" << p1.age << "身高为：" << *p1.height << endl;

	Per p2(p1);  //利用编译器提供的拷贝构造函数，会做浅拷贝操作，只拷贝值（指针变量p1,p2里的height为同一块地址）
	             //浅拷贝带来的问题就是堆区的内存重复释放
	cout << "p2的年龄为：" << p2.age << "身高为：" << *p2.height << endl;
}

//6   初始化列表
//作用：初始化属性
//语法：构造函数():属性1（值1），属性2（值2）...{}

class Persons
{
public:

	//传统初始化（构造函数）
	/*Persons(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}*/
	//初始化列表初始化属性
	Persons(int a, int b, int c):m_A(a), m_B(b), m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};

void Persons_test()
{
	//Persons p(10, 20, 30);
	Persons p(30,20,10);
	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}

//7   类对象作为类成员
//C++类中的成员可以是另一个类的对象，该成员为对象成员
//B类中有对象A作为成员，A为对象成员
class A
{
public:
	A(string pname)
	{
		cout << "A的构造函数调用" << endl;
		A_name = pname;
	}

	~A()
	{
		cout << "A的析构函数调用" << endl;
	}
	string A_name;
	
};

class B
{
public:

	B(string name, string pname) :B_name(name), A_phone(pname)
	{
		cout << "B的构造函数调用" << endl;
	}
	~B()
	{
		cout << "B的析构函数调用" << endl;
	}
	string B_name;
	A A_phone;
};
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身；析构顺序相反
void test21_7()
{
	B p("Taylor", "HUAWEI");
	cout << p.B_name << p.A_phone.A_name << endl;
}

//8   静态成员
//静态成员就是在成员变量和成员函数前加上关键字 static，称为静态成员
//静态成员分为：
//1.静态成员变量
//*所有对象共享共享同一份数据
//*在编译阶段分配内存
//*类内声明，类外初始化

//静态成员变量也是有访问权限


//2.静态成员函数
//*所有对象共享同一个函数
//*静态成员函数只能访问静态成员变量
//静态成员函数也是有访问权限的
class static_member
{
public:
	//静态成员变量
	static int m_A;
	int m_C;
	//静态成员函数
	static void func()
	{
		m_A = 200; //静态成员函数可以访问静态成员变量
		//m_C = 100; //静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的m_C属性
		cout << "static void func调用" << endl;
	}
private:
	static int m_B;
	static void func2()
	{
		cout << "static void func2的调用" << endl;
	}
};

int static_member::m_A = 100;
int static_member::m_B = 100;

void test_static_member()
{
	static_member p;
	cout << p.m_A << endl;

	static_member p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

//静态成员变量 不属于某个对象上，所有对象都共享同一份数据
//因此静态成员变量和静态成员函数有两种访问方式
void test_s_m_1()
{
	//1.通过对象进行访问
	static_member p;
	p.func();
	cout << p.m_A << endl;
	//2.通过类名进行访问
	cout << static_member::m_A << endl;
	static_member::func();
	//cout << static_member::m_B << endl; //类外访问不到私有的成员变量
	//cout << static_member::func2() << endl;//类外访问不到私有函数
}

int main21()
{
	//int i = 0, & r1 = i;
	//double d = 0, & r2 = d;
	//r2 = 3.14;
	//r2 = r1;
	//i = r2;
	//r1 = d;
	//int i = 0;
	//double* dp = &i;
	//int* ip = 0;
	//int* p = &i;
	//test(); //自动调用构造函数

	//Person p;   //此时窗口暂停了，程序没执行完，没调用析构
	
	//test21();

	//test21_4();
	//test21_6();
	
	//Persons_test();
	//test21_7();
	test_static_member();
	system("pause");
	return 0;
}