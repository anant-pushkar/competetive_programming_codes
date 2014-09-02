/*
Project name : Bye_Bye_Cakes
Created on : Mon Jun  9 11:12:28 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BYECAKES/
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
	vector<int> store , needed;
	int getMaxCake(){
		int maxCake = 0 , cake;
		for(int i=0;i<4;++i){
			if(needed[i]!=0){
				cake = store[i]/needed[i] + (store[i]%needed[i]==0 ? 0 : 1 );
				maxCake = cake>maxCake ? cake : maxCake ;
			}
		}
		return maxCake;
	}
public:
	Solver():
		store(vector<int>(4)),
		needed(vector<int>(4)){
		
		for(int i=0;i<4;++i){
			scanf("%d",&store[i]);
		}
		
		for(int i=0;i<4;++i){
			scanf("%d",&needed[i]);
		}
	}
	void printSoln(){
		int maxCake = getMaxCake();
		for(int i=0;i<4;++i){
			printf("%d ",needed[i]!=0 ? maxCake*needed[i]-store[i] : 0);
		}
		printf("\n");
	}
	bool isEnd(){
		bool check = true;
		for(int i=0;i<4;++i){
			check = check && (needed[i]==-1);
			check = check && (store[i] ==-1);
			if(!check)
				return false;
		}
		return check;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	while(true){
		Solver s;
		if(s.isEnd())
			break;
		s.printSoln();
	}
	return 0;
}

