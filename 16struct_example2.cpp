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
	cout << "按年龄排序后结果" << endl;
	for (int i = 0;i < len;i++)
	{
		cout << "姓名：" << harr[i].name << "\t年龄：" << harr[i].age 
			<< "\t性别：" << harr[i].sex << endl;
	}
}
int main()
{
	struct heros harray[5] =
	{
		{1,"刘备",23,"男"},
		{2,"关羽",22,"男"},
		{3,"张飞",20,"男"},
		{4,"赵云",21,"男"},
		{5,"貂蝉",19,"女"}
	};
	int len = sizeof(harray) / sizeof(harray[0]);
	bubblesort(harray, len);
	printinfo(harray, len);
	system("pause");
	return 0;
}