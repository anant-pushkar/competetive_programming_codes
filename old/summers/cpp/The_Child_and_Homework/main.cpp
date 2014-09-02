/*
Project name : The_Child_and_Homework
Created on : Tue Jul  1 15:11:41 2014
Author : Anant Pushkar
http://codeforces.com/contest/437/problem/A
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
inline int max(int a, int b , int c){
	return a>b ? a>c ? a : c : b>c ? b : c;
}
inline int min(int a , int b , int c){
	return a<b ? a<c ? a : c : b<c ? b : c;
}
char getSoln(int a , int b , int c , int d){
	int count=0;
	char soln;
	if(a>=2*max(b,c,d) || a<=min(b,c,d)/2){
		soln = 'A';
		++count;
	}
	if(b>=2*max(a,c,d) || b<=min(a,c,d)/2){
		soln = 'B';
		++count;
	}
	if(c>=2*max(b,a,d) || c<=min(b,a,d)/2){
		soln = 'C';
		++count;
	}
	if(d>=2*max(b,c,a) || d<=min(b,c,a)/2){
		soln = 'D';
		++count;
	}
	if(count!=1){
		return 'C';
	}
	return soln;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char a[103],b[103],c[103],d[103];
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	scanf("%s",d);
	printf("%c\n",getSoln(strlen(a)-2 , strlen(b)-2 , strlen(c)-2 , strlen(d)-2));
	return 0;
}

