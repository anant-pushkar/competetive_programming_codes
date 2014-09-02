/*
Project name : The_Simple_Coin_Game
Created on : Sat Aug  2 21:57:26 2014
Author : Anant Pushkar
2 2 +
1 2 -

1 1 -
2 0 +
2 1 +
0 3 +
1 3 +
2 3 -

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
int get_p(int n){
	int p=0;
	while(n>0){
		n = n>>1;
		++p;
	}
	return p;
}
class Solver{
	int x ,y;
	vector<vector<int> > lookup;
	int populate(int a , int b){
		if(lookup[a][b]!=INT_MAX){
			return lookup[a][b];
		}
		int sum=0 , x=0;
		for(int i=1;i<a;++i){
			sum += populate(i,b);
			++x;
		}
		for(int j=1;j<b;++j){
			sum += populate(a,j);
			++x;
		}
		if(sum!=x){
			lookup[a][b] = 1;
		}else{
			lookup[a][b]=0;
		}
		return lookup[a][b];
	}
public:
	Solver(int a , int b):
	x(a),
	y(b),
	lookup(vector<vector<int> >(a+1 , vector<int>(b+1, INT_MAX))){
		lookup[1][1] = 1;
		for(int i=1;i<lookup[1].size();++i){
			lookup[1][i] = 0;
		}
		for(int i=1;i<lookup.size();++i){
			lookup[i][1]=0;
		}
		populate(a,b);
	}
	string solve(int a , int b){
		return lookup[a][b]==1 ? "Play" : "No Play";
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , x , y;
	scanf("%d",&t);
	
	Solver s(43 , 43);
	
	while(t--){
		scanf("%d %d",&x,&y);
		cout<<s.solve(get_p(x),get_p(y))<<endl;
		
	}
	
	return 0;
}

