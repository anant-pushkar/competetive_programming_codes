/*
Project name : Just_Next
Created on : Fri Aug 29 22:31:48 2014
Author : Anant Pushkar
http://www.spoj.com/problems/JNEXT/
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
	int n;
	vector<int> num;
	bool next(){
		int index = n-1;
		while(index>0 && num[index-1]>=num[index]){
			--index;
		}
		
		if(index==0){
			return false;
		}
		
		int i=n-1 , j;
		while(i>0 && num[i]<=num[index-1]){
			--i;
		}
		
		int temp = num[index-1];
		num[index-1] = num[i];
		num[i] = temp;
		
		i=index;
		j=n-1;
		while(i<j){
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			
			++i;
			--j;
		}
		
		return true;
	}
public:
	Solver(int x):
	n(x),
	num(vector<int>(x)){
		for(int i=0;i<n;++i){
			scanf("%d",&num[i]);
		}
	}
	void print_soln(){
		if(next()){
			for(int i=0;i<n;++i){
				printf("%d",num[i]);
			}
			printf("\n");
		}else{
			printf("-1\n");
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		s.print_soln();
	}
	
	return 0;
}



