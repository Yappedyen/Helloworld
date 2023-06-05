#include<iostream>
#include<string>

using namespace std;


//封装函数显示界面  void showmenu()
void showmenu()
{
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
}

struct users
{
	int id;
	string name;
	int sex;
	int age;
	string phone;
	string address;
	int del;
};

#define MAX 1000 //最大人数

//通讯录结构体
struct addressbooks
{
	struct users userarray[MAX];
	int size;
};

void adduser(struct addressbooks * abs)
{
	//判断通讯录是否已满
	if (abs->size == MAX)
	{
		cout << "通讯录人数已满，无法添加！" << endl;
		return;
	}
	else {
		//添加具体联系人
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		abs->userarray[abs->size].id = rand()%MAX;
		abs->userarray[abs->size].del = 0;
		abs->userarray[abs->size].name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --男" << endl;
		cout << "2 --女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->userarray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->userarray[abs->size].age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->userarray[abs->size].phone = phone;

		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->userarray[abs->size].address = address;

		abs->size++;
		cout << "添加成功" << endl;

		system("pause");//按任意键
		system("cls");//清除屏幕
	}
}

void showuser(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "记录为空" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++)
		{
			if (abs->userarray[i].del == 0)
			{
				cout << "ID：" << abs->userarray[i].id
					<< "\t姓名：" << abs->userarray[i].name
					<< "\t性别：" << (abs->userarray[i].sex == 1 ? "男" : "女")
					<< "\t年龄：" << abs->userarray[i].age
					<< "\t电话：" << abs->userarray[i].phone
					<< "\t地址：" << abs->userarray[i].address << endl;
			}
		}
	}
	system("pause");//按任意键
	system("cls");//清除屏幕
}

int isexit(addressbooks* abs, string name)
{
	for (int i = 0;i < abs->size;i++)
	{
		if (abs->userarray[i].name == name && abs->userarray[i].del == 0)
		{
			return i;
		}
	}
	return -1;
}
void deluser(addressbooks * abs)
{
	cout << "请输入需要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);

	if(ret != -1)
	{
		abs->userarray[ret].del = 1;
		//查到此人，进行删除

		//for (int i = ret;i < abs->size;i++)
		//{
		//	//数据前移
		//	abs->userarray[i] = abs->userarray[i + 1];
		//}
		//abs->size--;//更新通讯录中人数

		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void finduser(addressbooks* abs)
{
	cout << "请输入需要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "ID：" << abs->userarray[ret].id
			<< "\t姓名：" << abs->userarray[ret].name
			<< "\t性别：" << (abs->userarray[ret].sex == 1 ? "男" : "女")
			<< "\t年龄：" << abs->userarray[ret].age
			<< "\t电话：" << abs->userarray[ret].phone
			<< "\t地址：" << abs->userarray[ret].address << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyuser(addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入新的姓名：" << endl;
		cin >> name;
		abs->userarray[ret].name = name;
		cout << "请输入性别：" << endl;
		cout << "1 --男" << endl;
		cout << "2 --女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->userarray[ret].sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->userarray[ret].age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->userarray[ret].phone = phone;

		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->userarray[ret].address = address;

		cout << "修改成功" << endl;

	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanuser(addressbooks* abs)
{
	cout << "是否要清空通讯录？" << endl;
	cout << "1 -- 是" << endl;
	cout << "2 -- 否" << endl;
	int temp = 0;
	cin >> temp;
	if (temp = 1) {
		abs->size = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}


int main_abs()
{
	srand((unsigned int)time(NULL));
	//创建通讯录结构体变量
	addressbooks abs;
	abs.size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;

		switch (select)
		{
		case 1:
			adduser(&abs);
			break;
		case 2:
			showuser(&abs);
			break;
		case 3:
			deluser(&abs);
			break;
		case 4:
			finduser(&abs);
			break;
		case 5:
			modifyuser(&abs);
			break;
		case 6:
			cleanuser(&abs);
			break;
		case 0:
			cout << "退出成功" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}