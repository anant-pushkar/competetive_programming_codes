/*
Project name : Distinct_Primes
Created on : Wed Jul 30 20:52:32 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AMR11E/
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
const int LIM = 48000;
vector<int> lookup;
vector<int> lucky;
void init(){
	lookup = vector<int>(LIM , 0);
	lucky  = vector<int>(1000);
	int count=0;
	for(int i=2;count<1000 && i<LIM;++i){
		if(lookup[i]==0){
			for(int j=2*i;j<LIM;j+=i){
				lookup[j] += 1;
			}
		}
		if(lookup[i]>=3){
			lucky[count++] = i;
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	init();
	while(t--){
		scanf("%d",&n);
		printf("%d\n",lucky[n-1]);
	}
	return 0;
}

