#include "set_points.h"

SetPoints :: SetPoints (int _Size ) 
{
	Size = _Size;
	mas = new TPoint [Size];
	for (int i=0; i < Size; i++ )
	{
		mas[i] = 0;
	    mas[i] = 0;
    }
}


SetPoints :: SetPoints ( const SetPoints & set)
{
	Size = set.Size;
	for ( int i =0; i < Size; i++)
		mas[i] = set.mas[i];
}


TPoint SetPoints :: operator [] ( int i )
{
	return mas[i];
}

/*TPoint SetPoints :: operator= ( const SetPoints &set )
{
	delete[] mas;
	Size = set.Size;
	mas = new TPoint [Size];
	for (int i=0; i < Size; i++)
		mas[i] = set.mas[i];
}*/
