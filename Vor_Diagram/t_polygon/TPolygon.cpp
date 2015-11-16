#include "TPolygon.h"

/*-----------------------------------------------------------------------------------*/
TPolygon:: TPolygon(void) // �-� �� ��������� "������ ��-�"
{
	pVertex = NULL;
	Size = 0;
}
/*-----------------------------------------------------------------------------------*/

TPolygon:: TPolygon(TVertex* pV)
{
	pVertex = new TVertex( pV -> Get_Point());
	TVertex* count_v = pV -> Neighbor(CLOCKWISE);
	while( pV != count_v) 
	{
		TVertex* V = new TVertex(count_v -> Get_Point());
		pVertex = pVertex -> Insert_Vertex(V);
		count_v = count_v -> Neighbor(CLOCKWISE);
	}
	pVertex = pVertex ->Get_pNext_Vertex();
	Resize(); // ��������� ���-�� ������ � ������ pV
}

/*-----------------------------------------------------------------------------------*/
void TPolygon::Resize(void) // ��������� ���-�� ������
{
	if (pVertex == NULL)
		Size = 0;
	else {
		TVertex* pV = pVertex -> Get_pNext_Vertex();
		for( Size = 1; pV != pVertex; ++Size)
			pV = pV -> Get_pNext_Vertex();
	}
}
/*-----------------------------------------------------------------------------------*/

TPolygon:: TPolygon(TPolygon& Pol) // ����������� �����������
{
	if( Pol.pVertex == NULL ) // ���� ��-� ������
	{
		pVertex = NULL;
		Size = 0;
	}
	else{
		Size = Pol.Size;
		pVertex = new TVertex( Pol.Get_Point() ); // ������� ������� ������� �� �����
		for(int i = 1; i < Size; ++i) // i = 1 - ������� ������� ��� �������
		{
			Pol.Advance(CLOCKWISE); // ������� ���� �� ������� ������� � Pol
			TVertex* V = new TVertex( Pol.Get_Point() ); // ������� ����� ��������� �������
			pVertex = pVertex -> Insert_Vertex(V); // ��������� ������� � ��� ��������� � ���������� ���� � *this
		}
		Pol.Advance(CLOCKWISE); // ���������� ���� � �������� ���������
		pVertex = pVertex -> Get_pNext_Vertex(); // ���. ������� *this ��������� � Pol
	}
}
/*-----------------------------------------------------------------------------------*/
TPolygon::~TPolygon(void) // ����������
{
	if( pVertex != NULL) 
	{
		TVertex* temp = pVertex -> Get_pNext_Vertex();
		while( pVertex != temp)
		{
			delete ( temp -> Remove_Vertex() ); // ��������� ������� �� �������� � ������� ��
			temp = pVertex -> Get_pNext_Vertex(); // ����������
		}
		delete pVertex; // ������� ���������� �������
	}
}
/*-----------------------------------------------------------------------------------*/

// ������� �������������� ������ � ��������������

/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Vertex(void) const // �������� ������� �������
{
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/
int TPolygon:: Get_Size(void) const // �������� ������ 
{
	return Size;
}
/*-----------------------------------------------------------------------------------*/

TPoint TPolygon:: Get_Point(void) const // �������� �����, �������������� ������� ������� ��-��
{
	return (pVertex -> Get_Point());
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Next_Vertex(void) const // ���������� ����. ������� ����� ������� ��� ��������� ����
{
	return ( pVertex -> Get_pNext_Vertex() );
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Prev_Vertex(void) const // �����. ���������� ����. ����� ���. ��� ��������� ����
{
	return ( pVertex -> Get_pPrev_Vertex() );
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Neighbor(int _rotation) const // _rotation (= {CLOCKWISE, COUNTER_CLOCKWISE}
{
	return ( pVertex -> Neighbor(_rotation) );
}
/*-----------------------------------------------------------------------------------*/

// ������� ���������� ��������� ��������������

/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Advance(int _rotation) // ���������� ���� (�������� ������� ������� ��-��) ���������� ��-�� �� �������� �������
{
	pVertex = pVertex -> Neighbor(_rotation);
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Advance_Set_Vertex(TVertex* pV) // ���������� ���� �� �������� �������
{
	// �������� ������������� ������� �������
	pVertex = pV;
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Insert_Vertex(TPoint& _point) // ��������� ������� ����� ������� � ����������� ���� �� ���. �������
{
	if ( Size == 0)
	{
		++Size;
		pVertex = new TVertex(_point);
	} 
	else {
		TVertex* pV = new TVertex(_point); // ������ �������
		pVertex = pVertex -> Insert_Vertex(pV); // ��������� ������� ����� ������� � ����������� ����
		Size++;
	}
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/
void TPolygon:: Remove_Vertex(void) // ������� ���. �������, ���� �� ���������������
{
	if( pVertex != NULL) 
	{
		TVertex* pV = pVertex;
		--Size;
		if(Size)
			pVertex = NULL; // ���� ������ ��� ������
		else // ����� ���������� ���� � ������� �������
			pVertex = pVertex -> Get_pPrev_Vertex(); 
		delete pV;
	}
}
/*-----------------------------------------------------------------------------------*/
TPolygon* TPolygon:: Split_Polygon(TVertex* pV)
{
	TVertex* copy_pV = pVertex -> Split(pV);
	Resize(); // ������������� ������ �������� �������� ����� ����������
	TPolygon* pPol = new TPolygon(copy_pV); // c������ ���. ������� � ������� �������� *copy_pV
	return pPol;
}
/*-----------------------------------------------------------------------------------*/










