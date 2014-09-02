/*
Project name : Sherlock_and_MiniMax
Created on : Tue Jun 17 17:13:16 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101may14/challenges/sherlock-and-minimax
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n,p,q,left,right;
	deque<int> numList;
public:
	Solver(int num):
		n(num){
			vector<int> arr(n);
			for(int i=0;i<n;++i){
				scanf("%d",&arr[i]);
			}
			scanf("%d %d",&p,&q);
			
			left=0;right=INT_MAX;
			for(int i=0;i<n;++i){
				if(arr[i]>=p && arr[i]<=q){
					numList.push_back(arr[i]);
				}
				left = (arr[i]<p && arr[i]>left) ? arr[i] : left ;
				right = (arr[i]>q && arr[i]<right) ? arr[i] : right ;
			}
			if(debug)cout<<"left:"<<left<<" right:"<<right<<endl;
			if(left!=0){
				numList.push_back(left);
			}
			if(right!=INT_MAX){
				numList.push_back(right);
			}
			sort(numList.begin(),numList.end());
		}
	int solve(){
		int val,closest;
		if((numList[0]+numList[1])/2<p){
			val = p;
			closest = numList[1];
		}else{
			val = p;
			closest = numList[0];
		}
		int maxDist = abs(val-closest) , dist ,maxVal=val ;
		for(int i=1;i<numList.size();++i){
			if((numList[i-1]+numList[i])/2<q ){
				closest = numList[i-1];
				val = (numList[i-1]+numList[i])/2;
			}else{
				closest = numList[i-1];
				val = q;
			}
			dist = abs(closest-val);
			if(debug)cout<<"maxDist:"<<maxDist<<" maxVal:"<<maxVal<<" val:"<<val<<" closest:"<<closest<<" dist:"<<dist<<endl;
			if(dist>maxDist){
				maxDist = dist;
				maxVal  = val;
			}
		}
		if(numList[numList.size()-1]<q){
			val=q;
			closest=numList[numList.size()-1];
			dist = abs(closest-val);
			if(debug)cout<<"maxDist:"<<maxDist<<" maxVal:"<<maxVal<<" val:"<<val<<" closest:"<<closest<<" dist:"<<dist<<endl;
			if(dist>maxDist){
				maxDist = dist;
				maxVal  = val;
			}
		}
		if(debug)cout<<"maxDist:"<<maxDist<<" maxVal:"<<maxVal<<" val:"<<val<<" closest:"<<closest<<" dist:"<<dist<<endl;
		return maxVal;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	Solver s(n);
	printf("%d\n",s.solve());
	return 0;
}

