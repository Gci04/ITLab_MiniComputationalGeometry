#include "TPoint.h"
#pragma once
class ConvexHull
{
public:
	TPoint *hull;   //������ ��� �������� ����� �������� ��������
	int k;   //���������� ����� � �������� ��������
	ConvexHull(TPoint p);
	~ConvexHull(void);
	int FindMaxX(ConvexHull a);  //������ ����� � ������������ �-�����������
	int FindMinX(ConvexHull a);  //������ ����� � ����������� �-�����������
	bool IsPointInHull(TPoint p, ConvexHull a);  //true ���� ����� ����������� �������� ��������
	int FindLeftSupportLine(TPoint p, ConvexHull a);   //����� ����� ������� ������
	int FindRightSupportLine(TPoint p, ConvexHull a);   //����� ������ ������� ������
	ConvexHull CreateNewConvexHull(TPoint p, ConvexHull a);
};

