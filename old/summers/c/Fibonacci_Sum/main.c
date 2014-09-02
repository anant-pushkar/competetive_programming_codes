/*
Project name : Fibonacci_Sum
Created on : Thu Jun  5 16:51:10 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FIBOSUM/
s : 0 1 2 4 7 12 .....

s(n)   = 2s(n-1) - s(n-3)
	   = 7s(n-3) - 2s(n-4) - 4s(n-5)
s(n-1) = 2s(n-2) - s(n-4)
	   = 4s(n-3) - s(n-4) - 2s(n-5)
s(n-2) = 2s(n-3) - s(n-5)

/       \    /           \   /       \
| s(n)  |    | 7  -2  -4 |   | s(n-3)|
| s(n-1)|  = | 4  -1  -2 | * | s(n-4)|
| s(n-2)|    | 2   0  -1 |   | s(n-5)|
\       /    \           /   \       /
n = 3k+2
F(n) = M * F(n-3)
     = M * M * F(n-6)
     .....
     = M**k * F(2)
F(2) = [2 1 0]'

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MOD 1000000007
int debug;
typedef long long int lld;
void square(lld ** M){
	int temp[3][3] , i , j;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			temp[i][j] = ((M[i][0]*M[0][j] + M[i][1]*M[1][j])%MOD + M[i][2]*M[2][j])%MOD;
		}
	}
	for(i=0;i<3;++i)for(j=0;j<3;++j)M[i][j] = temp[i][j];
}
lld **copy(lld M[3][3]){
	lld **N = (lld**)calloc(3,sizeof(lld*));
	int i , j;
	for(i=0;i<3;++i){
		N[i] = (lld*)calloc(3,sizeof(lld));
		for(j=0;j<3;++j)N[i][j] = M[i][j]%MOD;
	}
	return N;
}
void mult(lld A[3][3] , lld ** B){
	lld temp[3][3];
	int i , j;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			temp[i][j] = ((A[i][0]*B[0][j] + A[i][1]*B[1][j])%MOD + A[i][2]*B[2][j])%MOD;
		}
	}
	for(i=0;i<3;++i)for(j=0;j<3;++j)A[i][j] = temp[i][j];
}
int getNum(int n){
	if(n<0)
		return 0;
	int k = n/3;
	lld M[3][3] = {
			{7 , -2 , -4},
			{4 , -1 , -2},
			{2 ,  0 , -1}
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
	int i = 2 - n%3;
	return (((S[i][0]*2+MOD)%MOD + S[i][1]*1 + MOD)%MOD + S[i][2]*0 + MOD)%MOD;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	int a,b;
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%d\n",(getNum(b) - getNum(a-1)+MOD)%MOD);
	}
	return 0;
}