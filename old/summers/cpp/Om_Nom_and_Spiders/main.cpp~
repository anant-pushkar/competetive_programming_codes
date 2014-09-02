/*
Project name : Om_Nom_and_Spiders
Created on : Tue Jun 17 14:36:19 2014
Author : Anant Pushkar
http://codeforces.com/contest/436/problem/B
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
struct Snake{
	int initX , initY;
	char direction;
	int getRelSpeed(){
		switch(direction){
			case 'U':
				return 2;
			case 'D':
				return 0;
			case 'L':
				return 1;
			case 'R':
				return 1;
		}
	}
	int getDeltaY(int t){
		switch(direction){
			case 'U':
				return 0;
			case 'D':
				return 0;
			case 'L':
				return -t;
			case 'R':
				return t;
		}
	}
};
class Solver{
	int rowCount , colCount , index;
	vector<Snake> snakeList;
	void processRow(char row[] , int i){
		for(int j=0;j<colCount;++j){
			if(row[j]!='.'){
				snakeList[index].initX = i;
				snakeList[index].initY = j;
				snakeList[index].direction = row[j];
				++index;
			}
		}
	}
	int getCollisionCol(Snake &s){
		int relSpeed = s.getRelSpeed();
		if( (relSpeed==2 && s.initX%2==1) || relSpeed==0 ){
			return -1;
		}
		int time = s.initX/relSpeed;
		int finalY = s.initY + s.getDeltaY(time);
		if(debug)cout<<"finalY : "<<finalY<<endl;
		return finalY;
	}
public:
	Solver(int n , int m , int k):
		rowCount(n),
		colCount(m),
		snakeList(vector<Snake>(k)){
			char row[m+1];
			scanf("%s",row);
			index=0;
			for(int i=1;i<n;++i){
				scanf("%s",row);
				processRow(row,i);
			}
		}
	vector<int> solve(){
		vector<int> soln(colCount,0);
		int colNum , snakeCount = snakeList.size();
		for(int i=0;i<snakeCount;++i){
			colNum = getCollisionCol(snakeList[i]);
			if(debug)cout<<"Collision for "<<snakeList[i].initX<<","<<snakeList[i].initY<<" : "<<colNum<<endl;
			if(colNum>=0 && colNum<colCount){
				++soln[colNum];
			}
		}
		return soln;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	Solver s(n,m,k);
	vector<int> soln = s.solve();
	for(int i=0;i<m;++i){
		printf("%d ",soln[i]);
	}
	printf("\n");
	return 0;
}

