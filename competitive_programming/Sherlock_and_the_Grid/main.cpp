/*
Project name : Sherlock_and_the_Grid
Created on : Sun Sep 21 21:51:27 2014
Author : Anant Pushkar
http://www.codechef.com/COOK50/problems/GRID
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
	int n;
	vector<string> grid;
	vector<vector<int> > reach;
	
public:
	Solver(int x):
	n(x),
	reach(vector<vector<int> >(x , vector<int>(x,0))),
	grid(vector<string>(x)){
		for(int i=0;i<n;++i){
			cin>>grid[i];
		}
	}
	int solve(){
		for(int i=0;i<n;++i){
			for(int j=n-1;j>-1;--j){
				if(grid[i][j]=='#'){
					break;
				}
				++reach[i][j];
			}
		}
		for(int i=0;i<n;++i){
			for(int j=n-1;j>-1;--j){
				if(grid[j][i]=='#'){
					break;
				}
				++reach[j][i];
			}
		}
		int count = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				count += reach[i][j]==2 ? 1 : 0;
			}
		}
		
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

