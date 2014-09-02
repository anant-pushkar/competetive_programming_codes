/*
Project name : CATM
Created on : Fri Mar  7 20:52:40 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CATM/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<queue>
using namespace std;
bool debug=false;
bool flag=false;
typedef long long int lld;
class Field{
	int n , m;
	pair<int,int> c1 , c2 , r;
	queue<pair<int,int> > cat , rat;
	vector<vector<int> >  cat_dist , rat_dist;
	void occupy(int x , int y){
		if(x>=0 && x<n && y>=0 && y<m && cat_dist[x][y]==1<<30){
			cat.push(make_pair(x,y));
			cat_dist[x][y]=cat_dist[cat.front().first][cat.front().second]+1;
		}
	}
	void move_cat(){
		while(!cat.empty()){
			occupy(cat.front().first+1,cat.front().second);
			occupy(cat.front().first-1,cat.front().second);
			occupy(cat.front().first,cat.front().second+1);
			occupy(cat.front().first,cat.front().second-1);
			cat.pop();
		}
	}
	void move(int x , int y ){
		if(x>=0 && x<n && y>=0 && y<m && rat_dist[x][y]==1<<30){
			rat.push(make_pair(x,y));
			rat_dist[x][y]=rat_dist[rat.front().first][rat.front().second]+1;
		}
	}
	void move_rat(){
		while(!rat.empty()){
			move(rat.front().first+1,rat.front().second);
			move(rat.front().first-1,rat.front().second);
			move(rat.front().first,rat.front().second+1);
			move(rat.front().first,rat.front().second-1);
			rat.pop();
		}
	}
public:
	Field(int a, int b):
	n(a),
	m(b){}
	
	void read(){
		while(!cat.empty())cat.pop();
		while(!rat.empty())rat.pop();
		scanf("%d %d %d %d %d %d",&r.first,&r.second,&c1.first,&c1.second,&c2.first,&c2.second);
		--r.first;--r.second;--c1.first;--c1.second;--c2.first;--c2.second;
		cat_dist=vector<vector<int> >(n,vector<int>(m,1<<30));
		rat_dist=vector<vector<int> >(n,vector<int>(m,1<<30));
		int sr=r.first+r.second;
		int sc1=c1.first+c1.second;
		int sc2=c2.first+c2.second;
		if((sr+sc1)%2==0){
			cat.push(c1);
			cat_dist[c1.first][c1.second]=0;
		}
		if((sr+sc2)%2==0){
			cat.push(c2);
			cat_dist[c2.first][c2.second]=0;
		}
		rat.push(r);
		rat_dist[r.first][r.second]=0;
	}
	
	bool solve(){
		move_cat();
		move_rat();
		for(int i=0;i<m;++i){
			if(rat_dist[0][i]<cat_dist[0][i]){
				return true;
			}
			if(rat_dist[n-1][i]<cat_dist[n-1][i]){
				return true;
			}
		}
		for(int i=0;i<n;++i){
			if(rat_dist[i][0]<cat_dist[i][0]){
				return true;
			}
			if(rat_dist[i][m-1]<cat_dist[i][m-1]){
				return true;
			}
		}
		return false;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	Field f(n,m);
	while(k--){
		f.read();
		if(f.solve())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

