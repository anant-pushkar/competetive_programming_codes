/*
Project name : Pouring_water
Created on : Wed Jun 11 15:43:26 2014
Author : Anant Pushkar
http://www.spoj.com/problems/POUR1/
a%b = -b*(a/b) + a
x*b  +  y*(a%b)  = c
x*b  +  y*(-(a/b)*b + a) = c
(x-y*(a/b))*b + y*a  =  c
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
	int t , a , b , c , x , y ;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		if(a<b){
			a = a^b ;
			b = a^b ;
			a = a^b ;
		}
		if(c==0){
			printf("0\n");
		}else if(c>a || (a==b && a!=c)){
			printf("-1\n");
		}else if(a==c || b==c){
			printf("1\n");
		}else if(c%(a-b)==0 && a!=b+1){
			printf("%d\n",3*(c/(a-b))-(c==a-b ? 1 : 0));
		}else{
			
		}
	}
	return 0;
}