#include<iostream>
using namespace std;

//多态案例2  制作饮品
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入
	virtual void PourIncup() = 0;

	virtual void PutSomething() = 0;

	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}

	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	virtual void PourIncup()
	{
		cout << "倒入" << endl;
	}

	virtual void PutSomething()
	{
		cout << "放入调料" << endl;
	}

};

//制作茶
class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}

	virtual void Brew()
	{
		cout << "冲泡茶" << endl;
	}

	virtual void PourIncup()
	{
		cout << "倒入" << endl;
	}

	virtual void PutSomething()
	{
		cout << "放入调料" << endl;
	}

};

void dowork(AbstractDrinking * abs)
{
	abs->makeDrink();
	delete abs;
}

void test_poly_example2()
{
	dowork(new Coffee);

	cout << "-----------------------" << endl;
	dowork(new Tea);
}
int main_poly_example2()
{
	test_poly_example2();
	system("pause");
	return 0;
}