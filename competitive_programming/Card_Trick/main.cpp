/*
Project name : Card_Trick
Created on : Wed Sep 24 15:28:31 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CTRICK/
5
4 5
3 5 4

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
#include<list>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
void print_queue(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
queue<int> populate(int n){
	queue<int> q;
	q.push(n);
	
	int v;
	for(int i=n-1;i>0;--i){
		for(int j=0;j<i+1;++j){
			v = q.front();
			q.pop();
			q.push(v);
		}
		q.push(i);
		if(debug){
			cout<<i<<" : ";
			print_queue(q);
		}
	}
	v = q.front();
	q.pop();
	q.push(v);
	return q;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	queue<int> q;
	stack<int> s;
	while(t--){
		scanf("%d",&n);
		q = populate(n);
		
		while(!q.empty()){
			s.push(q.front());
			q.pop();
		}
		
		while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<endl;
	}
	
	return 0;
}

