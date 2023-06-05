#include<iostream>

using namespace std;
//1  继承基本语法
//继承实现界面

class Basepage
{
public:
	void header()
	{
		cout << "公共头" << endl;
	}
	void footer()
	{
		cout << "公共底部" << endl;
	}
	void left()
	{
		cout << "公共左栏" << endl;
	}
};
//继承好处：减少重复代码
//语法：class 子类:继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类
//class A:public B;
//A类称为子类 或 派生类
//B类称为父类 或 基类

//派生类中的成员，包含两大部分：
//一类是从基类继承过来的，一类是自己增加的成员
//从基类继承过来的表现其共性，而新增的成员表现其个性



//Java
class java:public Basepage
{
public:
	void content()
	{
		cout << "Java自己的特色" << endl;
	}
};
//Python
class python :public Basepage
{
public:
	void content()
	{
		cout << "Python自己的特色" << endl;
	}
};
//CPP
class cpp :public Basepage
{
public:
	void content()
	{
		cout << "CPP自己的特色" << endl;
	}
};

void test_inheritance()
{
	java ja;
	ja.header();
	ja.left();
	ja.footer();
	ja.content();

	python py;
	py.header();
	py.left();
	py.footer();
	py.content();

	cpp c;
	c.header();
	c.left();
	c.footer();
	c.content();
}

//2  继承方式
//继承方式三种：
//*公共继承
//*保护继承
//*私有继承

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承
class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//父类公共权限成员 到子类依然是公共权限
		m_B = 20;//父类保护权限成员 到子类依然是保护权限
		//m_C = 30;//父类私有权限成员 到子类访问不到
	}
};

//保护继承
class Son2 :protected Base1
{
public:
	void func()
	{
		m_A = 100;//父类公共权限成员 到子类是保护权限
		m_B = 200;//父类保护权限成员 到子类是保护权限
		//m_C = 300;//父类私有权限成员 到子类访问不到
	}
};

//私有继承
class Son3 :private Base1
{
public:
	void func()
	{
		m_A = 100;//父类公共权限成员 到子类是私有权限
		m_B = 100;//父类保护权限成员 到子类是私有权限
		//m_C = 100;//父类私有权限成员 到子类访问不到
	}
};

class Grandson3 :public Son3
{
public:
	void func()
	{
		//子类私有继承了父类属性，父类属性在子类中变为私有，孙子类公共继承子类，孙子类也是无法访问父类中成员
		//m_A = 14;
		//m_B = 20;
	}
};
void test_Son1()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 200;//保护权限，类外无法访问

	Son2 s2;
	//s2.m_A() = 100;//保护权限，类外无法访问
	//s2.m_B() = 200;//保护权限，类外无法访问

	Son3 s3;
	//s3.m_A = 1000;//私有权限，类外无法访问
	//s3.m_B = 100;//私有权限，类外无法访问
	//s3.m_C = 100;//私有权限，类外无法访问
}

//3  继承中的对象模型
//从父类继承过来的成员，哪些属于子类对象中？
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;//私有成员只是被隐藏了，但是还是会继承下去
};

class Son:public Base
{
public:
	int m_D;
};


//利用开发人员命令提示工具查看对象模型
//跳转盘符
//跳转文件路径 cd 具体路径下
//查看命名
//cl /d1 reportSingleClassLayout类名 文件名

void test25()
{
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器隐藏了，因此是访问不到，但是确实被继承下去了
	cout << "sizeof Son = " << sizeof(Son) << endl; //16
}

//4  继承中构造和析构顺序
//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//父类和子类的构造和析构顺序？

class Base2
{
public:
	Base2()
	{
		cout << "Base2构造函数" << endl;
	}

	~Base2()
	{
		cout << "Base2析构函数" << endl;
	}
};

class Son2_1:public Base2
{
public:
	Son2_1()
	{
		cout << "Son2构造函数" << endl;
	}

	~Son2_1()
	{
		cout << "Son2析构函数" << endl;
	}
};

void test_order()
{
	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反
	Son2_1 b;
}

//5  继承同名成员处理方式
//当子类与父类出现同名成员，通过子类对象，访问到子类或父类中同名的数据
//访问子类同名成员  直接访问即可
//访问父类同名成员  需要加作用域
class Same_Base
{
public :
	Same_Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base-func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base-func(int a)调用" << endl;
	}
	int m_A;
};

class Same_Son :public Same_Base
{
public:
	Same_Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son-func()调用" << endl;
	}

	int m_A;
};

void test_Same()
{
	Same_Son s;

	cout << "Son 下 m_A = " << s.m_A << endl;
	//如果通过子类对象 访问到父类中同名成员，需要加作用域
	cout << "Son 下 m_A = " << s.Same_Base::m_A << endl;
}

//同名成员函数处理
void test_Same1()
{
	Same_Son s1;
	s1.func();//直接调用 调用的是子类中的同名成员

	//如何调用到父类中同名成员函数
	s1.Same_Base::func();

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s1.Same_Base::func(100);
}

//继承同名静态成员处理方法
//继承中同名静态成员在子类对象上访问
//静态成员和非静态成员出现同名，处理方式一致
//访问子类同名成员  直接访问即可
//访问父类同名成员  需要加作用域

class Static_Base
{
public:
	static void func()
	{
		cout << "Base 下 static void func()调用" << endl;
	}
	static void func(int a)
	{
		cout << "Base 下 static void func()调用" << endl;
	}
	static int m_A;
};
int Static_Base::m_A = 100;

class Static_Son :public Static_Base
{
public:
	static void func()
	{
		cout << "Son 下 static void func()调用" << endl;
	}
	static int m_A;
};
int Static_Son::m_A = 200;
//同名静态成员属性
void test_static1()
{
	//1.通过对象访问
	Static_Son s1;
	cout << "Son 下 m_A = " << s1.m_A << endl;
	cout << "Base 下 m_A = " <<s1.Static_Base::m_A<< endl;
	//2.通过类名访问
	cout << "Son 下 m_A " << Static_Son::m_A << endl;
	//第一个::代表通过类名方式访问  第二个::代表访问父类作用域下
	cout << "Base 下 m_A " << Static_Son::Static_Base::m_A << endl;
}

//同名静态成员函数
void test_static2()
{
	//1.通过对象访问
	Static_Son s2;
	s2.func();
	s2.Static_Base::func();
	//2.通过类名访问
	Static_Son::func();
	Static_Son::Static_Base::func();
	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	Static_Son::Static_Base::func(100);
}

//多继承语法
//C++允许一个类继承多个类
//语法：class 子类: 继承方式 父类1，继承方式 父类2...
//多继承可能会引发父类中有同名成员出现，需要加作用域区分
//c++实际开发中不建议用多继承
class moreinheritance_Base1
{
public:
	moreinheritance_Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class moreinheritance_Base2
{
public:
	moreinheritance_Base2()
	{
		m_B = 200;
	}
	int m_A;
	int m_B;
};

//子类  需要继承Base1和Base2
class moreinheritance_Son :public moreinheritance_Base1,public moreinheritance_Base2
{
public:
	moreinheritance_Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test_moreinheritance_Son()
{
	moreinheritance_Son s;
	cout << "Son类大小：" << sizeof(s) << endl;
	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1::m_A = " << s.moreinheritance_Base1::m_A << endl;
	cout << "Base2::m_A = " << s.moreinheritance_Base2::m_A << endl;
}

//菱形继承
//菱形继承概念：
//两个派生类继承同一个基类
//又有某个类同时继承着两个派生类
//这种继承被称为菱形继承，或者钻石继承
//动物类
class animal
{
public:
	int m_Age;
};

//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字 virtual 变为虚继承
// animal 类称为虚基类
// 虚继承 继承的是一个指针 vbptr - virtual base pointer 虚基类指针
//羊类
class Sheep :virtual public animal
{

};

//驼类
class Tuo :virtual public animal
{

};

//羊驼类
class SheepTuo :public Sheep, public Tuo
{

};

 
void test_SheepTuo()
{
	SheepTuo ss;
	ss.Sheep::m_Age = 18;
	ss.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同的数据，需要加作用域区分
	cout << "ss.Sheep::m_Age = " << ss.Sheep::m_Age << endl;
	cout << "ss.Tuo::m_Age = " << ss.Tuo::m_Age << endl;
	//这份数据我们知道 只有一份就可以，菱形继承导致数据由两份，资源浪费
	cout << "ss.m_age = " << ss.m_Age << endl;
}
int main25()
{
	//test_inheritance();
	//test_Son1();
	//test25();
	//test_order();
	//test_Same();
	//test_Same1();
	//test_static1();
	//test_static2();
	//test_moreinheritance_Son();
	test_SheepTuo();
	system("pause");
	return 0;
}