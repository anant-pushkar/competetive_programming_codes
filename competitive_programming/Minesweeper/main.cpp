/*
Project name : Minesweeper
Created on : Mon Oct 13 10:35:33 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/5214486/dashboard
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
	int n , mine , zero;
	vector<string> grid;
	vector<vector<int> > view;
	vector<vector<bool> > visited;
	queue<pair<int,int> > q;
	void visit(pair<int,int> pos){
		int x = pos.first;
		int y = pos.second;
		
		if(x<0 || x>n-1 || y<0 || y>n-1 || visited[x][y]){
			return;
		}
		
		if(debug)cout<<"called on "<<x<<","<<y<<endl;
		
		visited[x][y] = true;
		if(view[x][y]!=0){
			view[x][y] = -1;
			return;
		}
		view[x][y] = -1;
		
		visit(make_pair(x+1,y));
		visit(make_pair(x-1,y));
		visit(make_pair(x,y+1));
		visit(make_pair(x,y-1));
		
		visit(make_pair(x+1,y+1));
		visit(make_pair(x-1,y+1));
		visit(make_pair(x+1,y-1));
		visit(make_pair(x-1,y-1));
		
	}
	void create_view(){
		int count;
		view = vector<vector<int> >(n , vector<int>(n));
		visited = vector<vector<bool> >(n , vector<bool>(n , false));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(grid[i][j]=='*'){
					++mine;
					view[i][j] = -1;
				}else{
					count=0;
					if(i!=0)
						count += grid[i-1][j]=='*' ? 1 : 0;
					if(i!=n-1)
						count += grid[i+1][j]=='*' ? 1 : 0;
					if(j!=0)
						count += grid[i][j-1]=='*' ? 1 : 0;
					if(j!=n-1)
						count += grid[i][j+1]=='*' ? 1 : 0;
					if(i!=0 && j!=0)
						count += grid[i-1][j-1]=='*' ? 1 : 0;
					if(i!=0 && j!=n-1)
						count += grid[i-1][j+1]=='*' ? 1 : 0;
					if(i!=n-1 && j!=0)
						count += grid[i+1][j-1]=='*' ? 1 : 0;
					if(i!=n-1 && j!=n-1)
						count += grid[i+1][j+1]=='*' ? 1 : 0;
						
					view[i][j] = count;
					if(count==0){
						++zero;
						q.push(make_pair(i,j));
					}
				}
			}
		}
	}
public:
	Solver():
	mine(0),
	zero(0){
		scanf("%d",&n);
		grid = vector<string>(n);
		for(int i=0;i<n;++i){
			cin>>grid[i];
		}
	}
	int solve(){
		create_view();
		pair<int,int> pos;
		
		int count=0;
		while(!q.empty()){
			pos = q.front();
			q.pop();
			
			if(visited[pos.first][pos.second]){
				continue;
			}
			
			++count;
			visit(pos);
		}
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)if(view[i][j]!=-1){
				++count;
			}
		}
		
		if(debug){
			cout<<"count:"<<count<<" zero:"<<zero<<endl;
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<view[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		Solver s;
		printf("Case #%d: %d\n",t,s.solve());
	}
	
	return 0;
}

