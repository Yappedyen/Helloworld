#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//谓词
//概念：
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫做一元谓词
//如果operator()接受两个参数，那么叫做二元谓词

//一元谓词
class GreaterFiver
{
public:
    //一元谓词
    bool operator()(int val)
    {
        return val > 5;
    }
    //二元谓词
    bool operator()(int val1,int val2)
    {
        return val1 > val2;
    }

};

void test_predicate1()
{
    vector<int>v;
    for(int i = 0;i <10;i++)
    {
        v.push_back(i);
    }

    //查找容器中　有没有大于５的数字
    //GreateFive()匿名函数对象
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFiver());
    if(it == v.end())
    {
        cout<<"未找到"<<endl;
    }else{
        cout<<"找到了大于５的数字"<<(*it)<<endl;
    }
}

void test_predicate2()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    sort(v.begin(), v.end());
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //使用函数对象　改变算法策略，变为排序规则为从大到小
    sort(v.begin(),v.end(),GreaterFiver());
    cout<<"---------------------"<<endl;
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
int main_predicate()
{
    test_predicate1();
    test_predicate2();
    //system("pause");
    return 0;
}