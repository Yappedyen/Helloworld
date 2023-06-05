#include<iostream>

using namespace std;

//1  ��Ա�����ͳ�Ա�����ֿ��洢
//c++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ�����

class person22
{
	int p_A;//�Ǿ�̬��Ա����  �����������  4�ֽ�
	static int p_B;//��̬��Ա���������������

	void func22()   //�Ǿ�̬��Ա���� ��������Ķ�����
	{

	}
	static void func22_1(){}//��̬��Ա���� ��������Ķ�����
};

void test22()
{
	person22 p;
	//�ն���ռ���ڴ�ռ�Ϊ��1
	//c++���������ÿ���ն���Ҳ���� 1 �ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ

	cout << "size of p =" << sizeof(p) << endl;
}

//2  thisָ��
//ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
//��������������ĸ���������Լ�
//thisָ�����������
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ��

//thisָ����;
//*���βκͳ�Ա����ͬ��ʱ������thisָ��������
//*����ķǾ�̬��Ա�����з��ض�������ʹ�� return *this

class Personthis
{
public:
	Personthis(int age)
	{
		//����thisָ��p1,thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}

	Personthis& Personaddage(Personthis& p)  //���������ֵ���صĻ�������ÿ������캯������һ���¶���ķ���
	{
		this->age += p.age;
		//thisָ��p3��ָ�룬��*thisָ��ľ���p3���������
		return *this;
	}
	int age;
};
//1.������Ƴ�ͻ
void testthis()
{
	Personthis p1(18);
	cout << p1.age << endl;
}
//2.���ض�������*this
void testthis_2()
{
	Personthis p2(10);
	Personthis p3(10);
	//��ʽ���˼��
	p3.Personaddage(p2).Personaddage(p2).Personaddage(p2);
	cout << "p3���䣺" << p3.age << endl;
}

//3  ��ָ����ʳ�Ա����
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����Ҫע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��

class Personnullpointer
{
public:
	void showclassname()
	{
		cout << "this is person class" << endl;
	}
	void showpersonage()
	{
		//����ԭ������Ϊ�����ָ��ΪNULL
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << this->m_age << endl;
	}
	int m_age;
};
void testnullpointer()
{
	Personnullpointer* p = NULL;
	p->showclassname();
	p->showpersonage();
}

//4  const���γ�Ա����
//������
//*��Ա�������const�����ǳ��������Ϊ������
//*�������ڲ������޸ĳ�Ա����
//*��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

//������
//*��������ǰ��const�Ƹö���Ϊ������
//*������ֻ�ܵ��ó�����

//������
class Personconst
{
public:
	//thisָ��ı���  ��ָ�볣��  ָ���ָ���ǲ����޸ĵ�
	//Personconst * const this
	//�������const ��ͱ��const Personconst * const this  ֵҲ�����޸���
	//�ڳ�Ա���������const�����ε���thisָ����ָ��ָ��
	void showPerson() const
	{
		//this->m_A = 100;
		this->m_B = 100;
		//this = NULL;//thisָ�벻�����޸�ָ���ָ���ֵҲ�����޸�
	}
	void func()
	{

	}
	int m_A;
	mutable int m_B;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};

void test_Personconst()
{
	Personconst p;
	p.showPerson();
}

//������
void test_Personconst2()
{
	const Personconst p;//�ڶ���ǰ��const����Ϊ������,�����޸�
	//p.m_A = 100;//�����޸�
	p.m_B = 100;//m_B����ֵ����������Ҳ�����޸�
	//������ֻ�ܵ��ó�����
	p.showPerson();
	//p.func();//�������޷�������ͨ��Ա��������ͨ��Ա���������޸�����
}
int main22()
{
	//test22();
	//testthis();
	//testthis_2();
	//testnullpointer();
	test_Personconst();
	system("pause");
	return 0;
}