/*
Project name : Majority_element
Module name  : {module}
Created on : Thu Aug  7 18:58:38 2014
Author : Anant Pushkar
Explore algorithms to find mejority element in an array
*/
#include "module.h"
const int MAJORITY_DOES_NOT_EXIST = 1;
const int UNKNOWN_ERR = 2;
extern bool debug;

std::pair<int,int> MajorityFinder::divide(int start , int end){
	if(end==start+1){
		return std::make_pair(arr[start] , 1);
	}
	int mid = (start+end)/2;
	
	std::pair<int,int> left = divide(start,mid) , right  = divide(mid,end) , soln;
	
	if(left.first==right.first){
		soln =  std::make_pair(left.first , left.second + right.second);
	}else{
		soln = left.second>right.second ? left : right;
	}
	
	if(debug){
		std::cout<<"dividing from "<<start<<" to "<<end<<" to get "<<soln.first<<","<<soln.second<<std::endl;
	}
	
	return soln;
}

int MajorityFinder::find_majority() throw(int){
	int diff=1 , n , count;
	std::queue<int> q , q2;
	for(int i=0;i+1<size;i+=2){
		if(arr[i]==arr[i+1]){
			q.push(arr[i]);
		}
	}
	while(true){
		if(q.empty()){
			throw MAJORITY_DOES_NOT_EXIST;
		}
		
		n = q.front();
		q.pop();
		count = q.size();
		while(!q.empty()){
			if(n==q.front()){
				q2.push(n);
				--count;
			}
			n = q.front();
			q.pop();
		}
		if(count==0){
			return n;
		}
		while(!q2.empty()){
			q.push(q2.front());
			q2.pop();
		}
	}
	throw MAJORITY_DOES_NOT_EXIST;
}

void MajorityFinder::handle_exp(int exp) const throw(int){
	switch(exp){
		case MAJORITY_DOES_NOT_EXIST:
			throw MAJORITY_DOES_NOT_EXIST;
			break;
		default:
			throw UNKNOWN_ERR;
			break;
	}
}

MajorityFinder::MajorityFinder(int n):
size(n),
arr(std::vector<int>(n)){
	for(int i=0;i<n;++i){
		arr[i] = rand()%max_val;
	}
}
MajorityFinder::MajorityFinder(int a[] , int n):
size(n),
arr(std::vector<int>(a , a + n)){
	if(debug){
		std::cout<<"MF constructed"<<std::endl;
	}
}	
int MajorityFinder::get_contestant(){
	int count = 1 , max_val = arr[0];
	for(int i=1;i<size;++i){
		if(arr[i]==max_val){
			++count;
		}else{
			--count;
		}
		if(count==0){
			max_val = arr[i];
			count = 1;
		}
	}
	return max_val;
}
bool MajorityFinder::is_majority(int n){
	int count = 0;
	for(int i=0;i<size;++i){
		count += arr[i]==n;
	}
	return count>size/2;
}
int MajorityFinder::get_majority() throw(int){
	/*std::pair<int,int> m = divide(0,size);
	if(m.second>size/2){
		return m.first;
	}else{
		throw MAJORITY_DOES_NOT_EXIST;
	}*/
	//return find_majority();
	int n = get_contestant();
	if(is_majority(n)){
		return n;
	}else{
		throw MAJORITY_DOES_NOT_EXIST;
	}
}
	
void MajorityFinder::report_error(int exp){
	switch(exp){
		case MAJORITY_DOES_NOT_EXIST:
			std::cout<<"Majority Element does not exist"<<std::endl;
			break;
		default:
			std::cout<<"Unknown error occured"<<std::endl;
			break;
	}
}

