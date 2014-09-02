/*
Project name : Alex_vs_Fedor
Created on : Sat Aug 30 11:10:23 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w9/challenges/alex-vs-fedor
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
lld countMST(vector<vector<lld> > &mat , int n , vector<vector<int> > &mult){
	int size = mat.size();
	vector<vector<lld> > m = mat;
	vector<vector<int> > mu = mult;
	
	lld count=0;
	for(int i=0;i<size;++i){
		for(int j=i+1;j<size;++j)if(mult[i][j]!=0){
			m[i][j] = 0;
			m[j][i] = 0;
			mu[i][j] = 0;
			mu[j][i] = 0;
			
			for(int k=0;k<size;++k)if(k!=i){
				m[i][k] += mat[j][k];
				m[j][k]  = 0;
				
				m[k][i] += mat[k][j];
				m[k][j]  = 0;
				
				mu[i][k] += mult[j][k];
				mu[j][k] = 0;
				
				mu[k][i] += mult[k][j]; 
				mu[k][j] = 0;
			}
			
			count += countMST(m , n-1 , mu);
			
			for(int k=0;k<size;++k)if(k!=i){
				m[i][k] -= mat[j][k];
				m[j][k]  = mat[j][k];
				
				m[k][i] -= mat[k][j];
				m[k][j]  = mat[k][j];
				
				mu[i][k] -= mult[j][k];
				mu[j][k] = mult[j][k];
				
				mu[k][i] -= mult[k][j]; 
				mu[k][j] = mult[k][j];
			}
			
			count += countMST(m , n-1 , mu);
			
			m[i][j] = mat[i][j];
			m[j][i] = mat[j][i];
		}
	}
	
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	scanf("%d %d",&n,&m);
	vector<vector<lld> > mat(n , vector<lld>(n,0));
	vector<vector<int> > mult(n , vector<int>(n,0));
	
	int a,b,c;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&a,&b,&c);
		--a;--b;
		mat[a][b] = c;
		mat[b][a] = c;
		
		mult[a][b] += 1;
		mult[b][a] += 1;
	}
	
	lld total = countMST(mat , n , mult);
	
	return 0;
}

