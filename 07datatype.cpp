#include <iostream>
using namespace std;
#include<string>
//�������ʹ��ڵ����壺������������ʵ��ڴ�ռ�

//1  int ����    ռ�ÿռ�                                       ��Χ
//short(������)  2byte                                       -2^15-2^15-1(-32768-32767)
//int�����Σ�    4byte                                       -2^31-2^31-1(-
//long�������ͣ� 4byte(win),4byte(linux32),8byte(linux64)    -2^31-2^31-1
//long long(�������ͣ�  8byte                                -2^63-2^63-1

//2 sizeof �ؼ���
//�����������ռ���ڴ��С
//�﷨��sizeof(�������� /����)
//���δ�С�Ƚ� 
// short < int <= long <= long long 

//3 ʵ�ͣ������ͣ� ��ʾС��
// ������float    4byte  7λ��Ч����
//˫����double    8byte  15-16λ��Ч����
//Ĭ������� ���һ��С��������ʾ6λ��Ч����

//4 �ַ���  �ַ��ͱ���������ʾ�����ַ�
//char ch = 'a';
//��ʾ�ַ��ͱ���ʱ���õ����Ž��ַ�����������Ҫ��˫����
//��������ֻ����һ���ַ������������ַ���
//�ַ��ͱ���ֻռ��1���ֽ�
//�ַ��ͱ������ǰ��ַ�����ŵ��ڴ��д洢�����ǽ���Ӧ��ASCII����ŵ��洢��Ԫ


//5 ת���ַ�
//���з� \n
//��б�� \\
//ˮƽ�Ʊ�� \t  ����������������  ��ռ8���ַ�

//6 �ַ����� ��ʾһ���ַ�
// c ����ַ���  char ������[] = "�ַ���ֵ"
// c++ ����ַ���  string ������ = "�ַ���ֵ"

//7 �������� bool ռ��1�ֽ�
//�������ٵ�ֵ
//true �� (1)
//false ��(0)

//8 ���ݵ�����

int main7() {
	short num1 = 32768;  //����������-32768
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;

	cout << "shortռ���ڴ�ռ��С��" << sizeof(num1) << endl;
	cout << "intռ���ڴ�ռ��С��" << sizeof(num2) << endl;
	cout << "longռ���ڴ�ռ��С��" << sizeof(num3) << endl;
	cout << "long longռ���ڴ�ռ��С��" << sizeof(num4) << endl;
	
	float f1 = 3.1415921f;
	double d1 = 3.1415926;
	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;

	//ͳ��float double ռ���ڴ�ռ�
	cout << "float ռ���ڴ�ռ�Ϊ��" << sizeof(float) << endl;
	cout << "double ռ���ڴ�ռ�Ϊ��" << sizeof(double) << endl;
	
	//��ѧ������
	float f2 = 3e2; //3 * 10 ^2
	cout << "f2=" << f2 << endl;
	float f3 = 3e-2; //3 * 0.1^2
	cout << "f3=" << f3 << endl;

	//�ַ��ͱ���������ʽ
	char ch = 'a';
	cout << ch << endl;
	//�ַ��ͱ���ռ���ڴ��С
	cout << sizeof(char) << endl;
	//�ַ��ͱ�����������
	//char ch2 = "b";  �����ַ��ͱ���ʱҪ�õ�����
	//char ch2 = 'abcdef'; �����ַ��ͱ���ʱ����������ֻ����һ���ַ�
	//�ַ��ͱ�����ӦASCII����  a-97  A-65
	cout << "a ��ASCII����Ϊ" << (int)ch << endl;

	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;
	cout << u - u2 << endl;

	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;

	cout << "hello world\n";
	cout << "\\" << endl;
	cout << "\thello" << endl;
	cout << "aaaa\thello" << endl;
	cout << "aaaaaaaa\thello" << endl;


	//c���
	//ע������  char �ַ�����[]
	//�Ⱥź��� Ҫ��˫����
	char str1[] = "hello world";
	cout << str1 << endl;
	//c++ ��� ����һ��ͷ�ļ�
	string str2 = "hello world";
	cout << str2 << endl;

	cout << sizeof(bool) << endl;

	bool flag = true;
	if (flag){
		cout << flag << endl;
	}

	//1.����
	//int a = 0;
	//cout << "������������" << endl;
	//cin >> a;
	//cout << "���ͱ���a = " << a << endl;

	//2.������
	//float f = 3.14f;
	//cin >> f;
	//cout << f << endl;

	//3.�ַ���
	//char ch = 'a';
	//cin >> ch;
	//cout << ch << endl;

	//4.�ַ�����
	string str = "hello";
	cin >> str;
	cout << str << endl;

	//5.bool��
	//bool flag = false;
	//cin >> flag;
	//cout << flag << endl;

	system("pause");
	return 0;
}