#include<iostream>
#include<string>
using namespace std;

struct heros
{
	int id;
	string name;
	int age;
	string sex;
};

void bubblesort(struct heros harr[], int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (harr[j].age > harr[j + 1].age)
			{
				struct heros temp = harr[j];
				harr[j] = harr[j + 1];
				harr[j + 1] = temp;
			}
		}
	}
}

void printinfo(struct heros harr[], int len)
{
	cout << "�������������" << endl;
	for (int i = 0;i < len;i++)
	{
		cout << "������" << harr[i].name << "\t���䣺" << harr[i].age 
			<< "\t�Ա�" << harr[i].sex << endl;
	}
}
int main()
{
	struct heros harray[5] =
	{
		{1,"����",23,"��"},
		{2,"����",22,"��"},
		{3,"�ŷ�",20,"��"},
		{4,"����",21,"��"},
		{5,"����",19,"Ů"}
	};
	int len = sizeof(harray) / sizeof(harray[0]);
	bubblesort(harray, len);
	printinfo(harray, len);
	system("pause");
	return 0;
}