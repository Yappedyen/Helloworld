#include<iostream>
#include<string>
using namespace std;

//ѧ���ṹ����
struct Student
{
	string name;
	int score;
};
//��ʦ�ṹ�嶨��
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
		cout << "��ʦ������" << tarr[i].tname << endl;
		for (int j = 0;j < 5;j++)
		{
			cout << "\tѧ��������" << tarr[i].stuarr[j].name << "\tѧ��������" << tarr[i].stuarr[j].score << endl;

		}
	}
}
int main16()
{
	srand((unsigned int)time(NULL));
	//1.����3����ʦ������
	struct Teacher tarr[3];
	//2.ͨ��������������ʦ����Ϣ��ֵ��������ʦ����ѧ����ֵ
	int len = sizeof(tarr) / sizeof(tarr[0]);
	allocateSpace(tarr, len);
	//3.��ӡ������ʦ��������ѧ����Ϣ
	printinfo(tarr, len);
	system("pause");
	return 0;
}