/*
Project name : Count_on_Cantor
Created on : Thu May 22 10:18:18 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CANTON/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,i,j,si,sj,pi,pj,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		i = ceil( (1 + sqrt(1+8*((double)n)))/4 );
		j = ceil( (-1 + sqrt(1+8*((double)n)))/4 );
		si= 2*(i-1)*(i-1) - i + 1;
		sj= 2*(j-1)*(j-1) + j - 1;
		pi= n-si;
		pj= n-sj;
		if(pi>2*i-1)x=4*i-2 - pi;
		else x=pi;
		if(pj>2*j)y=4*j-pj;
		else y=pj;
		printf("TERM %d IS %d/%d\n",n,x,y);
		
	}
	return 0;
}

