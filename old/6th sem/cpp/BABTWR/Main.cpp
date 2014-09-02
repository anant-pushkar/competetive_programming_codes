/*
Project name : BABTWR
Created on : Thu Dec 19 14:10:53 2013
http://www.spoj.com/problems/BABTWR/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
bool debug=false;
struct Block{
	int b1,b2,h,val;
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,a,b,c,index;
	vector<Block> dp;
	bool check;
	vector<deque<int> >adjList;
	queue<int>q;
	while(1){
		scanf("%d",&n);if(n==0)break;
		dp=vector<Block>(n*3);
		adjList=vector<deque<int> >(3*n);
		index=0;
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&a,&b,&c);
			
			dp[index].h=a;
			dp[index].val=a;
			dp[index].b1=b>c?b:c;
			dp[index++].b2=b>c?c:b;
			
			dp[index].h=b;
			dp[index].val=b;
			dp[index].b1=c>a?c:a;
			dp[index++].b2=c>a?a:c;
			
			dp[index].h=c;
			dp[index].val=c;
			dp[index].b1=a>b?a:b;
			dp[index++].b2=a>b?b:a;
		}
		for(int i=0;i<3*n;++i){
			for(int j=0;j<3*n;++j)if(dp[j].b1<dp[i].b1 && dp[j].b2<dp[i].b2){
				adjList[i].push_back(j);
			}
		}
		for(int i=0;i<3*n;++i)q.push(i);
		while(!q.empty()){
			a=q.front();q.pop();
			for(int i=0;i<adjList[a].size();++i)if(dp[adjList[a][i]].val<dp[a].val+dp[adjList[a][i]].h){
				q.push(adjList[a][i]);
				dp[adjList[a][i]].val=dp[a].val+dp[adjList[a][i]].h;
			}
		}
		a=0;
		for(int i=0;i<3*n;++i)a=a<dp[i].val?dp[i].val:a;
		printf("%d\n",a);
	}
	return 0;
}

