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
	int* a;
	int b;
	inequality_index index;
};

struct system {
	/*int **A;
	int *b;
	inequality_index *q;*/
	// instead have
	 inequality* inequalities;
	 int numInequalities;
};