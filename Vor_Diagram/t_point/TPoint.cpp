#include "TPoint.h"

// ���������� ������� ������
/*-----------------------------------------------------------------------------------*/
TPoint::TPoint(double _x, double _y)
{
	x = _x;
	y = _y;
}
/*-----------------------------------------------------------------------------------*/
TPoint TPoint::operator+(const TPoint& P)
{
	TPoint Res;
	Res.x = x + P.x;
	Res.y = y + P.y;
	return Res;
}
/*-----------------------------------------------------------------------------------*/
TPoint TPoint::operator-(const TPoint& P)
{
	TPoint Res;
	Res.x = x - P.x;
	Res.y = y - P.y;
	return Res;
}
/*-----------------------------------------------------------------------------------*/
TPoint operator*(const double scalar, const TPoint& P)
{
	TPoint Res;
	Res.x = scalar * P.x;
	Res.y = scalar * P.y;
	return Res;
}
/*-----------------------------------------------------------------------------------*/
int TPoint::operator<(const TPoint& P) const
{
	return ( (x < P.x) || ((x == P.x) && (y < P.y)) );
}
/*-----------------------------------------------------------------------------------*/
int TPoint::operator>(const TPoint& P) const
{
	return ( (x > P.x) || ((x == P.x) && (y > P.y)) );
}
/*-----------------------------------------------------------------------------------*/
int TPoint::operator==(const TPoint& P) const
{
	return ( (x == P.x) && (y == P.y) );
}
/*-----------------------------------------------------------------------------------*/
int TPoint::operator!=(const TPoint& P) const
{
	return ( (x != P.x) || (y != P.y) );
}
/*-----------------------------------------------------------------------------------*/
double& TPoint:: operator[](const int i) // ������
{
	if (( i != 0 ) || (i != 1) ) throw i;
	return (i == 0)?(x):(y);
}
/*-----------------------------------------------------------------------------------*/
double TPoint::Lenght() // ��������� ����� �������
{
	double L;
	L = sqrt(x * x + y * y);
	return L;
}
/*-----------------------------------------------------------------------------------*/
double TPoint::det(const TPoint& _P1, const TPoint& _P2)
{
	return ( (_P1.x * _P2.y) - (_P1.y * _P2.x) );
}
/*-----------------------------------------------------------------------------------*/
int TPoint:: Location(TPoint& P1, TPoint& P2) // P1 - ������, P2 - ����� (�������������� *this ������������ P1P2)
{
	TPoint P3 = *this;
	TPoint P1P2 = P2 - P1;
	TPoint P1P3 = P3 - P1;
	int Res;
	if( det(P1P2, P1P3) > 0.0) Res = LEFT; 
	if( det(P1P2, P1P3) < 0.0) Res = RIGHT;
	if( (P1P2.x * P1P3.x < 0 ) || (P1P2.y * P1P3.y < 0)) Res = BEHIND; // �������������� ���������� �� ����� ������
	if( P1P2.Lenght() < P1P3.Lenght() ) Res = BEYOND; // ������� ����� P1
	if( P3 == P1) Res = ORIGIN; // ������
	if( P3 == P2) Res = DESTINATION; // �����
	Res = BETWEEN;
	return Res;
}
/*-----------------------------------------------------------------------------------*/


	


