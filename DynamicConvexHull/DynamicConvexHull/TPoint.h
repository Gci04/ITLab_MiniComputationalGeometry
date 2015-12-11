#include "stdafx.h"
#include "math.h"
#include <iostream>
#pragma once
using namespace std;
class TPoint
{
public:
	double x;
	double y;
	TPoint(double _x=0.0, double y=0.0); //конструктор
	TPoint (const TPoint &p); //конструктор копирования
	TPoint operator+ (TPoint &p); //сумма координат точек
	TPoint operator- (TPoint &p); //разность координат точек
	double operator[] (int i); //операция индексации: возвращает координату х при [0] и координату y при [1]
	bool operator== (TPoint &p); //true если равны две точки
	bool operator!= (TPoint &p); //true если НЕравны две точки
	bool operator< (TPoint &p); //true если первая точка меньше второй
	bool operator> (TPoint &p); //true если первая точка больше второй
	double distance (TPoint &p); //расстояние между двумя точками
	~TPoint(void); //деструктор
};

