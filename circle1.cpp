#include"circle1.h"


//���ð뾶
void circle1::setr(int r)
{
	c_r = r;
}
//��ȡ�뾶
int circle1::getr()
{
	return c_r;
}
//����Բ��
void circle1::setcenter(point center)
{
	c_center = center;
}
//��ȡԲ��
point circle1::getcenter()
{
	return c_center;
}