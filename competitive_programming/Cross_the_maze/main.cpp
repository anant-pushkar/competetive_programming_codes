/*
Project name : Cross_the_maze
Created on : Tue Oct 21 21:42:39 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2924486/dashboard#s=p3
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


const int EAST = 0;
const int SOUTH= 1;
const int WEST = 2;
const int NORTH= 3;


class Solver{
	bool solved;
	int n , sx , sy , ex , ey;
	vector<string> grid;
	queue<char> path;
	bool is_wall(int x , int y){
		if(x<0 || x>n-1 || y<0 || y>n-1 || grid[x][y]=='#'){
			return true;
		}
		return false;
	}
	pair<int,int> make_pos(const pair<int,int> &pos , const pair<int,int> &move){
		return make_pair(pos.first+move.first , pos.second+move.second);
	}
	void solve(){
		int count=0 , dir=SOUTH , i;
		pair<int,int> pos=make_pair(sx,sy) , left=make_pair(sx,sy+1) , next_pos , next_left;
		
		vector<pair<int,int> > moves(4);
		moves[EAST] = make_pair( 0,1);
		moves[NORTH]= make_pair(-1,0);
		moves[WEST] = make_pair(0,-1);
		moves[SOUTH]= make_pair( 1,0);
		
		vector<char> dir_name(4);
		dir_name[EAST] = 'E';
		dir_name[WEST] = 'W';
		dir_name[SOUTH] = 'S';
		dir_name[NORTH] = 'N';
		
		bool check;
		if(debug){
			cout<<"position:"<<pos.first<<","<<pos.second<<endl;
			cout<<"left    :"<<left.first<<","<<left.second<<endl;
			cout<<"direction: "<<dir_name[dir]<<endl;
		}
		while(count<10000 && ( pos.first!=ex || pos.second!=ey ) ){
			if(is_wall(pos.first , pos.second)){
				if(debug)cout<<"Game END"<<endl;
				solved=false;
				break;
			}
			
			if(is_wall(left.first , left.second)){
				next_pos = make_pos(pos , moves[dir]);
				next_left = make_pos(left , moves[dir]);
				
				check = false;
				for(i=0;i<4 && is_wall(next_pos.first , next_pos.second);++i){
					++dir;
					dir = dir%4;
					
					check = true;
					next_left = next_pos;
					next_pos = make_pos(pos , moves[dir]);
					if(debug)cout<<"direction: "<<dir_name[dir]<<endl;
				}
				
				if(check){
					next_left = make_pos(next_left , moves[dir]);
				}
			}else{
				next_pos = left;
				next_left = make_pos(left , moves[(dir+2)%4]);
				
				--dir;
				dir = (dir+4)%4;
				if(debug)cout<<"direction: "<<dir_name[dir]<<endl;
			}
			
			pos = next_pos;
			left = next_left;
			path.push(dir_name[dir]);
			++count;
			
			if(debug){
				cout<<endl<<endl<<"===================="<<endl;
				cout<<"position:"<<pos.first<<","<<pos.second<<endl;
				cout<<"left    :"<<left.first<<","<<left.second<<endl;
				cout<<"direction: "<<dir_name[dir]<<endl;
			}
		}
		solved = pos.first==ex && pos.second==ey;
	}
public:
	Solver(){
		cin>>n;
		grid = vector<string>(n);
		for(int i=0;i<n;++i){
			cin>>grid[i];
		}
		cin>>sx>>sy>>ex>>ey;
		--sx;
		--sy;
		--ex;
		--ey;
	}
	void print_soln(){
		solve();
		if(!solved){
			cout<<"Edison ran out of energy."<<endl;
			return;
		}
		cout<<path.size()<<endl;
		while(!path.empty()){
			cout<<path.front();
			path.pop();
		}
		cout<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	for(int t=1;t<=T;++t){
		Solver s;
		cout<<"Case #"<<t<<": ";
		s.print_soln();
	}
	
	return 0;
}

