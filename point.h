#pragma once
#include<iostream>
using namespace std;

//������
class point
{
public:
	//����x����
	void setx(int x);

	//����y����
	void sety(int y);

    int getx();

	int gety();

private:
	int p_x;
	int p_y;
};