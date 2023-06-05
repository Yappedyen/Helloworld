#include<iostream>
#include<stack>
#include<string>
using namespace std;

//stack 栈 先进后出(FILO)的数据结构，只有一个出口
//栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为  
//栈顶top() 入栈push()  出栈pop()  是否为空empty()  栈返回元素个数size()

//stack常用接口
//构造函数：
//stack<T> stk;    //stack采用模板类实现，stack对象的默认构造形式
//stack(const stack &stk);    //拷贝构造函数

//赋值操作：
//stack& operator = (const stack &stk);    //重载等号操作符

//数据存取：
//push(elem);    //向栈顶添加元素
//pop();    //从栈顶移除第一个元素
//top();    //返回栈顶元素
//大小操作：
//empty();    //判断堆栈是否为空
//size();    //返回栈的大小

void test_stack1()
{
	stack<int> stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);

	cout << "栈的大小：" << stk.size() << endl;
	//只要栈不为空，查看栈顶，并且执行出栈操作
	while (!stk.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素：" << stk.top() << endl;

		//出栈
		stk.pop();
	}
}
int main_stack()
{
	test_stack1();
	system("pause");
	return 0;

}