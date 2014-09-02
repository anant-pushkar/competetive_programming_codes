/*
Project name : CHEFBM
Created on : Sat May  3 12:59:28 2014
Author : Anant Pushkar
Codechef May challenge
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
bool compare(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.first < p2.first;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m , p ;
	scanf("%d %d %d",&n,&m,&p);
	
	vector<pair<int,int> > cmd(p);
	for(int i=0;i<p;++i){
		scanf("%d %d",&cmd[i].first,&cmd[i].second);
		--cmd[i].first;
		--cmd[i].second;
	}
	sort(cmd.begin() , cmd.end() , compare);
	
	int index = 0 , id , j;
	lld count;
	stack<int > delta;
	vector<int> freq(p+1,-1),num(m,0);
	for(int i=0;i<n;++i){
		count = m-1;
		if(index<p && cmd[index].first == i){
			for(j=0;j+index<p && cmd[j+index].first==i;++j) {
				freq[j]=cmd[j+index].second;
				num[cmd[j+index].second]=0;
				if(cmd[j+index].second!=0)num[cmd[j+index].second-1]=0;
				if(cmd[j+index].second!=m-1)num[cmd[j+index].second+1]=0;
			}
			sort(freq.begin(),freq.begin()+j);
			freq[j]=-1;
			index += j;
			
			for(j=0;freq[j]!=-1;++j){
				id=freq[j];++num[id];
				while(freq[j+1]==id){
					++j;
					++num[id];
				}
				delta.push(id);
			}
			
			while(!delta.empty()){
				id=delta.top();delta.pop();
				if(id!=m-1 && num[id]>num[id+1]+1){
					count=-1;
					break;
				}else{
					if(id!=m-1)count += num[id+1]-num[id];
					if(id!=0 && num[id-1]==0)count += num[id];
				}
			}
		}
		printf("%lld\n",count);
	}
	
	return 0;
}

