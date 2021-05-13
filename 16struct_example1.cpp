#include<iostream>
#include<string>
using namespace std;

//学生结构定义
struct Student
{
	string name;
	int score;
};
//老师结构体定义
struct Teacher
{
	string tname;
	struct Student stuarr[5];
};



void allocateSpace(struct Teacher tarr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < len;i++)
	{
		tarr[i].tname = "Teacher_";
		tarr[i].tname += nameSeed[i];
		for (int j = 0;j < 5;j++)
		{
			tarr[i].stuarr[j].name = "Student_";
			tarr[i].stuarr[j].name += nameSeed[j];
			int random = rand() % 61 + 40; //40~100
			tarr[i].stuarr[j].score = random;
		}
	}
}

void printinfo(struct Teacher tarr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << "老师姓名：" << tarr[i].tname << endl;
		for (int j = 0;j < 5;j++)
		{
			cout << "\t学生姓名：" << tarr[i].stuarr[j].name << "\t学生分数：" << tarr[i].stuarr[j].score << endl;

		}
	}
}
int main16()
{
	srand((unsigned int)time(NULL));
	//1.创建3名老师的数组
	struct Teacher tarr[3];
	//2.通过函数给三名老师的信息赋值，并给老师带的学生赋值
	int len = sizeof(tarr) / sizeof(tarr[0]);
	allocateSpace(tarr, len);
	//3.打印所有老师及所带的学生信息
	printinfo(tarr, len);
	system("pause");
	return 0;
}