#include<iostream>
#include<string>
using namespace std;

int main9() {
	//�Ӽ��˳�
	int a1 = 10, b1 = 3;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;

	int a2 = 10, b2 = 20;
	cout << a2 / b2 << endl;

	int a3 = 10, b3 = 0;
	//�������������������Ϊ0

	//����С�����
	double d1 = 0.5;
	double d2 = 0.22;
	cout << d1 / d2 << endl;

	//ȡģ���㣨ȡ�ࣩ
	//�������������������Ϊ0������������ȡģ����
	//����С���ǲ�������ȡģ�����
	cout << a1 % b1 << endl;
	cout << a2 % b2 << endl;
	//cout << d1 % d2 << endl;

	//�����ݼ�����
	//ǰ�á�����
	//ǰ�õ���
	int a = 0;
	++a; //�ñ���+1
	//���õ���
	int b = 0;
	b++; //�ñ���+1

	//ǰ�úͺ�������
	//ǰ�õ���  ���ñ���+1��Ȼ����б��ʽ����
	int c = ++a2 * 10;
	//���õ���  �Ƚ��б��ʽ���㣬Ȼ�����+1
	int d = b2++ * 10;
	//ǰ�õݼ�
	int c1 = --a2 * 10;
	int d3 = b2-- * 10;
	cout << c << endl;
	cout << d << endl;
	cout << c1 << endl;
	cout << d3 << endl;
	cout << a2 << endl;
	cout << b2 << endl;
	
	//��ֵ�����
	//=��+=��-=��*=��/=��%=
	a += 2;
	a /= 2;
	a *= 2;
	a %= 2;
	cout << a << endl;

	//�Ƚ������   ���ڱ��ʽ�ıȽϣ�����һ����ֵ���ֵ
	//==��!=��<��>��<=��>=

	cout << (c == d) << endl;
	cout << (c != d) << endl;
	cout << (c>=d) << endl;
	cout << (c <= d) << endl;

	//�߼������
	//!�ǡ�&&�롢||��
	cout << !a << endl;
	cout << (a && b) << endl;
	cout << (a || b) << endl;
	system("pause");
	return 0;
}