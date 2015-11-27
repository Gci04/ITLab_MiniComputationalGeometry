#include "StdAfx.h"
#include "ConvexHull.h"


ConvexHull::ConvexHull(TPoint p)
{
	k=1;
	hull=new TPoint[k];
	hull[0]=p;
}

ConvexHull::~ConvexHull(void)
{
	delete[] hull;
}

int ConvexHull:: FindMaxX(ConvexHull a) //������ ����� � ������������ �-�����������
{
	int n=0;
	int xn=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]>xn)
		{
			xn=hull[i][0];
			n=i;
		};
	return n;
}

int ConvexHull:: FindMinX(ConvexHull a)  //������ ����� � ����������� �-�����������
{
	int m=0;
	int xm=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]<xm)
		{
			xm=hull[i][0];
			m=i;
		};
	return m;
}

bool ConvexHull:: IsPointInHull(TPoint p, ConvexHull a)  //true ���� ����� ����������� �������� ��������
{
	int m=FindMinX(a);   //������ ����� � ����������� �-�����������
	int n=FindMaxX(a);  //������ ����� � ������������ �-�����������
	//������� ��� ������� - ������� � ������, ������� ��������� ������ MN
	int ku;  //������ �������� �������
	int kd;   //������ ������� �������
	TPoint *u;  //������� ������
	TPoint *d;    //������ ������
	if (m<n)
	{
		ku=a.k-(n-m-1);
		u=new TPoint[ku];
		kd=n-m+1;
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j>=0; i++,j--)
			u[i]=a.hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=a.k-1; j<=n; j++,i++)
			u[i]=a.hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			d[i]=a.hull[j];
	}
	else //if m>n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!m=n
	{
		ku=n-m+1;
		u=new TPoint[ku];
		kd=a.k-(n-m-1);
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j<=a.k; i++,j++)
			d[i]=a.hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=0; j<=n; j++,i++)
			d[i]=a.hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			u[i]=a.hull[j];
	}
	bool fl=true;
	int i=0;
	while ((fl)&&(i<ku-1))
	{
		if (p[1]*(u[i][0]-u[i+1][0])-p[0]*(u[i][1]-u[i+1][1])+u[i][1]*u[i+1][0]-u[i+1][1]*u[i][0]>0)
			fl=false;
		i++;
	}
	i=0;
	while ((fl)&&(i<kd-1))
	{
		if (p[1]*(d[i][0]-d[i+1][0])-p[0]*(d[i][1]-d[i+1][1])+d[i][1]*d[i+1][0]-d[i+1][1]*d[i][0]<0)
			fl=false;
		i++;
	}
	return fl;
}
