/*
Project name : RRSTONE
Created on : Sat May  3 11:59:53 2014
Author : Anant Pushkar
Codechef May challenge
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , i;
	scanf("%d" , &n);
	
	lld k , arr[n] , max=LLONG_MIN , min=LLONG_MAX;
	scanf("%lld",&k);
	
	for(i=0;i<n;++i){
		scanf("%lld" , &arr[i]);
		max = arr[i]>max ? arr[i] : max;
		min = arr[i]<min ? arr[i] : min;
	}
	
	if(k==0){}
	else if(k%2==1){
		for(i=0;i<n;++i)arr[i] = max - arr[i];
	}else{
		for(i=0;i<n;++i)arr[i] = arr[i] - min;
	}
	
	for(i=0;i<n;++i)printf("%lld ",arr[i]);
	printf("\n");
	return 0;
}
