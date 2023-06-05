#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//常用查找算法
//算法简介：
//find　　//查找元素
//find_if  //按条件查找元素
//adjacent_find   //查找相邻重复元素
//binary_search  //二分查找法
//count  //统计元素个数
//count_if  //按条件统计元素个数

//1. find
//功能描述：
//查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
//函数原型：
//find(iterator beg,iterator end,value);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束未知迭代器位置
//beg  开始迭代器
//end  结束迭代器
//value  查找的元素

//查找　内置数据类型
void test_find1()
{
    vector<int>v;
    for(int i = 0;i <10; i++)
    {
        v.push_back(i);
    }

    //查找　容器中是否有５这个元素
    vector<int>::iterator it = find(v.begin(),v.end(),5);
    if(it == v.end())
    {
        cout<<"没有找到"<<endl;
    }else{
        cout<<"找到：　"<< *it<<endl;
    }
}

class Person_find
{
public:
    Person_find(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    };
    //重载　==　底层find知道如何对比person数据类型
    bool operator==(const Person_find &p)
    {
        if((this->m_Name == p.m_Name && this->m_Age == p.m_Age) || this->m_Age == p.m_Age)
        {
            return true;
        }else{
            return false;
        }
    }

   
    string m_Name;
    int m_Age;
};
//查找自定义数据类型
void test_find2()
{
    vector<Person_find>v;
    //创建数据
    Person_find p1("A",20);
    Person_find p2("B",10);
    Person_find p3("C",30);
    Person_find p4("D",40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person_find pp("BB",20);
    vector<Person_find>::iterator it = find(v.begin(), v.end(), pp);
    if(it == v.end())
    {
        cout<<"没有找到"<<endl;
    }else{
        cout<<"找到元素:"<<it->m_Name<<it->m_Age<<endl;
    }
}

//2. find_if
//按条件查找元素
//函数原型：
//find_if(iterator beg, iterator end, _Pred);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//_Pred函数或者谓词（返回bool类型的仿函数）

//查找内置数据类型
class Greater_findif
{
public:
    bool operator()(int val)
    {
        return val >5;
    }
};

void test_find_if1()
{
    vector<int>v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),Greater_findif());
    if(it == v.end())
    {
        cout<<"没有找到"<<endl;
    }else{
        cout<<"找到大于５的数字为："<<*it<<endl;
    }
}

class Greater_findif_self
{
public:
     bool operator()(const Person_find &p)
    {
        return p.m_Age > 20;
    }
};
//查找自定义数据类型
void test_find_if2()
{
    vector<Person_find>v;
    Person_find p1("Q", 10);
    Person_find p2("W", 20);
    Person_find p3("E", 30);
    Person_find p4("R", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person_find>::iterator it = find_if(v.begin(), v.end(), Greater_findif_self());
    if(it == v.end())
    {
        cout<<"没有找到年龄大于20的人"<<endl;
    }else{
        cout<<"找到年龄大于20的人："<<it->m_Name<<" "<<it->m_Age<<endl;
    }

}

//3. adjacent_find
//功能描述：
//查找相邻重复元素
//函数原型：
//adjacent_find(iterator beg, iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器
//beg　开始迭代器
//end 结束迭代器

void test_adjacent_find1()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    vector<int>::iterator it = adjacent_find(v.begin(),v.end());

    if(it == v.end())
    {
        cout<<"未找到相邻元素"<<endl;
    }else{
        cout<<"找到重复元素："<<*it<<endl;
    }
}

//4. binary_search
//功能描述：
//查找指定元素是否存在
//函数原型：
//bool binary_search(iterator beg, iterator end,value);
//查找指定的元素，查到返回true 否则false
//注意：在无序序列中不可用
//beg 开始迭代器
//end 结束迭代器
//value 查找的元素

void test_binary_search()
{
    vector<int>v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    //查找容器中是否有９元素
    //注意：容器必须是有序的序列
    //如果是无序序列，结果未知
    bool ret = binary_search(v.begin(),v.end(),9);
    if(ret)
    {
        cout<<"找到了元素"<<endl;
    }else{
        cout<<"未找到"<<endl;
    }
}

//5. count
//功能描述：
//统计元素个数
//函数原型：
//count(iterator beg,iterator end,value);
//统计元素出现个数
//beg开始迭代器
//end 结束迭代器
//value 统计的元素

//内置数据类型
void test_count1()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    int num = count(v.begin(),v.end(),3);
    cout<<num<<endl;
}

//自定义数据类型
void test_count2()
{
    vector<Person_find>v;
    Person_find p1("Q",10);
    Person_find p2("W", 20);
    Person_find p3("E",30);
    Person_find p4("R", 40);
    Person_find p5("T",30);

    Person_find p("Y", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    int num = count(v.begin(),v.end(),p);
    cout<<"num:"<<num<<endl;
}

//6. count_if
//功能描述：
//按条件统计元素个数
//函数原型：
//count_if(iterator beg,iterator end, _Pred);
//按条件统计元素出现次数
//beg 开始迭代器
//end 结束迭代器
//_Pred 谓词

class Greater_countif
{
public:
    bool operator()(int val)
    {
        return val >2;
    }
};
void test_count_if1()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    int num = count_if(v.begin(),v.end(),Greater_countif());
    cout<<"num:"<<num<<endl;
}

class Greater_countif_self
{
public:
     bool operator()(const Person_find &p)
    {
        return p.m_Age > 20;
    }
};
void test_count_if2()
{
    vector<Person_find>v;
    Person_find p1("Q",10);
    Person_find p2("W", 20);
    Person_find p3("E",30);
    Person_find p4("R", 40);
    Person_find p5("T",30);

    Person_find p("Y", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(),v.end(),Greater_countif_self());
    cout<<"num:"<<num<<endl;
}
int main_find()
{
    test_find1();
    test_find2();
    test_find_if1();
    test_find_if2();
    test_adjacent_find1();
    test_binary_search();
    test_count1();
    test_count2();
    test_count_if1();
    test_count_if2();
    cout<<"ok"<<endl;
    return 0; 
}