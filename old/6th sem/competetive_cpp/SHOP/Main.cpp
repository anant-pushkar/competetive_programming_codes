/*
Project name : SHOP
Created on : Fri Mar  7 19:02:26 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SHOP/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool debug=false;
typedef long long int lld;
const int X=-1;
const int S=-2;
const int D=-3;
class Shop{
	vector<vector<int> > grid;
	int  height , width;
	pair<int,int> start,end;
	queue<pair<int,int> > q;
	queue<int> dist;
	vector<vector<int> > lookup;
	void propogate(pair<int,int> v , int d , int x , int y){
		if(x<0 || x>=height || y<0 || y>=width)return ;
		if(lookup[x][y]<d+(grid[x][y]==D?0:grid[x][y]) || grid[x][y]==X || grid[x][y]==S)return ;
		if(grid[x][y]==D){
			lookup[x][y]=d;
			return ;
		}
		
		if(debug)cout<<"Propogating to "<<x<<","<<y<<" with "<<d+grid[x][y]<<endl;
		q.push(make_pair(x,y));
		dist.push(d+grid[x][y]);
		lookup[x][y]=d+grid[x][y];
	}
public:
	Shop(int h,int w):
	height(h),
	width(w),
	grid(vector<vector<int> >(h,vector<int>(w,0))){
		string s;
		for(int i=0;i<h;++i){
			cin>>s;
			for(int j=0;j<w;++j){
				switch(s[j]){
					case 'X':
						grid[i][j]=X;
						break;
					case 'S':
						start=make_pair(i,j);
						grid[i][j]=S;
						break;
					case 'D':
						end=make_pair(i,j);
						grid[i][j]=D;
						break;
					default:
						grid[i][j]=s[j]-'0';
						break;
				}
			}
		}
	}
	int solve(){
		lookup = vector<vector<int> >(height,vector<int>(width,1<<30));
		
		q.push(start);
		dist.push(0);
		lookup[start.first][start.second]=true;
		
		pair<int,int> v;
		int d;
		while(!q.empty()){
			v=q.front();q.pop();
			d=dist.front();dist.pop();
			
			propogate(v,d,v.first+1,v.second);
			propogate(v,d,v.first-1,v.second);
			propogate(v,d,v.first,v.second+1);
			propogate(v,d,v.first,v.second-1);
		}
		return lookup[end.first][end.second];
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int h,w;
	while(true){
		cin>>h>>w;
		if(w==0 && h==0)break;
		Shop s(w,h);
		cout<<s.solve()<<endl;
	}
	return 0;
}

