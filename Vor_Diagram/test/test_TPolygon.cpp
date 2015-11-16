#include "TPolygon.h"
#include "gtest.h"

/*---------------------------------------------------------------------------------------*/
// ������������ ������ <TPolygon>

/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_create_polygon_by_default) // ���� ������� ������� � ������� ������������ �� ��������
{
	ASSERT_NO_THROW(TPolygon P);
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_insert_new_vertex) // ���� �������� ����� ������� � �������
{
	TPolygon Pol;
	TPoint P1(3.3, 4.4);

	ASSERT_NO_THROW(Pol.Insert_Vertex(P1));
};
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_get_active_point) // ���� �������� ����� � ������� �������
{
	TPolygon Pol;
	TPoint P1(3.3, 4.4);
	TPoint P2(2.2, 1.1);

	Pol.Insert_Vertex(P1);
	Pol.Insert_Vertex(P2);
	EXPECT_EQ(P2, Pol.Get_Point()); //��������� ������� �������
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_get_size_polygon) // ���� �������� ������ ��������
{
	TPolygon Pol;
	TPoint P1(3.3, 4.4);
	TPoint P2(2.2, 1.1);

	Pol.Insert_Vertex(P1);
	Pol.Insert_Vertex(P2);

	EXPECT_EQ(2,Pol.Get_Size());
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_create_polygon_from_a_vertex_list) // ���� ������� ������� �� ������������ ������ ������
{
	// ���������� ������������ ������ ������
    TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);
	//
	ASSERT_NO_THROW(TPolygon P(&V1));
	TPolygon P(&V1);
	EXPECT_EQ(3, P.Get_Size());
	EXPECT_EQ(V1.Get_Point(),P.Get_Point());
	P.Advance(CLOCKWISE);
	EXPECT_EQ(V2.Get_Point(),P.Get_Point());
	P.Advance(CLOCKWISE);
	EXPECT_EQ(V3.Get_Point(),P.Get_Point());
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_create_copied_polygon) // ���� ������� ����� ��������
{ 
	// ���������� ������������ ������ ������
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);
	//
	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);

	TPolygon P(&V1);
	ASSERT_NO_THROW( TPolygon P1 = P);
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, copied_polygon_is_equal_to_source_one) // ������������� ������� ����� ������ ����
{
	// ���������� ������������ ������ ������
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);
	//
	TPolygon P1(&V1);
	TPolygon P2 = P1;
	EXPECT_EQ(P1.Get_Size(), P2.Get_Size()); // ��������� ������
	EXPECT_EQ(P1.Get_Point(), P2.Get_Point()); // ��������� �������� �������
	EXPECT_NE(P1.Get_Vertex(), P2.Get_Vertex()); // ��������� ������� ����������� ������
	EXPECT_NE(P1.Get_Next_Vertex(), P2.Get_Next_Vertex());
	EXPECT_NE(P1.Get_Prev_Vertex(), P2.Get_Prev_Vertex());
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_get_neighbor) // ���� �������� ������� �� ������� ������� � ������
{
	//���������� ��������
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);
	TPolygon P(&V1);
	EXPECT_EQ(V2.Get_Point(), P.Neighbor(CLOCKWISE) -> Get_Point());
	EXPECT_EQ(V3.Get_Point(), P.Neighbor(COUNTER_CLOCKWISE) -> Get_Point());
}
/*---------------------------------------------------------------------------------------*/
TEST(TPolygon, can_change_active_vertex_in_polygon)
{
	//���������� ��������
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);
	TPolygon P(&V1);
	P.Advance(CLOCKWISE);
	EXPECT_EQ(V2.Get_Point(), P.Get_Point());
}
/*TEST(TPolygon, can_change_active_vertex_to_set_vertex) // ����� �������� ��� ������ ������� ����������� ��������, ����� ����������
{
	//���������� ��������
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);

	TPolygon P(&V3);
	P.Neighbor(CLOCKWISE);
	//EXPECT_EQ(V3.Get_Point(),P.Get_Point());
	//P.Advance_Set_Vertex(&V1);
}*/


