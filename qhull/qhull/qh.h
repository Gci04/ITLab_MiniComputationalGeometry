# include "set_points.h"

using namespace std;

class ConvexHull  
{
	SetPoints hull; // оболочка, состоящая из набора точек
	int HullSize;
public:

	ConvexHull (int _HullSize ); 
	ConvexHull ( const ConvexHull &h);
	TPoint operator[] (int i);

	TPoint left (); // нахождение самой левой точки
	TPoint right(); // нахождение самой правой точки
	TPoint remote ( TPoint , TPoint , ConvexHull h); // наиболее удаленная точка от прямой l

	ConvexHull Split (TPoint A, TPoint B, ConvexHull &above, ConvexHull &bellow);

	TPoint QiuckHull(); 

};


