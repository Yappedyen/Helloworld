#include<iostream>
#include"point.h"
#include"circle1.h"
using namespace std;

//C++��������������ԣ���װ���̳С���̬
//���������Ϊ���󣬶������������Ժ���Ϊ

//1.��װ
// 
//���壺
//*�����Ժ���Ϊ��Ϊһ�����壬���������е�����
//�﷨
// class ����{����Ȩ��: ���� / ��Ϊ};
//*�����Ժ���Ϊ���ڲ�ͬȨ���¼���Ȩ�޿���
//����Ȩ��
//1 public  ����Ȩ��  ��Ա ���ڿ��Է��ʣ�����Ҳ���Է���
//2 protected  ����Ȩ��  ��Ա ���ڿ��Է��ʣ����ⲻ���Է���  ���ӿ��Է��ʸ����еı�������
//3 private  ˽��Ȩ��  ��Ա ���ڿ��Է��ʣ����ⲻ���Է���  ���Ӳ����Է��ʸ��׵�˽������

//struct��class����
// Ĭ�Ϸ���Ȩ�޲�ͬ
// *struct Ĭ��Ȩ��Ϊ����
// *class Ĭ��Ȩ��Ϊ˽��


//����Ա��������Ϊ˽��
// �ŵ㣺�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
//       ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��


//Բ����
const double PI = 3.14;

//���һ��Բ�࣬��Բ��
class circle
{
	//����Ȩ��
	//����Ȩ��
public:
	//����
	//�뾶
	int r;

	//��Ϊ
	//��ȡԲ���ܳ�
	double calculatezc()
	{
		return 2 * PI * r;
	}
	
};


//���һ��ѧ���࣬������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class student
{
public:
	//���е����Ժ���Ϊ ͳһ��Ϊ ��Ա
	//���� ��Ա���� ��Ա����
	//��Ϊ ��Ա���� ��Ա����
	//����
	string name;
	string id;

	//��ʾ������ѧ��
	void showstu()
	{
		cout << "����Ϊ��" << name << "\tѧ��Ϊ��" << id << endl;
	}
	//��������ֵ
	void setname(string sname)
	{
		name = sname;
	}

	void setid(string sid)
	{
		id = sid;
	}
};

class person
{
public:
	//����Ȩ��
	string m_name;

protected:
	//����Ȩ��
	string m_car;

private:
	//˽��Ȩ��
	int m_psd;

public:  //private/protected �������ⲻ�ɷ���
	void func()
	{
		m_name = "Taylor";
		m_car = "Bens";
		m_psd = 12548;
	}
};

class c1
{
	int m_a; //Ĭ��Ȩ�� ˽��
};

struct c2
{
	int m_a; //Ĭ��Ȩ�� ����
};

//�������
class person1
{
private:
	//����  �ɶ���д
	string p_name;
	//����  ֻ��
	int p_age;
	//����  ֻд
	string lover;
	
public:
	//�������� 
	void setname(string name)
	{
		p_name = name;
	 }
	//��ȡ����
	string getname()
	{
		return p_name;
	}

	//��ȡ����  �ɶ���д ������޸ģ����䷶Χ������0��150֮�䣩
	int getage()
	{
		//p_age = 0;
		return p_age;
	}

	void setage(int age)
	{
		if (age < 0 || age >150)
		{
			p_age = 0;
			cout << "��������������" << endl;
			return;
		}
		p_age = age;
	}

	//���ð��� ֻд
	void setlover(string slover)
	{
		lover = slover;
	}
};

//�����������������
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����

class cube
{
public:
	//���ó�
	void setl(int l)
	{
		c_l = l;
	}
	int getl()
	{
		return c_l;
	}
	//���ÿ�
	void setw(int w)
	{
		c_w = w;
	}
	int getw()
	{
		return c_w;
	}
	void seth(int h)
	{
		c_h = h;
	}
	int geth()
	{
		return c_h;
	}
	//��ȡ���������
	int calcuteS()
	{
		return 2 * (c_l * c_w + c_l * c_h + c_w * c_h);
	}
	//��ȡ���������
	int calcuteV()
	{
		return c_l * c_w * c_h;
	}

	//���ó�Ա�����ж�
	bool issamebyclass(cube& c)
	{
		if (c_l == c.getl() && c_w == c.getw() && c_h == c.geth())
		{
			return true;
		}
		return false;
	}
private:
	int c_l;
	int c_w;
	int c_h;
};

//����ȫ�ֺ����ж��������Ƿ����
bool issame(cube& cube1, cube& cube2)
{
	if (cube1.getl() == cube2.getl() && cube1.getw() == cube2.getw() && cube1.geth() == cube2.geth())
	{
		return true;
	}
}

//���Բ��ϵ����
//Բ��
//class point
//{
//public:
//	//����x����
//	void setx(int x)
//	{
//		p_x = x;
//	}
//	//����y����
//	void sety(int y)
//	{
//		p_y = y;
//	}
//	int getx()
//	{
//		return p_x;
//	}
//	int gety()
//	{
//		return p_y;
//	}
//private:
//	int p_x;
//	int p_y;
//};

//class circle1
//{
//private:
//	int c_r;
//	//�����п�������һ���� ��Ϊ�����еĳ�Ա
//	point c_center;
//public:
//	//���ð뾶
//	void setr(int r)
//	{
//		c_r = r;
//	}
//	//��ȡ�뾶
//	int getr()
//	{
//		return c_r;
//	}
//	//����Բ��
//	void setcenter(point center)
//	{
//		c_center = center;
//	}
//	//��ȡԲ��
//	point getcenter()
//	{
//		return c_center;
//	}
//};
//�жϵ��Բ�Ĺ�ϵ
void isincircle(circle1& c, point& p)
{
	//��������֮����� ƽ��
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());

	//����뾶��ƽ��
	int rdis = c.getr() * c.getr();
	//�жϹ�ϵ
	if (distance == rdis)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rdis)
	{
		cout << "����Բ��" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}
int main20()
{
	//ͨ��Բ�� ���������Բ(����)
	//ʵ������ͨ��һ���� ����һ������Ĺ��̣�
	circle cl;
	//����������Խ��и�ֵ
	cl.r = 10;
	cout << "Բ�ܣ�" << cl.calculatezc() << endl;

	student stu1;
	string name;
	string id;
	cout << "����������" << endl;
	cin >> name;
	cout << "����ѧ�ţ�" << endl;
	cin >> id;
	stu1.setname(name);
	stu1.setid(id);
	stu1.showstu();

	person p1;
	p1.m_name = "Swift";
	//p1.m_car = "byd"; //����Ȩ�����ݣ���������ʲ���
	//p1.m_psd = 54555; //˽��Ȩ�����ݣ�������ʲ���

	//struct�� class����
	//c1 cl1;
	//cl1.m_a = 100;   //classĬ��˽�У����ܷ���
	c2 struct1;
	struct1.m_a = 100;  //struct Ĭ��Ȩ�޹��������Է���

	//����Ա������Ϊ˽��
	person1 p;
	p.setname("Taylor");

	cout << "������" << p.getname() << endl;
	p.setage(1000);
	cout << "����Ϊ��" << p.getage() << endl;
	p.setlover("Swift");
	//cout << "���ˣ�" << p.setlover() << endl;

	//�������������
	cube cube1;
	cube1.setl(10);
	cube1.setw(5);
	cube1.seth(2);
	cout << "�����������" << cube1.calcuteS() << endl;
	cout << "�����������" << cube1.calcuteV() << endl;
	
	cube cube2;
	cube2.setl(10);
	cube2.setw(5);
	cube2.seth(2);
	bool ret = issame(cube1, cube2);
	if (ret)
	{
		cout << "���" << endl;
	}
	else {
		cout << "�����" << endl;
	}

	//���ó�Ա�����ж�
	ret = cube1.issamebyclass(cube2);
	if (ret)
	{
		cout << "��Ա�����жϣ����" << endl;
	}
	else {
		cout << "��Ա�����жϣ������" << endl;
	}

	//����Բ
	circle1 c;
	c.setr(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);
	//������
	point p2;
	p2.setx(10);
	p2.sety(10);
	//�жϹ�ϵ
	isincircle(c, p2);

	system("pause");
	return 0;
}