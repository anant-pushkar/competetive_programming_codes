/*
Project name : Labyrinth
Created on : Mon Jun  9 11:43:10 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LABYR1/
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
class Solver{
	int nRow , nCol , x , y ,globalMaxPair;
	vector<vector<bool> > grid;
	queue<pair<int,int> > q;
	bool isFree(int x , int y){
		if(x<0 ||x>nRow ||y<0 || y>nCol)
			return false;
		return grid[x][y];
	}
	bool isLeaf(int x , int y){
		if(!isFree(x,y))
			return false;
		int count=0;
		count += isFree(x+1,y) ? 1 : 0;
		count += isFree(x-1,y) ? 1 : 0;
		count += isFree(x,y+1) ? 1 : 0;
		count += isFree(x,y-1) ? 1 : 0;
		return count == 1 ;
	}
	int getPairwiseMax(int arr[4]){
		int max = 0 , val;
		for(int i=0;i<4;++i){
			for(int j=i+1;j<4;++j){
				val = arr[i]+arr[j];
				max = max<val ? val : max;
				if(debug)cout<<"max pair : "<<arr[i]<<" , "<<arr[j]<<" , "<<val<<endl;
			}
		}
		return max;
	}
	int getMax(int arr[4]){
		int max=0 , val;
		for(int i=0;i<4;++i){
			val = arr[i];
			max = val<max ? max : val ;
		}
		return max;
	}
	int dfs(int x , int y , int px , int py){
		if(x<0 || x>=nCol || y<0 || y>=nRow || !isFree(x,y)){
			return 0;
		}
		if(debug)cout<<"DFS on "<<x<<","<<y<<" from "<<px<<","<<py<<endl;
		int a , b , c , d;
		a = x-1==px && y==py ? 0 : dfs(x-1,y,x,y);
		b = x+1==px && y==py ? 0 : dfs(x+1,y,x,y);
		c = x==px && y-1==py ? 0 : dfs(x,y-1,x,y);
		d = x==px && y+1==py ? 0 : dfs(x,y+1,x,y);
		int arr[4] = {a,b,c,d};
		int max = getMax(arr)+1;
		int maxPair = getPairwiseMax(arr);
		globalMaxPair = globalMaxPair<maxPair ? maxPair : globalMaxPair;
		if(debug)cout<<"returning with "<<max<<" from "<<x<<","<<y<<"p("<<px<<","<<py<<")"<<" , globalMaxPair : "<<globalMaxPair<<endl;
		return max;
	}
public:
	Solver(int c , int r):
		nRow(r),
		nCol(c),
		grid(vector<vector<bool> >(r , vector<bool>(c))){
		
		char str[nCol+1];
		for(int i=0;i<nRow;++i){
			scanf("%s",str);
			for(int j=0;j<nCol;++j){
				grid[i][j] = str[j]=='.';
			}
		}
		if(debug)cout<<"grid created. Searching for leaf"<<endl;
		for(int i=0;i<nRow;++i){
			for(int j=0;j<nCol;++j){
				if(isLeaf(i,j)){
					x=i;
					y=j;
					if(debug)cout<<"leaf at "<<x<<" , "<<y<<endl;
					return;
				}
			}
		}
	}
	int solve(){
		globalMaxPair=0;
		dfs(x,y,x,y);
		return globalMaxPair ;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , c , r;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&c,&r);
		Solver s(c,r);
		printf("Maximum rope length is %d.\n",s.solve());
	}
	return 0;
}

