#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class circle1
{
private:
	int c_r;
	//�����п�������һ���� ��Ϊ�����еĳ�Ա
	point c_center;
public:
	//���ð뾶
	void setr(int r);
	//��ȡ�뾶
	int getr();
	//����Բ��
	void setcenter(point center);

	//��ȡԲ��
	point getcenter();

};