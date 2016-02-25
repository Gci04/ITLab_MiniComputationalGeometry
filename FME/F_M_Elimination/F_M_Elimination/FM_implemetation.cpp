#include "fm_elimination.h"
#include "inequality_index.h"

int* create_b(int rows){
	int *arr= new int[rows];
	for (int i = 0; i<rows; i++){
		arr[i] = rand()%21 - 10;
	}
	return arr;
}
int ** create_a(int col, int rows){
	int **arr = new int*[rows];
	for (int i = 0; i<rows; i++){
		arr[i] = new int[col];
	}
	for (int i = 0; i<rows; i++){
		for(int j = 0; j<col; j++){
			arr[i][j] = rand()% 20 + -10;      //rand()% (high - low) + low
		}
	}
	return arr;
}
void printResult(struct system &K, int numrows, int numcols) {
	for (int i = 0; i < numrows; i++) {
		for (int j = 0; j < numcols; j++)
			cout <<setw(3)<< K.inequalities[i].a[j] << " ";
		cout << " | " << K.inequalities[i].b << endl;
	}
	cout <<endl;
}

struct system Calculating_new_system(struct system &X,int index_to_eliminate, int numcol, int s){
	int * positiveRows = new int[X.numInequalities];
	int * negativeRows = new int[X.numInequalities];
	int * zeroRows = new int[X.numInequalities];
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < X.numInequalities; i ++)
		if(X.inequalities[i].a[index_to_eliminate]>0)
			positiveRows[numPositiveRows++] = i;
		else if (X.inequalities[i].a[index_to_eliminate] < 0)
			negativeRows[numNegativeRows++] = i;
		else
			zeroRows[numZeroRows++] = i;

	struct system result;
	result.numInequalities = numPositiveRows * numNegativeRows + numZeroRows;
	result.inequalities = new inequality[result.numInequalities];
	for (int i = 0; i < result.numInequalities; i++){
		result.inequalities[i].a = new int[numcol];
	}
	int rw =0;
	//Combinations  of positive & negative rows ( copied to newA and newB)
	for(int i=0; i < numNegativeRows ; i++){
		int NegCoff = -X.inequalities[negativeRows[i]].a[index_to_eliminate]; 
		for(int j=0; j < numPositiveRows; j++){ 
			inequality_index q(X.inequalities[negativeRows[i]].index, X.inequalities[positiveRows[j]].index);
			if(q.size() <= s+1){
				int PosCoff = X.inequalities[positiveRows[j]].a[index_to_eliminate];
				for(int k =0; k<numcol; k++){ 
					result.inequalities[rw].a[k] = PosCoff * X.inequalities[negativeRows[i]].a[k] +
						NegCoff *X.inequalities[positiveRows[j]].a[k];
				}
				result.inequalities[rw].b = PosCoff * X.inequalities[negativeRows[i]].b + NegCoff * X.inequalities[positiveRows[j]].b;
				result.inequalities[rw].index = q;
				rw++;
			}
		}
	}

	//copy zero rows from A to newA and b to newB
	for( int i = rw; i < rw + numZeroRows; i++){
		for (int j = 0; j < numcol; j++){
			result.inequalities[i].a[j] = X.inequalities[zeroRows[i - rw]].a[j];
		}
		result.inequalities[i].b = X.inequalities[zeroRows[i - rw]].b;
	}
	result.numInequalities = rw + numZeroRows;
	return result;
}