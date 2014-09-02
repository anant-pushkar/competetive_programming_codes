/*
Project name : RENT
Created on : Mon Dec  9 03:17:18 IST 2013
http://www.spoj.com/problems/RENT/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
struct Task{
	int start,end,val;
	
	Task(int s,int e,int v):
	start(s),
	end(e),
	val(v){}
	
	Task():
	start(-1),
	end(-1),
	val(-1){}
};
bool compare(const Task &t1 , const Task &t2){
	return t1.end<t2.end;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,st,d,p,index;scanf("%d",&t);
	lld val;
	vector<Task> list;
	vector<int> pre;
	vector<lld> lookup;
	while(t--){
		scanf("%d",&n);
		list=vector<Task>(n);
		pre =vector<int>(n);
		lookup=vector<lld>(n,0);
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&st,&d,&p);
			list[i]=Task(st,st+d,p);
		}
		sort(list.begin(),list.end(),compare);
		index=0;
		for(int i=0;i<n;++i){
			while(list[index].end<=list[i].start)++index;
			pre[i]=index-1;
		}
		lookup[0]=list[0].val;
		for(int i=1;i<n;++i){
			val=(pre[i]!=-1?lookup[pre[i]]:0)+list[i].val;
			for(int j=pre[i]+1;j<i;++j){
				val=val>lookup[j]?val:lookup[j];
			}
			lookup[i]=val;
		}
		if(debug){
			for(int i=0;i<n;++i)printf("%lld ",lookup[i]);
			printf("\n");
		}
		val=0;
		for(int i=0;i<n;++i)val=val>lookup[i]?val:lookup[i];
		printf("%lld\n",val);
	}
	return 0;
}

