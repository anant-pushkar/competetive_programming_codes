/*
Project name : Jzzhu_and_Sequences
Created on : Sat Jul 19 18:39:29 2014
Author : Anant Pushkar
http://codeforces.com/contest/450/problem/B
f[i]  = f[i-1]-f[i-2]
	  = -f[i-3]
f[i-1]= f[i-2]-f[i-3]
M = {{0 , -1} , {1 , -1}}

2 3 1 -2 -3 -1 2 3 1 -2 
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
typedef unsigned long long int llu;
vector<vector<lld> > M;
void multiply(vector<vector<lld> > &A , const vector<vector<lld> > &B){
	int size = A.size() , temp[size][size];
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			temp[i][j] = 0;
			for(int k=0;k<size;++k){
				temp[i][j] += (A[i][k]*B[k][j]+MOD)%MOD;
			}
			temp[i][j] = (temp[i][j]+MOD)%MOD;
		}
	}
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			A[i][j] = temp[i][j];
		}
	}
}
vector<vector<lld> > getMat(lld n){
	vector<vector<lld> > temp=M , product(2,vector<lld>(2,0));
	product[0][0]=1;
	product[1][1]=1;
	lld k = n/2 - (n%2==0 ? 1 : 0);
	if(debug)cout<<"k:"<<k<<endl;
	if(debug){
			cout<<"P : "<<endl;
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					cout<<product[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl<<"M : "<<endl;
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					cout<<temp[i][j]<<" ";
				}
				cout<<endl<<endl;
			}
		}
	while(k>0){
		if( (k&1) == 1){
			multiply(product,temp);
		}
		multiply(temp,temp);
		k = k>>1;
		if(debug){
			cout<<"P : "<<endl;
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					cout<<product[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl<<"M : "<<endl;
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					cout<<temp[i][j]<<" ";
				}
				cout<<endl<<endl;
			}
		}
	}
	return product;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld x , y;
	scanf("%lld %lld",&x,&y);
	
	lld n , val , temp = MOD;
	scanf("%lld",&n);
	temp *= MOD;
	
	vector<vector<lld> > mat;
	if(n==1){
		printf("%lld\n",(x+MOD)%MOD);
	}else if(n==2){
		printf("%lld\n",(y+MOD)%MOD);
	}else{
		//M = {{0 , -1} , {1 , -1}};
		M = vector<vector<lld> >(2,vector<lld>(2));
		M[0][0]=0;
		M[0][1]=-1;
		M[1][0]=1;
		M[1][1]=-1;
		mat = getMat(n);
		if(n%2==0){
			val = y*mat[0][0] + x*mat[0][1];
		}else{
			val = y*mat[1][0] + x*mat[1][1];
		}
		val = (val+temp)%MOD;
		printf("%lld\n",val);
	}
	
	return 0;
}