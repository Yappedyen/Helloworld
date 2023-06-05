#include<iostream>
using namespace std;

//��̬����2  ������Ʒ
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//����
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

//��������
class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}

	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	virtual void PourIncup()
	{
		cout << "����" << endl;
	}

	virtual void PutSomething()
	{
		cout << "�������" << endl;
	}

};

//������
class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}

	virtual void Brew()
	{
		cout << "���ݲ�" << endl;
	}

	virtual void PourIncup()
	{
		cout << "����" << endl;
	}

	virtual void PutSomething()
	{
		cout << "�������" << endl;
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