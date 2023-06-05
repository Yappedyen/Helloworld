#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;


//常用算术生成算法
//注意：算术生成算法属于小型算法，使用时包含的头文件为#include<numeric>
//算法简介:
//accumulate  //计算容器元素累计总和
//fill  //向容器中添加元素

//1. accumulate
//函数原型：
//accumulate(iterator beg, iterator end, value);
//beg  开始迭代器
//end  结束迭代器
//value  起始累加值

void myprint_fill(int val)
{
    cout<<val<<" ";
}

void test_accumulate()
{
    vector<int>v;
    for(int i = 0; i<=100;i++)
    {
        v.push_back(i);
    }

    int totol = accumulate(v.begin(),v.end(),0);
    cout<<"totol:"<<totol<<endl;
}

void test_fill()
{
    vector<int>v;
    v.resize(10);
    //后期重新填充
    fill(v.begin(),v.end(),100);
    for_each(v.begin(),v.end(),myprint_fill);
    cout<<endl;
}
int main_arithmetic()
{
    test_accumulate();
    test_fill();
    return 0;
}