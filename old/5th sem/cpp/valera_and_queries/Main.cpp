/*
Project name : valera_and_queries
Created on : Fri Dec 13 15:13:57 IST 2013
http://codeforces.com/contest/369/problem/E

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
bool debug=false;
bool compare(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.second<p2.second;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m;cin>>n>>m;
	vector<pair<int,int> > count(n);
	int s,e,sum;
	while(n--){
		scanf("%d %d",&s,&e);
		count[n]=make_pair(s,e);
	}
	sort(count.begin(),count.end(),compare);
	while(m--){
		scanf("%d",&n);
		set<int> seg;
		while(n--){
			scanf("%d",&s);
			if(debug)cout<<"Looking for "<<s<<endl;
			for(int i=lower_bound(count.begin(),count.end(),make_pair(0,s),compare)-count.begin();count[i].second>=s && i<count.size();++i){
				if(debug)cout<<"Finding at "<<i<<endl;
				if(count[i].first<=s && count[i].second>=s){
					if(debug)cout<<"Adding "<<i<<endl;
					seg.insert(i);
				}
			}
		}
		printf("%d\n",seg.size());
	}
	return 0;
}

