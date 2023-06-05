#include<iostream>

using namespace std;

//计算器类
//案例分析：
//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

//多态优点
//1.代码组织结构清晰
//2.可读性强
//3.利于前期和后期的扩展以及维护

class Calcutor
{
public:
	int getresult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//如果想扩展新的功能，需要修改源码
		//在真实开发中 提倡 开闭原则
		//开闭原则：对扩展进行开发，对修改进行关闭
	}

	int m_Num1;
	int m_Num2;
};

void test_calcutor()
{
	Calcutor c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.getresult("+") << endl;
	cout << c.getresult("-") << endl;
	cout << c.getresult("*") << endl;
}

//利用多态实现计算器

//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法
class AddCalculator :public AbstractCalculator
{
public:
	int getresult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法
class SubCalculator :public AbstractCalculator
{
public:
	int getresult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法
class MulCalculator :public AbstractCalculator
{
public:
	int getresult()
	{
		return m_Num1 * m_Num2;
	}
};

void test_calculator()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	
	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getresult() << endl;
	//用完记得销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->getresult() << endl;
	delete abc;

	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->getresult() << endl;
	delete abc;
}
int main_poly1()
{
	//test_calcutor();
	test_calculator();
	system("pause");
	return 0;
}