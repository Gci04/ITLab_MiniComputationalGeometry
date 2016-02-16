#include "inequality_index.h"

inequality_index :: inequality_index(){
		index = 0;
	}
inequality_index::inequality_index(const inequality_index &a, const inequality_index &b){
	n = a.n;
		index = new int [n];
		for (int i = 0; i < n; i++){
			if((b.index [i] == 1)||(a.index[i] == 1)){
				index [i] = 1;
			}
			else 
				index[i] = 0;
		}
	}
inequality_index :: inequality_index(int total_inq, int pos ){
	n = total_inq;
		index = new int [total_inq];
		for (int i = 0; i<total_inq; i++){
			index[i]= 0;
			if (i == pos){
				index[i] = 1;
			}
		}
	}
inequality_index :: ~inequality_index() 
{ delete[] index;}
inequality_index * inequality_index :: unite (inequality_index *set1,int total_inq){
	for (int i = 0; i < total_inq; i++){
			if((index [i] == 1)||(set1->index[i] == 1)){
				set1->index [i] = 1;
			}
		}
		return set1;
	}
int inequality_index:: size (){
		int total = 0;
		for(int i =0; i < n; i++){
			if (index[i] == 1){
				total++;
			}
		}
		return total;
	}
bool inequality_index :: operator!=(inequality_index &A){
	if (A.size() == size())
			return false;
		else 
			return true;
	}
bool inequality_index :: is_subset (inequality_index &A){
	bool test;
	for (int i=0; i<n; i++){
		if (index[i] != A.index[i]){
			test = true;
			return false;
		}
		else
			test = true;
	}
	return test;
}