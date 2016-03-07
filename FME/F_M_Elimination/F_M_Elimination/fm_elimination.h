#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "Windows.h"
#include <vector>

using namespace std;

class ineq_collection;

ineq_collection Calculating_new_system( ineq_collection &X,int index_to_eliminate, int numcol, int s); //main function for calculating new systems (newA and newB)
