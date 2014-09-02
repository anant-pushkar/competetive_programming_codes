/*
Project name : Sereja_and_Brackets
Created on : Thu Jan 30 13:53:02 2014
Author : Anant Pushkar
codeforces 381 E
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
struct node{
	int start,end,count;
	deque<node*> children;
};
class tree{
	
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[1000001];
	scanf("%s",str);
	
	return 0;
}

