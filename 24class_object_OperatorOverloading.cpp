#include<iostream>

using namespace std;

//���������
//�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������

//1  �Ӻ����������
//���ã�ʵ�������Զ�������������ӵ�����
//�ܽ᣺�������õ��������͵ı��ʽ��������ǲ����ܸı��
//      ��Ҫ�������������
class Person_a
{
public:

	//1.��Ա��������+��
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

//2.ȫ�ֺ�������+��
Person_a  operator+(const Person_a& p1, const Person_a& p2)
{
	Person_a temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//�������صİ汾
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
	//��Ա�������ر��ʵ���
	//Person_a p3 = p1.operator+(p2);
	//ȫ�ֺ������ر��ʵ���
	//Person_a p3 = operator+(p1, p2);

	Person_a p3 = p1 + p2 + p4;
	//���������Ҳ���Է�����������
	//Person_a p3 = p1 + 100;//Person_a + int �汾
	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
}


//2  �������������
//���ã���������Զ�����������
class Person_left_shit
{
	friend ostream& operator<<(ostream& out, Person_left_shit& p);
public:
	Person_left_shit(int a,int b)
	{
		m_a = a;
		m_b = b;
	}
	//���ó�Ա�������� ��������� p.operator<<(cout)  �򻯰汾 p<<cout
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ�� cout�����

	/*void operator<<(cout)
	{

	}*/
private:
	int m_a;
	int m_b;
};

//ֻ����ȫ�ֺ����������������
//ostream ���������cout ȫ��ֻ����һ���������ٴ���һ���������������ô���
//out����Ҳ���������ã���Ȼ����ÿ�������
ostream & operator<<(ostream &out, Person_left_shit &p) //���� operator<<(cout,p)  �� cout << p
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

//�������������
//���ã�ͨ�����ص����������ʵ���Լ�����������
class myInteger
{
	friend ostream& operator<<(ostream& out, myInteger myint);
public:
	myInteger()
	{
		m_num = 0;
	}
	//����ǰ��++�����  ��������Ϊ��һֱ��һ�����ݽ��в���
	myInteger& operator++()
	{
		//�Ƚ���++����
		m_num++;
		//�ٽ�����������
		return *this;
	}
	//���غ���++�����
	//���õ������ܷ��ؾֲ����ã��������ִ������ֲ�����ᱻ�ͷţ��������÷Ƿ�����
	myInteger operator++(int)  //int ����ռλ������������������ǰ�úͺ��õ���
	{
		//�ȼ�¼��ʱ���
		myInteger temp = *this;
		//�����
		m_num++;
		//��󽫼�¼�������
		return temp;
	}
private:
	int m_num;
};

//����<<�����
//ostream& operator<<(ostream& out, myInteger & myint) //���� operator<<(cout,p)  �� cout << p
//{
//	out << myint.m_num;
//	return out;
//}

ostream& operator<<(ostream& out, myInteger myint) //���� operator<<(cout,p)  �� cout << p
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

//4  ��ֵ���������
//c++���������ٸ�һ�������4������
//1.Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//2.Ĭ�������������޲Σ�������Ϊ�գ�
//3.Ĭ�Ͽ������캯���������Խ���ֵ����
//4.��ֵ����� operator= �����Խ���ֵ����

//�������������ָ�����������ֵ����ʱҲ�������ǳ�������⣨�����ڴ��ظ��ͷţ�

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

	//���� = �����
	Person_assignment& operator=(Person_assignment& p)
	{
		//�������ṩǳ����
		//m_age = p.m_age;

		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ����ڽ������
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		//���
		m_age = new int(*p.m_age);
		//���ض���ָ��
		return *this;
	}
	int* m_age;
};

void test_assignment()
{
	Person_assignment p1(10);
	Person_assignment p2(20);
	Person_assignment p3(30);
	p3 = p2 = p1;//��ֵ�����������ǳ�������⣬������������
	cout << *p1.m_age << endl;
	cout << *p2.m_age << endl;
	cout << *p3.m_age << endl;
}

//5  ��ϵ���������
//���ã����ع�ϵ������������������Զ������Ͷ�����жԱȲ���
class Person_relation
{
public:
	Person_relation(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	//����==�����
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
		cout << "p1��p2һ��" << endl;
	}
	else {
		cout << "p1��p2��һ��" << endl;
	}
}

//6  �����������������
//�����������������Ҳ��������
//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//�º���û�й̶�д�����ǳ����
class myprint
{
public:

	//���صĺ������������
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
	myprint1("hello world");//ʹ�������ǳ������ں������ã���˳�Ϊ�º���
	myPrint2("hello world");
}
//�º�����û�й̶�д��
//�ӷ���
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

	//������������:��������+�º���
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