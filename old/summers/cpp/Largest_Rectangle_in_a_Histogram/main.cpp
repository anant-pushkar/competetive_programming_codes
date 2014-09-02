/*
Project name : Largest_Rectangle_in_a_Histogram
Created on : Thu Jun 12 17:42:14 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HISTOGRA/
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
class Solver{
	vector<lld> heightArr;
public:
	Solver(int n):
		heightArr(vector<lld>(n)){
			for(int i=0;i<n;++i){
				scanf("%lld",&heightArr[i]);
			}
		}
	lld solve(){
		stack<lld> heightQ , indexQ , edgeQ;
		lld  max=0 , height , edge;
		int n = heightArr.size();
		for(int i=0;i<n;++i){
			while(!heightQ.empty() && heightQ.top()>=heightArr[i]){
				height = heightQ.top();
				edge   = edgeQ.top();
				indexQ.pop();
				heightQ.pop();
				edgeQ.pop();
				max = max<height*(i-edge-1) ? height*(i-edge-1) : max;
				if(debug)cout<<"Poped "<<height<<" area:"<<height*(i-edge-1)<<" max:"<<max<<endl;
			}
			edgeQ.push(heightQ.empty() ? -1 : indexQ.top());
			indexQ.push(i);
			heightQ.push(heightArr[i]);
			if(debug)cout<<"pushed "<<heightArr[i]<<"["<<i<<"]"<<" edge:"<<edgeQ.top()<<endl;
		}
		while(!heightQ.empty()){
			height = heightQ.top();
			edge   = edgeQ.top();
			indexQ.pop();heightQ.pop();edgeQ.pop();
			max = max<height*(n-edge-1) ? height*(n-edge-1) : max;
		}
		return max;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n ;
	while(true){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		Solver s(n);
		printf("%lld\n",s.solve());
	}
	return 0;
}

