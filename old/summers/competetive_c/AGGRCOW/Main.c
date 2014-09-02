/*
Project name : AGGRCOW
Created on : Tue May  6 15:10:25 2014
Author : Anant Pushkar
Binary search over function
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 100001
typedef long long int lld;
int debug=0;
int n,c;
lld arr[SIZE];
int cmpfunc (const void * a, const void * b){
   return ( *(lld*)a - *(lld*)b );
}
int f(lld x){
	int count=1 , i ;
	lld pos=arr[0];
	for(i=1;i<n;++i)if(arr[i]-pos>=x){
		pos=arr[i];
		++count;
		if(count==c)return 1;
	}
	return 0;
}
lld search(){
	lld s=0 , e=arr[n-1]-arr[0]+1 , pos=arr[0];
	while(e-s>1){
		if(f((e+s)/2)==1)s=(e+s)/2;
		else e=(e+s)/2;
	}
	return s;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&c);
		for(i=0;i<n;++i)scanf("%lld",&arr[i]);
		qsort(arr, n, sizeof(lld), cmpfunc);
		printf("%lld\n",search());
	}
	return 0;
}
