#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;


//deque����
//���ܣ�˫�����飬���Զ�ͷ�˽��в���ɾ������

//deque��vector����
//1.vector����ͷ���Ĳ���ɾ��Ч��̫�ͣ�������Խ��Ч��Խ��
//2.deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
//3.vector����Ԫ��ʱ���ٶȻ��deque�죬��������ڲ�ʵ���й�

//deque�ڲ�����ԭ��
//deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
//�п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�

//deque�����ĵ�����Ҳ��֧��������ʵ�

//deque���캯��
//����ԭ�ͣ�
//deque<T> deqT;    //Ĭ�Ϲ�����ʽ
//deque(beg, end);    //���캯����[beg, end]�����е�Ԫ�ؿ���������
//deque(n, elem);    //���캯����n��elem����������
//deque(const deque &deq);    //�������캯��

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end();it++)
	{
		//*it = 100;   �����е����ݲ������޸���
		cout << *it << " ";
	}
	cout << endl;
}

void test_deq1()
{
	deque<int>dl;
	for (int i = 0;i < 10;i++)
	{
		dl.push_back(i);
	}
	printDeque(dl);

	deque<int>d2(dl.begin(), dl.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}

//deque��ֵ����
//����ԭ�ͣ�
//deque& operator = (const deque &deq);    //���صȺŲ�����
//assign(beg, end);    //��(beg, end)�����е����ݿ�����ֵ������
//assign(n, elem);    //��n��elem������ֵ������

void test_deq2()
{
	deque<int>d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//operator= ��ֵ
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	//assign ��ֵ
	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(2, 20);
	printDeque(d4);
}

//deque��С����
//����ԭ��
//deque.empty();    //�ж������Ƿ�Ϊ��
//deque.size();    //����������Ԫ�صĸ���
//deque.resize(num);    // ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
                        //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//deque.resize(num, elem);    //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
                              //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//deque����û����������

void test_deq3()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1Ϊ�գ�" << endl;
	}
	else {
		cout << d1.size() << endl;
	}
	//����ָ����С
	d1.resize(5);
	printDeque(d1);
}

//deque�����ɾ��
//����ԭ�ͣ�
//���˲��������
//push_back(elem);    //������β�����һ������
//push_front(elem);    //������ͷ������һ������
//pop_back();    //ɾ���������һ������
//pop_front();    //ɾ��������һ������

//ָ��λ�ò���;
//insert(pos, elem);    //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
//insert(pos, n, elem);    //��posλ�ò���n��elem���ݣ��޷���ֵ
//insert(pos,beg,end);    //��posλ�ò���(beg, end)��������ݣ��޷���ֵ
//clear();    //�����������������
//erase(beg,end);    //ɾ��(beg, end)��������ݣ�������һ�����ݵ�λ��
//erase(pos);    //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��

void test_deq4()
{
	deque<int>d1;

	//β��
	d1.push_back(10);
	d1.push_back(20);
	//10 20
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	//200 100 10 20
	printDeque(d1);

	//βɾ
	d1.pop_back();

	//ͷɾ
	d1.pop_front();
}

void test_deq5()
{
	deque<int>d1;

	d1.push_back(10);
	d1.push_back(20);

	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//insert����
	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(), 2, 10000);
	printDeque(d1);

	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
}

void test_deq6()
{
	deque<int>d1;

	d1.push_back(10);
	d1.push_back(20);

	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//ɾ��
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//�����䷽ʽɾ��
	d1.erase(d1.begin(), d1.end());
	printDeque(d1);

	//���
	d1.clear();
	printDeque(d1);
}

//deque���ݴ�ȡ
//����ԭ�ͣ�
//at(int idx);    //��������idx��ָ������
//operator[];    //��������idx��ָ������
//front();    //���������е�һ������Ԫ��
//back();    //�������������һ������Ԫ��

void test_deq7()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//ͨ��[]��ʽ����Ԫ��
	for (int i = 0;i < d.size();i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//ͨ��at��ʽ����Ԫ��
	for (int i = 0;i < d.size();i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ�أ�" << d.front() << endl;
	cout << "���һ��Ԫ�أ�" << d.back() << endl;

}

//deque����
//�����㷨ʵ�ֶ�deque������������
//�㷨��
//sort(iterator beg, iterator end)  //��beg��end������Ԫ�ؽ�������

void test_deq8()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);

	//����  Ĭ���������  ��С���� ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	sort(d.begin(), d.end());
	cout << "�����" << endl;
	printDeque(d);
}
int main_deque()
{
	//test_deq1();
	//test_deq2();
	//test_deq3();
	//test_deq4();
	//test_deq5();
	//test_deq6();
	//test_deq7();
	test_deq8();
	system("pause");
	return 0;
}