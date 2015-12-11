#include "StdAfx.h"
#include "ConvexHull.h"
using namespace std;

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

ConvexHull::ConvexHull(const ConvexHull &a)  //конструктор копирования
{
	k=a.k;
	hull=new TPoint[k];
	for (int i=0; i<k; i++)
		hull[i]=a.hull[i];
}
ConvexHull& ConvexHull::operator=(const ConvexHull &a) //присваивание
{
	if (this != &a )
	{
		if ( k != a.k )
		{
			delete [] hull;
			hull = new TPoint[a.k];
		}
		k=a.k;
		for ( int i=0; i<k; i++)
			hull[i]=a.hull[i];
	}
	return *this;
}
int ConvexHull:: FindMaxX() //индекс точки с максимальной Х-координатой
{
	int n=0;
	int xn=hull[0][0];
	for(int i=1; i<k; i++)
		if (hull[i][0]>xn)
		{
			xn=hull[i][0];
			n=i;
		};
	return n;
}

int ConvexHull:: FindMinX()  //индекс точки с минимальной Х-координатой
{
	int m=0;
	int xm=hull[0][0];
	for(int i=1; i<k; i++)
		if (hull[i][0]<xm)
		{
			xm=hull[i][0];
			m=i;
		};
	return m;
}

bool ConvexHull:: IsPointInHull(TPoint p)  //true если точка принадлежит выпуклой оболочке
{
	int m=FindMinX();   //индекс точки с минимальной Х-координатой                
	int n=FindMaxX();  //индекс точки с максимальной Х-координатой   
	bool fl=true;
	if (m==n)
		if (k==1)
			if (p==hull[0]) fl=true;
			else fl=false;
		else
			if (p[1]*(hull[0][0]-hull[1][0])-p[0]*(hull[0][1]-hull[1][1])+hull[0][1]*hull[1][0]-hull[1][1]*hull[0][0]==0) fl= true; //возникновение ошибок из-за способа хранения вещественнных чисел
			else fl=false;
	else
	{
	//создаем два массива - верхний и нижний, которые разделяет прямая MN
	int ku;  //размер верхнего массива
	int kd;   //размер нижнего массива
	TPoint *u;  //верхний массив
	TPoint *d;    //нижний массив
	if (m<n)
	{
		ku=k-(n-m-1);
		u=new TPoint[ku];
		kd=n-m+1;
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j>=0; i++,j--)
			u[i]=hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=k-1; j<=n; j++,i++)
			u[i]=hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			d[i]=hull[j];
	}
	else  
	{
		ku=n-m+1;
		u=new TPoint[ku];
		kd=k-(n-m-1);
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j<=k; i++,j++)
			d[i]=hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=0; j<=n; j++,i++)
			d[i]=hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			u[i]=hull[j];
	}
	//bool fl=true;
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
	}
	return fl;
}

int ConvexHull:: FindLeftSupportLine(TPoint p)   //поиск левой опорной прямой
{
	int l=-1;
	for (int i=0;i<k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<k))
		{
			if (hull[j][1]*(p[0]-hull[i][0])-hull[j][0]*(p[1]-hull[i][1])+p[1]*hull[i][0]-hull[i][1]*p[0]>0)
				fl=false;
		j++;
		}
	if (fl) 
		if (l=-1)
			l=i;
		else
			if (p.distance(hull[l])<p.distance(hull[i]))
				l=i;
	i++;
	}
	return l;
}
int ConvexHull:: FindRightSupportLine(TPoint p)   //поиск правой опорной прямой
{
	int r=-1;
	for (int i=0;i<k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<k))
		{
			if (hull[j][1]*(p[0]-hull[i][0])-hull[j][0]*(p[1]-hull[i][1])+p[1]*hull[i][0]-hull[i][1]*p[0]<0)
				fl=false;
		j++;
		}
	if (fl) 
		if (r=-1)
			r=i;
		else
			if (p.distance(hull[r])<p.distance(hull[i]))
				r=i;
	i++;
	}
	return r;
}

ConvexHull ConvexHull:: CreateNewConvexHull(TPoint p)
{
	if (IsPointInHull(p))
		return (*this);
	else 
	{
		int l=FindLeftSupportLine(p);
		int r=FindRightSupportLine(p);
		int knew; //размер нового массива
		if (r<l) 
			knew=k-(r-l-1)+1;
		else knew=-(r-l-1)+1;
		TPoint *b;
		b=new TPoint[knew];
		if (r>l)
		{
			int st=0;
			for (int i=0;i<=l; i++)
			{
				b[i]=hull[i];
				st++;
			}
			b[st]=p;
			st++;
			for (int j=st, t=r; j<knew; j++,t++)
				b[j]=hull[t];
		}
		else //if (r<l) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			int st=0;
			for (int i=r, j=0; i<=l; i++,j++)
			{
				b[j]=hull[i];
				st++;
			}
			b[st]=p;  
		}
		delete[] hull;
		k=knew;
		hull=new TPoint[k];
		for (int i=0; i<k; i++)
			hull[i]=b[i];
		delete[] b;
	}
	return (*this);
}