#pragma once
#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<vector>
#include<map>
#include"speaker.h"

using namespace std;

//设计演讲管理类
class SpeechManager
{
public:
    //构造函数
    SpeechManager();

    //菜单功能
    void show_menu();
    //退出系统
    void exitSystem();
    //析构函数
    ~SpeechManager();

    //初始化容器和属性
    void initSpeech();

    //创建12名选手
    void createspeakers();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示晋级结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示往届记录
    void showRecord();

    //清空记录
    void clearRecord();
    //判断文件是否为空
    bool fileisempty;

    //存放往届记录数据
    map<int,vector<string> >m_Record;

    //成员属性
    //保存第一轮比赛选手编号容器
    vector<int>v1;

    //第一轮晋级的选手编号
    vector<int>v2;

    //胜出前三名选手编号容器
    vector<int>vVictory;
    //存放编号以及对应具体选手容器
    map<int, Speaker>m_Speaker;

    //存放比赛轮数
    int m_Index;

};
