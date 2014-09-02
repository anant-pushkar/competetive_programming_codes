/*
Project name : Sherlock_and_GCD
Created on : Mon Jul 21 20:00:34 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/sherlock-and-gcd
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int gcd(int a , int b){
	if(a<b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int has_pair(int a[] , int n){
	int i , j;
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			if(gcd(a[i],a[j])==1){
				if(debug)printf("%d %d\n",a[i],a[j]);
				return 1;
			}
		}
	}
	return 0;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n , a[100] , i , j;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		printf("%s\n",has_pair(a,n) ? "YES" : "NO");
	}
	return 0;
}
