/*
Project name : Machau_vs_Maggu
Created on : Fri May 23 20:38:09 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MACVSMAG/
Hint : http://codeforces.com/blog/entry/10476
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
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
bool compare(const pair<int,int> &p1 ,const pair<int,int> &p2){
	return p1.first<p2.first;
}
class Graph{
	int n,m,ax,ay,bx,by;
	vector<pair<int,int> > booklist;
public:
	Graph(){
		scanf("%d %d %d %d %d %d",&n,&m,&ax,&ay,&bx,&by);
		int a,b;
		for(int i=0;i<m;++i){
			scanf("%d %d",&a,&b);
			booklist[i]=make_pair(a,b);
			sort(booklist.begin(),booklist.end(),compare);
		}
	}
	bool solve(){
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Graph g;
	bool soln = g.solve();
	printf("%s\n", soln ? "YAY MACHAU" : "MAGGU FOREVER");
	return 0;
}

