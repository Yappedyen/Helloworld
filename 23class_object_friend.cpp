#include<iostream>

using namespace std;

//��Ԫ
//�ڳ������Щ˽������Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���
//��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա

//��Ԫ�ؼ��� friend

//��Ԫ������ʵ��
//*ȫ�ֺ�������Ԫ
//*������Ԫ
//*��Ա��������Ԫ


//������
class Building
{
	//goodGayȫ�ֺ����� Building�����ѣ����Է���Building��˽�г�Ա
	//friend void goodGay(Building* building);
	//GoodGay���Ǳ���ĺ����ѣ����Է��ʱ�����˽�г�Ա
	friend class GoodGay;
	
public:
	Building()
	{
		m_Sittingroom = "����";
		m_Bedroom = "����";
	}
public:
	string m_Sittingroom;//����
private:
	string m_Bedroom;

};

//ȫ�ֺ���
void goodGay(Building* building)
{
	cout << "Goodgayȫ�ֺ��� ���ڷ��ʣ�" << building->m_Sittingroom << endl;
	cout << "Goodgayȫ�ֺ��� ���ڷ��ʣ�" << building->m_Sittingroom << endl;
}

//������Ԫ
class GoodGay
{
public:
	GoodGay();
	void visit(); //�ιۺ��� ����Building�е�����
	
private:
	Building* building;
};
void testgoogay()
{
	Building p;
	goodGay(&p);
}
//����д��Ա����
GoodGay::GoodGay()
{
	//�������������
	building = new Building;
}

void GoodGay::visit()
{
	cout << "GoodGay�����ڷ��ʣ�" << building->m_Sittingroom << endl;
	cout << "GoodGay�����ڷ��ʣ�" << building->m_Bedroom << endl;
}


void testGoodGayvisit()
{
	GoodGay gg;
	gg.visit();
}

//��Ա��������Ԫ
//building1���л��Ƚ����Լ���GoodGay1������GoodGay1��Ҫ����building�ඨ�壻
//����GoodGay1������һ��˽�б���Building1 *building1�����Ե�������building1�ࣻ
//GoodGay1��Ĺ��캯����Ҫnewһ��building1�����Ե���building�ඨ��֮��
class Building1; 
class GoodGay1
{
public:
	GoodGay1();
	void visit1();//��visit1�������Է���Building��˽�г�Ա
	void visit2();//��visit2���������Է���Building��˽�г�Ա
private:
	Building1* building1;
};

class Building1
{
	//���߱����� GoodGay���µ�visit1��Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
	friend void GoodGay1::visit1();
	//��Ԫ����ǰ ��Ԫ����һ��Ҫ�ȳ���
public:
	Building1();

public:
	string m_Sittingroom1;//����
private:
	string m_Bedroom1;
};

//����ʵ�ֳ�Ա����
Building1::Building1()
{
	m_Sittingroom1 = "����";
	m_Bedroom1 = "����";
}

GoodGay1::GoodGay1()
{
	building1 = new Building1;
}

void GoodGay1::visit1()
{
	cout << "visit1 ���ڷ��ʣ�" << building1->m_Sittingroom1 << endl;
	cout << "visit1 ���ڷ��ʣ�" << building1->m_Bedroom1 << endl;
}

void GoodGay1::visit2()
{
	cout << "visit2 ���ڷ��ʣ�" << building1->m_Sittingroom1 << endl;
	//cout << "visit2 ���ڷ��ʣ�" << building1->m_Bedroom1 << endl;
}

void testGoodGay1()
{
	GoodGay1 gg1;
	gg1.visit1();
	gg1.visit2();
}

int main23()
{
	//testgoogay();
	//testGoodGayvisit();
	testGoodGay1();
	system("pause");
	return 0;
}