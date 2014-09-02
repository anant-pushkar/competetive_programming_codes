/*
Project name : coder
Created on : Mon Jan 20 21:02:19 2014
Author : Anant Pushkar
codeforces 384 : A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,count=0;
	scanf("%d",&n);
	vector<vector<char> > grid(n,vector<char>(n,'.'));
	for(int i=0;i<n;++i){
		for(int j=i%2;j<n;j+=2){
			grid[i][j]='C';
			++count;
		}
	}
	printf("%d\n",count);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}
