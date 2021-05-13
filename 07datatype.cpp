#include <iostream>
using namespace std;
#include<string>
//数据类型存在的意义：给变量分配合适的内存空间

//1  int 整形    占用空间                                       范围
//short(短整型)  2byte                                       -2^15-2^15-1(-32768-32767)
//int（整形）    4byte                                       -2^31-2^31-1(-
//long（长整型） 4byte(win),4byte(linux32),8byte(linux64)    -2^31-2^31-1
//long long(长长整型）  8byte                                -2^63-2^63-1

//2 sizeof 关键字
//求出数据类型占用内存大小
//语法：sizeof(数据类型 /变量)
//整形大小比较 
// short < int <= long <= long long 

//3 实型（浮点型） 表示小数
// 单精度float    4byte  7位有效数字
//双精度double    8byte  15-16位有效数字
//默认情况下 输出一个小数，会显示6位有效数字

//4 字符型  字符型变量用于显示单个字符
//char ch = 'a';
//显示字符型变量时，用单引号将字符括起来，不要用双引号
//单引号内只能有一个字符，不可以是字符串
//字符型变量只占用1个字节
//字符型变量不是把字符本身放到内存中存储，而是将对应的ASCII编码放到存储单元


//5 转义字符
//换行符 \n
//反斜杠 \\
//水平制表符 \t  可以整齐的输出数据  共占8个字符

//6 字符串型 表示一串字符
// c 风格字符串  char 变量名[] = "字符串值"
// c++ 风格字符串  string 变量名 = "字符串值"

//7 布尔类型 bool 占用1字节
//代表真或假的值
//true 真 (1)
//false 假(0)

//8 数据的输入

int main7() {
	short num1 = 32768;  //会溢出，变成-32768
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;

	cout << "short占用内存空间大小：" << sizeof(num1) << endl;
	cout << "int占用内存空间大小：" << sizeof(num2) << endl;
	cout << "long占用内存空间大小：" << sizeof(num3) << endl;
	cout << "long long占用内存空间大小：" << sizeof(num4) << endl;
	
	float f1 = 3.1415921f;
	double d1 = 3.1415926;
	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;

	//统计float double 占用内存空间
	cout << "float 占用内存空间为：" << sizeof(float) << endl;
	cout << "double 占用内存空间为：" << sizeof(double) << endl;
	
	//科学计数法
	float f2 = 3e2; //3 * 10 ^2
	cout << "f2=" << f2 << endl;
	float f3 = 3e-2; //3 * 0.1^2
	cout << "f3=" << f3 << endl;

	//字符型变量创建方式
	char ch = 'a';
	cout << ch << endl;
	//字符型变量占用内存大小
	cout << sizeof(char) << endl;
	//字符型变量常见错误
	//char ch2 = "b";  创建字符型变量时要用单引号
	//char ch2 = 'abcdef'; 创建字符型变量时，单引号内只能有一个字符
	//字符型变量对应ASCII编码  a-97  A-65
	cout << "a 的ASCII编码为" << (int)ch << endl;

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


	//c风格
	//注意事项  char 字符串名[]
	//等号后面 要用双引号
	char str1[] = "hello world";
	cout << str1 << endl;
	//c++ 风格 包含一个头文件
	string str2 = "hello world";
	cout << str2 << endl;

	cout << sizeof(bool) << endl;

	bool flag = true;
	if (flag){
		cout << flag << endl;
	}

	//1.整型
	//int a = 0;
	//cout << "请输入整数：" << endl;
	//cin >> a;
	//cout << "整型变量a = " << a << endl;

	//2.浮点型
	//float f = 3.14f;
	//cin >> f;
	//cout << f << endl;

	//3.字符型
	//char ch = 'a';
	//cin >> ch;
	//cout << ch << endl;

	//4.字符串型
	string str = "hello";
	cin >> str;
	cout << str << endl;

	//5.bool型
	//bool flag = false;
	//cin >> flag;
	//cout << flag << endl;

	system("pause");
	return 0;
}