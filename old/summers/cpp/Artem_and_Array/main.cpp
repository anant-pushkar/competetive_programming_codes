/*
Project name : Artem_and_Array
Created on : Sat Jun 21 20:40:40 2014
Author : Anant Pushkar
http://codeforces.com/contest/442/problem/C
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
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	stack<int> s ;
	lld count = 0;
	s.push(arr[0]);
	for(int i=1;i<n-1;++i){
		if(s.top()>=arr[i]){
			count += s.top();
			if(debug)cout<<"count +="<<s.top()<<endl;
		}else{
			s.push(arr[i]);
			if(debug)cout<<"pushed "<<arr[i]<<endl;
		}
	}
	s.pop();
	while(!s.empty()){
		count += s.top();
		s.pop();
	}
	printf("%lld\n",count);
	return 0;
}

