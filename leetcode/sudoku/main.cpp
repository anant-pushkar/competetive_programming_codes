/*
Project name : sudoku
Created on : Sat Oct  4 13:39:14 2014
Author : Anant Pushkar

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
class Solution{
	deque<pair<int,int> > dot_list;
	deque<int> get_valid(const vector<vector<char> > &board , int x , int y){
		int used=0 , mask;
		for(int i=0;i<9;++i)if(board[x][i]!='.'){
			mask = 1<<(board[x][i]-'0');
			used = used|mask;
		}
		for(int i=0;i<9;++i)if(board[i][y]!='.'){
			mask = 1<<(board[i][y]-'0');
			used = used|mask;
		}
		int a = 3*(x/3) , b = 3*(y/3) ;
		for(int i=a;i<a+3;++i){
			for(int j=b;j<b+3;++j)if(board[i][j]!='.'){
				mask = 1<<(board[i][j]-'0');
				used = used|mask;
			}
		}
		mask=2;
		if(debug)cout<<"used list for "<<x<<","<<y<<" : "<<used<<endl;
		deque<int> val;
		for(int i=0;i<9;++i){
			if((mask&used)==0){
				val.push_back(i+1);
			}
			mask = mask<<1;
		}
		return val;
	}
	bool solve(vector<vector<char> > &board , int index){
		if(index==dot_list.size()){
			return true;
		}
		int x=dot_list[index].first , y=dot_list[index].second;
		deque<int> val = get_valid(board , x , y);
		if(val.size()==0){
			return false;
		}
		if(debug){
			cout<<"========================"<<endl;
			cout<<index<<" : looking for "<<x<<","<<y<<endl;
		}
		for(int i=0;i<val.size();++i){
			if(debug)cout<<"fitting "<<val[i]<<endl;
			board[x][y] = '0'+val[i];
			if(solve(board,index+1)){
				if(debug)cout<<"successful return from "<<index<<endl;
				return true;
			}
			board[x][y] = '.';
		}
		if(debug)cout<<"unsuccessful return from "<<index<<endl;
		return false;
	}
public:
	bool debug;
	void solveSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;++i){
        	for(int j=0;j<9;++j)if(board[i][j]=='.'){
        		dot_list.push_back(make_pair(i,j));
        	}
        }
        solve(board , 0);
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	string row;
	vector<vector<char> > grid(9 , vector<char>(9));
	while(t--){
		for(int i=0;i<9;++i){
			cin>>row;
			for(int j=0;j<9;++j){
				grid[i][j] = row[j];
			}
		}
		s.solveSudoku(grid);
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				cout<<grid[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}

