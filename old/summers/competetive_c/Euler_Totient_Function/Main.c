/*
Project name : Euler_Totient_Function
Created on : Thu May 29 14:26:24 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ETF/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define SIZE 1000001
int debug=0;
typedef long long int lld;
int lookup[SIZE];
void init(){
	lld i , j , p;
	for(i=0;i<SIZE;++i)
		lookup[i]=0;
	lookup[1]=1;
	for(i=2;i<SIZE;++i)if(lookup[i]==0){
		p=1;
		while(p*i<SIZE){
			lookup[p*i] = p*(i-1);
			p *= i;
		}
		for(j=2;j*i<SIZE;++j)if(lookup[j*i]==0){
			lookup[j*i] = -1;
		}
	}
}
int extract(int n , int p){
	int base=1 , index=n;
	while(n%p==0){
		base *= p;
		n /= p;
	}
	lookup[index] = lookup[base]*totient(n);
	return lookup[index];
}
int totient(int n){
	if(lookup[n]!=-1)
		return lookup[n];
	int i;
	if(n%2==0)
		return extract(n,2);
	
	for(i=3;i<sqrt(n)+1;i+=2)
		if(n%i==0)
			break;
	return extract(n,i);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n;
	scanf("%d",&t);
	init();
	while(t--){
		scanf("%d",&n);
		printf("%d\n",totient(n));
	}
	return 0;
}
