#include<iostream>

using namespace std;

//1  成员变量和成员函数分开存储
//c++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上

class person22
{
	int p_A;//非静态成员变量  属于类对象上  4字节
	static int p_B;//静态成员变量不属于类对象

	void func22()   //非静态成员函数 不属于类的对象上
	{

	}
	static void func22_1(){}//静态成员函数 不属于类的对象上
};

void test22()
{
	person22 p;
	//空对象占用内存空间为：1
	//c++编译器会给每个空对象也分配 1 字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址

	cout << "size of p =" << sizeof(p) << endl;
}

//2  this指针
//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
//这块代码如何区分哪个对象调用自己
//this指针解决这个问题
//this指针指向被调用的成员函数所属的对象

//this指针是隐含每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用

//this指针用途
//*当形参和成员变量同名时，可用this指针来区分
//*在类的非静态成员函数中返回对象本身，可使用 return *this

class Personthis
{
public:
	Personthis(int age)
	{
		//这里this指向p1,this指针指向被调用的成员函数所属的对象
		this->age = age;
	}

	Personthis& Personaddage(Personthis& p)  //这里如果以值返回的话，会调用拷贝构造函数创建一份新对象的返回
	{
		this->age += p.age;
		//this指向p3的指针，而*this指向的就是p3这个对象本体
		return *this;
	}
	int age;
};
//1.解决名称冲突
void testthis()
{
	Personthis p1(18);
	cout << p1.age << endl;
}
//2.返回对象本身用*this
void testthis_2()
{
	Personthis p2(10);
	Personthis p3(10);
	//链式编程思想
	p3.Personaddage(p2).Personaddage(p2).Personaddage(p2);
	cout << "p3年龄：" << p3.age << endl;
}

//3  空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性

class Personnullpointer
{
public:
	void showclassname()
	{
		cout << "this is person class" << endl;
	}
	void showpersonage()
	{
		//报错原因是因为传入的指针为NULL
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << this->m_age << endl;
	}
	int m_age;
};
void testnullpointer()
{
	Personnullpointer* p = NULL;
	p->showclassname();
	p->showpersonage();
}

//4  const修饰成员函数
//常函数
//*成员函数后加const后我们称这个函数为常函数
//*常函数内不可以修改成员属性
//*成员属性声明时加关键字mutable后，在常函数中依然可以修改

//常对象
//*声明对象前加const称该对象为常对象
//*常对象只能调用常函数

//常函数
class Personconst
{
public:
	//this指针的本质  是指针常量  指针的指向是不可修改的
	//Personconst * const this
	//后面加了const 后就变成const Personconst * const this  值也不可修改了
	//在成员函数后面加const，修饰的是this指向，让指针指向
	void showPerson() const
	{
		//this->m_A = 100;
		this->m_B = 100;
		//this = NULL;//this指针不可以修改指针的指向的值也不可修改
	}
	void func()
	{

	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值
};

void test_Personconst()
{
	Personconst p;
	p.showPerson();
}

//常对象
void test_Personconst2()
{
	const Personconst p;//在对象前加const，变为常对象,不可修改
	//p.m_A = 100;//不能修改
	p.m_B = 100;//m_B特殊值，常对象下也可以修改
	//常对象只能调用常函数
	p.showPerson();
	//p.func();//常对象无法调用普通成员函数，普通成员函数可以修改属性
}
int main22()
{
	//test22();
	//testthis();
	//testthis_2();
	//testnullpointer();
	test_Personconst();
	system("pause");
	return 0;
}