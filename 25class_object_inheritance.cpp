#include<iostream>

using namespace std;
//1  �̳л����﷨
//�̳�ʵ�ֽ���

class Basepage
{
public:
	void header()
	{
		cout << "����ͷ" << endl;
	}
	void footer()
	{
		cout << "�����ײ�" << endl;
	}
	void left()
	{
		cout << "��������" << endl;
	}
};
//�̳кô��������ظ�����
//�﷨��class ����:�̳з�ʽ ����
//���� Ҳ��Ϊ ������
//���� Ҳ��Ϊ ����
//class A:public B;
//A���Ϊ���� �� ������
//B���Ϊ���� �� ����

//�������еĳ�Ա���������󲿷֣�
//һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա
//�ӻ���̳й����ı����乲�ԣ��������ĳ�Ա���������



//Java
class java:public Basepage
{
public:
	void content()
	{
		cout << "Java�Լ�����ɫ" << endl;
	}
};
//Python
class python :public Basepage
{
public:
	void content()
	{
		cout << "Python�Լ�����ɫ" << endl;
	}
};
//CPP
class cpp :public Basepage
{
public:
	void content()
	{
		cout << "CPP�Լ�����ɫ" << endl;
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

//2  �̳з�ʽ
//�̳з�ʽ���֣�
//*�����̳�
//*�����̳�
//*˽�м̳�

//�����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//�����̳�
class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//���๫��Ȩ�޳�Ա ��������Ȼ�ǹ���Ȩ��
		m_B = 20;//���ౣ��Ȩ�޳�Ա ��������Ȼ�Ǳ���Ȩ��
		//m_C = 30;//����˽��Ȩ�޳�Ա ��������ʲ���
	}
};

//�����̳�
class Son2 :protected Base1
{
public:
	void func()
	{
		m_A = 100;//���๫��Ȩ�޳�Ա �������Ǳ���Ȩ��
		m_B = 200;//���ౣ��Ȩ�޳�Ա �������Ǳ���Ȩ��
		//m_C = 300;//����˽��Ȩ�޳�Ա ��������ʲ���
	}
};

//˽�м̳�
class Son3 :private Base1
{
public:
	void func()
	{
		m_A = 100;//���๫��Ȩ�޳�Ա ��������˽��Ȩ��
		m_B = 100;//���ౣ��Ȩ�޳�Ա ��������˽��Ȩ��
		//m_C = 100;//����˽��Ȩ�޳�Ա ��������ʲ���
	}
};

class Grandson3 :public Son3
{
public:
	void func()
	{
		//����˽�м̳��˸������ԣ����������������б�Ϊ˽�У������๫���̳����࣬������Ҳ���޷����ʸ����г�Ա
		//m_A = 14;
		//m_B = 20;
	}
};
void test_Son1()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 200;//����Ȩ�ޣ������޷�����

	Son2 s2;
	//s2.m_A() = 100;//����Ȩ�ޣ������޷�����
	//s2.m_B() = 200;//����Ȩ�ޣ������޷�����

	Son3 s3;
	//s3.m_A = 1000;//˽��Ȩ�ޣ������޷�����
	//s3.m_B = 100;//˽��Ȩ�ޣ������޷�����
	//s3.m_C = 100;//˽��Ȩ�ޣ������޷�����
}

//3  �̳��еĶ���ģ��
//�Ӹ���̳й����ĳ�Ա����Щ������������У�
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;//˽�г�Աֻ�Ǳ������ˣ����ǻ��ǻ�̳���ȥ
};

class Son:public Base
{
public:
	int m_D;
};


//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ת�̷�
//��ת�ļ�·�� cd ����·����
//�鿴����
//cl /d1 reportSingleClassLayout���� �ļ���

void test25()
{
	//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	//������˽�г�Ա���� �Ǳ������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ��
	cout << "sizeof Son = " << sizeof(Son) << endl; //16
}

//4  �̳��й��������˳��
//����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
//���������Ĺ��������˳��

class Base2
{
public:
	Base2()
	{
		cout << "Base2���캯��" << endl;
	}

	~Base2()
	{
		cout << "Base2��������" << endl;
	}
};

class Son2_1:public Base2
{
public:
	Son2_1()
	{
		cout << "Son2���캯��" << endl;
	}

	~Son2_1()
	{
		cout << "Son2��������" << endl;
	}
};

void test_order()
{
	//�̳��еĹ��������˳�����£�
	//�ȹ��츸�࣬�ٹ������࣬������˳���빹���˳���෴
	Son2_1 b;
}

//5  �̳�ͬ����Ա����ʽ
//�������븸�����ͬ����Ա��ͨ��������󣬷��ʵ����������ͬ��������
//��������ͬ����Ա  ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա  ��Ҫ��������
class Same_Base
{
public :
	Same_Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base-func()����" << endl;
	}

	void func(int a)
	{
		cout << "Base-func(int a)����" << endl;
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
		cout << "Son-func()����" << endl;
	}

	int m_A;
};

void test_Same()
{
	Same_Son s;

	cout << "Son �� m_A = " << s.m_A << endl;
	//���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
	cout << "Son �� m_A = " << s.Same_Base::m_A << endl;
}

//ͬ����Ա��������
void test_Same1()
{
	Same_Son s1;
	s1.func();//ֱ�ӵ��� ���õ��������е�ͬ����Ա

	//��ε��õ�������ͬ����Ա����
	s1.Same_Base::func();

	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	s1.Same_Base::func(100);
}

//�̳�ͬ����̬��Ա������
//�̳���ͬ����̬��Ա����������Ϸ���
//��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
//��������ͬ����Ա  ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա  ��Ҫ��������

class Static_Base
{
public:
	static void func()
	{
		cout << "Base �� static void func()����" << endl;
	}
	static void func(int a)
	{
		cout << "Base �� static void func()����" << endl;
	}
	static int m_A;
};
int Static_Base::m_A = 100;

class Static_Son :public Static_Base
{
public:
	static void func()
	{
		cout << "Son �� static void func()����" << endl;
	}
	static int m_A;
};
int Static_Son::m_A = 200;
//ͬ����̬��Ա����
void test_static1()
{
	//1.ͨ���������
	Static_Son s1;
	cout << "Son �� m_A = " << s1.m_A << endl;
	cout << "Base �� m_A = " <<s1.Static_Base::m_A<< endl;
	//2.ͨ����������
	cout << "Son �� m_A " << Static_Son::m_A << endl;
	//��һ��::����ͨ��������ʽ����  �ڶ���::������ʸ�����������
	cout << "Base �� m_A " << Static_Son::Static_Base::m_A << endl;
}

//ͬ����̬��Ա����
void test_static2()
{
	//1.ͨ���������
	Static_Son s2;
	s2.func();
	s2.Static_Base::func();
	//2.ͨ����������
	Static_Son::func();
	Static_Son::Static_Base::func();
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	Static_Son::Static_Base::func(100);
}

//��̳��﷨
//C++����һ����̳ж����
//�﷨��class ����: �̳з�ʽ ����1���̳з�ʽ ����2...
//��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
//c++ʵ�ʿ����в������ö�̳�
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

//����  ��Ҫ�̳�Base1��Base2
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
	cout << "Son���С��" << sizeof(s) << endl;
	//�������г���ͬ����Ա����Ҫ������������
	cout << "Base1::m_A = " << s.moreinheritance_Base1::m_A << endl;
	cout << "Base2::m_A = " << s.moreinheritance_Base2::m_A << endl;
}

//���μ̳�
//���μ̳и��
//����������̳�ͬһ������
//����ĳ����ͬʱ�̳�������������
//���ּ̳б���Ϊ���μ̳У�������ʯ�̳�
//������
class animal
{
public:
	int m_Age;
};

//������̳� ������μ̳е�����
//�̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
// animal ���Ϊ�����
// ��̳� �̳е���һ��ָ�� vbptr - virtual base pointer �����ָ��
//����
class Sheep :virtual public animal
{

};

//����
class Tuo :virtual public animal
{

};

//������
class SheepTuo :public Sheep, public Tuo
{

};

 
void test_SheepTuo()
{
	SheepTuo ss;
	ss.Sheep::m_Age = 18;
	ss.Tuo::m_Age = 28;
	//�����μ̳У���������ӵ����ͬ�����ݣ���Ҫ������������
	cout << "ss.Sheep::m_Age = " << ss.Sheep::m_Age << endl;
	cout << "ss.Tuo::m_Age = " << ss.Tuo::m_Age << endl;
	//�����������֪�� ֻ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�
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