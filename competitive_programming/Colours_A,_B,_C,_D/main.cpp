/*
Project name : Colours_A,_B,_C,_D
Created on : Sun Aug  3 17:06:54 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ABCD/
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	char top[2*n+1] , bottom[2*n+1] , base[5];
	strcpy(base , "ABCD");
	scanf("%s",top);
	
	for(int i=0;i<2*n;i+=2){
		for(int j=0;j<4;++j){
			if(top[i]!=base[j] && top[i+1]!=base[j]){
				bottom[i] = base[j];
				break;
			}
		}
		for(int j=0;j<4;++j){
			if(top[i]!=base[j] && top[i+1]!=base[j] && bottom[i]!=base[j]){
				bottom[i+1] = base[j];
				break;
			}
		}
	}
	
	char c;
	for(int i=1;i<2*n-1;i+=2){
		if(bottom[i]==bottom[i+1]){
			c = bottom[i-1];
			bottom[i-1] = bottom[i];
			bottom[i]   = c;
		}
	}
	
	bottom[2*n] = '\0';
	printf("%s\n",bottom);
	
	return 0;
}

