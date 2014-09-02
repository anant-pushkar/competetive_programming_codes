/*
Project name : ACM_ICPC_Team
Created on : Tue Jul  1 10:14:09 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w6/challenges/acm-icpc-team
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
typedef unsigned long long int llu;
int n,m;
vector<vector<int> > lookup;
int getMax(vector<char*> &topicList){
	int max=0 , count;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			count=0;
			for(int k=0;k<m;++k){
				if(topicList[i][k]=='1' || topicList[j][k]=='1'){
					++count;
				}
			}
			max = count>max ? count : max;
			lookup[i][j] = count;
		}
	}
	return max;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d %d",&n,&m);
	vector<char*> topicList(n);
	for(int i=0;i<n;++i){
		topicList[i] = new char[m+1];
		scanf("%s",topicList[i]);
	}
	lookup = vector<vector<int> >(n,vector<int>(n));
	int maxCount = getMax(topicList) , count=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(lookup[i][j]==maxCount){
				++count;
			}
		}
	}
	printf("%d\n%d\n",maxCount,count);
	return 0;
}

