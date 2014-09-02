/*
Project name : Sorting_is_not_easy
Created on : Tue Jun 17 15:53:03 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LSORT/
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
class Solver{
	int size;
	vector<int> arr;
	vector<vector<lld> > lookup;
	lld getMinCost(int x , int y){
		if(x<0 || y<0 || x>size-1 || y>size-1){
			return (size/2)*(size/2)*(size-1)*(size-1);
		}
		if(lookup[x][y]!=-1){
			return lookup[x][y];
		}
		lld c1 = getMinCost(x+1,y) + arr[x]*(y-x+1);
		lld c2 = getMinCost(x,y-1) + arr[y]*(y-x+1);
		lookup[x][y] = c1<c2 ? c1 : c2;
		return lookup[x][y];
	}
	void print_lookup(){
		cout<<"arr : ";
		for(int i=0;i<size;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl<<"lookup : "<<endl;
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j){
				cout<<lookup[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
public:
	Solver(int n):
		size(n),
		arr(vector<int>(n)),
		lookup(vector<vector<lld> >(n,vector<lld>(n,-1))){
			int x;
			for(int i=0;i<n;++i){
				scanf("%d",&x);
				arr[x-1] = i+1;
			}
		}
	lld solve(){
		for(int i=0;i<size;++i){
			lookup[i][i] = arr[i];
		}
		int soln = getMinCost(0,size-1);
		if(debug)print_lookup();
		return soln;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%lld\n",s.solve());
	}
	return 0;
}

