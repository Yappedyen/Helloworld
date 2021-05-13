#include <iostream>
using namespace std;
//标识符命名规则
//标识符不能为关键字
//标识符只能是字母、数字、下划线
//第一个字符必须为字母或下划线，字母区分大小写
int main6()
{
	//1.标识符不为关键字
	//int int = 10;
	//2.标识符只能是字母、数字、下划线
	int abc = 10;
	int _abc = 20;
	int _123abc = 30;
	//3.第一个字符必须为字母或下划线
	//int 123abc = 40;
	//4.区分大小写
	int aaa = 100;
	cout << aaa << endl;
	//cout << AAA << endl; // AAA和aaa不是同一个
	//变量起名最好见名知意
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	system("pause");
	return 0;
}