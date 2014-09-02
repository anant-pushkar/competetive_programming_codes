/*
Project name : Ksenia_and_Pan_Scales
Created on : Mon Jan 20 16:32:55 2014
Author : Anant Pushkar
codeforces 382 : A
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
	int count[2]={0,0},index=0;
	char str[28];
	
	scanf("%s",str);
	int l=strlen(str);
	for(int i=0;i<l;++i){
		if(str[i]=='|')++index;
		else ++count[index];
	}
	
	char wt[28];
	scanf("%s",wt);
	l=strlen(wt);
	int diff=count[0]-count[1],n;
	diff=diff>0?diff:-diff;
	if(diff==0){
		if(l==0)printf("%s\n",str);
		else if(l%2!=0)printf("Impossible\n");
		else{
			index=0;
			while(str[index]!='|')printf("%c",str[index++]);
			for(int i=0;i<l/2;++i)printf("%c",wt[i]);
			while(index<strlen(str))printf("%c",str[index++]);
			for(int i=l/2;i<l;++i)printf("%c",wt[i]);
			printf("\n");
		}
	}else{
		n=count[0]+count[1]+l;
		if(n%2!=0 || l<diff)printf("Impossible\n");
		else{
			n/=2;
			index=0;
			while(str[index]!='|')printf("%c",str[index++]);
			for(int i=0;i<n-count[0];++i)printf("%c",wt[i]);
			while(index<strlen(str))printf("%c",str[index++]);
			for(int i=n-count[0];i<strlen(wt);++i)printf("%c",wt[i]);
			printf("\n");
		}
	}
	return 0;
}

