#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//C++���ļ���������ͷ�ļ�<fstream>

//�ļ����ͷ�Ϊ���֣�
//1.�ı��ļ�  -- �ļ����ı���ASCII����ʽ�洢�ڼ������
//2.�������ļ� -- �ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ���

//�����ļ��������ࣺ
//1.ofstream:д����
//2.ifstream:������
//3.fstream:��д����

//д�ļ�����
//1.����ͷ�ļ�
//#include<fstream>
//2.����������
// ofstream ofs;
//3.���ļ�
//ofs.open("�ļ�·��",�򿪷�ʽ);
//4.д����
//ofs<<"д�������";
//5.�ر��ļ�
//ofs.close();


//�ļ��򿪷�ʽ
// ios::in     Ϊ���ļ������ļ�
// ios::out    Ϊд�ļ������ļ�
// ios::ate    ��ʼλ�ã��ļ�β
// ios::app    ׷�ӷ�ʽд�ļ�
// ios::trunc  ����ļ�������ɾ�����ٴ���
// ios::binary �����Ʒ�ʽ

//�ļ��򿪷�ʽ�������ʹ��  ����|������
// �ö����Ʒ�ʽд�ļ�  ios::binary | ios::out


//���ļ�����
//1.����ͷ�ļ�
//#include<fstream>
//2.����������
// ifstream ifs;
//3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
//ifs.open("�ļ�·��",�򿪷�ʽ);
//4.������
//���ַ�ʽ��ȡ
//5.�ر��ļ�
//ifs.close();

//д�ļ�
void test_ofstream()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "HarmonyOS";
	ofs.close();
}

//���ļ�
void test_ifstream()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������
	//��һ��
	//char buf[1024] = { 0 };//�ַ������ʼ��Ϊ0
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))  //��ȡһ�У�(����ĵ�ַ����С)
	//{
	//	cout << buf << endl;
	//}

	//������
	/*string buf;
	while ( getline(ifs, buf))
	{
		cout << buf << endl;
	}*/

	//������
	char c;
	while ((c = ifs.get()) != EOF)  //EOF end of file
	{
		cout << c;
	}
	ifs.close();
}


//�������ļ�
//д�ļ�
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ�ͣ�ostream& write(const char * buffer, int len);
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

//���ļ�
//�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
//����ԭ�ͣ�istream& read(char *buffer,int len);
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

class Person
{
public:
	char m_Name[64];
	int m_age;
};

//�������ļ� д�ļ�

void test_binary_write()
{
	ofstream ofs("person.txt", ios::out | ios::binary); //���涨��Ĺ��캯��

	//ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "����", 18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

void test_binary_read()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������" << p.m_Name << " ���䣺" << p.m_age << endl;
	ifs.close();

}
int main27()
{
	//test_ofstream();
	//test_ifstream();
	//test_binary_write();
	test_binary_read();
	system("pause");
	return 0;
}