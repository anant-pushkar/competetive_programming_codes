/*
Project name : Cavity_Map
Created on : Sat Jul 26 18:31:16 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101jul14/challenges/cavity-map
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
	vector<string> grid , final_grid;
	void solve(){
		for(int i=1;i<n-1;++i){
			for(int j=1;j<n-1;++j){
				if(grid[i+1][j]<grid[i][j] && grid[i-1][j]<grid[i][j] && grid[i][j+1]<grid[i][j] && grid[i][j-1]<grid[i][j]){
					final_grid[i][j] = 'X';
				}
			}
		}
	}
public:
	Solver(int num):
	n(num),
	grid(vector<string>(n)),
	final_grid(vector<string>(n)){
		for(int i=0;i<n;++i){
			cin>>grid[i];
			final_grid[i] = grid[i];
		}
		solve();
	}
	void print_map(){
		for(int i=0;i<n;++i){
			cout<<final_grid[i]<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	s.print_map();
	
	return 0;
}

