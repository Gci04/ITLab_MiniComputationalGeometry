#include "TVertex.h"

/*-----------------------------------------------------------------------------------*/
TVertex:: TVertex(double _x, double _y):Point(_x, _y)
{
	Next_Vertex = this; 
	Prev_Vertex = this;
}
/*-----------------------------------------------------------------------------------*/
TVertex:: TVertex(const TPoint& _point):Point(_point)
{
	Next_Vertex = this; 
	Prev_Vertex = this;
}
/*-----------------------------------------------------------------------------------*/

// �������� � ����������� �������

TVertex* TVertex::Get_pNext_Vertex(void) const
{
	return Next_Vertex;
}
/*-----------------------------------------------------------------------------------*/
TVertex* TVertex::Get_pPrev_Vertex(void) const
{
	return Prev_Vertex;
}
/*-----------------------------------------------------------------------------------*/
TVertex* TVertex::Insert_Vertex(TVertex* pV) // ������� ������� ����� *this
{
	TVertex* temp = this -> Next_Vertex;
	this -> Next_Vertex = pV;
	pV -> Prev_Vertex = this;
	temp -> Prev_Vertex = pV;
	pV -> Next_Vertex = temp;
	
	return pV;
}
/*-----------------------------------------------------------------------------------*/
TVertex* TVertex::Remove_Vertex(void) // ������� ������� �������
{
	this -> Prev_Vertex -> Next_Vertex = this -> Next_Vertex;
	this -> Next_Vertex -> Prev_Vertex = this -> Prev_Vertex;

	Next_Vertex = Prev_Vertex = this;
	return this;
}
/*-----------------------------------------------------------------------------------*/
void TVertex::Splice_Vertex(TVertex* pV) //  ?????? "������ ����������" 
{
	TVertex* temp = this -> Next_Vertex;
	this -> Next_Vertex = pV -> Next_Vertex;
	pV -> Next_Vertex -> Prev_Vertex = this;

	pV -> Next_Vertex = temp;
	temp -> Prev_Vertex = pV;
}
/*-----------------------------------------------------------------------------------*/
TVertex* TVertex::Split(TVertex *pV) 
{
	// ��������� ����� ������� *this ����� *this, � ����� ������� *pV ����� ���
	TVertex* copy_this = new TVertex(Get_Point()); // ������� ����� *this
	TVertex* copy_pV = new TVertex( pV -> Get_Point()); // ������� ����� *pV

	this -> Insert_Vertex(copy_this); // �������� ����� ����� *this
	pV -> Prev_Vertex -> Insert_Vertex(copy_pV); // �������� ����� ����� *pV

	Splice_Vertex(copy_pV); // ���������
	return copy_pV;
}	
/*-----------------------------------------------------------------------------------*/
TPoint TVertex::Get_Point(void) const
{
	return Point;
}
/*-----------------------------------------------------------------------------------*/
TVertex* TVertex::Neighbor(int _rotation)
{
	TVertex* pV = this->Get_pNext_Vertex();
	if( _rotation != CLOCKWISE) pV = this -> Get_pPrev_Vertex();
	return pV;
}
/*-----------------------------------------------------------------------------------*/





