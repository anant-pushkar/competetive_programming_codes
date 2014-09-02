/*
Project name : Road_net
Created on : Mon Jun 16 14:26:46 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ROADNET/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n , net[200][200] , i , j , k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				scanf("%d",&net[i][j]);
			}
		}
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				for(k=0;k<n;++k){
					if(i!=k && j!=k && net[i][k]+net[k][j]==net[i][j]){
						break;
					}
				}
				if(k==n){
					printf("%d %d\n",i+1,j+1);
				}
			}
		}
		if(t>0){
			printf("\n");
		}
	}
	return 0;
}
