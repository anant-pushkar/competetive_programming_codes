/*
Project name : theatre_square
Created on : Sun Jan 12 21:08:35 2014
Author : Anant Pushkar
2010 Codeforces Beta Round #1 ProblemA
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long int lld;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld n,m,a;
	cin>>n>>m>>a;
	lld x=n/a + (n%a==0?0:1);
	lld y=m/a + (m%a==0?0:1);
	cout<<x*y<<endl;
	return 0;
}

