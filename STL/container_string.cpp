#include<iostream>
#include<string>
using namespace std;

//string
//����
//string ��C++�����ַ�������string��������һ����
//string��char*����
//char*��һ��ָ��  //c���Ե��ַ���
//string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�������
//�ص㣺
//string���ڲ���װ�˺ܶ��Ա����
//���磺����find������copy��ɾ��delete���滻replace������insert
//string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ�磬�����ڲ����и���


//string���캯��
//string();  ����һ���յ��ַ��� ���磺string str;
//string(const char* s); ʹ���ַ���s��ʼ��
//string(const string & str);  ʹ��һ��string�����ʼ����һ��string����
//string(int n, char c)  ʹ��n���ַ�c��ʼ��

void test_str1()
{
	string s1;//Ĭ�Ϲ���
	const char* str = "hello world";

	string s2(str);

	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 'a');
	cout << s4 << endl;
}

//string��ֵ����
//��string�ַ������и�ֵ
//��ֵ������
//string & operator = (const char* s);  //char*�����ַ��� ��ֵ����ǰ���ַ���
//string & operator=(const string &s);  // ���ַ���s������ǰ���ַ���
//string & operator=(char c);  //�ַ���ֵ����ǰ���ַ���
//string & assign(const char *s);  //���ַ���s������ǰ���ַ���
//string & assign(const char *s, int n);  //���ַ���s��ǰn���ַ�������ǰ���ַ���
//string & assign(const string &s);  //���ַ���s������ǰ�ַ���
//string & assign(int n, char c);    //��n���ַ�c������ǰ�ַ���

void test_str2()
{
	string str1 = "hello world";
	string str2 = str1;
	string str3;
	str3 = 'ss';
	string str4;
	str4.assign("c++");
	string str5;
	str5.assign("cssddfsfa", 5);
	string str6;
	str6.assign(str5);
	string str7;
	str7.assign(4,'d');
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	cout << str7 << endl;
}

//string�ַ���ƴ��
//ʵ�����ַ���ĩβƴ���ַ���

//������
//string & operator+=(const char* str);  //����+=������
//string & operator+=(const char c);   //����+=������
//string & operator+=(const string& str);  //����+=������
//string & append(const char *s);  // ���ַ���s���ӵ���ǰ�ַ�����β
//string & append(const char *s, int n);    //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//string & append(const string &s);    //ͬoperator+=(const string& str)
//string & append(const string &s, int pos, int n);    //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

void test_str3()
{
	string str1 = "I";
	str1 += " love ";
	str1 += 'y';
	str1 += "ou,";
	string str2;
	str2 = "Are you love me ?";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append(" and ");
	str3.append("you are", 3);
	//str3.append(str2);
	str3.append(str2, 7, 8);

	cout << str3 << endl;
}

//string���Һ��滻
//���ң�����ָ���ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���
//����ԭ�ͣ�
//int find(const string &str, int pos = 0) const;    //����str��һ�γ���λ�ã���pos��ʼ����
//int find(const char* s, int pos = 0) const;     //����s��һ�γ���λ�ã���pos��ʼ����
//int find(const char* s, int pos, int n) const;     //��posλ�ò���s��ǰn���ַ���һ��λ��
//int find(const char c, int pos = 0) const;    //�����ַ�c��һ�γ���λ��
//int rfind(const string& str, int pos = npos) const;    //����str���һ��λ�ã���pos��ʼ����
//int rfind(const char* s, int pos = npos) const;     //����s���һ�γ���λ�ã���pos��ʼ����
//int rfind(const char* s, int pos��int n) const;    //��pos����s��ǰn���ַ����һ��λ��
//int rfind(const char c, int pos = 0) const;    //�����ַ�c���һ�γ���λ��
//string& replace(int pos, int n, const string& str);    //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//string& replace(int pos, int n, const char* s);    //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

//rfind �� find����
//rfind�����������  find�������Ҳ���
void test_strfind()
{
	string str1 = "abcdefgfgfgfg";
	int pos = str1.find("fg");
	int pos1 = str1.find("fg", 5,1);
	int pos2 = str1.find('g');
	int pos3 = str1.rfind("fg");
	cout << pos << endl;
	cout << pos1 << endl;
	cout << pos2 << endl;
	cout << pos3 << endl;
}

void test_strreplace()
{
	string str1 = "abcdefgh";
	str1.replace(1, 3, "11111");
	cout << str1 << endl;
}

//string�ַ����Ƚ�
//�ȽϷ�ʽ���ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
//  =  ����  0
//  >  ����  1
//  <  ����  -1
//����ԭ�ͣ�
//int compare(const string &s) const;  //���ַ���s�Ƚ�
//int compare(const char * s) const;   //���ַ���s�Ƚ�

void test_strcom()
{
	string str1 = "xello";
	string str2 = "hello";
	int answer = str1.compare(str2);
	cout << answer << endl;
}

//string�ַ���ȡ
//string�е����ַ���ȡ��ʽ�����֣�
//char & operator[](int n);  //ͨ��[]��ʽȡ�ַ�
//char & at(int n);    //ͨ��at��ʽ��ȡ�ַ�

void test_access()
{
	string str = "hello";
	
	cout <<str.size() << endl;
	cout << sizeof(str.size()) << endl;
	cout << typeid(str.size()).name() << endl;
	//1.ͨ��[]���ʵ����ַ�
	for (int i = 0;i < str.size();i++)
	{
		cout << str[i] << " ";
	}

	//2.ͨ��at��ʽ���ʵ����ַ�
	for (int i = 0; i < str.size();i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//�޸ĵ����ַ�
	str[0] = 'x';
	cout << str << endl;

}

//string�����ɾ��
//��string�ַ������в����ɾ���ַ�����
//����ԭ�ͣ�
//string & insert(int pos, const char * s);  //�����ַ���
//string & insert(int pos, const string& str);   //�����ַ���
//string & insert(int pos, int n, char c);    //��ָ��λ�ò���n���ַ�c
//string & erase(int pos, int n = npos);    //ɾ����pos��ʼ��n���ַ�

void test_strinsert()
{
	string str = "hello";

	//����
	str.insert(1, "4440");
	cout << str << endl;

	//ɾ��
	str.erase(1, 3);
	cout << str << endl;
}

//string�Ӵ�
//���ַ����л�ȡ��Ҫ���Ӵ�
//����ԭ�ͣ�
//string substr(int pos = 0, int n = npos) const;  //������pos��ʼ��n���ַ���ɵ��ַ���

void test_strsubstr()
{
	string str = "abcdef";
	string subStr = str.substr(1, 4);

	cout << subStr << endl;
}

//ʵ�ò���
void test_useful()
{
	string email = "zhangxiaofei@sina.com";
	//���ʼ���ַ�� ��ȡ �û�����Ϣ
	int pos = email.find("@");  //12

	string userName = email.substr(0, pos);
	cout << userName << endl;
}
int main_string()
{

	//test_str1();
	//test_str2();
	//test_str3();
	//test_strfind();
	//test_strreplace();
	//test_strcom();
	test_access();
	test_strinsert();
	test_strsubstr();
	test_useful();
	system("pause");
	return 0;
}