/*
Project name : PacMan_-_BFS
Created on : Mon Jul 28 18:45:16 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/pacman-bfs
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
	int pc_x , pc_y , fd_x , fd_y , r , c;
	vector<string> grid;
	vector<vector<bool> > lookup;
	vector<vector<int> > parent_x , parent_y;
	queue<int> bfs_x , bfs_y;
	bool propogate(int x , int y , int px , int py){
		if(x<0 || x>=r || y<0 || y>=c){
			return false;
		}
		if(lookup[x][y] || grid[x][y]=='%'){
			return false;
		}
		
		parent_x[x][y] = px;
		parent_y[x][y] = py;
		bfs_x.push(x);
		bfs_y.push(y);
		return x==fd_x && y==fd_y;
	}
public:
	Solver(){
		cin>>pc_x>>pc_y;
		cin>>fd_x>>fd_y;
		cin>>r>>c;
		
		lookup = vector<vector<bool> >(r , vector<bool>(c,false)); 
		parent_x = vector<vector<int> >(r , vector<int>(c)); 
		parent_y = vector<vector<int> >(r , vector<int>(c)); 
		grid   = vector<string>(r);
		
		for(int i=0;i<r;++i){
			cin>>grid[i];
			for(int j=0;j<c;++j){
				parent_x[i][j] = i;
				parent_y[i][j] = j;
			}
		}
	}
	
	void solve(){
		propogate(pc_x , pc_y , pc_x , pc_y);
		
		queue<int> exp_x , exp_y;
		int x , y;
		while(!bfs_x.empty()){
			x = bfs_x.front();
			bfs_x.pop();
			
			y = bfs_y.front();
			bfs_y.pop();
			
			if(lookup[x][y]){
				continue;
			}
			lookup[x][y] = true;
			
			exp_x.push(x);
			exp_y.push(y);
			
			if(propogate(x-1 , y , x , y) || propogate(x , y-1 , x , y) || propogate(x , y+1 , x , y) || propogate(x+1 , y , x , y)){
				break;
			}
		}
		cout<<exp_x.size()+1<<endl;
		while(!exp_x.empty()){
			cout<<exp_x.front()<<" "<<exp_y.front()<<endl;
			exp_x.pop();
			exp_y.pop();
		}
		cout<<fd_x<<" "<<fd_y<<endl;
	}
	void print_soln(){
		stack<int> sx , sy;
		int x = fd_x , y = fd_y , a , b;
		while(parent_x[x][y]!=x || parent_y[x][y]!=y){
			sx.push(x);
			sy.push(y);
			
			a = parent_x[x][y];
			b = parent_y[x][y];
			
			x=a;y=b;
		}
		cout<<sx.size()<<endl;
		cout<<pc_x<<" "<<pc_y<<endl;
		while(!sx.empty()){
			cout<<sx.top()<<" "<<sy.top()<<endl;
			sx.pop();
			sy.pop();
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	s.solve();
	s.print_soln();
	return 0;
}

