#include<iostream>
#include<stack>
#include<string>
using namespace std;

//stack ջ �Ƚ����(FILO)�����ݽṹ��ֻ��һ������
//ջ��ֻ�ж��˵�Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ  
//ջ��top() ��ջpush()  ��ջpop()  �Ƿ�Ϊ��empty()  ջ����Ԫ�ظ���size()

//stack���ýӿ�
//���캯����
//stack<T> stk;    //stack����ģ����ʵ�֣�stack�����Ĭ�Ϲ�����ʽ
//stack(const stack &stk);    //�������캯��

//��ֵ������
//stack& operator = (const stack &stk);    //���صȺŲ�����

//���ݴ�ȡ��
//push(elem);    //��ջ�����Ԫ��
//pop();    //��ջ���Ƴ���һ��Ԫ��
//top();    //����ջ��Ԫ��
//��С������
//empty();    //�ж϶�ջ�Ƿ�Ϊ��
//size();    //����ջ�Ĵ�С

void test_stack1()
{
	stack<int> stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);

	cout << "ջ�Ĵ�С��" << stk.size() << endl;
	//ֻҪջ��Ϊ�գ��鿴ջ��������ִ�г�ջ����
	while (!stk.empty())
	{
		//�鿴ջ��Ԫ��
		cout << "ջ��Ԫ�أ�" << stk.top() << endl;

		//��ջ
		stk.pop();
	}
}
int main_stack()
{
	test_stack1();
	system("pause");
	return 0;

}