#include<iostream>

using namespace std;

//多态
// 
//1. 概念
//多态分为两类：
// * 静态多态：函数重载和运算符重载属于静态多态，复用函数名
// * 动态多态：派生类和虚函数实现运行时多态

//静态多态和动态多态区别：
//*静态多态的函数地址早绑定 - 编译阶段确定函数地址
//*动态多态的函数地址晚绑定 - 运行阶段确定函数地址

//动物类
class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "What does the animal say ?" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	//重写 函数返回值类型，函数名，参数列表完全相同  virtual可写可不写
	void speak()
	{
		cout << "(>^ω^<)喵" << endl;
	}
};

//狗类
class dog :public Animal
{
public:

	void speak()
	{
		cout << "汪" << endl;
	}
};
//地址早绑定 在编译阶段确定函数地址
//如果执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数

//动态多态使用
//父类的指针或者引用 执行子类对象
void dospeak(Animal &animal)  //Animal & animal = cat;
{
	animal.speak();
}

void test_speak()
{
	Cat cat;
	dospeak(cat);

	dog d;
	dospeak(d);
}

//Animal 内部结构
// vfptr - 虚函数（表）指针  virtual function pointer
// vfptr 指向 vftable(虚函数表)  表内记录虚函数的地址(&Animal::speak)

//Cat 内部结构
//不重写虚函数时，继承父类，4个字节大小(vfptr -> vftable(&Animal::speak)
//子类重写父类虚函数时，子类中的虚函数表内部会替换成 子类的虚函数地址(&Cat::speak)

//当父类的指针或者引用指向子类对象时，发生多态 Animal &animal = cat; animal.speak();
void test_02()
{
	cout << "sizeof Animal = " << sizeof(Animal) << endl; // 基类空类大小为 1，加了virtual 后大小为 4 ，是指针
	cout << "sizeof Cat = " << sizeof(Cat) << endl;
}

//3.  纯虚函数和抽象类
//在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
//因此可以将虚函数改为纯虚函数
//纯虚函数语法：virtual 返回值类型 函数名 (参数列表) = 0;
//当类中有了纯虚函数，这个类也称为抽象类

//抽象类特点：
//* 无法实例化对象
//* 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class pure_virtual_Base
{
public:
	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象
	virtual void func() = 0;
};

class pure_Son :public pure_virtual_Base
{
public:
	virtual void func()
	{
		cout << "子类的重写纯虚函数" << endl;
	}
};
void test_pure_virtual()
{
	//抽象类无法实例化对象
	//pure_virtual_Base b;
	//new pure_virtual_Base;

	//pure_Son s;  //子类必须重写父类中的纯虚函数，否则无法实例化对象

	pure_virtual_Base* base = new pure_Son;
	base->func();
	delete base;
}


//虚析构和纯虚析构
//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数改为虚析构或者纯虚虚构

//虚析构和纯虚析构共性：
//* 可以解决父类指针释放子类对象
//* 都需要有具体的函数实现

//虚析构和纯虚析构区别
//如果是纯虚析构，该类属于抽象类，无法实例化对象

//虚析构语法：
//virtual ~类名(){}
//纯虚析构语法：
//virtual ~类名() = 0;
//类名::~类名(){}

class Animal_Base
{
public:
	Animal_Base()
	{
		cout << "Animal 构造函数调用" << endl;
	}
	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	/*virtual ~Animal_Base()
	{
		cout << "Animal 虚析构函数调用" << endl;
	}*/

	//纯虚析构 需要声明也需要实现
	//有了纯虚虚构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal_Base() = 0;  //只是声明，需要代码实现

	//纯虚函数
	virtual void speak() = 0;
};

Animal_Base::~Animal_Base()
{
	cout << "Animal 纯虚析构函数调用" << endl;
}
class Cat_Son :public Animal_Base
{
public:
	Cat_Son(string name)
	{
		cout << "Cat 构造函数调用" << endl;
		m_Name = new string(name);
	}

	~Cat_Son()
	{
		
		if (m_Name != NULL)
		{
			cout << "Cat 析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_Name<<"Cat speak" << endl;
	}
	
	string *m_Name;
};

void test_Cat()
{
	Animal_Base* animal = new Cat_Son("Tom");
	animal->speak();
	//父类指针在析构时 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	delete animal;
}


//总结：
//1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
//2. 如果子类中没有堆区数据，可以不写虚析构或纯虚析构
//3. 拥有纯虚析构函数的类也属于抽象类


int main26()
{
	//test_speak();
	//test_02();
	//test_pure_virtual();
	test_Cat();
	system("pause");
	return 0;
}