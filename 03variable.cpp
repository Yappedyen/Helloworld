#include <iostream>
using namespace std;

int main3()
{

	//变量创建的语法
	int a = 10;
	int v1 = 0, v2 = 0;
	cout << "Enter two number:" << endl;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << ","<< "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << endl;
	// cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << endl;
	/* 
	 *cout << "The sum of " << v1;
		 << " and " << v2;
		 << " is " << v1 + v2 << endl;
	 */
	//cout << "/*";
	//cout << "*/";
	cout << /* "*/" */";
	cout << /* "*/" /* " /*" */;
	cout << "a = " << a << endl;
	system("pause");
	return 0;
}