/*
Project name : Subarray_LCM
Created on : Sun Sep 21 22:13:23 2014
Author : Anant Pushkar
http://www.codechef.com/COOK50/problems/SUBLCM
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int arr[100001];
int n;
int get_gcd(int a , int b){
	if(a<b){
		lld c = a;
		a = b;
		b = c;
	}
	return a%b==0 ? b : get_gcd(b , a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	
	int i , len , max , g;
	lld lcm;
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		len=1 ; 
		max=0 ; 
		lcm=arr[0];
		for(i=1;i<n;++i){
			g = get_gcd(lcm , arr[i]);
			if(g==1){
				++len;
				lcm = lcm * arr[i];
			}else{
				max = max<len ? len : max;
				len = 1;
				lcm = arr[i];
			}
		}
		max = max<len ? len : max;
		printf("%d\n" , max==1 ? -1 : max);
	}
	return 0;
}
