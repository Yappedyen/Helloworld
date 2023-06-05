#include<iostream>

using namespace std;

//��̬
// 
//1. ����
//��̬��Ϊ���ࣺ
// * ��̬��̬���������غ�������������ھ�̬��̬�����ú�����
// * ��̬��̬����������麯��ʵ������ʱ��̬

//��̬��̬�Ͷ�̬��̬����
//*��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
//*��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ

//������
class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "What does the animal say ?" << endl;
	}
};

//è��
class Cat :public Animal
{
public:
	//��д ��������ֵ���ͣ��������������б���ȫ��ͬ  virtual��д�ɲ�д
	void speak()
	{
		cout << "(>^��^<)��" << endl;
	}
};

//����
class dog :public Animal
{
public:

	void speak()
	{
		cout << "��" << endl;
	}
};
//��ַ��� �ڱ���׶�ȷ��������ַ
//���ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���

//��̬��̬��������
//1���м̳й�ϵ
//2��������д������麯��

//��̬��̬ʹ��
//�����ָ��������� ִ���������
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

//Animal �ڲ��ṹ
// vfptr - �麯������ָ��  virtual function pointer
// vfptr ָ�� vftable(�麯����)  ���ڼ�¼�麯���ĵ�ַ(&Animal::speak)

//Cat �ڲ��ṹ
//����д�麯��ʱ���̳и��࣬4���ֽڴ�С(vfptr -> vftable(&Animal::speak)
//������д�����麯��ʱ�������е��麯�����ڲ����滻�� ������麯����ַ(&Cat::speak)

//�������ָ���������ָ���������ʱ��������̬ Animal &animal = cat; animal.speak();
void test_02()
{
	cout << "sizeof Animal = " << sizeof(Animal) << endl; // ��������СΪ 1������virtual ���СΪ 4 ����ָ��
	cout << "sizeof Cat = " << sizeof(Cat) << endl;
}

//3.  ���麯���ͳ�����
//�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������
//��˿��Խ��麯����Ϊ���麯��
//���麯���﷨��virtual ����ֵ���� ������ (�����б�) = 0;
//���������˴��麯���������Ҳ��Ϊ������

//�������ص㣺
//* �޷�ʵ��������
//* ���������д�������еĴ��麯��������Ҳ���ڳ�����

class pure_virtual_Base
{
public:
	//���麯��
	//ֻҪ��һ�����麯����������Ϊ����
	virtual void func() = 0;
};

class pure_Son :public pure_virtual_Base
{
public:
	virtual void func()
	{
		cout << "�������д���麯��" << endl;
	}
};
void test_pure_virtual()
{
	//�������޷�ʵ��������
	//pure_virtual_Base b;
	//new pure_virtual_Base;

	//pure_Son s;  //���������д�����еĴ��麯���������޷�ʵ��������

	pure_virtual_Base* base = new pure_Son;
	base->func();
	delete base;
}


//�������ʹ�������
//��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//�����ʽ���������е�����������Ϊ���������ߴ����鹹

//�������ʹ����������ԣ�
//* ���Խ������ָ���ͷ��������
//* ����Ҫ�о���ĺ���ʵ��

//�������ʹ�����������
//����Ǵ����������������ڳ����࣬�޷�ʵ��������

//�������﷨��
//virtual ~����(){}
//���������﷨��
//virtual ~����() = 0;
//����::~����(){}

class Animal_Base
{
public:
	Animal_Base()
	{
		cout << "Animal ���캯������" << endl;
	}
	//�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal_Base()
	{
		cout << "Animal ��������������" << endl;
	}*/

	//�������� ��Ҫ����Ҳ��Ҫʵ��
	//���˴����鹹֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal_Base() = 0;  //ֻ����������Ҫ����ʵ��

	//���麯��
	virtual void speak() = 0;
};

Animal_Base::~Animal_Base()
{
	cout << "Animal ����������������" << endl;
}
class Cat_Son :public Animal_Base
{
public:
	Cat_Son(string name)
	{
		cout << "Cat ���캯������" << endl;
		m_Name = new string(name);
	}

	~Cat_Son()
	{
		
		if (m_Name != NULL)
		{
			cout << "Cat ������������" << endl;
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
	//����ָ��������ʱ �����������������������������������ж������ԣ������ڴ�й©
	delete animal;
}


//�ܽ᣺
//1. �������������������������ͨ������ָ���ͷ��������
//2. ���������û�ж������ݣ����Բ�д��������������
//3. ӵ�д���������������Ҳ���ڳ�����


int main26()
{
	//test_speak();
	//test_02();
	//test_pure_virtual();
	test_Cat();
	system("pause");
	return 0;
}