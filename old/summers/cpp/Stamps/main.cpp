/*
Project name : Stamps
Created on : Sat May 24 12:17:12 2014
Author : Anant Pushkar
http://www.spoj.com/problems/STAMPS/
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
	int T;scanf("%d",&T);
	int n,m,count;
	vector<int> maxb(1000,0);
	for(int t=0;t<T;++t){
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;++i)scanf("%d",&maxb[i]);
		sort(maxb.begin(),maxb.begin()+m);
		count=0;
		for(int i=m-1;i>=0 && n>0;--i){
			n -= maxb[i];
			++count;
		}
		printf("Scenario #%d:\n",t+1);
		if(n<=0)printf("%d\n",count);
		else printf("impossible\n");
	}
	return 0;
}

