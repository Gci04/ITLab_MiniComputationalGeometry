#include "stdafx.h"
#include "TPoint.h"
#include "ConvexHull.h"
int main(int argc, _TCHAR* argv[])
{
	TPoint p(2,3);
	ConvexHull t(p);
	ConvexHull t1(p);
	cout << "p  " << p[0] <<"   "<<p[1] << endl << "t   " << t.hull[0][0] <<"   "<< t.hull[0][1] <<endl;
	TPoint p1(4,5);
	cout << "p1  " << p1[0] <<"   "<<p1[1] << endl;
	//int a=t.FindMinX();
	//cout << a <<endl ;
	//int k=t.FindRightSupportLine(p1);
	//bool fl=t.IsPointInHull(p);
	//cout << fl << endl;
	t.CreateNewConvexHull(p);
	cout << t.hull[0][0] <<"   " << t.hull[0][1] <<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl;
	t1=t1.CreateNewConvexHull(p1);
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   "<< p[0] <<"   "<<p[1] << endl << t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl;
	TPoint p2(3,2);
	t1=t.CreateNewConvexHull(p2);
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl;
	system("pause");
	return 0;
}
