/*
Project name : ROCK
Created on : Sun Dec  8 18:00:59 IST 2013
http://www.spoj.com/problems/ROCK/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
bool debug=false;
int n;
char str[201];
vector<vector<int> >len;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,maxl;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",str);
		
		len=vector<vector<int> >(n,vector<int>(n,0));
		
		for(int i=0;i<n;++i){
			for(int j=i;j<n;++j){
				int count=0;
				for(int q=i;q<=j;++q)if(str[q]=='1')++count;
				
				int l=j-i+1;
				if(count>l-count)len[i][j]=l;
				else len[i][j]=count;
			}
		}
		
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				for(int k=i;k<j;++k)if(len[i][k]+len[k+1][j]>len[i][j])len[i][j]=len[i][k]+len[k+1][j];
			}
		}
		if(debug){
			for(int i=0;i<n;++i)printf("%c ",str[i]);
			printf("\n");
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					printf("%d ",len[i][j]);
				}
				printf("\n");
			}
		}
		printf("%d\n",len[0][n-1]);
	}
	return 0;
}

