#include<iostream>
#include<string>

using namespace std;


//��װ������ʾ����  void showmenu()
void showmenu()
{
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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

#define MAX 1000 //�������

//ͨѶ¼�ṹ��
struct addressbooks
{
	struct users userarray[MAX];
	int size;
};

void adduser(struct addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�����������޷���ӣ�" << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->userarray[abs->size].id = rand()%MAX;
		abs->userarray[abs->size].del = 0;
		abs->userarray[abs->size].name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --��" << endl;
		cout << "2 --Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->userarray[abs->size].sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->userarray[abs->size].age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->userarray[abs->size].phone = phone;

		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->userarray[abs->size].address = address;

		abs->size++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�������
		system("cls");//�����Ļ
	}
}

void showuser(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++)
		{
			if (abs->userarray[i].del == 0)
			{
				cout << "ID��" << abs->userarray[i].id
					<< "\t������" << abs->userarray[i].name
					<< "\t�Ա�" << (abs->userarray[i].sex == 1 ? "��" : "Ů")
					<< "\t���䣺" << abs->userarray[i].age
					<< "\t�绰��" << abs->userarray[i].phone
					<< "\t��ַ��" << abs->userarray[i].address << endl;
			}
		}
	}
	system("pause");//�������
	system("cls");//�����Ļ
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
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);

	if(ret != -1)
	{
		abs->userarray[ret].del = 1;
		//�鵽���ˣ�����ɾ��

		//for (int i = ret;i < abs->size;i++)
		//{
		//	//����ǰ��
		//	abs->userarray[i] = abs->userarray[i + 1];
		//}
		//abs->size--;//����ͨѶ¼������

		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

void finduser(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "ID��" << abs->userarray[ret].id
			<< "\t������" << abs->userarray[ret].name
			<< "\t�Ա�" << (abs->userarray[ret].sex == 1 ? "��" : "Ů")
			<< "\t���䣺" << abs->userarray[ret].age
			<< "\t�绰��" << abs->userarray[ret].phone
			<< "\t��ַ��" << abs->userarray[ret].address << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyuser(addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "�������µ�������" << endl;
		cin >> name;
		abs->userarray[ret].name = name;
		cout << "�������Ա�" << endl;
		cout << "1 --��" << endl;
		cout << "2 --Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->userarray[ret].sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->userarray[ret].age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->userarray[ret].phone = phone;

		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->userarray[ret].address = address;

		cout << "�޸ĳɹ�" << endl;

	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanuser(addressbooks* abs)
{
	cout << "�Ƿ�Ҫ���ͨѶ¼��" << endl;
	cout << "1 -- ��" << endl;
	cout << "2 -- ��" << endl;
	int temp = 0;
	cin >> temp;
	if (temp = 1) {
		abs->size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}


int main_abs()
{
	srand((unsigned int)time(NULL));
	//����ͨѶ¼�ṹ�����
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
			cout << "�˳��ɹ�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}