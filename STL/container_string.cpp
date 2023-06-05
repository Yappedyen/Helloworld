#include<iostream>
#include<string>
using namespace std;

//string
//本质
//string 是C++风格的字符串，而string本质上是一个类
//string和char*区别：
//char*是一个指针  //c语言的字符串
//string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
//特点：
//string类内部封装了很多成员方法
//例如：查找find，拷贝copy，删除delete，替换replace，插入insert
//string管理char*所分配的内存，不用担心复制越界和取值越界，由类内部进行负责


//string构造函数
//string();  创建一个空的字符串 例如：string str;
//string(const char* s); 使用字符串s初始化
//string(const string & str);  使用一个string对象初始化另一个string对象
//string(int n, char c)  使用n个字符c初始化

void test_str1()
{
	string s1;//默认构造
	const char* str = "hello world";

	string s2(str);

	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 'a');
	cout << s4 << endl;
}

//string赋值操作
//给string字符串进行赋值
//赋值函数：
//string & operator = (const char* s);  //char*类型字符串 赋值给当前的字符串
//string & operator=(const string &s);  // 把字符串s赋给当前的字符串
//string & operator=(char c);  //字符赋值给当前的字符串
//string & assign(const char *s);  //把字符串s赋给当前的字符串
//string & assign(const char *s, int n);  //把字符串s的前n个字符赋给当前的字符串
//string & assign(const string &s);  //把字符串s赋给当前字符串
//string & assign(int n, char c);    //用n个字符c赋给当前字符串

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

//string字符串拼接
//实现在字符串末尾拼接字符串

//函数：
//string & operator+=(const char* str);  //重载+=操作符
//string & operator+=(const char c);   //重载+=操作符
//string & operator+=(const string& str);  //重载+=操作符
//string & append(const char *s);  // 把字符串s连接到当前字符串结尾
//string & append(const char *s, int n);    //把字符串s的前n个字符连接到当前字符串结尾
//string & append(const string &s);    //同operator+=(const string& str)
//string & append(const string &s, int pos, int n);    //字符串s中从pos开始的n个字符连接到字符串结尾

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

//string查找和替换
//查找：查找指定字符串是否存在
//替换：在指定的位置替换字符串
//函数原型：
//int find(const string &str, int pos = 0) const;    //查找str第一次出现位置，从pos开始查找
//int find(const char* s, int pos = 0) const;     //查找s第一次出现位置，从pos开始查找
//int find(const char* s, int pos, int n) const;     //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const;    //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const;    //查找str最后一次位置，从pos开始查找
//int rfind(const char* s, int pos = npos) const;     //查找s最后一次出现位置，从pos开始查找
//int rfind(const char* s, int pos，int n) const;    //从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const;    //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str);    //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s);    //替换从pos开始的n个字符为字符串s

//rfind 和 find区别
//rfind从右往左查找  find从左往右查找
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

//string字符串比较
//比较方式：字符串比较是按字符的ASCII码进行对比
//  =  返回  0
//  >  返回  1
//  <  返回  -1
//函数原型：
//int compare(const string &s) const;  //与字符串s比较
//int compare(const char * s) const;   //与字符串s比较

void test_strcom()
{
	string str1 = "xello";
	string str2 = "hello";
	int answer = str1.compare(str2);
	cout << answer << endl;
}

//string字符存取
//string中单个字符存取方式有两种：
//char & operator[](int n);  //通过[]方式取字符
//char & at(int n);    //通过at方式获取字符

void test_access()
{
	string str = "hello";
	
	cout <<str.size() << endl;
	cout << sizeof(str.size()) << endl;
	cout << typeid(str.size()).name() << endl;
	//1.通过[]访问单个字符
	for (int i = 0;i < str.size();i++)
	{
		cout << str[i] << " ";
	}

	//2.通过at方式访问单个字符
	for (int i = 0; i < str.size();i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str[0] = 'x';
	cout << str << endl;

}

//string插入和删除
//对string字符串进行插入和删除字符操作
//函数原型：
//string & insert(int pos, const char * s);  //插入字符串
//string & insert(int pos, const string& str);   //插入字符串
//string & insert(int pos, int n, char c);    //在指定位置插入n个字符c
//string & erase(int pos, int n = npos);    //删除从pos开始的n个字符

void test_strinsert()
{
	string str = "hello";

	//插入
	str.insert(1, "4440");
	cout << str << endl;

	//删除
	str.erase(1, 3);
	cout << str << endl;
}

//string子串
//从字符串中获取想要的子串
//函数原型：
//string substr(int pos = 0, int n = npos) const;  //返回由pos开始的n个字符组成的字符串

void test_strsubstr()
{
	string str = "abcdef";
	string subStr = str.substr(1, 4);

	cout << subStr << endl;
}

//实用操作
void test_useful()
{
	string email = "zhangxiaofei@sina.com";
	//从邮件地址中 获取 用户名信息
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