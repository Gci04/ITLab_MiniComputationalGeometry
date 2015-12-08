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
	TPoint(double _x=0.0, double y=0.0); //�����������
	TPoint operator+ (TPoint &p); //����� ��������� �����
	TPoint operator- (TPoint &p); //�������� ��������� �����
	double operator[] (int i); //�������� ����������: ���������� ���������� � ��� [0] � ���������� y ��� [1]
	bool operator== (TPoint &p); //true ���� ����� ��� �����
	bool operator!= (TPoint &p); //true ���� ������� ��� �����
	bool operator< (TPoint &p); //true ���� ������ ����� ������ ������
	bool operator> (TPoint &p); //true ���� ������ ����� ������ ������
	double distance (TPoint &p); //���������� ����� ����� �������
	~TPoint(void); //����������
};

