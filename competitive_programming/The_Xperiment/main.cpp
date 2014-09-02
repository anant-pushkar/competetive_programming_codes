/*
Project name : The_Xperiment
Created on : Wed Aug 27 00:47:18 2014
Author : Anant Pushkar

*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
vector<int> lookup;
void preprocess(){
	int count = 0;
	vector<bool> is_prime(5001,true);
	for(int i=2;i<5001;++i)if(is_prime[i]){
		for(int j=2*i;j<5001;j+=i){
			is_prime[j] = false;
		}
		++count;
	}
	
	lookup = vector<int>(count);
	int index=0;
	for(int i=2;i<5001;++i)if(is_prime[i]){
		lookup[index++] = i;
	}	
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	preprocess();
	
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			printf("%d ",lookup[i]);
		}
		printf("\n");
	}
	
	return 0;
}

