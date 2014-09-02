/*
Project name : Kundu_and_Tree
Created on : Mon Jun 23 09:48:49 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w5/challenges/kundu-and-tree
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
#define MOD 1000000007
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	vector<list<int> > adjList;
	vector<bool> lookup;
	int dfs(int v){
		if(lookup[v]){
			return 0;
		}
		lookup[v] = true;
		list<int>::iterator iter;
		int count=0;
		for(iter = adjList[v].begin() ; iter!=adjList[v].end() ; ++iter){
			count += dfs(*iter);
		}
		return count+1;
	}
	deque<lld> get_component_sizelist(){
		deque<lld> sizelist;
		int size;
		for(int i=0;i<n;++i){
			size = dfs(i);
			if(size!=0){
				sizelist.push_back(size);
			}
		}
		return sizelist;
	}
public:
	Solver(int num):
	n(num),
	adjList(vector<list<int> >(n)){
		int x , y;
		char color;
			for(int i=0;i<n-1;++i){
			scanf("%d %d %c",&x,&y,&color);
			if(color!='r'){
				--x;--y;
				adjList[x].push_back(y);
				adjList[y].push_back(x);
			}
		}
		lookup = vector<bool>(n,false);
	}
	int solve(){
		deque<lld> sizelist = get_component_sizelist();
		int l = sizelist.size();
		lld sum1=0;
		for(int i=0;i<l;++i){
			sum1 += sizelist[i];
			sum1 = sum1%MOD;
		}
		
		lld sum2=0;
		vector<lld> diff(n,0);
		for(int i=0;i<l;++i){
			sum1 -= sizelist[i];
			sum1  = (sum1+MOD)%MOD;
			
			sum2 += sum1*sizelist[i];
			sum2  = sum2%MOD;
			diff[i] = sum2;
		}
		
		lld sum3=0;
		for(int i=0;i<l;++i){
			sum3 += (sum2-diff[i]+MOD)*sizelist[i];
			sum3  = sum3%MOD;
		}
		
		return sum3%MOD;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	Solver s(n);
	printf("%d\n",s.solve());
	return 0;
}

