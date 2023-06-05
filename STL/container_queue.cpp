#include<iostream>
#include<queue>

#include<string>

using namespace std;

//queue 队列 是一种先进先出(FIFO)的数据结构，有两个出口
//只能队尾(back)进数据（入队）push()
//只能队头(front)出数据（出队）pop()

//队列容器允许从一端新增元素，从另一端移除元素
//队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
//入队 push()
//出队pop()


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

	//准备数据
	Person p1("Tom", 20);
	Person p2("Jarry", 30);
	Person p3("Mickal", 10);
	Person p4("Tolly", 40);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "队列大小：" << q.size() << endl;
	//判断只要队列不为空，查看队头，查看队尾，出队
	while (!q.empty())
	{
		//查看队头
		cout << "队头元素：" << q.front().m_name << " " << q.front().m_age << endl;
		//队尾
		cout << "队尾元素：" << q.back().m_name << " " << q.back().m_age << endl;
		q.pop();
	}
}
int main_queue()
{
	test_queue1();
	system("pause");
	return 0;
}