#include<iostream>
#include<vector>
#include<string>

using namespace std;
//vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
//vector����ͨ��������
//��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
// 
//��̬��չ��
//��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�

//vector�����ĵ�������֧��������ʵĵ�����
// 
// 
//vector���캯��
//����ԭ�ͣ�
//vector<T> v;    //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//vector(v.begin(), v.end());    //��v[begin(), end())�����е�Ԫ�ؿ���������
//vector(n, elem);    //���캯����n��elem����������
//vector(const vector &vec);    //�������캯��

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test_vec1()
{
	vector<int> v;  //Ĭ�Ϲ���  �޲ι���
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);

	}
	printVector(v);

	//ͨ�����䷽ʽ���й���
	vector<int>v1(v.begin(), v.end());
	printVector(v1);

	//n��elem��ʽ����
	vector<int>v2(10, 100);
	printVector(v2);

	//��������
	vector<int>v3(v2);
	printVector(v3);
}

//vector��ֵ
void test_vec2()
{
	vector<int> v;  //Ĭ�Ϲ���  �޲ι���
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);

	}
	printVector(v);

	//��ֵ  operator=
	vector<int> v1;
	v1 = v;
	printVector(v1);

	//assign
	vector<int>v2;
	v2.assign(v1.begin(), v1.end());
	printVector(v2);

	//n��elem��ʽ��ֵ
	vector<int> v3;
	v3.assign(10, 100);
	printVector(v3);
}

//vector�����ʹ�С
//����ԭ�ͣ�
//empty();    //�ж������Ƿ�Ϊ��
//capacity();    //����������
//size();    //����������Ԫ�صĸ���
//resize(int num);    //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
                      //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//resize(int num, elem);    //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
                            //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

void test_vec3()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else {
		cout << "v1��Ϊ��" << endl;
		cout << "������" << v1.capacity() << endl;
		cout << "��С��" << v1.size() << endl;
	}

	//����ָ����С
	//v1.resize(15);//Ĭ��0���
	v1.resize(15, 100);//�������ذ汾ָ��Ĭ�����ֵ
	printVector(v1);

	v1.resize(5);    //�������ָ���ı�ԭ���̣��������ֻ�ɾ����
	printVector(v1);
}

//vector�����ɾ��
//����ԭ�ͣ�
//push_back(ele);    //β������Ԫ��ele
//pop_back();    //ɾ�����һ��Ԫ��
//insert(const_iterator pos, ele);    //������ָ��λ��pos����Ԫ��ele
//insert(const_iterator pos, int count, ele);    //������ָ��λ��pos����count��Ԫ��ele
//erase(const_iterator pos);    //ɾ��������ָ���Ԫ��
//erase(const_iterator start, const_iterator end);    //ɾ����������start��end֮���Ԫ��
//clear();    //ɾ������������Ԫ��

void test_vec4()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	v1.pop_back();
	printVector(v1);

	//����  ��һ�������ǵ�����
	v1.insert(v1.begin(), 100);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//ɾ��
	v1.erase(v1.begin());
	printVector(v1);
	//���
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

//vector�������ݴ�ȡ
void test_vec5()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	
	//����[]��ʽ����������Ԫ��
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//����at��ʽ����Ԫ��
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ��" << v1.front() << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ��" << v1.back() << endl;
}

//vector��������
//ʵ������������Ԫ�ؽ��л���
//����ԭ�ͣ�
//swap(vec);    ��vec�뱾����Ԫ�ػ���

//����ʹ��
void test_vec6()
{
	vector<int>v1;
	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10;i > 0;i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}

//ʵ����;
//����swap���������ڴ�ռ�
void test_vec7()
{
	vector<int>v;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
	}
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	v.resize(3);
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	//����swap�����ڴ�
	vector<int>(v).swap(v);     //vector<int>(v)  ��������
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;
}

//vectorԤ���ռ�
//����vector�ڶ�̬��չ����ʱ����չ����
//����ԭ�ͣ�
//reserve(int len);    //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
void test_vec8()
{
	vector<int> v;

	//Ԥ���ռ�
	v.reserve(100000);

	int num = 0;  //ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	
}
int main_vector()
{
	//string s;
	//cout << s[0] << endl;
	//test_vec1();
	//test_vec2();
	//test_vec3();
	//test_vec4();
	//test_vec5();
	//test_vec6();
	//test_vec7();
	test_vec8();
	system("pause");
	return 0;
}
