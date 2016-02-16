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
void printResult(int ** a, int * b, int numrows, int numcols) {
	for (int i = 0; i < numrows; i++) {
		for (int j = 0; j < numcols; j++)
			cout <<setw(3)<< a[i][j] << " ";
		cout << " | " << b[i] << endl;
	}
	cout <<endl;
}
void Calculating_new_system(struct system &X,int index_to_eliminate, int &numrows, int numcol, int s){
	int * positiveRows = new int[numrows];
	int * negativeRows = new int[numrows];
	int * zeroRows = new int[numrows];
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < numrows ; i ++)
		if(X.A[i][index_to_eliminate]>0)
			positiveRows[numPositiveRows++] = i;
		else if (X.A[i][index_to_eliminate] < 0)
			negativeRows[numNegativeRows++] = i;
		else
			zeroRows[numZeroRows++] = i;

	int newNumRows = numPositiveRows * numNegativeRows + numZeroRows;
	int ** newA = new int*[newNumRows];
	int * newB = new int[newNumRows];
	for (int i = 0; i < newNumRows; i++){
		newA[i] = new int[numcol];
	}
	int rw =0;
	//Combinations  of positive & negative rows ( copied to newA and newB)
	for(int i=0; i< numNegativeRows ; i++){
		int NegCoff = -X.A[negativeRows[i]][index_to_eliminate]; 
		for(int j=0; j< numPositiveRows; j++){ 
			inequality_index q(X.q[negativeRows[i]], X.q[positiveRows[j]]);
			if(q.size() <= s+1){
				int PosCoff = X.A[positiveRows[j]][index_to_eliminate];
				for(int k =0; k<numcol; k++){ 
					newA[rw][k] = PosCoff * X.A[negativeRows[i]][k] +
						NegCoff *X.A[positiveRows[j]][k];
				}
				newB[rw] = PosCoff * X.b[negativeRows[i]] + NegCoff * X.b[positiveRows[j]];
				rw++;
			}
		}
	}

		//copy zero rows from A to newA and b to newB
		int a=0;
		for( int i = rw; i < newNumRows; i++){
			for (int j =0; j<numcol; j++){
				newA[i][j] = X.A[zeroRows[a]][j];
			}
			newB[i] = X.b[zeroRows[a]];
			a++;
		}

		//reset memory
		for (int i = 0; i < numrows; i++){ //deleting old memory
			delete [] X.A[i];
		}
		delete []X.A;
		delete []X.b;
		X.A = newA;
		X.b = newB;
		numrows = newNumRows;
}