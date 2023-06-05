#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//常用的集合算法
//算法简介
//set_intersection  //求两个容器的交集
//set_union  //求两个容器的并集
//set_difference  //求两个容器的差集

//1. set_intersection
//函数原型：
//set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的交集
//注意：　两个集合必须是有序序列
//目标容器开辟空间需要从两个容器中取最小值
//set_intersection返回值既是交集中最后一个元素的位置
//beg1  容器１开始迭代器
//end1  容器１结束迭代器
//beg2  容器２开始迭代器
//end2  容器２结束迭代器
//dest  目标容器开始迭代器

void myprint_set(int val)
{
    cout<<val<<" ";
}
void test_set_intersection()
{
    vector<int>v1;
    vector<int>v2;
    for(int i = 0;i <10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int>vTarget;
    //目标容器需要提前开辟空间
    //最特殊情况　大容器包含小容器　开辟空间　取小容器的size即可
    vTarget.resize(min(v1.size(),v2.size()));
    //获取交集
    vector<int>::iterator itend = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),itend,myprint_set);
    cout<<endl;
}

//2. set_union
//函数原型：
//set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的并集
//注意：　两个集合必须是有序序列
//目标容器开辟空间需要两个容器相加
//set_union返回值既是并集中最后一个元素的位置
//beg1  容器１开始迭代器
//end1  容器１结束迭代器
//beg2  容器２开始迭代器
//end2  容器２结束迭代器
//dest  目标容器开始迭代器

void test_set_union()
{
    vector<int>v1;
    vector<int>v2;

    for(int i = 0;i <10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int>vTarget;
    //目标容器提前开辟空间
    //最特殊情况　两个容器没有交集，并集就是两个容器size相加
    vTarget.resize(v1.size() + v2.size());

    vector<int>::iterator itend = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),itend,myprint_set);
    cout<<endl;
}


//3. set_difference
//函数原型：
//set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的差集
//注意：两个集合必须是有序序列
//beg1  容器１开始迭代器
//end1  容器１结束迭代器
//beg2  容器２开始迭代器
//end2  容器２结束迭代器
//dest  目标容器开始迭代器

void test_set_difference()
{

    vector<int>v1;
    vector<int>v2;
    for(int i = 0;i <10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vTarget;
    //目标容器提前开辟空间
    //最特殊情况　两个容器没有交集　取两个容器中大的size作为目标容器开辟空间
    vTarget.resize(max(v1.size(),v2.size()));
    cout<<"v1和v2的差集："<<endl;
    vector<int>::iterator itend = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),itend,myprint_set);
    cout<<endl;

    cout<<"v2和v1的差集："<<endl;
    itend = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),vTarget.begin());
    for_each(vTarget.begin(),itend,myprint_set);
    cout<<endl;
}
int main_set()
{
    test_set_intersection();
    test_set_union();
    test_set_difference();
    return 0;
}