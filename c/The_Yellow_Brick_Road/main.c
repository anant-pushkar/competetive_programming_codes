/*
Project name : The_Yellow_Brick_Road
Created on : Wed Sep 24 17:02:43 2014
Author : Anant Pushkar
http://www.spoj.com/problems/YELBRICK/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int get_gcd(int a , int b){
	if(a<b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	return a%b==0 ? b : get_gcd(b , a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , a[1000] , b[1000] , c[1000] , i , g_a , g_b , g_c , g;
	lld vol;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		vol = 0;
		for(i=0;i<n;++i){
			scanf("%d %d %d",&a[i] , &b[i] , &c[i]);
			vol += a[i]*b[i]*c[i];
		}
		g_a = a[0];
		g_b = b[0];
		g_c = c[0];
		for(i=1;i<n;++i){
			g_a = get_gcd(g_a , a[i]);
			g_b = get_gcd(g_b , b[i]);
			g_c = get_gcd(g_c , c[i]);
		}
		
		g = get_gcd( get_gcd(g_a , g_b) , g_c) ;
		printf("%lld\n",vol/(g*g*g));
	}
	return 0;
}
