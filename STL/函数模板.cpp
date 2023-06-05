#include<iostream>

using namespace std;

//����ģ��
//C++��һ�ֱ��˼��  ���ͱ��  ����Ҫ����ģ��
//C++�ṩ����ģ����ƣ�����ģ�����ģ��

//����ģ���﷨
//����ģ�����ã�
//����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ���������ͱ�ʾ

//�﷨
//template<typename T>
//������������

//����;
//template  -- ��������ģ��
//typename --  ���������ķ�����һ���������ͣ�������class����
//T --  ͨ���������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
// T func(T a);

template<typename T> // ����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ�õ���������

void Swapdata(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//���ú���ģ�彻��
	//���ַ�ʽʹ�ú���ģ��
	//1���Զ������Ƶ�
	//Swapdata(a, b);

	//2����ʾָ������
	Swapdata<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

//����
//���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//�������Ӵ�С�������㷨Ϊѡ������
//�ֱ�����char�����int������в���
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //�϶����ֵ�±�
		for (int j = i + 1;j < len;j++)
		{
			//�϶������ֵ �� ����������ֵҪС��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max] < arr[j])
			{
				max = j; // �������ֵ�±�
			}
		}
		if (max != i)
		{
			//����max��i�±��Ԫ��
			Swapdata(arr[max], arr[i]);
		}
		
	}
}
//��ӡ����ģ��
template<class T>
void printarr(T arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test02()
{
	//����char����
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(char);
	mySort(chararr, num);
	printarr(chararr, num);
}

void test03()
{
	//����int����
	int intarr[] = { 7, 5, 1, 3,9,2,4,6,8 };
	int num = sizeof(intarr) / sizeof(int);
	mySort(intarr, num);
	printarr(intarr, num);
}

//��ͨ�����뺯��ģ������
// ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
// ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
// ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��

//��ͨ����
int myadd01(int a, int b)
{
	return a + b;
}

//����ģ��
template<class T>
T myadd02(T a, T b)
{
	return a + b;
}

void test04()
{
	int a = 10;
	int b = 20;
	char c = 'c'; // a - 97  c - 99
	cout << myadd01(a, c) << endl; // ��������ʽ����ת��
	//cout << myadd02(a, c) << endl; //�Զ��Ƶ������ᷢ����ʽ����ת��
	cout << myadd02<int>(a, c) << endl;//��ʾָ�����ͣ�������ʽ����ת��
}

// ��ͨ�����뺯��ģ��ĵ��ù���
//���ù������£�
//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3.����ģ��Ҳ���Է�������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ�����ͨ����

//��ͨ������ģ�庯��һ�㲻ͬʱ���֣���ֹ������
void myprint(int a, int b)
{
	cout << "��ͨ����" << endl;
}

template<class T>
void myprint(T a, T b)
{
	cout << "ģ�庯��" << endl;
}
//����ģ������
template<class T>
void myprint(T a, T b, T c)
{
	cout << "���ص�ģ�庯��" << endl;
}
void test05()
{
	int a = 10;
	int b = 30;
	myprint(a, b); // ���ȵ�����ͨ����

	myprint<>(a, b); // ǿ�Ƶ��ú���ģ��

	myprint(a, b, 100); //�������صĺ���ģ��

	//�������ģ��������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1, c2);
}

//ģ�������
//�����ԣ�
//ģ���ͨ���Բ��������ܵģ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

// ���a,b ����������飬�޷�ʵ�֣����ߴ�������Զ�����������Ϳ���Ҳ�޷���������
//void f(T a, T b)
//{
//	a = b;
// if(a>b)..
//}
//�ṩģ������أ�Ϊ��Щ�ض��������ṩ���廯��ģ��

//�Ա����������Ƿ���Ⱥ���
//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

template<class T>
bool mycompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else {
		return false;
	}
}

//���þ��廯�ǰ汾ʵ�ִ��룬���廯���ȵ���
template<> bool mycompare(Person& a, Person& b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else {
		return false;
	}
}
void test06()
{
	int a = 10;
	int b = 20;
	bool ret = mycompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else {
		cout << "a!=b" << endl;
	}
}

void test07()
{
	Person p1("Tom", 18);
	Person p2("Taylor", 20);

	bool ret = mycompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p1 != p2" << endl;
	}
}
int main1()
{
	//test01(); 
	//test02();
	//cout<<(!4)<<endl;
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
	return 0;
}