#include<iostream>
#include<algorithm>
#include<functional>

#include"SpeechManager.cpp"

using namespace std;
//比赛规则
//1.学校举行一场演讲比赛，共12个人参加。比赛两轮，第一轮为淘汰赛，第二轮为决赛
//2.每名选手对应编号10001-10012
//3.比赛方式：分组比赛，每组６人；
//4.每一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲
//5.十个评委分别给每个选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩
//6.当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮比赛
//7.第二轮为决赛，前三名胜出
//8.每轮比赛过后需要显示晋级选手的信息


//管理类
//功能描述
//提供菜单界面与用户交互
//对演讲比赛流程进行控制
//与文件读写交互



int main()
{
    //创建管理类对象
    SpeechManager sm;
    srand((unsigned int)time(NULL));
    //测试选手创建
    // for(map<int,Speaker>::iterator it = sm.m_Speaker.begin();it!= sm.m_Speaker.end();it++)
    // {
    //     cout<<"选手编号："<<it->first<<"姓名："<<it->second.m_Name<<"分数："<<it->second.m_Score[0]<<endl;
    // }
    
    int choice = 0;  //用于存储用户输入
    while (true)
    {
        sm.show_menu();
        cout<<"请输入你的选择："<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:  //开始比赛
                sm.startSpeech();
                break;
            case 2:  //查看往届比赛记录
                sm.showRecord();
                break;
            case 3:  //清空比赛记录
                sm.clearRecord();
                break;
            case 0:  //退出系统
                sm.exitSystem();
                break;
            default:
                system("clear");
                break;
            
        }
    }

    cout<<"**************************"<<endl;
    return 0;
}