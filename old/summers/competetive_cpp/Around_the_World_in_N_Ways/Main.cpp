/*
Project name : Around_the_World_in_N_Ways
Created on : Tue May 20 10:53:11 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/apc/challenges/around-the-world-in-n-ways
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
#define MOD 1000000007
using namespace std;
bool debug=false;
typedef long long int lld;
void square(lld ** M){
	int temp[3][3];
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp[i][j] = ((M[i][0]*M[0][j] + M[i][1]*M[1][j])%MOD + M[i][2]*M[2][j])%MOD;
		}
	}
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)M[i][j] = temp[i][j];
}
lld **copy(lld M[3][3]){
	lld **N = (lld**)calloc(3,sizeof(lld*));
	for(int i=0;i<3;++i){
		N[i] = (lld*)calloc(3,sizeof(lld));
		for(int j=0;j<3;++j)N[i][j] = M[i][j]%MOD;
	}
	return N;
}
void mult(lld A[3][3] , lld ** B){
	lld temp[3][3];
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp[i][j] = ((A[i][0]*B[0][j] + A[i][1]*B[1][j])%MOD + A[i][2]*B[2][j])%MOD;
		}
	}
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)A[i][j] = temp[i][j];
}
int getNum(int n){
	int k = (n-1)/3;
	lld M[3][3] = {
			{1 , 1 , 1},
			{1 , 2 , 2},
			{2 , 3 , 4}
	} , S[3][3] = {
			{1 , 0 , 0},
			{0 , 1 , 0},
			{0 , 0 , 1}
	};
	lld **m = copy(M);
	while(k!=0){
		if(k%2)mult(S,m);
		square(m);
		k = k>>1;
	}
	free(m);
	int i = (n-1)%3;
	return ((S[i][0]*1 + S[i][1]*2)%MOD + S[i][2]*4)%MOD;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		printf("%d\n",getNum(n));
	}
	return 0;
}

