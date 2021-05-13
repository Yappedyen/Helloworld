#include<iostream>
using namespace std;

int main10() {
	//程序运行结构
	//顺序结构、选择结构、循环结构

	//1、选择结构  
	//单行if语句  if(){}
	//int sorce = 0;
	//cout << "请输入一个分数：" << endl;
	//cin >> sorce;
	//if (sorce >= 100) {
	//	cout << "超过100" << endl;
	//}

	////多行if 语句  if(){}else{}
	//if (sorce >= 200) {
	//	cout << "超过200" << endl;
	//}
	//else {
	//	cout << "小于200" << endl;
	//}

	////多条件if语句  if(){}else if(){}...else{}
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

	////嵌套if语句  if(){if(){}}
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

	cout << "请分别输入小猪的重量：单位Kg" << endl;
	cin >> num1>>num2>>num3;
	if (num1 >= num2) {
		if (num1 >= num3) {
			cout << "A重" << endl;
		}
		else {
			cout << "C重" << endl;
		}
	}
	else {
		if (num2 >= num3) {
			cout << "B重" << endl;
		}
		else {
			cout << "C重" << endl;
		}
	}*/

	//三目运算符  实现简单的判断
	//表达式1 ？ 表达式2 : 表达式3
	//表达式1为true，执行表达式2，并返回表达式2的结果
	//如果表达式1为假，执行表达式3，并返回表达式3的结果
	/*int c = 0, max = 0;
	c = num1 >= num2 ? num1 : num2;
	max = c >= num3 ? c : num3;
	cout << "Max:"<< max << endl;*/

	//switch语句
	//执行多条件分支语句
	//switch(表达式){case 结果1:执行语句;break;case 结果2:执行语句;break;...defalt:执行语句;break;}
	//表达式类型只能是整型或者字符型
	//对于多条件判断，switch执行效率高，但是不可以判断区间
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

	//2.循环结构
	//while(循环条件){循环语句}
	/*int num = 0;
	while (10 >=num) {
		cout << num << endl;
		++num;
	}*/

	//猜随机数
	//添加随机数种子，作为利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));
	//cout << srand(time(0)) << endl;
	//int randnum = rand() % 100 + 1;  //rand()%100 +1 生成 0 +1 ~99 + 1 随机数
	//int val = 0;
	//while (1) {
	//	cin >> val;
	//	if (randnum > val)
	//	{
	//		cout << "过大" << endl;
	//	}
	//	else if (randnum < val)
	//	{
	//		cout << "过小" << endl;
	//	}
	//	else {
	//		cout << "正确" << endl;
	//		break;  // break 退出循环
	//	}
	//}
	
	//do...while 循环    满足循环条件，执行循环语句
	//do{循环语句}while(循环条件);
	//与while区别在于do...while会先执行一次循环语句，再判断循环条件
	/*int num = 0;
	do {
		cout << num << endl;
		++num;
	} while (num < 10);*/

	//水仙花数  指一个3位数，它的每个位上的数字的3次幂之和等于它本身 1^3+5^3+3^3=153
	//1.打印所有3位数
	//int num = 100;
	//do {
	//	int a = 0, b = 0, c = 0;
	//	a = num % 10;  //个位
	//	b = num / 10 % 10;  //十位
	//	c = num / 100;  //百位

	//	if (a*a*a + b*b*b + c*c*c == num) {
	//		cout << num << endl;
	//	}
	//	num++;
	//} while (num < 1000);


	//for循环语句
	//for(起始表达式;条件表达式;末尾循环体){循环语句;}
	//for (int i = 1;i <= 100;i++) {
	//	int a = 0,b = 0, c = 0,d = 0;
	//	a = i % 10;
	//	b = i / 10 % 10;
	//	c = i / 100;
	//	d = i % 7;
	//	if (a == 7 || b == 7 || d == 0) {
	//		cout <<"咚咚咚"<< endl;
	//	}
	//	else {
	//		cout << i << endl;
	//	}
	//}

	//嵌套循环
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


	//跳转语句
	//用于跳出选择结构或者循环结构
	//出现在switch条件语句中，终止case并跳出switch
	//出现在循环语句中，跳出 当前的循环语句
	//出现在嵌套循环中，跳出最近的内层循环语句
	//1.出现在switch中
	cout << "请输出副本难度" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;
	int select = 0;
	cin >> select;
	switch (select) {
	case 1:
		cout << "普通" << endl;
		break;
	case 2:
		cout << "中等" << endl;
		break;
	case 3:
		cout << "困难" << endl;
		break;
	default:
		break;
	}

	//2.出现在循环语句中
	for (int i = 0; i < 10;i++)
	{
		if (i == 5) {
			break;
		}
		cout << i << endl;
	}

	//3.出现在嵌套循环语句中
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (j == 5) {
				break;  //退出内层循环
			}
			cout << "%";
		}
		cout << endl;
	}


	//continue语句
	//在循环语句中，跳出本次循环中余下尚未执行的语句，继续执行下一次循环
	for (int i = 0; i < 10;i++)
	{
		if (i % 2 == 1)
		{
			continue;
			
		}
		cout << i << endl;
	}


	//跳转语句goto
	//无条件跳转语句
	//goto 标记；
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