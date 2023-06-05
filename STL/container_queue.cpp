#include<iostream>
#include<queue>

#include<string>

using namespace std;

//queue ���� ��һ���Ƚ��ȳ�(FIFO)�����ݽṹ������������
//ֻ�ܶ�β(back)�����ݣ���ӣ�push()
//ֻ�ܶ�ͷ(front)�����ݣ����ӣ�pop()

//�������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ
//��� push()
//����pop()


class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void test_queue1()
{
	queue<Person> q;

	//׼������
	Person p1("Tom", 20);
	Person p2("Jarry", 30);
	Person p3("Mickal", 10);
	Person p4("Tolly", 40);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "���д�С��" << q.size() << endl;
	//�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ���鿴��β������
	while (!q.empty())
	{
		//�鿴��ͷ
		cout << "��ͷԪ�أ�" << q.front().m_name << " " << q.front().m_age << endl;
		//��β
		cout << "��βԪ�أ�" << q.back().m_name << " " << q.back().m_age << endl;
		q.pop();
	}
}
int main_queue()
{
	test_queue1();
	system("pause");
	return 0;
}