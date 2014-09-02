/*
Project name : morgan-and-a-string
Created on : Sat May  3 14:45:04 2014
Author : Anant Pushkar
Hackerrank April Challenge
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
#define X 1
#define Y 2
#define size 100001
using namespace std;
bool debug=false;
typedef long long int lld;
char *str1 , *str2;
vector<vector<char> > charAdded;
vector<vector<int> > next;
void init(){
	str1 = new char[size];
	str2 = new char[size];
	
	charAdded = vector<vector<char> >(size,vector<char>(size));
	next = vector<vector<int> >(size,vector<int>(size));
}
bool isLessThan(){
	
}
char *getAns(int a , int b){
	if(a==0 && b==1)return str2 + strlen(str2) - 1 ;
	if(a==1 && b==0)return str1 + strlen(str1) - 1 ;
	
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	init();
	while(t--){
		scanf("%s",str1);
		scanf("%s",str2);
		
		printf("%s\n",getAns(strlen(str1),strlen(str2)));
	}
	return 0;
}

