// testTPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*#include "TPoint.h"
#include <gtest.h>

TEST(TPoint, can_create_point)
{
  ASSERT_NO_THROW(TPoint p(1,2));
}

TEST(TPoint, can_create_copied_point)
{
  TPoint p(1,2);

  ASSERT_NO_THROW(TPoint p1(p));
}

TEST(TPoint, copied_point_is_equal_to_source_one)
{
	TPoint p1(1,2);
	TPoint p2=p1;
	EXPECT_EQ(p1,p2);
}

TEST(TPoint, throws_when_set_element_with_negative_index)
{
	TPoint p(1,2);
	ASSERT_ANY_THROW(p[-1]);
}

TEST(TPoint, throws_when_set_element_with_too_large_index)
{
	TPoint p(1,2);
	ASSERT_ANY_THROW(p[2]);
}

TEST(TPoint, compare_equal_points_return_true)
{
  TPoint p1(1,2), p2(2,1);
  p2 = p1;
  EXPECT_EQ(p1, p2);
}

TEST(TPoint, can_add_point_to_point)
{
  TPoint p1(1,2), p2(2,3), p3(3,5);
  EXPECT_EQ(p1+p2, p3);
}

TEST(TPoint, can_subtract_point_from_point)
{
  TPoint p1(1,2), p2(2,3), p3(3,5);
  EXPECT_EQ(p3-p2, p1);
}

TEST(TPoint, can_find_distance_between_points)
{
  TPoint p1(1,2), p2(2,3);
  EXPECT_EQ(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)), p1.distance(p2));
}*/