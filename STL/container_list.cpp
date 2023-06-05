#include<iostream>
#include<string>
#include<list>

using namespace std;
//list �����ݽ�����ʽ�洢
//list  ����  ��һ�������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
//��������ɣ�������һϵ�н�����
//������ɣ�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
//STL�е�������һ��˫��ѭ������  ָ�������� prev��next

//�ŵ㣺
//���Զ�����λ�ý��п��ٲ����ɾ��Ԫ��
//ȱ�㣺
//���������ٶȣ�û�������
//ռ�ÿռ�������

//���������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������

//list���ŵ㣺
//1.���ö�̬�洢���䣬��������ڴ��˷Ѻ����
//2.����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��

//list��ȱ�㣺
//���������ǿռ䣨ָ���򣩺�ʱ�䣨����������ķѽϴ�

//list��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ������ġ�

//STL��list��vector���������ʹ�õ�������������ȱ��

//list���캯��
//����ԭ�ͣ�
//list<T> lst;    //list����ģ����ʵ�֣������Ĭ�Ϲ�����ʽ��
//list(beg, end);    //���캯������beg, end)�����е�Ԫ�ؿ���������
//list(n, elem);    //���캯����n��elem����������
//list(const list &lst);    //�������캯��

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin();it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_list1()
{
	//����list����
	list<int> L1;

	//��������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//��������
	printList(L1);

	//���䷽ʽ����
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	//��������
	list<int>L3(L2);
	printList(L3);

	//n��elem
	list<int>L4(3, 100);
	printList(L4);

}

//list��ֵ�ͽ���
//����ԭ�ͣ�
//assign(beg,end);    //��(beg,end)�����е����ݿ�����ֵ������
//assign(n,elem);    //��n��elem������ֵ������
//list& operator=(const list &lst);    //���صȺŲ�����
//swap(lst);    //��lst�뱾����Ԫ�ػ���
int main_list()
{
	test_list1();
	system("pause");
	return 0;
}