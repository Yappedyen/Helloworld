#include<iostream>

using namespace std;

//友元
//在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
//友元的目的就是让一个函数或者类 访问另一个类中私有成员

//友元关键字 friend

//友元的三种实现
//*全局函数做友元
//*类做友元
//*成员函数做友元


//建筑物
class Building
{
	//goodGay全局函数是 Building好朋友，可以访问Building中私有成员
	//friend void goodGay(Building* building);
	//GoodGay类是本类的好朋友，可以访问本类中私有成员
	friend class GoodGay;
	
public:
	Building()
	{
		m_Sittingroom = "客厅";
		m_Bedroom = "卧室";
	}
public:
	string m_Sittingroom;//客厅
private:
	string m_Bedroom;

};

//全局函数
void goodGay(Building* building)
{
	cout << "Goodgay全局函数 正在访问：" << building->m_Sittingroom << endl;
	cout << "Goodgay全局函数 正在访问：" << building->m_Sittingroom << endl;
}

//类做友元
class GoodGay
{
public:
	GoodGay();
	void visit(); //参观函数 访问Building中的属性
	
private:
	Building* building;
};
void testgoogay()
{
	Building p;
	goodGay(&p);
}
//类外写成员函数
GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "GoodGay类正在访问：" << building->m_Sittingroom << endl;
	cout << "GoodGay类正在访问：" << building->m_Bedroom << endl;
}


void testGoodGayvisit()
{
	GoodGay gg;
	gg.visit();
}

//成员函数做友元
//building1类中会先介绍自己的GoodGay1，所以GoodGay1类要先于building类定义；
//但是GoodGay1类中有一个私有变量Building1 *building1，所以得先声明building1类；
//GoodGay1类的构造函数需要new一个building1，所以的在building类定义之后
class Building1; 
class GoodGay1
{
public:
	GoodGay1();
	void visit1();//让visit1函数可以访问Building中私有成员
	void visit2();//让visit2函数不可以访问Building中私有成员
private:
	Building1* building1;
};

class Building1
{
	//告诉编译器 GoodGay类下的visit1成员函数作为本类的好朋友，可以访问私有成员
	friend void GoodGay1::visit1();
	//友元声明前 友元函数一定要先出现
public:
	Building1();

public:
	string m_Sittingroom1;//客厅
private:
	string m_Bedroom1;
};

//类外实现成员函数
Building1::Building1()
{
	m_Sittingroom1 = "客厅";
	m_Bedroom1 = "卧室";
}

GoodGay1::GoodGay1()
{
	building1 = new Building1;
}

void GoodGay1::visit1()
{
	cout << "visit1 正在访问：" << building1->m_Sittingroom1 << endl;
	cout << "visit1 正在访问：" << building1->m_Bedroom1 << endl;
}

void GoodGay1::visit2()
{
	cout << "visit2 正在访问：" << building1->m_Sittingroom1 << endl;
	//cout << "visit2 正在访问：" << building1->m_Bedroom1 << endl;
}

void testGoodGay1()
{
	GoodGay1 gg1;
	gg1.visit1();
	gg1.visit2();
}

int main23()
{
	//testgoogay();
	//testGoodGayvisit();
	testGoodGay1();
	system("pause");
	return 0;
}