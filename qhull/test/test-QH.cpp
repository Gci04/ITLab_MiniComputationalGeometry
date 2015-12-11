#include "../qhull/qh.h"
#include "gtest/gtest.h"


TEST(ConvexHull,can_split)
{
	TPoint A(2,2);
	TPoint B(4,6);
    TPoint c(3,4);
	TPoint d(1,1);
    TPoint f(7,9);
	
	ConvexHull h(5);
	
	h[0] = A;
	h[1] = B;
	h[2] = c;
	h[3] = d;
	h[4] = f;
	
	ConvexHull above(5);
	ConvexHull bellow(5);

	h.Split (A,B,above,bellow);

	EXPECT_EQ (A.X, above[0][0]);
	EXPECT_EQ (A.Y, above[0][1]);
	/*EXPECT_EQ (B, above[1]);
	EXPECT_EQ (c, above[2]) ;
	EXPECT_EQ (d, bellow[3]);
	EXPECT_EQ (f, above[4] );*/
}
