/*
Project name : Happy_Numbers_I
Created on : Mon May 26 21:13:56 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HPYNOS/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 811
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int count[SIZE];
void init(){
	int i;
	for(i=0;i<SIZE;++i)
		count[i]= -1;
	count[1]  = 1;
	count[10] = 2;
	count[100]= 2;
}
int getSum(int n){
	int sum=0 ;
	while(n>0){
		sum += (n%10)*(n%10);
		n /= 10;
	}
	return sum;
}
int getCount(int n){
	if(debug)printf("called on %d\n",n);
	if(n>=SIZE || n<10 || count[n]==0)
		return -1;
	if(count[n]!=-1)
		return count[n];
	int val = getCount(getSum(n));
	if(val==-1){
		count[n] = 0;
		return -1;
	}
	return val+1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	lld n;
	init();
	scanf("%lld",&n);
	printf("%d\n",getCount(getSum(n)));
	return 0;
}
