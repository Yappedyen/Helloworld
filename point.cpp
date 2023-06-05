#include"point.h"

//留实现   point作用域下的函数
void point::setx(int x)
{
	p_x = x;
}
//设置y坐标
void point::sety(int y)
{
	p_y = y;
}

int point::getx()
{
	return p_x;
}

int point::gety()
{
	return p_y;
}