/*
Project name : play-game
Created on : Sun May  4 17:15:18 2014
Author : Anant Pushkar
Hackerank April Challenge
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define size 100001
int debug=0;
typedef long long int lld;
typedef struct {
	lld first;
	int second;
}pair;
int n;
int brick[size];
pair lookup[size];
pair make_pair(lld a , int b){
	pair p;
	p.first=a;
	p.second=b;
	return p;
}
pair getMax(int index){
	lld sum=0;
	if(index>n-4){
		if(debug)printf("terminal getMax(%d)\n",index);
		int i;
		for(i=n-1;i>=index;--i)sum += brick[i];
		if(debug)printf("getMax(%d) returning %lld,%d\n",index,sum,n-index);
		return make_pair(sum,n-index);
	}
	if(lookup[index].first!=-1){
		if(debug)printf("memoized getMax(%d)\n",index);
		return lookup[index];
	}
	if(debug)printf("getMax(%d)\n",index);
	pair m1=getMax(index+1),m2=getMax(index+2),m3=getMax(index+3);
	
	lld a = brick[index] + getMax(index+m1.second+1).first;
	lld b = brick[index] + brick[index+1] + getMax(index+m2.second+2).first;
	lld c = brick[index] + brick[index+1] + brick[index+2] + getMax(index+m3.second+3).first;
	lld d = a>b ? a>c ? a : c : b>c ? b : c;
	int id= a>b ? a>c ? 1 : 3 : b>c ? 2 : 3;
	
	if(debug)printf("getMax(%d) returning %lld,%d\n",index,d,id);
	return make_pair(d,id);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(debug)printf("n=%d\n",n);
		for(i=0;i<n;++i)scanf("%d",&brick[i]);
		if(debug)printf("initialising lookup\n");
		for(i=0;i<size;++i)lookup[i].first=-1;
		printf("%lld\n" , getMax(0).first);
	}
	return 0;
}
