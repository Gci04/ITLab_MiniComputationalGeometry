#include "fm_elimination.h"
#include "inequality_index.h"

int main (int argc, char *argv[]){
	srand(time(NULL));
	int numVariables , numRows, choice;
	cout << " Test with random numbers (press 1). "<<'\n'
		<<"Fill the variables manually (press 2) \n";
	cin>> choice;
	cout<< "Enter Total number of inequalities and number of variables "<<'\n';
	cin>> numRows;
	cin>> numVariables;
	int** A = new int* [numRows];
	int* b = new int[numRows];
	if (choice == 1){
		A = create_a(numVariables, numRows);
		b = create_b(numRows);
		for (int i = 0; i < numRows; i++){
			for(int j = 0; j < numVariables; j++){
				cout <<setw(4)<<A[i][j];
			}
			cout <<setw(4)<<b[i]<<'\n';
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i<numRows; i++){
			A[i] = new int[numVariables];
		}
		for (int i = 0; i<numRows; i++){
			for(int j=0; j<numVariables; j++){
				cin>>A[i][j];
			}
			cin>>b[i];
		}
	}
	inequality_index * Q = new inequality_index [numRows];
	for (int i =0; i < numRows; i++){
		inequality_index x(numRows, i);
		Q[i] = x;
	}
	int element_to_eliminate, total_to_eliminate;
	cout << "Enter index of element to eliminate"<<'\n';
	cin>> element_to_eliminate;
	cout << "Input the number of elements to eliminate !"<<endl;
	cin>>total_to_eliminate;
	struct system collection;
	collection.numInequalities = numRows;
	collection.inequalities = new inequality[collection.numInequalities];
	for (int i = 0; i < collection.numInequalities; i++) {
		collection.inequalities[i].a = A[i];
		collection.inequalities[i].b = b[i];
		collection.inequalities[i].index = Q[i];
	}
	/*
	collection.A = A;
	collection.b = b;
	collection.q = Q;*/
	long Start = GetTickCount();
	for(int i = 0; i < total_to_eliminate; i++){
		struct system newSystem = Calculating_new_system(collection,element_to_eliminate,numVariables, i);    //all computations here
		//
		collection = newSystem;
		element_to_eliminate ++;

	}
	long Finish = GetTickCount();
	cout<< " Time elapsed (m/s) = " <<Finish - Start <<endl;
	printResult(collection, numRows, numVariables);
	//Free memory
	for (int i = 0; i < numRows; i++){
		delete [] A[i];
	}
	delete []A;
	delete []b;
	return 0;
}