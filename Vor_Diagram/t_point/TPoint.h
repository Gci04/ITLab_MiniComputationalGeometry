#include <cmath>


enum Position{LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION}; // ��������� ����� ������������ ������
          //�����, C�����, �������, ������, �����, ������, �����


// ����� "�����"
class TPoint
{
protected:
	double x; // ���������� �����
	double y;
public:
	TPoint(double _x = 0.0, double _y = 0.0);
// ��������� ��������
	TPoint operator+(const TPoint& P);
	TPoint operator-(const TPoint& P);
	friend TPoint operator*(const double scalar, const TPoint& P); // C����� * TPoint
	double det(const TPoint& _P1, const TPoint& _P2); // ������������ ��������
// �������� ���������
	int operator<(const TPoint& P) const; // ������������������ �������
	int operator>(const TPoint& P) const;
	int operator==(const TPoint& P) const;
	int operator!=(const TPoint& P) const;
// �������� ������� � �����������
	double& operator[](const int i); // i = 0 -> x; i = 1 -> y

	double Lenght(); // ���������� ����� �������

	// ���������� ��������� ����� ����������� ������������� ������� (�������) ������ 
	int Location(TPoint& P1, TPoint& P2); // P1 - ������, P2 - ����� �������
	//double Distation(const Edge& _E); // ��������� ���������� �� �������� ����� �� ������ �����
};
	                                                 
                                                      

