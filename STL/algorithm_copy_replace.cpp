#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//常用拷贝和替换算法
//算法简介：
//copy  //容器内指定范围的元素拷贝到另一容器中
//replace  //将容器内指定范围的旧元素修改为新元素
//replace_if  //容器内指定范围满足条件的元素替换为新元素
//swap  //互换两个容器的元素


void myprint_copy(int val)
{
    cout<<val<<" ";
}

//1.copy
//函数原型：
//copy(iterator beg,iterator end, iterator dest);
void test_copy1()
{
    vector<int>v;
    for(int i =0;i < 10;i++)
    {
        v.push_back(i);
    }

    vector<int>v1;
    v1.resize(v.size());
    copy(v.begin(),v.end(),v1.begin());
    for_each(v1.begin(),v1.end(),myprint_copy);
    cout<<endl;


}

//2. replace
//函数原型：
//replace(iterator beg,iterator end,oldvalue, newvalue);
//将区间内旧元素替换成新元素
//beg 开始迭代器
//end 结束迭代器
//oldvalue 旧元素
//newvalue 新元素

void test_replace()
{
    vector<int>v;
    for(int i =0;i < 10;i++)
    {
        v.push_back(i);
    }
    cout<<"替换前："<<endl;
    for_each(v.begin(),v.end(),myprint_copy);
    cout<<endl;

    replace(v.begin(),v.end(),2,2000);
    cout<<"替换后："<<endl;
    for_each(v.begin(),v.end(),myprint_copy);
    cout<<endl;
}

//3. replace_if
//函数原型：
//replace_if(iterator beg,iterator end, _pred, newvalue);
//按条件替换元素，满足条件的替换成指定元素
//beg 开始迭代器
//end 结束迭代器
//_pred 谓词
//newvalue 替换的新元素

class greater30
{
public:
    bool operator()(int val)
    {
        return val > 30;
    }
};

void test_replace_if()
{
    vector<int>v;
    for(int i =0;i < 10;i++)
    {
        v.push_back(i*10);
    }
    cout<<"替换前"<<endl;
    for_each(v.begin(),v.end(),myprint_copy);
    cout<<endl;

    replace_if(v.begin(),v.end(),greater30(),3000);
    cout<<"替换后："<<endl;
    for_each(v.begin(),v.end(),myprint_copy);
    cout<<endl;
}

//4. swap
//函数原型：
//swap(container c1,container c2);
//注意：swap交换容器时，注意交换的容器要同种类型
//互换两个容器的元素
//c1容器
//c2容器２

void test_swap()
{
    vector<int>v1;
    vector<int>v2;
    for(int i =0;i < 10;i++)
    {
        v1.push_back(i);
        v2.push_back(i*10);
    }

    cout<<"交换前："<<endl;
    for_each(v1.begin(),v1.end(),myprint_copy);
    cout<<endl;
    for_each(v2.begin(),v2.end(),myprint_copy);
    cout<<endl;

    swap(v1,v2);
    cout<<"交换后："<<endl;
    for_each(v1.begin(),v1.end(),myprint_copy);
    cout<<endl;
    for_each(v2.begin(),v2.end(),myprint_copy);
    cout<<endl;

    

}
int main_copy()
{
    test_copy1();
    test_replace();
    test_replace_if();
    return 0;
}