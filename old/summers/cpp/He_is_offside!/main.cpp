/*
Project name : He_is_offside!
Created on : Sat May 24 20:45:30 2014
Author : Anant Pushkar
http://www.spoj.com/problems/OFFSIDE/
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
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m,d,a,d1,d2,a1;
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0)break;
		a1=INT_MAX;d1=INT_MAX;d2=INT_MAX;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			a1 = a1<a ? a1 : a ;
		}
		for(int i=0;i<m;++i){
			scanf("%d",&d);
			if(d1>d){
				d2=d1;
				d1=d;
			}else if(d2>d){
				d2=d;
			}
		}
		printf("%c\n",a1<d2 ? 'Y' : 'N');
	}
	return 0;
}

