/*
Project name : Feed_with_Candy
Created on : Tue Jun 17 14:07:15 2014
Author : Anant Pushkar
http://codeforces.com/contest/436/problem/A
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
struct Candy{
	int type , height , mass;
};
class Solver{
	int candyCount , initH;
	vector<Candy> candyList;
	vector<vector<int> > lookup;
	int getMax(int index , int h){
		if(index>=candyCount){
			return 0;
		}
		if(lookup[index][h]!=-1){
			if(debug)cout<<"memval at index:"<<index<<" h:"<<h<<" "<<lookup[index][h]<<endl;
			return lookup[index][h];
		}
		int n1 = getMax(index+1,h);
		int n2 = h>=candyList[index].height ? getMax(index+1,h+candyList[index].mass) : 0;
		lookup[index][h] = n1>n2+1 ? n1 : n2+1;
		if(debug)cout<<"val set at index:"<<index<<" h:"<<h<<" "<<lookup[index][h]<<endl;
		return lookup[index][h];
	}
public:
	Solver(int n , int x):
		candyCount(n),
		initH(x),
		candyList(vector<Candy>(n)){
			int h=0;
			for(int i=0;i<n;++i){
				scanf("%d %d %d" , &candyList[i].type , &candyList[i].height , &candyList[i].mass);
				h += candyList[i].height;
			}
			lookup = vector<vector<int> >(n , vector<int>(h,-1));
		}
	int solve(){
		return getMax(0,initH);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,x;
	scanf("%d %d",&n,&x);
	Solver s(n,x);
	printf("%d\n",s.solve());
	return 0;
}

