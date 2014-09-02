/*
Project name : Majority_element
Created on : Thu Aug  7 18:58:38 2014
Author : Anant Pushkar
Explore algorithms to find majority element in an array
*/
#include"module.h"
using namespace std;
bool debug=false;

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	srand(time(NULL));
	
	int arr[8] = {2,1,2,1,2,2,3,2};
	MajorityFinder mf(arr , 8);

	try{
		cout<<mf.get_majority()<<endl;
	}catch(int exp){
		mf.report_error(exp);
	}

	return 0;
}

