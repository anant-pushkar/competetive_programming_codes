/*
Project name : Best_spot
Created on : Fri Jul  4 15:43:57 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w6/challenges/best-spot
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
vector< vector<int> > land , pStore , lookup;
int r , c , h , w , x , y;
void readGrid(int &a , int &b , vector<vector<int> > &grid){
	scanf("%d %d",&a,&b);
	grid = vector< vector<int> >(a,vector<int>(b));
	for(int i=0;i<a;++i){
		for(int j=0;j<b;++j){
			scanf("%d",&grid[i][j]);
		}
	}
}
inline int getDiff(int i , int j , int k , int l){
	if(i==r || j==c || k==h || l==w){
		return 0;
	}
	if(debug){
		cout<<"getDiff on "<<i<<" "<<j<<" "<<k<<" "<<l<<" = "<<(land[i][j]-pStore[k][l])*(land[i][j]-pStore[k][l])<<endl;
		//cout<<"land : "<<land[i][j]<<" pStore:"<<pStore[k][l]<<endl;
	}
	return (land[i][j]-pStore[k][l])*(land[i][j]-pStore[k][l]);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	readGrid(r,c,land);
	readGrid(h,w,pStore);
	
	x = r-h+1;
	y = c-w+1;
	if(debug)cout<<"x:"<<x<<" y:"<<y<<endl;
	lookup = vector< vector<int> >(x , vector<int>(y,0));
	
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			lookup[0][0] += getDiff(i,j,i,j);
		}
	}
	if(debug)cout<<0<<","<<0<<":"<<lookup[0][0]<<endl<<endl;
	
	int diff;
	for(int i=0;i<x;++i){
		if(i!=0){
			diff=0;
			for(int k=0;k<w;++k){
				diff += getDiff(i,k,0,k) - getDiff(i+h-1,k,h-1,k);
			}
			lookup[i][0] = lookup[i-1][0] - diff;
			if(debug)cout<<i<<","<<0<<":"<<lookup[i][0]<<endl;
		}
		for(int j=1;j<y;++j){
			diff=0;
			for(int k=i;k<i+h;++k){
				diff += getDiff(k,j-1,k-i,0) - getDiff(k,j+w-1,k-i,w-1);
			}
			lookup[i][j] = lookup[i][j-1] - diff;
			if(debug)cout<<i<<","<<j<<":"<<lookup[i][j]<<endl;
		}
		if(debug)cout<<endl;
	}
	
	if(debug)cout<<"lookup : "<<endl;
	int min=INT_MAX , a=0 , b=0;
	for(int i=0;i<x;++i){
		for(int j=0;j<y;++j){
			if(debug)cout<<lookup[i][j]<<" ";
			if(min>lookup[i][j]){
				min = lookup[i][j];
				a = i;
				b = j;
			}
		}
		if(debug)cout<<endl;
	}
	printf("%d\n%d %d\n",min,a,b);
	
	return 0;
}

