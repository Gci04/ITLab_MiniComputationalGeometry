#include "TPoint.h"
#pragma once
class ConvexHull
{
public:
	TPoint *hull;   //массив для хранения точек выпуклой оболочки
	int k;   //количество точек в выпуклой оболочке
	ConvexHull(TPoint p); //конструктор
	ConvexHull(const ConvexHull &a);  //конструктор копирования
	~ConvexHull(void);  //деструктор
	ConvexHull& operator=(const ConvexHull &a); //присваивание
	int FindMaxX();  //индекс точки с максимальной Х-координатой
	int FindMinX();  //индекс точки с минимальной Х-координатой
	bool IsPointInHull(TPoint p);  //true если точка принадлежит выпуклой оболочке
	int FindLeftSupportLine(TPoint p);   //поиск левой опорной прямой
	int FindRightSupportLine(TPoint p);   //поиск правой опорной прямой
	ConvexHull CreateNewConvexHull(TPoint p);
};

