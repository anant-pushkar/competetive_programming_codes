/*
Project name : AMZ_Word
Created on : Thu Sep  4 23:42:10 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AMZSEQ/

one[i] = one[i-1] + two[i-1]
two[i] = one[i-1] + two[i-1] + thr[i-1]
thr[i] = two[i-1] + thr[i-1]

/        \   /       \   /          \
| one[i] |   | 1 1 0 |   | one[i-1] |
| two[i] | = | 1 1 1 | * | two[i-1] |
| thr[i] |   | 0 1 1 |   | thr[i-1] |
\        /   \       /   \          /

/        \   /       \i-1 /        \
| one[i] |   | 1 1 0 |    | one[1] |
| two[i] | = | 1 1 1 | *  | two[1] |
| thr[i] |   | 0 1 1 |    | thr[1] |
\        /   \       /    \        /

one[1] = 1
two[1] = 1
thr[1] = 1
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
int M[3][3] = {
		{1 , 1 , 0},
		{1 , 1 , 1},
		{0 , 1 , 1}
};

//m1=m2
void copy(int m1[3][3] , int m2[3][3]){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			m1[i][j] = m2[i][j];
		}
	}
}

//m1 *= m2
void mult(int m1[3][3] , int m2[3][3]){
	int a,b,c;
	int m[3][3];
	for(int i=0;i<3;++i){
		a = m1[i][0];
		b = m1[i][1];
		c = m1[i][2];
		
		for(int j=0;j<3;++j){
			m[i][j] = a*m2[0][j] + b*m2[1][j] + c*m2[2][j];
		}
	}
	copy(m1,m);
}

void pow(int m[3][3] , int p){
	int temp[3][3] = {
		{1 , 0 , 0},
		{0 , 1 , 0},
		{0 , 0 , 1}
	} , val[3][3];
	copy(val , M);
	while(p>0){
		if( (p&1)==1 ){
			mult(temp , val);
		}
		mult(val,val);
		p = p>>1;
	}
	copy(m,temp);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int m[3][3] , one , two , thr , n;
	
	scanf("%d",&n);
	pow(m , n-1);
	
	if(debug){
		cout<<"m : "<<endl;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				cout<<m[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	one = m[0][0] + m[0][1] + m[0][2];
	two = m[1][0] + m[1][1] + m[1][2];
	thr = m[2][0] + m[2][1] + m[2][2];
	
	printf("%d\n",one+two+thr);
	
	return 0;
}

