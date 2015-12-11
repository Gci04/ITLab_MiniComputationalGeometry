#include "StdAfx.h"
#include "TPoint.h"


TPoint:: TPoint(double _x, double _y)                      //конструктор
{
	x=_x;
	y=_y;
}
TPoint:: TPoint (const TPoint &p)
{
	x=p.x;
	y=p.y;
}
TPoint TPoint:: operator+ (TPoint &p)                  //сумма координат точек
{
	TPoint q;
	q.x=x+p.x;
	q.y=y+p.y;
	return q;
}

TPoint TPoint:: operator- (TPoint &p)                   //разность координат точек
{
	TPoint q;
	q.x=x-p.x;
	q.y=y-p.y;
	return q;
}

double TPoint:: operator[] (int i)                      //операция индексации: возвращает координату х при [0] и координату y при [1]            
{
	if (i==0) return (x);
	else if (i==1) return (y);
	     else throw i;
}

bool TPoint:: operator== (TPoint &p)                    //true если равны две точки
{
	return ((x==p.x)&&(y==p.y));
}

bool TPoint:: operator!= (TPoint &p)                    //true если НЕравны две точки
{
	return ((x!=p.x)||(y!=p.y));
}

bool TPoint:: operator< (TPoint &p)                      //true если первая точка меньше второй
{
	return ((x<p.x)||((x==p.x)&&(y<p.y)));
}

bool TPoint:: operator> (TPoint &p)                      //true если первая точка больше второй
{
	return ((x>p.x)||((x==p.x)&&(y>p.y)));
}

double TPoint:: distance (TPoint &p)                              //расстояние между двумя точками
{
	return (sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)));
}

TPoint::~TPoint(void)                                    //деструктор
{
}
