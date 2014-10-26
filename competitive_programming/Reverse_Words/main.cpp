/*
Project name : Reverse_Words
Created on : Tue Oct 14 18:02:15 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/351101/dashboard#s=p1
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
void reverse(char *str , int l){
	int i=0 , j=l-1;
	char c;
	while(i<j){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		
		++i;
		--j;
	}
}
void contract(char *str){
	int n=strlen(str);
	int i=0 , j=0;
	while(j<n && isspace(str[j])){
		++j;
	}
	while(i<n && j<n){
		while(j<n && !isspace(str[j])){
			str[i++] = str[j++];
		}
		str[i++] = ' ';
		while(j<n && isspace(str[j])){
			++j;
		}
	}
	str[i] = '\0';
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	int i , j;
	char str[1001];
	cin.getline(str , 1001);
	for(int t=1;t<=T;++t){
		cin.getline(str , 1001);
		reverse(str , strlen(str));
		contract(str);
		i=0;
		j=1;
		while(j<strlen(str)){
			while(!isspace(str[j])){
				++j;
			}
			reverse(str+i , j-i);
			i=j+1;
			j=i+1;
		}
		printf("Case #%d: %s\n" , t , str);
	}
	
	return 0;
}

