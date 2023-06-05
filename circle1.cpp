#include"circle1.h"


//设置半径
void circle1::setr(int r)
{
	c_r = r;
}
//获取半径
int circle1::getr()
{
	return c_r;
}
//设置圆心
void circle1::setcenter(point center)
{
	c_center = center;
}
//获取圆心
point circle1::getcenter()
{
	return c_center;
}