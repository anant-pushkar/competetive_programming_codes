/*
Project name : Volcanoes
Created on : Mon Jan 20 22:26:58 2014
Author : Anant Pushkar
codeforces 384 : C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld n,m;
	cin>>n>>m;
	set<pair<lld,lld> > vol;
	lld a,b,d;
	while(m--){
		cin>>a>>b;
		vol.insert(make_pair(a-1,b-1));
	}
	queue<pair<lld,lld> > q;
	queue<lld> l;
	q.push(make_pair(0,0));
	l.push(0);
	lld dist=1<<29;
	bool check=false;
	while(!q.empty()){
		a=q.front().first;
		b=q.front().second;
		d=l.front();
		q.pop();l.pop();
		if(debug)cout<<a+1<<","<<b+1<<endl;
		if(a==n-1 && b==n-1){
			dist=d;
			check=true;
			break;
		}
		if(a+1<n && b<n && vol.find(make_pair(a+1,b))==vol.end()){
			q.push(make_pair(a+1,b));
			l.push(d+1);
		}
		if(a<n && b+1<n && vol.find(make_pair(a,b+1))==vol.end()){
			q.push(make_pair(a,b+1));
			l.push(d+1);
		}
	}
	cout<<(check?dist:-1)<<endl;
	return 0;
}

