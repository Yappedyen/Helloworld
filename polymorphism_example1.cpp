#include<iostream>

using namespace std;

//��������
//����������
//�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������

//��̬�ŵ�
//1.������֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ںͺ��ڵ���չ�Լ�ά��

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
		//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
		//����ʵ������ �ᳫ ����ԭ��
		//����ԭ�򣺶���չ���п��������޸Ľ��йر�
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

//���ö�̬ʵ�ּ�����

//ʵ�ּ�����������
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
//�ӷ�
class AddCalculator :public AbstractCalculator
{
public:
	int getresult()
	{
		return m_Num1 + m_Num2;
	}
};
//����
class SubCalculator :public AbstractCalculator
{
public:
	int getresult()
	{
		return m_Num1 - m_Num2;
	}
};
//�˷�
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
	//��̬ʹ������
	//����ָ���������ָ���������
	
	//�ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->getresult() << endl;
	//����ǵ�����
	delete abc;

	//��������
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->getresult() << endl;
	delete abc;

	//�˷�����
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