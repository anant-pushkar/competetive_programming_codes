/*
Project name : MCOINS
Created on : Sun Dec 29 16:14:41 2013
Author : Anant Pushkar
http://www.spoj.com/problems/MCOINS/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int k,l,m;
vector<bool> lookup;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d %d %d",&k,&l,&m);
	lookup=vector<bool>(1000001,false);
	lookup[1]=true;
	lookup[k]=true;
	lookup[l]=true;
	
	for(int i=2;i<1000001;++i){
	  if(!lookup[i]) lookup[i]=lookup[i] || !lookup[i-1];
	  if(!lookup[i]) lookup[i]=lookup[i] || (i-k>=0 ? !lookup[i-k] : false ) ;
	  if(!lookup[i]) lookup[i]=lookup[i] || (i-l>=0 ? !lookup[i-l] : false ) ;
	}
	
	for(int i=0;i<m;++i){
	  int n;scanf("%d",&n);
	  char c=lookup[n]?'A':'B';
	  printf("%c",c);
	}
	printf("\n");
	
	return 0;
}

