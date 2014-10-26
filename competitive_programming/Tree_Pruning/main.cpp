/*
Project name : Tree_Pruning
Created on : Thu Oct  9 09:00:53 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w11/challenges/tree-pruning
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
inline lld get_max(lld a , lld b){
	return a>b ? a : b;
}
void construct_removals(int node , int a , int b  , int k , const vector<lld> &wt , vector<int> &max_removals , vector<vector<lld> > &max_wt){
	if(debug)cout<<"merging "<<a+1<<","<<b+1<<" for "<<node+1<<" k:"<<k<<endl;
	int n=max_removals[a] , m=max_removals[b] , max_removal = 0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j)if(i+j<k+1){
			if(debug)cout<<"merging "<<i<<","<<j<<" : "<<max_wt[a][i] + max_wt[b][j] + wt[node]<<endl;
			max_wt[node][i+j] = get_max(max_wt[a][i] + max_wt[b][j] + wt[node] , max_wt[node][i+j]);
			max_removal = get_max(max_removal , i+j);
		}
	}
	max_removals[node] = get_max(max_removals[node] , max_removal);
}
void construct_removals(int node , int a , int k , const vector<lld> &wt , vector<int> &max_removals , vector<vector<lld> > &max_wt){
	if(debug)cout<<"merging "<<a+1<<" for "<<node+1<<" k:"<<k<<endl;
	int n=max_removals[a] , max_removal = 0;
	for(int i=0;i<=n;++i)if(i<k+1){
		if(debug)cout<<"merging "<<i<<" : "<<max_wt[a][i] + wt[node]<<endl;
		max_wt[node][i] = get_max(max_wt[a][i] +  wt[node] , max_wt[node][i]);
		max_removal = get_max(max_removal , i);
	}
	max_removals[node] = get_max(max_removals[node] , max_removal);
}

void print_removals(int node , const vector<vector<lld> > &max_wt , const vector<int> &max_removals){
	cout<<"MAX REMOVALS of "<<node+1<<" : ";
	for(int i=0;i<=max_removals[node];++i){
		cout<<max_wt[node][i]<<" ";
	}
	cout<<endl;
}
void visit(int node , int p , int k , const vector<deque<int> > &adj_list , const vector<lld> &wt , vector<int> &max_removals , vector<vector<lld> > &max_wt){
	if(debug)cout<<"visiting "<<node+1<<" from parent "<<p+1<<endl;
	int n=adj_list[node].size();
	
	if(n==1){
		max_wt[node][0] = wt[node];
		max_wt[node][1] = 0;
		max_removals[node] = 1;
		
		if(debug)print_removals(node , max_wt , max_removals);
		return ;
	}
	
	for(int i=0;i<n;++i)if(adj_list[node][i]!=p){
		visit(adj_list[node][i] , node , k , adj_list , wt , max_removals , max_wt);
		if(n==2 && node!=0){
			construct_removals(node,adj_list[node][i] , k , wt , max_removals , max_wt);
		}
	}
	
	for(int i=0;i<n;++i)if(adj_list[node][i]!=p){
		for(int j=i+1;j<n;++j)if(adj_list[node][j]!=p){
			construct_removals(node , adj_list[node][i] , adj_list[node][j] , k , wt , max_removals , max_wt);
		}
	}
	
	max_wt[node][1] = get_max(max_wt[node][1] , 0);
	max_removals[node] = get_max(1 , max_removals[node]);
	
	if(debug)print_removals(node , max_wt , max_removals);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , k;
	scanf("%d %d",&n,&k);
	
	vector<lld> wt(n);
	for(int i=0;i<n;++i){
		scanf("%lld",&wt[i]);
	}
	
	int a,b;
	vector<deque<int> > adj_list(n);
	for(int i=0;i<n-1;++i){
		scanf("%d %d",&a,&b);
		--a;--b;
		if(debug)cout<<"Adding edge between "<<a+1<<","<<b+1<<endl;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	
	vector<int> max_removals(n,-1);
	vector<vector<lld> > max_wt(n , vector<lld>(k+1,LLONG_MIN));

	visit(0,0,k,adj_list,wt,max_removals,max_wt);
	
	lld max=0;
	for(int i=0;i<=k;++i){
		max = get_max(max , max_wt[0][i]);
	}
	
	printf("%lld\n",max);
	
	return 0;
}

