#include<iostream>
#include<string>
using namespace std;

//结构体：用户自定义数据类型，允许用户存储不同的数据类型
//struct 结构体名{结构体成员列表};
// 
//结构体创建变量的方式
//1.struct 结构体名 变量名
//2.struct 结构体名 变量名 = {成员1值，成员2值...}
//3.定义结构体时顺便创建变量

//定义结构体时关键字是struct，不可省略
// 创建结构体变量时，关键字struct可以省略
// 结构体变量利用操作符"."访问成员

//1.创建学生数据类型：学生包括（姓名，年龄，分数）
//自定义数据类型，一些类型集合组成的一个类型
//语法 struct 类型名称 {成员列表}
//结构体定义
struct Student
{
	//成员列表
	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
}s3;  //顺便创建结构体变量

//结构体数组
//将自定义的结构体放入到数组中方便维护
//struct 结构体名 数组名{元素个数} = {{},{},...{}};

//1.定义结构体
//2.创建结构体数组
//3.给结构体数组中的元素赋值
//4.遍历结构体数组

//结构体指针
//通过指针访问结构体中的成员
//利用操作符 '->' 可以通过结构体指针访问结构体属性


//结构体嵌套结构体
//结构体中的成员可以是另一个结构体
//案例：一个老师的结构体中，记录一个学生的结构体
struct teacher
{
	int id;
	string name;
	int age;
	struct Student stu[2];
};

//结构体做函数参数
//将结构体作为参数向函数中传递
//传递方式两种：
//1.值传递
//修饰形参，实参不会变
void printstu1(struct Student s)
{
	s.age = 20;
	cout << "姓名：" << s.name << "\t年龄：" << s.age << "\t分数：" << s.score << endl;
}
//2.地址传递
//修饰形参，实参也会变，改的是地址对应的值
void printstu2(struct Student* p)
{
	p->age = 20;
	cout << "姓名：" << p->name << "\t年龄：" << p->age << "\t分数：" << p->score << endl;
}


int main()
{
	//2.通过学生类型创建具体学生
	// 创建结构体变量时 struct 可以省略；定义时不能省
	//2.1 struct Student s1
	struct Student s1;
	//给s1属性赋值，通过.访问结构体变量中的属性
	s1.name = "Taylor";
	s1.age = 22;
	s1.score = 100;
	cout << "姓名：" << s1.name << "\t年龄：" << s1.age << "\t分数：" << s1.score << endl;
	
	//2.2 struct Student s2 = {...}
	struct Student s2 = { "Swift",20,99 };
	cout << "姓名：" << s2.name << "\t年龄：" << s2.age << "\t分数：" << s2.score << endl;
	
	//2.3 定义结构体时顺便创建变量
	//p21
	s3.name = "蕾蕾子";
	s3.age = 22;
	s3.score = 98;
	cout << "姓名：" << s3.name << "\t年龄：" << s3.age << "\t分数：" << s3.score << endl;
	
	//创建结构体数组
	struct Student stdarr[] =
	{
		{"msi",18,100},
		{"huawei",14,100},
		{"lenovo",20,98}
	};
	//给结构体数组中的元素赋值
	stdarr[2].name = "edit";
	//遍历结构体数组
	for (int i = 0;i < 3;i++)
	{
		cout << "姓名：" << stdarr[i].name << "\t年龄：" << stdarr[i].age << "\t分数：" << stdarr[i].score << endl;

	}

	//结构体指针
	//1.创建学生结构体变量
	Student s4 = { "张三",18,100 };
	//2.通过指针指向结构体变量
	Student * p = &s4;
	//3.通过指针指向结构体变量中数据
	p->score = 82;
	cout << "姓名：" << p->name << "\t年龄：" << p->age << "\t分数：" << p->score << endl;


	//结构体嵌套结构体
	//创建老师
	teacher t = { 100,"老王",50, { { "Taylor",20,90 },{ "msi",18,100} } };
	cout << "老师姓名：" << t.name << "编号：" << t.id 
		<< "年龄：" << t.age << "学生姓名：" << t.stu[1].name 
		<< "学生年龄：" << t.stu[1].age 
		<< "学生分数：" << t.stu[1].score << endl;	

	//结构体做函数参数
	//将学生传入到一个参数中，打印学生的信息
	struct Student stu1 = { "lv",18,60 };
	cout << stu1.name << endl;
	printstu1(stu1);
	cout << "姓名：" << stu1.name << "\t年龄：" << stu1.age << "\t分数：" << stu1.score << endl;
	printstu2(&stu1);

	system("pause");
	return 0;
}