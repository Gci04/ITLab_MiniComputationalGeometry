#include "fm_elimination.h"

class inequality_index 
{
private :
	int n;
	int * index ;
public:
	inequality_index ();
	inequality_index (const inequality_index &a, const inequality_index &b) ;
	inequality_index (int total_inq, int pos );
	~inequality_index ();
	inequality_index* unite (inequality_index *set1,int total_inq);
	int size ();
	bool operator != (inequality_index &A);
	bool is_subset (inequality_index &A);
};

struct inequality {
	vector <int> a;
	int b;
	inequality_index index;
};
class ineq_collection {
public:
	vector  <inequality> arr_inequality;
	int numInequalities;

	void add_inequality (inequality S);
	void remove_inequality(inequality_index R);
	friend void create_linear_system(ineq_collection &A, int col, int rows);
	friend void create_system_manualy(ineq_collection &A, int col, int rows);
	friend void printResult(ineq_collection &K , int numrows, int numcols);
};