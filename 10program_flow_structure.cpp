#include<iostream>
using namespace std;

int main10() {
	//�������нṹ
	//˳��ṹ��ѡ��ṹ��ѭ���ṹ

	//1��ѡ��ṹ  
	//����if���  if(){}
	//int sorce = 0;
	//cout << "������һ��������" << endl;
	//cin >> sorce;
	//if (sorce >= 100) {
	//	cout << "����100" << endl;
	//}

	////����if ���  if(){}else{}
	//if (sorce >= 200) {
	//	cout << "����200" << endl;
	//}
	//else {
	//	cout << "С��200" << endl;
	//}

	////������if���  if(){}else if(){}...else{}
	//if (sorce >= 300) {
	//	cout << sorce << endl;
	//}
	//else if (sorce >= 200) {
	//	cout << sorce << endl;
	//}
	//else if (sorce >= 100) {
	//	cout << sorce << endl;
	//}else {
	//	cout << sorce << endl;
	//}

	////Ƕ��if���  if(){if(){}}
	//if (sorce >= 600) {
	//	if (sorce >= 700) {
	//		cout << sorce << endl;
	//	}
	//}
	//else if (sorce >= 200) {
	//	cout << sorce << endl;
	//}
	//else {
	//	cout << sorce << endl;
	//}

	/*int num1 =0, num2 = 0,num3 = 0;

	cout << "��ֱ�����С�����������λKg" << endl;
	cin >> num1>>num2>>num3;
	if (num1 >= num2) {
		if (num1 >= num3) {
			cout << "A��" << endl;
		}
		else {
			cout << "C��" << endl;
		}
	}
	else {
		if (num2 >= num3) {
			cout << "B��" << endl;
		}
		else {
			cout << "C��" << endl;
		}
	}*/

	//��Ŀ�����  ʵ�ּ򵥵��ж�
	//���ʽ1 �� ���ʽ2 : ���ʽ3
	//���ʽ1Ϊtrue��ִ�б��ʽ2�������ر��ʽ2�Ľ��
	//������ʽ1Ϊ�٣�ִ�б��ʽ3�������ر��ʽ3�Ľ��
	/*int c = 0, max = 0;
	c = num1 >= num2 ? num1 : num2;
	max = c >= num3 ? c : num3;
	cout << "Max:"<< max << endl;*/

	//switch���
	//ִ�ж�������֧���
	//switch(���ʽ){case ���1:ִ�����;break;case ���2:ִ�����;break;...defalt:ִ�����;break;}
	//���ʽ����ֻ�������ͻ����ַ���
	//���ڶ������жϣ�switchִ��Ч�ʸߣ����ǲ������ж�����
	/*int state = 0;
	cin >> state;
	switch (state) {
	case 10: 
		cout << state << endl;
		break;
	case 9:
		cout << state << endl;
		break;
	case 8:
		cout << state << endl;
		break;
	default:
		cout << state << endl;
		break;
	}*/

	//2.ѭ���ṹ
	//while(ѭ������){ѭ�����}
	/*int num = 0;
	while (10 >=num) {
		cout << num << endl;
		++num;
	}*/

	//�������
	//�����������ӣ���Ϊ���õ�ǰϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int)time(NULL));
	//cout << srand(time(0)) << endl;
	//int randnum = rand() % 100 + 1;  //rand()%100 +1 ���� 0 +1 ~99 + 1 �����
	//int val = 0;
	//while (1) {
	//	cin >> val;
	//	if (randnum > val)
	//	{
	//		cout << "����" << endl;
	//	}
	//	else if (randnum < val)
	//	{
	//		cout << "��С" << endl;
	//	}
	//	else {
	//		cout << "��ȷ" << endl;
	//		break;  // break �˳�ѭ��
	//	}
	//}
	
	//do...while ѭ��    ����ѭ��������ִ��ѭ�����
	//do{ѭ�����}while(ѭ������);
	//��while��������do...while����ִ��һ��ѭ����䣬���ж�ѭ������
	/*int num = 0;
	do {
		cout << num << endl;
		++num;
	} while (num < 10);*/

	//ˮ�ɻ���  ָһ��3λ��������ÿ��λ�ϵ����ֵ�3����֮�͵��������� 1^3+5^3+3^3=153
	//1.��ӡ����3λ��
	//int num = 100;
	//do {
	//	int a = 0, b = 0, c = 0;
	//	a = num % 10;  //��λ
	//	b = num / 10 % 10;  //ʮλ
	//	c = num / 100;  //��λ

	//	if (a*a*a + b*b*b + c*c*c == num) {
	//		cout << num << endl;
	//	}
	//	num++;
	//} while (num < 1000);


	//forѭ�����
	//for(��ʼ���ʽ;�������ʽ;ĩβѭ����){ѭ�����;}
	//for (int i = 1;i <= 100;i++) {
	//	int a = 0,b = 0, c = 0,d = 0;
	//	a = i % 10;
	//	b = i / 10 % 10;
	//	c = i / 100;
	//	d = i % 7;
	//	if (a == 7 || b == 7 || d == 0) {
	//		cout <<"������"<< endl;
	//	}
	//	else {
	//		cout << i << endl;
	//	}
	//}

	//Ƕ��ѭ��
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cout << "* ";
		}
		cout << endl;
	}


	for (int i = 1;i < 10;i++)
	{
		for (int j = 1;j < 10;j++)
		{
			if (j <= i) {
				cout << j << "x" << i << "=" << j * i<<"\t";
			}
		}
		cout << endl;
	}


	//��ת���
	//��������ѡ��ṹ����ѭ���ṹ
	//������switch��������У���ֹcase������switch
	//������ѭ������У����� ��ǰ��ѭ�����
	//������Ƕ��ѭ���У�����������ڲ�ѭ�����
	//1.������switch��
	cout << "����������Ѷ�" << endl;
	cout << "1.��ͨ" << endl;
	cout << "2.�е�" << endl;
	cout << "3.����" << endl;
	int select = 0;
	cin >> select;
	switch (select) {
	case 1:
		cout << "��ͨ" << endl;
		break;
	case 2:
		cout << "�е�" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;
	default:
		break;
	}

	//2.������ѭ�������
	for (int i = 0; i < 10;i++)
	{
		if (i == 5) {
			break;
		}
		cout << i << endl;
	}

	//3.������Ƕ��ѭ�������
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (j == 5) {
				break;  //�˳��ڲ�ѭ��
			}
			cout << "%";
		}
		cout << endl;
	}


	//continue���
	//��ѭ������У���������ѭ����������δִ�е���䣬����ִ����һ��ѭ��
	for (int i = 0; i < 10;i++)
	{
		if (i % 2 == 1)
		{
			continue;
			
		}
		cout << i << endl;
	}


	//��ת���goto
	//��������ת���
	//goto ��ǣ�
	cout << "1.Q" << endl;
	cout << "2.W" << endl;
	goto FLAG;
	cout << "3.E" << endl;
	cout << "4.R" << endl;
	FLAG:
	cout << "5.T" << endl;
	system("pause");
	return 0;
}