/*
Project name : Black_Widow_Rings
Created on : Sat Sep 20 18:13:07 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BWIDOW/
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n , max_inner , index;
	vector<int> inner , outer;
	bool check;
	while(t--){
		scanf("%d",&n);
		inner = vector<int>(n);
		outer = vector<int>(n);
		
		max_inner = 0;
		for(int i=0;i<n;++i){
			scanf("%d %d",&inner[i] , &outer[i]);
			if(max_inner<inner[i]){
				max_inner = inner[i];
				index = i;
			}
		}
		
		
		check = true;
		for(int i=0;i<n;++i)if(i!=index){
			if(outer[i]>=max_inner){
				check = false;
				printf("-1\n");
				break;
			}
		}
		if(check){
			printf("%d\n",index+1);
		}
		
	}
	
	return 0;
}

