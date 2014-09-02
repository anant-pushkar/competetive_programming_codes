/*
Project name : Pacman_-_UCS
Created on : Mon Jul 28 19:59:40 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/pacman-ucs
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
class Solver{
	int pc_x , pc_y , fd_x , fd_y , r , c;
	vector<string> grid;
	vector<vector<bool> > lookup;
	vector<vector<int> > parent_x , parent_y;
	queue<int> ucs_x , ucs_y;
	int get_heuristic_dist(int x , int y){
		if(x<0 || x>=r || y<0 || y>=c){
			return INT_MAX;
		}
		return abs(x-fd_x) + abs(y-fd_y);
	}
	void exchange(int &a , int &b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	int get_min_index(const deque<int> &x_arr , const deque<int> &y_arr , int start){
		int min_dist = INT_MAX , min_index = -1 , size = x_arr.size() , dist;
		for(int i=start;i<size;++i){
			dist = get_heuristic_dist(x_arr[i] , y_arr[i]);
			if(min_dist>dist){
				min_dist = dist;
				min_index= i;
			}
		}
		if(debug)cout<<"Min index from "<<start<<" is "<<min_index<<" : "<<x_arr[min_index]<<" "<<y_arr[min_index]<<endl;
		return min_index;
	}
	void print_deque(deque<int> &x_arr , deque<int> &y_arr){
		int size = x_arr.size();
		for(int i=0;i<size;++i){
			cout<<x_arr[i]<<","<<y_arr[i]<<" ";
		}
		cout<<endl;
	}
	void sort_heuristic(deque<int> &x_arr , deque<int> &y_arr){
		int size = x_arr.size() , index , i;
		
		for(i=0;i<size;++i){
			index = get_min_index(x_arr , y_arr , i);
			if(index==-1){
				break;
			}
			if(index==i){
				continue;
			}
			exchange(x_arr[i] , x_arr[index]);
			exchange(y_arr[i] , y_arr[index]);
		}
		while(x_arr.size()>i){
			x_arr.erase(x_arr.begin() + i);
			y_arr.erase(y_arr.begin() + i);
		}
		
		if(debug){
			cout<<"After reduce : ";
			print_deque(x_arr , y_arr);
		}
	}
	bool propogate(int x , int y , int px , int py){
		if(x<0 || x>=r || y<0 || y>=c){
			return false;
		}
		if(lookup[x][y] || grid[x][y]=='%'){
			return false;
		}
		
		if(debug)cout<<"Propogating "<<x<<" "<<y<<" from "<<px<<" "<<py<<endl;
		
		parent_x[x][y] = px;
		parent_y[x][y] = py;
		ucs_x.push(x);
		ucs_y.push(y);
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
		
		int x , y;
		deque<int> x_arr , y_arr;
		while(!ucs_x.empty()){
			x = ucs_x.front();
			ucs_x.pop();
			
			y = ucs_y.front();
			ucs_y.pop();
			
			if(lookup[x][y]){
				continue;
			}
			lookup[x][y] = true;
			
			x_arr.push_back(x-1);
			y_arr.push_back(y);
			
			x_arr.push_back(x+1);
			y_arr.push_back(y);
			
			x_arr.push_back(x);
			y_arr.push_back(y-1);
			
			x_arr.push_back(x);
			y_arr.push_back(y+1);
			
			sort_heuristic(x_arr , y_arr);
			for(int i=0;i<x_arr.size();++i){
				if(propogate(x_arr[i] , y_arr[i] , x , y)){
					return;
				}
			}
			
			x_arr.clear();
			y_arr.clear();
		}
		
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

