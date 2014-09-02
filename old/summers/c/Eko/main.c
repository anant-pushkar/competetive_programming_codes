/*
Project name : Eko
Created on : Sun May 11 16:42:03 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EKO/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
lld n;
lld m;
lld *h;
int f(lld x){
	int i;
	lld sum=0;
	for(i=0;i<n;++i){
		sum += h[i]>x ? h[i]-x : 0;
		if(sum>=m)return 1;
	}
	return sum>=m;
}
lld search(lld min , lld max){
	lld s=min , e=max+1 , m;
	while(e-s>1){
		m = (e+s)/2;
		if(f(m)) s=m;
		else e=m;
	}
	return s;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	scanf("%lld %lld",&n,&m);
	h = (lld*)calloc(n,sizeof(lld));
	lld max = 0, min=1000000001;
	int i;
	for(i=0;i<n;++i){
		scanf("%lld",&h[i]);
		max = max<h[i] ? h[i] : max;
		min = min>h[i] ? h[i] : min;
	}
	printf("%lld\n",search(min,max));
	
	return 0;
}
