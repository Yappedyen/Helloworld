#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
//����  ��5��ѡ�֣�ABCDE,10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

//ʵ�ֲ��裺
//1.��������ѡ�֣��ŵ�vector��
//2.����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3.sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
//4.deque��������һ�飬�ۼ��ܷ�
//5.��ȡƽ����


class Player
{
public:
	Player(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};

void createPlayer(vector<Player> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "palyer";
		name += nameSeed[i];

		int score = 0;
		Player p(name, score);
		//��������player���� ���뵽������
		v.push_back(p);
	}
}

void setScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		//����ί�ķ��� ����deque������
		deque<int> d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "ѡ�֣�" << it->m_name << endl;

		for (deque<int>::iterator it = d.begin();it != d.end();it++)
		{
			cout <<  *it<<" ";
		}
		cout << endl;
		//����
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//��ƽ���ָ���ѡ��
		it->m_score = avg;
	}
}
int main_stl_example()
{
	//���������
	srand((unsigned int)time(NULL));
	//1.����5��ѡ��
	vector<Player>v;  //���ѡ������
	createPlayer(v);
	//����
	/*for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "������" << (*it).m_name << "������" << (*it).m_score << endl;
	}*/

	//2.���
	setScore(v);

	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "������" << (*it).m_name << "  ������" << (*it).m_score << endl;
	}
	system("pause");
	return 0;
}