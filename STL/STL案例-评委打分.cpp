#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
//需求：  有5名选手：ABCDE,10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

//实现步骤：
//1.创建五名选手，放到vector中
//2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3.sort算法对deque容器中分数排序，去除最高和最低分
//4.deque容器遍历一遍，累加总分
//5.获取平均分


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
		//将创建的player对象 放入到容器中
		v.push_back(p);
	}
}

void setScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		//将评委的分数 放入deque容器中
		deque<int> d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "选手：" << it->m_name << endl;

		for (deque<int>::iterator it = d.begin();it != d.end();it++)
		{
			cout <<  *it<<" ";
		}
		cout << endl;
		//排序
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//将平均分赋给选手
		it->m_score = avg;
	}
}
int main_stl_example()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//1.创建5名选手
	vector<Player>v;  //存放选手容器
	createPlayer(v);
	//测试
	/*for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << (*it).m_name << "分数：" << (*it).m_score << endl;
	}*/

	//2.打分
	setScore(v);

	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << (*it).m_name << "  分数：" << (*it).m_score << endl;
	}
	system("pause");
	return 0;
}