#include "fm_elimination.h"
#include "inequality_index.h"

void create_linear_system(ineq_collection &A, int col, int rows){
	for (int i = 0; i < rows; i++){
		struct inequality temp;
		//temp.index(rows, i);
		inequality_index temp1(rows, i);
		temp.b = rand()%21 - 10;
		temp.index =temp1;
		for (int j = 0; j < col; j++){
			temp.a.push_back(rand()% 20 + -10);
			//temp.a[j]  = rand()% 20 + -10;
		}
		A.arr_inequality.push_back(temp);
	}
}
void create_system_manualy(ineq_collection &A, int col, int rows){
	for (int i = 0; i < rows; i++){
		struct inequality temp;
		//temp.index(rows, i);
		inequality_index temp1(rows, i);
		cin >>temp.b ;
		temp.index =temp1;
		for (int j = 0; j < col; j++){
			cin>>temp.a[j];
		}
		A.arr_inequality.push_back(temp);
	}

}

void printResult(ineq_collection &K ) {
	for (int i = 0; i < K.arr_inequality.size(); i++) {
		for (int j = 0; j < K.arr_inequality[1].a.size(); j++)
			cout <<setw(3)<< K.arr_inequality[i].a[j] << " ";
		cout << " | " << K.arr_inequality[i].b << '\n';
	}
	cout <<'\n';
}

 ineq_collection Calculating_new_system( ineq_collection &X,int index_to_eliminate, int numcol, int s){
	vector <int> positiveRows;
	vector <int> negativeRows;
	vector <int> zeroRows;
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < X.arr_inequality.size(); i ++)
		if(X.arr_inequality[i].a[index_to_eliminate]>0)
			positiveRows.push_back(i);
		else if (X.arr_inequality[i].a[index_to_eliminate] < 0)
			negativeRows.push_back(i);
		else
			zeroRows.push_back(i);

	ineq_collection result;
	int rw =0;
	//Combinations  of positive & negative rows ( copied to newA and newB)
	for(int i=0; i < negativeRows.size() ; i++){
		int NegCoff = -X.arr_inequality[negativeRows[i]].a[index_to_eliminate]; 
		for(int j=0; j < positiveRows.size(); j++){ 
			inequality_index q(X.arr_inequality[negativeRows[i]].index, X.arr_inequality[positiveRows[j]].index);
			if(q.size() <= s+1){
				int PosCoff = X.arr_inequality[positiveRows[j]].a[index_to_eliminate];
				for(int k =0; k<numcol; k++){ 
					result.arr_inequality[rw].a[k] = PosCoff * X.arr_inequality[negativeRows[i]].a[k] +
						NegCoff *X.arr_inequality[positiveRows[j]].a[k];
				}
				result.arr_inequality[rw].b = PosCoff * X.arr_inequality[negativeRows[i]].b + NegCoff * X.arr_inequality[positiveRows[j]].b;
				result.arr_inequality[rw].index = q;
				rw++;
			}
		}
	}

	//copy zero rows from A to newA and b to newB
	for( int i = rw; i < rw + zeroRows.size(); i++){
		for (int j = 0; j < numcol; j++){
			result.arr_inequality[i].a[j] = X.arr_inequality[zeroRows[i - rw]].a[j];
		}
		result.arr_inequality[i].b = X.arr_inequality[zeroRows[i - rw]].b;
	}
	return result;
}