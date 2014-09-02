/*
Project name : Candy_I
Created on : Thu May 15 16:19:07 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CANDY/
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
	int n , arr[10001] , i , sum , diff ;
	while(1){
		scanf("%d",&n);
		if(n==-1)break;
		sum = 0 ;
		for(i=0;i<n;++i){
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}
		sum /= n;
		diff=0;
		for(i=0;i<n;++i){
			diff += sum>arr[i] ? sum-arr[i] : 0;
		}
		printf("%d\n",diff);
	}
	return 0;
}
