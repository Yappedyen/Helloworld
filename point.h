#pragma once
#include<iostream>
using namespace std;

//留声明
class point
{
public:
	//设置x坐标
	void setx(int x);

	//设置y坐标
	void sety(int y);

    int getx();

	int gety();

private:
	int p_x;
	int p_y;
};