#include<iostream>

using namespace std;
//STL  Standard Template Library
//STL �����Ϸ�Ϊ������(container)�㷨(algorithm)������(iterator)
//�������㷨֮��ͨ�������������޷�����
//STL �������еĴ��붼������ģ�������ģ�庯��


//STL�������  �������㷨�����������º�����������������������ռ�������
//1���������������ݽṹ����vector��list��deque��set��map�ȡ������������
//2���㷨�����ֳ��õ��㷨����sort��find��copy��for_each��
//3�����������������������㷨֮��Ľ��ϼ�
//4���º�������Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ���  --  ���ص�()
//5����������һ�����������������߷º�����������ӿڵĶ���
//6���ռ�������������ռ�����������

//���� 
//�������ݽṹ�����飬����������ջ�����У����ϣ�ӳ�����
//������Ϊ����ʽ�����͹���ʽ����
//����ʽ������ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ��
//����ʽ�������������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ

//�㷨
//���޵Ĳ��裬����߼��ϻ���ѧ�ϵ�����
//�㷨��Ϊ���ʱ��㷨�ͷ��ʱ��㷨
//�ʱ��㷨��ָ��������л���������ڵ�Ԫ�ص����ݡ����翽�����滻��ɾ���ȵ�
//���ʱ��㷨����ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ�Ҽ�ֵ�ȵ�

//���������������㷨֮��ճ�ϼ�
//�ṩһ�ַ�����ʹ֮�ܹ�����Ѱ��ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ
//ÿ�����������Լ�ר���ĵ�����
//������ʹ�÷ǳ�������ָ�룬��ѧ�׶����ǿ��������������Ϊָ��

//���������ࣺ
//���������    �����ݵ�ֻ������    ֻ����֧��++��==����=
//���������    �����ݵ�ֻд����    ֻд��֧��++
//ǰ�������    ��д������������ǰ�ƽ�������    ��д��֧��++��==����=
//˫�������    ��д������������ǰ��������    ��д��֧��++��--
//������ʵ�����    ��д��������������Ծ�ķ�ʽ�����������ݣ�������ǿ�ĵ�����    ��д��֧��++��--��[n]��-n��<��<=��>��>=
//���õ������е���������Ϊ˫�����������������ʵ�����

//1.vector���������������
//������ vector
//�㷨�� for_each
//�������� vector<int>::iterator
#include<vector>
#include<algorithm>


void myPrint(int val)
{
	cout << val << endl;
}

void test_s1()
{
	//������һ��vector����������
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//ͨ�����������������е�����
	vector<int>::iterator itBegin = v.begin();//��ʼ������  ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();  //����������  ָ�����������һ��Ԫ�ص���һ��λ��

	//��һ�ֱ���
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	//�ڶ��ֱ���
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;
	}

	//�����ֱ���  ����STL�ṩ�����㷨
	for_each(v.begin(), v.end(), myPrint);

}

//2.vector����Զ�����������
class Person_vector
{
public:
	Person_vector(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}

public:
	string mName;
	int mAge;
};

void test_vector()
{
	vector<Person_vector> v;
	Person_vector p1("Taylor", 23);
	Person_vector p2("AW", 24);
	Person_vector p3("QW", 25);
	Person_vector p4("RRET", 26);
	Person_vector p5("SDF", 27);

	//����������������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//���������е�����
	for (vector<Person_vector>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it).mName << "  " << (*it).mAge << endl;  //*it ��Person_vector  
		cout << it->mName << it->mAge << endl;
	}
}

//����Զ����������͵�ָ��
void test_vector1()
{
	vector<Person_vector*> v;
	Person_vector p1("Taylor", 23);
	Person_vector p2("AW", 24);
	Person_vector p3("QW", 25);
	Person_vector p4("RRET", 26);
	Person_vector p5("SDF", 27);

	//����������������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//���������е�����
	for (vector<Person_vector *>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it)->mName << "  " << (*it)->mAge << endl;  // *it ��Person_vector *;ָ��
	}
}

//vector����Ƕ������
//vector ����һ�����飬Ƕ������������ά����
void test_vector2()
{
	vector<vector<int> > v;

	//����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	//��С��������������
	for (int i = 1;i < 5;i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
		v5.push_back(i+4);
	}

	//��С�������뵽��������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//ͨ�����������������ݱ���
	for (vector<vector<int> >::iterator it = v.begin();it != v.end();it++)
	{
		//(*it) ---- ���� vector<int>
		for (vector<int>::iterator vit = (*it).begin();vit != (*it).end();vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}
int main_stl()
{
	//test_s1();
	//test_vector();
	test_vector1();
	test_vector2();
	// system("pause");
	return 0;
}