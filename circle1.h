#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class circle1
{
private:
	int c_r;
	//在类中可以让另一个类 作为本类中的成员
	point c_center;
public:
	//设置半径
	void setr(int r);
	//获取半径
	int getr();
	//设置圆心
	void setcenter(point center);

	//获取圆心
	point getcenter();

};