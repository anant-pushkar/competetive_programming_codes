/*
Project name : hamburgar
Created on : Wed Dec 11 11:58:38 IST 2013
http://codeforces.com/problemset/problem/371/C

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int kb,nb,pb,ks,ns,ps,kc,nc,pc;
lld r;
lld getCost(lld n){
	lld ab=(n*kb-nb);ab=ab>0?ab:0;
	lld as=(n*ks-ns);as=as>0?as:0;
	lld ac=(n*kc-nc);ac=ac>0?ac:0;
	if(debug){
		printf("cost for : n=%lld \n",n);
		printf("cost of b : %lld\n",ab*pb);
		printf("cost of s : %lld\n",as*ps);
		printf("cost of c : %lld\n",ac*pc);
		printf("\n\n");
	}
	return ab*pb+as*ps+ac*pc;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char str[101];
	scanf("%s",str);
	int i;
	kb=0;ks=0;kc=0;
	for(i=0;i<strlen(str);++i){
		switch(str[i]){
		case 'B':
			++kb;
			break;
		case 'S':
			++ks;
			break;
		case 'C':
			++kc;
			break;
		}
	}
	scanf("%d %d %d",&nb,&ns,&nc);
	scanf("%d %d %d",&pb,&ps,&pc);
	scanf("%lld",&r);	
	if(debug){
		printf("kb=%d ks=%d kc=%d\n",kb,ks,kc);
		printf("nb=%d ns=%d nc=%d\n",nb,ns,nc);
		printf("pb=%d ps=%d pc=%d\n",pb,ps,pc);
		printf("r=%lld\n",r);
	}
	lld n=1;
	while(getCost(n)<=r)n*=2;
	lld start=n/2,end=n,mid=(start+end)/2,cost;
	while(end-start>1){
		cost=getCost(mid);
		if(debug)printf("start=%lld , end=%lld , cost=%lld\n",start,end,cost);
		if(cost>r)end=mid;
		else if(cost<r) start=mid;
		else break;
		mid=(start+end)/2;
	}
	if(cost==r)printf("%lld\n",mid);
	else printf("%lld\n",start);
	return 0;
}
