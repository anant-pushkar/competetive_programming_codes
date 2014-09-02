/*
Project name : valera_and_fools
Created on : Sat Dec 14 13:00:29 IST 2013
http://codeforces.com/problemsituation/problem/369/D
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
bool debug=false;
int n,k;
vector<int> p;
int traverse(){
	queue<pair<int,int> > q;
	queue<int> bq;
	pair<int,int> state;
	int b,check0,count=0;;
	bool check100;
	vector<bool> cache100(n,false),cache0(n,false);
	vector<vector<bool> > lookup(n+3,vector<bool>(n+3,false));
	
	if(p[n-1]==100)cache100[n-1]=true;
	if(p[n-1]==0)cache0[n-1]=true;
	for(int i=n-2;i>=0;--i){
		cache100[i]=cache100[i+1];
		cache0[i]=cache0[i+1];
		
		if(p[i]==100)cache100[i]=true;
		if(p[i]!=0)cache0[i]=false;
	}
	
	q.push(make_pair(0,1));
	bq.push(k);
	lookup[0][1]=true;++count;
	
	while(!q.empty()){
		state=q.front();q.pop();
		b=bq.front();bq.pop();
		if(debug)cout<<state.first<<" "<<state.second<<" "<<b<<endl;
		if(b<=0 || state.first>=n || state.second>=n)continue;
		check100=cache100[state.second];
		check0=!cache0[state.second];
		if(!check100 && p[state.first]>0 && lookup[state.first][state.second+1]==false && state.second<n){
			q.push(make_pair(state.first,state.second+1));
			bq.push(b-1);
			lookup[state.first][state.second+1]=true;++count;
		}
		if(p[state.first]!=100 && check0!=0 && lookup[state.second][state.second+1]==false && state.second<n){
			q.push(make_pair(state.second,state.second+1));
			bq.push(b-1);
			lookup[state.second][state.second+1]=true;++count;
		}
		if(p[state.first]>0 && check0!=0 && lookup[state.second+1][state.second+2]==false && state.second<n){
			q.push(make_pair(state.second+1,state.second+2));
			bq.push(b-1);
			lookup[state.second+1][state.second+2]=true;++count;
		}
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d %d",&n,&k);
	p=vector<int>(n);
	for(int i=0;i<n;++i)scanf("%d",&p[i]);
	printf("%d\n",traverse());
	return 0;
}

