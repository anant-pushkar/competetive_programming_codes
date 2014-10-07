/*
Project name : Assistance_Required
Created on : Wed Oct  1 12:39:26 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ASSIST/
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
#include<list>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
deque<int> lucky;
void init(){
	vector<int> num(33809);
	for(int i=0;i<33809;++i){
		num[i] = i+2;
	}
	
	int n , m;
	list<int> active(num.begin() , num.end());
	list<int>::iterator it , tmp;
	while(!active.empty()){
		it = active.begin();
		n = *it;
		lucky.push_back(n);
		
		for(int i=0;it!=active.end();++i){
			if(i%n==0){
				it = active.erase(it);
			}else{
				++it;
			}
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	init();
	while(true){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		printf("%d\n",lucky[n-1]);
	}
	return 0;
}

