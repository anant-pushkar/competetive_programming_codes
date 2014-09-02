/*
Project name : SERVICE
Created on : Wed Jan  8 10:33:14 2014
Author : Anant Pushkar
http://www.spoj.com/status/SERVICE
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 39999
typedef long long int lld;
int debug=0,n,l;
int cost[201][201] , query[1001];
lld lookup[SIZE],arr[SIZE];
int getIndex(int a , int b){
	int n1=a>b?a:b;
	int n2=a+b-n1;
	return n1*200+n2;
}
lld getDist(int a , int b , int index){
	if(debug)printf("called on %d %d %d\n",a,b,index);
	if(index==n)return 0;
	int idx=getIndex(a,b);
	if(mem[idx][index]!=-1){
		return mem[idx][index];
	}
	
	if(query[index]==a) mem[idx][index]=getDist(b,query[index-1],index+1);
	else if(query[index]==b) mem[idx][index]=getDist(a,query[index-1],index+1);
	else if(query[index]==query[index-1]) mem[idx][index]=getDist(a,b,index+1);
	else{
		lld d1 = cost[a][query[index]] + getDist(b,query[index-1],index+1);
		lld d2 = cost[b][query[index]] + getDist(a,query[index-1],index+1);
		lld d3 = cost[query[index-1]][query[index]] + getDist(a,b,index+1);
		lld d  = d1<d2?d1:d2;
		d = d3<d?d3:d;
		mem[idx][index]=d;
	}
	return mem[idx][index];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&l,&n);
		int i=0,j=0;
		for(i=0;i<l;++i)for(j=0;j<l;++j){
			scanf("%d",&cost[i][j]);
		}
		for(i=0;i<n;++i){
			scanf("%d",&query[i]);
			--query[i];
		}
		lld dist,d1,d2,d3;
		switch(query[0]){
			case 0:
				dist = getDist(1,2,1);
				break;
			case 1:
				dist = getDist(0,2,1);
				break;
			case 2:
				dist = getDist(1,0,1);
				break;
			default:
				d1 = getDist(1,2,1) + cost[0][query[0]];
				d2 = getDist(0,2,1) + cost[1][query[0]];
				d3 = getDist(1,0,1) + cost[2][query[0]];
				
				dist=d1<d2?d1:d2;
				dist=dist<d3?dist:d3;
				
				break;
		}
		printf("%lld\n",dist);
	}
	return 0;
}

