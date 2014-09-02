/*
Project name : Maze_Escape
Created on : Mon Jul 28 13:36:49 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/maze-escape
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
#include<ctime>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int id;
	scanf("%d",&id);
	
	string grid[3];
	for(int i=0;i<3;++i){
		cin>>grid[i];
	}
	
	queue<string> move_list;
	
    if(grid[0][1]=='e'){
        cout<<"UP"<<endl;
        return 0;
    }
    if(grid[2][1]=='e'){
        cout<<"DOWN"<<endl;
        return 0;
    }
    if(grid[1][0]=='e'){
        cout<<"LEFT"<<endl;
        return 0;
    }
    if(grid[1][2]=='e'){
        cout<<"RIGHT"<<endl;
        return 0;
    }
    
    if(grid[2][1]!='#'){
		if(grid[2][0]!='#'){
			move_list.push("DOWN");
		}
		if(grid[2][2]!='#'){
			move_list.push("DOWN");
		}
		move_list.push("DOWN");
	}
	
	if(grid[0][1]!='#'){
		if(grid[0][0]!='#'){
			move_list.push("UP");
		}
		if(grid[0][2]!='#'){
			move_list.push("UP");
		}
		move_list.push("UP");
	}
	
	if(grid[1][2]!='#'){
		if(grid[0][2]!='#'){
			move_list.push("RIGHT");
		}
		if(grid[2][2]!='#'){
			move_list.push("RIGHT");
		}
		move_list.push("RIGHT");
	}
	
	if(grid[1][0]!='#'){
		if(grid[0][0]!='#'){
			move_list.push("LEFT");
		}
		if(grid[2][0]!='#'){
			move_list.push("LEFT");
		}
		move_list.push("LEFT");
	}
	
	srand (time(NULL));
	int n = rand() % move_list.size()/2 + rand() % (move_list.size()-move_list.size()/2);
	for(int i=0;i<n;++i){
		move_list.pop();
	}
	cout<<move_list.front()<<endl;
	
	return 0;
}

