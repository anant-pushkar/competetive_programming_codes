/*
Project name : subarrays
Created on : Thu Jun 12 15:12:53 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ARRAYSUB/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int getMax(int arr[] , int start , int end , int max){
	if(start==0 || max==arr[start-1] || max<arr[end-1]){
		int i;
		max = INT_MIN;
		for(i=start;i<end;++i){
			max = max<arr[i] ? arr[i] : max;
		}
	}
	return max;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , i , k , max=INT_MAX;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	for(i=0;i<=n-k;++i){
		max = getMax(arr,i,i+k,max);
		printf("%d ",max);
	}
	printf("\n");
	return 0;
}
