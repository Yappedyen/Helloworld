#include<iostream>

using namespace std;

//运算符重载
//对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

//1  加号运算符重载
//作用：实现两个自定义数据类型相加的运算
//总结：对于内置的数据类型的表达式的运算符是不可能改变的
//      不要乱用运算符重载
class Person_a
{
public:

	//1.成员函数重载+号
	/*Person_a operator+(const Person_a& p)
	{
		Person_a temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/
	int m_A;
	int m_B;
};

//2.全局函数重载+号
Person_a  operator+(const Person_a& p1, const Person_a& p2)
{
	Person_a temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//函数重载的版本
Person_a operator+(const Person_a& p1, int num)
{
	Person_a temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test_operator()
{
	Person_a p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person_a p2;
	p2.m_A = 20;
	p2.m_B = 20;

	Person_a p4;
	p4.m_A = 20;
	p4.m_B = 20;
	//成员函数重载本质调用
	//Person_a p3 = p1.operator+(p2);
	//全局函数重载本质调用
	//Person_a p3 = operator+(p1, p2);

	Person_a p3 = p1 + p2 + p4;
	//运算符重载也可以发生函数重载
	//Person_a p3 = p1 + 100;//Person_a + int 版本
	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
}


//2  左移运算符重载
//作用：可以输出自定义数据类型
class Person_left_shit
{
	friend ostream& operator<<(ostream& out, Person_left_shit& p);
public:
	Person_left_shit(int a,int b)
	{
		m_a = a;
		m_b = b;
	}
	//利用成员函数重载 左移运算符 p.operator<<(cout)  简化版本 p<<cout
	//不会利用成员函数重载<<运算符，因为无法实现 cout在左侧

	/*void operator<<(cout)
	{

	}*/
private:
	int m_a;
	int m_b;
};

//只能用全局函数重载左移运算符
//ostream 输出流对象cout 全局只能有一个，不能再创建一个对象，所以用引用传入
//out返回也必须是引用，不然会调用拷贝构造
ostream & operator<<(ostream &out, Person_left_shit &p) //本质 operator<<(cout,p)  简化 cout << p
{
	out << p.m_a << " "<< p.m_b;
	return out;
}

void test_left_shit()
{
	Person_left_shit p(10,10);
	/*p.m_a = 10;
	p.m_b = 10;*/
	cout << p << endl;;
}

//递增运算符重载
//作用：通过重载递增运算符，实现自己的整型数据
class myInteger
{
	friend ostream& operator<<(ostream& out, myInteger myint);
public:
	myInteger()
	{
		m_num = 0;
	}
	//重载前置++运算符  返回引用为了一直对一个数据进行操作
	myInteger& operator++()
	{
		//先进行++运算
		m_num++;
		//再将自身做返回
		return *this;
	}
	//重载后置++运算符
	//后置递增不能反回局部引用，这个函数执行完会后局部对象会被释放，返回引用非法操作
	myInteger operator++(int)  //int 代表占位参数，可以用于区分前置和后置递增
	{
		//先记录当时结果
		myInteger temp = *this;
		//后递增
		m_num++;
		//最后将记录结果返回
		return temp;
	}
private:
	int m_num;
};

//重载<<运算符
//ostream& operator<<(ostream& out, myInteger & myint) //本质 operator<<(cout,p)  简化 cout << p
//{
//	out << myint.m_num;
//	return out;
//}

ostream& operator<<(ostream& out, myInteger myint) //本质 operator<<(cout,p)  简化 cout << p
{
	out << myint.m_num;
	return out;
}
void test_myint()
{
	myInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test_myint1()
{
	myInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

//4  赋值运算符重载
//c++编译器至少给一个类添加4个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝构造函数，对属性进行值拷贝
//4.赋值运算符 operator= 对属性进行值拷贝

//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题（堆区内存重复释放）

class Person_assignment
{
public:
	Person_assignment(int age)
	{
		m_age = new int(age);
	}

	~Person_assignment()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//重载 = 运算符
	Person_assignment& operator=(Person_assignment& p)
	{
		//编译器提供浅拷贝
		//m_age = p.m_age;

		//应该先判断是否有属性在堆区，如果有先释放干净，在进行深拷贝
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		//深拷贝
		m_age = new int(*p.m_age);
		//返回对象指针
		return *this;
	}
	int* m_age;
};

void test_assignment()
{
	Person_assignment p1(10);
	Person_assignment p2(20);
	Person_assignment p3(30);
	p3 = p2 = p1;//赋值操作，会出现浅拷贝问题，所以用深拷贝解决
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;
	cout << *p3.m_age << endl;
}

//5  关系运算符重载
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
class Person_relation
{
public:
	Person_relation(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	//重载==运算符
	bool operator==(Person_relation& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person_relation& p)
	{
		if (this->m_name != p.m_name && this->m_age != p.m_age)
		{
			return true;
		}
		return false;
	}
	string m_name;
	int m_age;
};

void test_relation()
{
	Person_relation p1("Taylor", 18);
	Person_relation p2("Swift", 20);

	cout << p1.m_name << endl;
	cout << p1.m_age << endl;
	cout << p2.m_name << endl;
	cout << p2.m_age << endl;
	if (p1 == p2)
	{
		cout << "p1和p2一样" << endl;
	}
	else {
		cout << "p1和p2不一样" << endl;
	}
}

//6  函数调用运算符重载
//函数调用运算符（）也可以重载
//由于重载后使用的方式非常像函数的调用，因此成为仿函数
//仿函数没有固定写法，非常灵活
class myprint
{
public:

	//重载的函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void myPrint2(string tet)
{
	cout << tet << endl;
}

void test_myprint()
{
	myprint myprint1;
	myprint1("hello world");//使用起来非常类似于函数调用，因此称为仿函数
	myPrint2("hello world");
}
//仿函数灵活，没有固定写法
//加法类
class myadd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test_myadd()
{
	myadd myadd1;
	cout<<myadd1(100, 100)<<endl;

	//匿名函数对象:匿名对象+仿函数
	cout << myadd()(200, 100) << endl;
}

int main24()
{
	//test_operator();
	//test_left_shit();
	//test_myint();
	
	//test_myint1();

	//test_assignment();

	//test_relation();
	//test_myprint();
	test_myadd();
	system("pause");
	return 0;
}