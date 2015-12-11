# include "tpoint.h"

class SetPoints 
{
public:
	TPoint *mas; 
	int Size;
public:

	SetPoints( int _Size = 0 );
	SetPoints ( const SetPoints & set);

	TPoint operator[] (int i);
	//TPoint operator= ( const SetPoints & set );

};
