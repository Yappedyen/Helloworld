#include<iostream>
#include"point.h"
#include"circle1.h"
using namespace std;

//C++面向对象三大特性：封装、继承、多态
//万事万物皆为对象，对象上有其属性和行为

//1.封装
// 
//意义：
//*将属性和行为作为一个整体，变现生活中的事物
//语法
// class 类名{访问权限: 属性 / 行为};
//*将属性和行为放在不同权限下加以权限控制
//访问权限
//1 public  公共权限  成员 类内可以访问，类外也可以访问
//2 protected  保护权限  成员 类内可以访问，类外不可以访问  儿子可以访问父亲中的保护内容
//3 private  私有权限  成员 类内可以访问，类外不可以访问  儿子不可以访问父亲的私有内容

//struct和class区别
// 默认访问权限不同
// *struct 默认权限为公共
// *class 默认权限为私有


//将成员属性设置为私有
// 优点：将所有成员属性设置为私有，可以自己控制读写权限
//       对于写权限，我们可以检测数据的有效性


//圆周率
const double PI = 3.14;

//设计一个圆类，求圆周
class circle
{
	//访问权限
	//公共权限
public:
	//属性
	//半径
	int r;

	//行为
	//获取圆的周长
	double calculatezc()
	{
		return 2 * PI * r;
	}
	
};


//设计一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号
class student
{
public:
	//类中的属性和行为 统一称为 成员
	//属性 成员属性 成员变量
	//行为 成员函数 成员方法
	//属性
	string name;
	string id;

	//显示姓名和学号
	void showstu()
	{
		cout << "姓名为：" << name << "\t学号为：" << id << endl;
	}
	//给姓名赋值
	void setname(string sname)
	{
		name = sname;
	}

	void setid(string sid)
	{
		id = sid;
	}
};

class person
{
public:
	//公共权限
	string m_name;

protected:
	//保护权限
	string m_car;

private:
	//私有权限
	int m_psd;

public:  //private/protected 函数类外不可访问
	void func()
	{
		m_name = "Taylor";
		m_car = "Bens";
		m_psd = 12548;
	}
};

class c1
{
	int m_a; //默认权限 私有
};

struct c2
{
	int m_a; //默认权限 公共
};

//设计人类
class person1
{
private:
	//姓名  可读可写
	string p_name;
	//年龄  只读
	int p_age;
	//爱人  只写
	string lover;
	
public:
	//设置姓名 
	void setname(string name)
	{
		p_name = name;
	 }
	//获取姓名
	string getname()
	{
		return p_name;
	}

	//获取年龄  可读可写 如果想修改（年龄范围必须是0·150之间）
	int getage()
	{
		//p_age = 0;
		return p_age;
	}

	void setage(int age)
	{
		if (age < 0 || age >150)
		{
			p_age = 0;
			cout << "不符合正常年龄" << endl;
			return;
		}
		p_age = age;
	}

	//设置爱人 只写
	void setlover(string slover)
	{
		lover = slover;
	}
};

//案例：设计立方体类
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等

class cube
{
public:
	//设置长
	void setl(int l)
	{
		c_l = l;
	}
	int getl()
	{
		return c_l;
	}
	//设置宽
	void setw(int w)
	{
		c_w = w;
	}
	int getw()
	{
		return c_w;
	}
	void seth(int h)
	{
		c_h = h;
	}
	int geth()
	{
		return c_h;
	}
	//获取立方体面积
	int calcuteS()
	{
		return 2 * (c_l * c_w + c_l * c_h + c_w * c_h);
	}
	//获取立方体体积
	int calcuteV()
	{
		return c_l * c_w * c_h;
	}

	//利用成员函数判断
	bool issamebyclass(cube& c)
	{
		if (c_l == c.getl() && c_w == c.getw() && c_h == c.geth())
		{
			return true;
		}
		return false;
	}
private:
	int c_l;
	int c_w;
	int c_h;
};

//利用全局函数判断立方体是否相等
bool issame(cube& cube1, cube& cube2)
{
	if (cube1.getl() == cube2.getl() && cube1.getw() == cube2.getw() && cube1.geth() == cube2.geth())
	{
		return true;
	}
}

//点和圆关系案例
//圆类
//class point
//{
//public:
//	//设置x坐标
//	void setx(int x)
//	{
//		p_x = x;
//	}
//	//设置y坐标
//	void sety(int y)
//	{
//		p_y = y;
//	}
//	int getx()
//	{
//		return p_x;
//	}
//	int gety()
//	{
//		return p_y;
//	}
//private:
//	int p_x;
//	int p_y;
//};

//class circle1
//{
//private:
//	int c_r;
//	//在类中可以让另一个类 作为本类中的成员
//	point c_center;
//public:
//	//设置半径
//	void setr(int r)
//	{
//		c_r = r;
//	}
//	//获取半径
//	int getr()
//	{
//		return c_r;
//	}
//	//设置圆心
//	void setcenter(point center)
//	{
//		c_center = center;
//	}
//	//获取圆心
//	point getcenter()
//	{
//		return c_center;
//	}
//};
//判断点和圆的关系
void isincircle(circle1& c, point& p)
{
	//计算两点之间距离 平方
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());

	//计算半径的平方
	int rdis = c.getr() * c.getr();
	//判断关系
	if (distance == rdis)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rdis)
	{
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}
int main20()
{
	//通过圆类 创建具体的圆(对象)
	//实例化（通过一个类 创建一个对象的过程）
	circle cl;
	//给对象的属性进行赋值
	cl.r = 10;
	cout << "圆周：" << cl.calculatezc() << endl;

	student stu1;
	string name;
	string id;
	cout << "输入姓名：" << endl;
	cin >> name;
	cout << "输入学号：" << endl;
	cin >> id;
	stu1.setname(name);
	stu1.setid(id);
	stu1.showstu();

	person p1;
	p1.m_name = "Swift";
	//p1.m_car = "byd"; //保护权限内容，在类外访问不到
	//p1.m_psd = 54555; //私有权限内容，类外访问不到

	//struct和 class区别
	//c1 cl1;
	//cl1.m_a = 100;   //class默认私有，不能访问
	c2 struct1;
	struct1.m_a = 100;  //struct 默认权限公共，可以访问

	//将成员属性设为私有
	person1 p;
	p.setname("Taylor");

	cout << "姓名：" << p.getname() << endl;
	p.setage(1000);
	cout << "年龄为：" << p.getage() << endl;
	p.setlover("Swift");
	//cout << "爱人：" << p.setlover() << endl;

	//创建立方体对象
	cube cube1;
	cube1.setl(10);
	cube1.setw(5);
	cube1.seth(2);
	cout << "立方体面积：" << cube1.calcuteS() << endl;
	cout << "立方体体积：" << cube1.calcuteV() << endl;
	
	cube cube2;
	cube2.setl(10);
	cube2.setw(5);
	cube2.seth(2);
	bool ret = issame(cube1, cube2);
	if (ret)
	{
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}

	//利用成员函数判断
	ret = cube1.issamebyclass(cube2);
	if (ret)
	{
		cout << "成员函数判断：相等" << endl;
	}
	else {
		cout << "成员函数判断：不相等" << endl;
	}

	//创建圆
	circle1 c;
	c.setr(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);
	//创建点
	point p2;
	p2.setx(10);
	p2.sety(10);
	//判断关系
	isincircle(c, p2);

	system("pause");
	return 0;
}