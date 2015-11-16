#include "../t_point/TPoint.h"

// ����� "�������"


enum  ROTATION {CLOCKWISE, COUNTER_CLOCKWISE};
    //�� �������, ������ ������� �������

class TVertex
{
private:
	TPoint Point; // �����
	TVertex* Next_Vertex; // ��������� �� ������������� (�� ������� �������)
	TVertex* Prev_Vertex; // �������� �� ��������������� (������ ������� �������)
	
public:
// ������������
	TVertex(double _x, double _y); // ������ ������� �� ������ ���������
	TVertex(const TPoint& _point); // ������ ������� �� ������ �����


// �������� � ����������� �������
	TVertex* Get_pNext_Vertex(void) const; // ���������� ��������� �� ����. �������
	TVertex* Get_pPrev_Vertex(void) const; // ���������� ��������� �� ����. �������
	TVertex* Insert_Vertex(TVertex* pV); // ��������� ������� ����� *this
	TVertex* Remove_Vertex(void); // ������� ������� �������, ���������� ��������� �� ���

	void Splice_Vertex(TVertex* pV); // C��������� ���� ������ ????? (������)
	TVertex* Split(TVertex* pV); // ��������� ��������� ������ �� ��� � ����������� �����

	TPoint Get_Point(void)const; // ���������� �����, � ������� ��������� ������� �������
	TVertex* Neighbor(int _rotation); // ���������� ������ ��� �������� �� �������, ��� ������ ������� �������
};
