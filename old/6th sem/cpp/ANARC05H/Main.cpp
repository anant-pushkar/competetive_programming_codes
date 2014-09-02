/*
Project name : ANARC05H
Created on : Sun Dec 29 16:45:12 2013
Author : Anant Pushkar
http://www.spoj.com/problems/ANARC05H/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
char str[26];
bool isGreater(int s1,int e1,int s2,int e2){
	if(e1-s1>e2-s2)return true;
	if(e1-s1<e2-s2)return false;
	for(int i1=s1,i2=s2;i1<e1;++i1,++i2){
		if(str[i1]>str[i2])return true;
		if(str[i1]<str[i2])return false;
	}
	return false;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	while(1){
	  scanf("%s",str);
	  if(strcmp(str,"bye")==0)break;
	  int l=strlen(str);
	}
	return 0;
}

