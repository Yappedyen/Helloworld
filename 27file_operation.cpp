#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//C++对文件操作包含头文件<fstream>

//文件类型分为两种：
//1.文本文件  -- 文件以文本的ASCII码形式存储在计算机中
//2.二进制文件 -- 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂

//操作文件的三大类：
//1.ofstream:写操作
//2.ifstream:读操作
//3.fstream:读写操作

//写文件步骤
//1.包含头文件
//#include<fstream>
//2.创建流对象
// ofstream ofs;
//3.打开文件
//ofs.open("文件路径",打开方式);
//4.写数据
//ofs<<"写入的数据";
//5.关闭文件
//ofs.close();


//文件打开方式
// ios::in     为读文件而打开文件
// ios::out    为写文件而打开文件
// ios::ate    初始位置：文件尾
// ios::app    追加方式写文件
// ios::trunc  如果文件存在先删除，再创建
// ios::binary 二进制方式

//文件打开方式可以配合使用  利用|操作符
// 用二进制方式写文件  ios::binary | ios::out


//读文件步骤
//1.包含头文件
//#include<fstream>
//2.创建流对象
// ifstream ifs;
//3.打开文件并判断文件是否打开成功
//ifs.open("文件路径",打开方式);
//4.读数据
//四种方式读取
//5.关闭文件
//ifs.close();

//写文件
void test_ofstream()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "HarmonyOS";
	ofs.close();
}

//读文件
void test_ifstream()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	//第一种
	//char buf[1024] = { 0 };//字符数组初始化为0
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))  //获取一行，(放入的地址，大小)
	//{
	//	cout << buf << endl;
	//}

	//第三种
	/*string buf;
	while ( getline(ifs, buf))
	{
		cout << buf << endl;
	}*/

	//第四种
	char c;
	while ((c = ifs.get()) != EOF)  //EOF end of file
	{
		cout << c;
	}
	ifs.close();
}


//二进制文件
//写文件
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型：ostream& write(const char * buffer, int len);
//参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

//读文件
//二进制方式读文件主要利用流对象调用成员函数read
//函数原型：istream& read(char *buffer,int len);
//参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

class Person
{
public:
	char m_Name[64];
	int m_age;
};

//二进制文件 写文件

void test_binary_write()
{
	ofstream ofs("person.txt", ios::out | ios::binary); //里面定义的构造函数

	//ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "张三", 18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

void test_binary_read()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_age << endl;
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