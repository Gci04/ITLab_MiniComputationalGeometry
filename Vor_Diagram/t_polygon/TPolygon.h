#include "TVertex.h"
#include <iostream>

// ����� "�������������"

class TPolygon{
private:
	TVertex* pVertex; // ���� �������������� (������� ������� ������� ��-��)
	int Size;  // ���-�� ������ � ��������������
private:
    void Resize(void); // ������������� ���-�� ������ � ��������������
public:
	TPolygon(void); // �����������
	TPolygon(TVertex* pV); // ������� ��-� �� ������ ������������ ������ ������
	TPolygon(TPolygon& Pol); // �-� �����������
	~TPolygon(void); // ����������

//  ������� �������������� ������ � ��������������

	TVertex* Get_Vertex(void) const; // �������� ������� ������� ��-��
	int Get_Size(void) const; // �������� ������ ��-��
	TPoint Get_Point(void) const; // �������� �����, �������������� ������� ������� ��-��
//  Edge Get_Edge(void) const; // �������� ������� ����� (������� � ���. �������, ����� � ����.)

	TVertex* Get_Next_Vertex(void) const; // ���������� ����. ������� ����� ������� ��� ��������� ����
	TVertex* Get_Prev_Vertex(void) const;
	TVertex* Neighbor(int _rotation) const; 

// ������� ��������� ��������� ��-��
	TVertex* Advance(int _rotation); // ���������� ���� (�������� ������� ������� ��-��)
	TVertex* Advance_Set_Vertex(TVertex* pV); // ���������� ���� �� �������� �������

	TVertex* Insert_Vertex(TPoint& _point);// ��������� ������� ����� ������� � ����������� ���� �� ���. �������
	void Remove_Vertex(void); // ������� ���. �������, ���� �� ���������������

// ���������� ���������
	TPolygon* Split_Polygon(TVertex* pV); // ��������� ������� ������� ����� ����� ����. ������� ������� � �������� *pV. ���. ������� �� �����.
	                                      // ���������� ��������� �� ����� �������, ������� ������� �������� *copy_pV
};