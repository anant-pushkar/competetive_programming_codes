/*
Project name : Prime_Sum
Created on : Wed May 21 22:37:37 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w3/challenges/prime-sum
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,soln;scanf("%d",&t);
	llu n,k;
	while(t--){
		scanf("%llu %llu",&n,&k);
		if(k==1){
			if(n==1) soln = 0;
			else if(n%2==0)soln= (n==2);
			else{
				soln=1;
				for(llu i=3;i<=sqrtl(n)+1;i+=2)if((n%i)==0){
					soln=0;
					break;
				}
			}
		}else if(k>n/2)soln=0;
		else soln=1;
		printf("%s\n",soln ? "Yes" : "No");
	}
	return 0;
}
