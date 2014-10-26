/*
Project name : Bad_Horse
Created on : Mon Oct 20 01:14:24 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2933486/dashboard
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
class Solver{
	vector<deque<int> >  adj_list;
	vector<int> type;
	bool visit(int node , int tp){
		if(type[node]!=-1){
			return tp==type[node];
		}
		
		type[node] = tp;
		for(int i=0;i<adj_list[node].size();++i){
			if(!visit(adj_list[node][i] , (tp+1)%2)){
				return false;
			}
		}
		
		return true;
	}
public:
	Solver(){
		int n;
		cin>>n;
		
		vector<string> a(n),b(n);
		for(int i=0;i<n;++i){
			cin>>a[i]>>b[i];
		}
		
		int index=0;
		map<string,int> index_of;
		for(int i=0;i<n;++i){
			if(index_of.find(a[i])==index_of.end()){
				index_of[a[i]] = index++;
			}
			if(index_of.find(b[i])==index_of.end()){
				index_of[b[i]] = index++;
			}
		}
		
		int x , y;
		adj_list = vector<deque<int> >(index);
		type  = vector<int>(index , -1);
		for(int i=0;i<n;++i){
			x = index_of[a[i]];
			y = index_of[b[i]];
			
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}
	}
	string solve(){
		for(int i=0;i<adj_list.size();++i)if(type[i]==-1){
			if(!visit(i , 0)){
				return "No";
			}
		}
		return "Yes";
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	for(int t=1;t<=T;++t){
		Solver s;
		cout<<"Case #"<<t<<": "<<s.solve()<<endl;
	}
	
	return 0;
}

