#include "fm_elimination.h"
#include "inequality_index.h"

int main (int argc, char *argv[]){
	ineq_collection entity1;
	srand(time(NULL));
	int numVariables , numRows, choice;
	cout <<" Test with random numbers (press 1). "<<'\n'
		<<" Fill the variables manually (press 2) \n";
	cin>> choice;
	cout<< "Enter Total number of inequalities and number of variables "<<'\n';
	cin>> numRows;
	cin>> numVariables;

	if (choice == 1){
		create_linear_system(entity1,numVariables , numRows); 
		printResult(entity1,  numRows, numVariables);
	}

	else if (choice == 2){
		create_system_manualy(entity1,numVariables , numRows); 
	}

	int element_to_eliminate, total_to_eliminate;
	cout << "Enter index of element to eliminate"<<'\n';
	cin>> element_to_eliminate;
	cout << "Input the number of elements to eliminate !"<<'\n';
	cin>>total_to_eliminate;
	ineq_collection collection;

	long Start = GetTickCount();
	for(int i = 0; i < total_to_eliminate; i++){
		ineq_collection newSystem = Calculating_new_system(entity1 ,element_to_eliminate,numVariables, i);    //all computations here
		
		entity1 = newSystem;
		element_to_eliminate ++;

	}
	long Finish = GetTickCount();
	cout<< " Time elapsed (m/s) = " <<Finish - Start <<'\n';
	printResult(entity1, numRows, numVariables);

	return 0;
}
