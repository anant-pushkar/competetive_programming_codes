/*
Project name : The_Child_and_Set
Created on : Tue Jul  1 15:25:46 2014
Author : Anant Pushkar
http://codeforces.com/contest/437/problem/B
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int getVal(int n){
	int val=1;
	if(debug)cout<<"n:"<<n;
	while((n&1)==0){
		val = val<<1;
		n = n>>1;
	}
	if(debug)cout<<" val:"<<val<<endl;
	return val;
}
bool isValid(queue<int> q , int sum){
	while(!q.empty()){
		sum -= getVal(q.front());
		q.pop();
	}
	return sum==0;
}
int getMax(int n){
	int sum=0;
	for(int i=1;i<=n;++i){
		sum += getVal(i);
	}
	return sum;
}
map<pair<int,int>,queue<int> > mem;
queue<int> getSoln(int sum , int limit , int max){
	if(sum>max || sum<1 || limit<1){
		return queue<int>();
	}
	if(mem.find(make_pair(sum,limit))!=mem.end()){
		return mem[make_pair(sum,limit)];
	}
	if(sum==max){
		queue<int>  q;
		for(int i=1;i<=limit;++i){
			q.push(i);
		}
		mem[make_pair(sum,limit)] = q;
		return q;
	}
	int v = getVal(limit);
	queue<int> q1 = getSoln(sum-v,limit-1,max-v);
	q1.push(limit);
	
	queue<int> q2 = getSoln(sum,limit-1,max-v);
	
	if(debug){
		cout<<"sum:"<<sum<<" lim:"<<limit<<" q1:"<<q1.size()<<" q2:"<<q2.size()<<endl;
	}
	
	queue<int>soln =  isValid(q1,sum) ? q1 : isValid(q2,sum) ? q2 : queue<int>();
	mem[make_pair(sum,limit)] = soln;
	return soln;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int sum , limit;
	scanf("%d %d",&sum,&limit);
	int max=getMax(limit);

	queue<int> soln = getSoln(sum,limit,max);
	if(soln.size()==0){
		printf("-1\n");
	}else{
		printf("%d\n",soln.size());
		while(!soln.empty()){
			printf("%d ",soln.front());
			soln.pop();
		}
		printf("\n");
	}
	return 0;
}

