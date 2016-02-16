#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "Windows.h"

using namespace std;

/* Functions that initializes the matrix A and vector b  */
int ** create_a(int col, int rows);
int* create_b(int rows);

void printResult(int ** a, int * b, int numrows, int numcols);
void Calculating_new_system(struct system &X,int index_to_eliminate, int &numrows, int numcol, int s); //main function for calculating new systems (newA and newB)
