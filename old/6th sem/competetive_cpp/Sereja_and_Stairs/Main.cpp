/*
Project name : Sereja_and_Stairs
Created on : Thu Jan 30 13:27:20 2014
Author : Anant Pushkar
codeforces 381 B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int m,n,max=0;scanf("%d",&m);
	vector<int> lookup(5001,0);
	for(int i=0;i<m;++i){
		scanf("%d",&n);
		++lookup[n];
		max=max>n?max:n;
	}
	queue<int> q;
	stack<int> s;
	for(int i=1;i<max;++i)if(lookup[i]>0){
		q.push(i);
		if(lookup[i]>1)s.push(i);
	}
	cout<<(q.size()+s.size()+1)<<endl;
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	printf("%d ",max);
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}

