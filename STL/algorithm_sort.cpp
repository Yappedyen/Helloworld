#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;
//常用排序算法
//算法简介：
//sort  //对容器内元素进行排序
//random_shuffle  //洗牌　　指定范围内的元素随机调整次序
//merge  //容器元素合并，并存储到另一容器中
//reverse  //反转指定范围的元素

//1. sort
//函数原型：
//sort(iterator beg, iterator end, _Pred);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg  开始迭代器
//end  结束迭代器
//_Pred  谓词

void myPrint_sort(int val)
{
    cout<<val<<" ";
}

class descend_sort
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void test_sort1()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    //利用sort进行升序
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint_sort);
    cout<<endl;

    //改变为降序
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),myPrint_sort);
    cout<<endl;
}

//2. random_shuffle
//函数原型：
//random_shuffle(iterator beg,iterator end);
//指定范围内的元素随机调整次序
//beg 开始迭代器
//end 结束迭代器

void test_random_shuffle1()
{
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i =0;i < 10;i++)
    {
        v.push_back(i);
    }

    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint_sort);
    cout<<endl;
}

//3. merge
//函数原型：
//merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//容器元素合并，并存储到另一容器中
//注意：两个容器必须是有序的
//beg1 容器１开始迭代器
//end1 容器１结束迭代器
//beg2 容器２开始迭代器
//end2 容器２结束迭代器
//dest 目标容器开始迭代器

void test_merge()
{
    vector<int>v1;
    vector<int>v2;
    for(int i =10;i >0;i--)
    {
        v1.push_back(i);
        v2.push_back(i-1);
    }
    //默认都为升序
    //两个原容器同为降序　需要用谓词
    //目标容器
    vector<int>vTarget;
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin(),greater<int>());
    for_each(vTarget.begin(),vTarget.end(),myPrint_sort);
    cout<<endl;
}

//4.reverse
//函数原型：
//reverse(iterator beg,iterator end);
//反转指定范围的元素
//beg 开始迭代器
//end 结束迭代器

void test_reverse()
{
    vector<int>v;
    for(int i =0;i < 10;i++)
    {
        v.push_back(i);
    }

    cout<<"反转前："<<endl;
    for_each(v.begin(),v.end(),myPrint_sort);
    cout<<endl;
    cout<<"反转后:"<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint_sort);
    cout<<endl;
}
int main_sort()
{
    test_sort1();
    test_random_shuffle1();
    test_merge();
    test_reverse();
    return 0;
}