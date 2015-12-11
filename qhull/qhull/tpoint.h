#include <iostream>


using namespace std;
class TPoint
{
public:

	double X;
	double Y;

	TPoint( double a=0, double b=0 );


	TPoint operator +(TPoint &);
	TPoint operator -(TPoint &);
	int operator< (TPoint &);
	int operator> (TPoint &);
	double operator [] (int);
	int operator == (TPoint &);
	int operator != (TPoint &);

	int CheckPoint(TPoint a, TPoint b, TPoint c); //  Оппредеение положения точки b относительно вектора ac
	double length();

	double VectorMult(TPoint  i,  TPoint& j,  TPoint k); // Векторное произведение
};


