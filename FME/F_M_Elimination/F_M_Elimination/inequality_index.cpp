#include "inequality_index.h"

inequality_index :: inequality_index(){
}
inequality_index::inequality_index(const inequality_index &a, const inequality_index &b){
	index.resize(a.index.size(), 0);
	for (int i = 0; i < a.index.size(); i++){
			if((b.index [i] == 1)||(a.index[i] == 1)){
				index [i] = 1;
			}
		}
}
inequality_index :: inequality_index(int total_inq, int pos ){
	index.resize(total_inq,0);
	index[pos]=1;
}

inequality_index * inequality_index :: unite (inequality_index *set1,int total_inq){
	inequality_index * temp;
	for (int i = 0; i <index.size(); i++){
			if((index [i] == 1)||(set1->index[i] == 1)){
				temp->index [i] = 1;
			}
			else 
				temp->index[i] =0;
		}
		return temp;
	}
int inequality_index:: size ()const{
		return index.size();
	}
bool inequality_index :: operator!=(inequality_index &A) const{
	for (int i = 0; i<index.size(); i++){
		if (A.index[i] != index[i])
			return false;
		}
	return true;
}
bool inequality_index :: is_subset (inequality_index &A) const{
	for (int i=0; i<index.size(); i++){
		if (index[i] > A.index[i])
			return false;
		}
	return true;
}
void  ineq_collection :: add_inequality(inequality S){
	arr_inequality.push_back(S);
}
void  ineq_collection :: remove_inequality(int idx){
	arr_inequality[idx] = arr_inequality.back(); 
	arr_inequality.pop_back();
	
}