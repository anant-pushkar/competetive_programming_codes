/*
Project name : BotClean
Created on : Mon Jul 28 09:34:51 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/botclean
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
struct Position{
	int x , y;
	
	Position():
	x(-1),
	y(-1){
	
	}
	
	Position(int a , int b):
	x(a),
	y(b){
	
	}
	
	Position(const Position &pos):
	x(pos.x),
	y(pos.y){
	
	}
};
ostream& operator<<(ostream& os, const Position& pos){
	os<<pos.x<<" "<<pos.y;
	return os;
}
istream& operator>>(istream& is, Position& pos)
{
  is>>pos.x>>pos.y;
  return is;
}
bool operator==(const Position &p1 , const Position &p2){
	return p1.x==p2.x && p2.y==p1.y;
}
class Solver{
	Position r_pos;
	vector<string> grid;
	deque<Position> dirty_cells;
	void find_dirty(){
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j){
				if(grid[i][j]=='d'){
					dirty_cells.push_back(Position(i,j));
					if(debug)cout<<"Found dirt at "<<i<<" "<<j<<endl;
				}
			}
		}
	}
	inline int get_dist(Position p1 , Position p2){
		return abs(p1.x-p2.x) + abs(p1.y-p2.y);
	}
	Position find_target(){
		int size = dirty_cells.size();
		int min_dist = INT_MAX , min_index=-1;
		int dist;
		for(int i=0;i<size;++i){
			dist = get_dist(r_pos,dirty_cells[i]);
			min_index = min_dist>dist ? i : min_index;
			min_dist = min_dist>dist ? dist : min_dist;
		}
		
		if(debug)cout<<"Heuristic dist from "<<r_pos<<" "<<min_dist<<" from "<<dirty_cells[min_index]<<endl; 
		return dirty_cells[min_index];
	}
public:
	Solver():
	grid(vector<string>(5)){
		cin>>r_pos;
		for(int i=0;i<5;++i){
			cin>>grid[i];
		}
	}
	void print_move(){
		find_dirty();
		Position target = find_target();
		if(debug)cout<<"target found at"<<target<<endl;
		if(target==r_pos){
			cout<<"CLEAN"<<endl;
		}else if(target.y>r_pos.y){
			cout<<"RIGHT"<<endl;
		}else if(target.y<r_pos.y){
			cout<<"LEFT"<<endl;
		}else if(target.x>r_pos.x){
			cout<<"DOWN"<<endl;
		}else{
			cout<<"UP"<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	s.print_move();
	return 0;
}

