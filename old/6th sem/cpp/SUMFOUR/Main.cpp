/*
Project name : SUMFOUR
Created on : Fri Mar 21 23:41:46 2014
Author : Anant Pushkar
spoj binary search
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int n;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d",&n);
	int A[n] , B[n] , C[n] , D[n];
	for(int i=0;i<n;++i)scanf("%d %d %d %d\n",&A[i],&B[i],&C[i],&D[i]);
	
	int index=0;
	vector<int> sum1(n*n) , sum2(n*n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			sum1[index]=A[i]+B[j];
			sum2[index]=C[i]+D[j];
			++index;
		}
	}
	sort(sum1.begin(),sum1.end());
	sort(sum2.begin(),sum2.end());
	
	int count=0,temp;
	for(int i=0;i<sum1.size();++i){
		count+=upper_bound(sum2.begin(),sum2.end(),-sum1[i])-lower_bound(sum2.begin(),sum2.end(),-sum1[i]);
	}
	printf("%d\n",count);
	
	return 0;
}

