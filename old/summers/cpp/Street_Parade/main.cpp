/*
Project name : Street_Parade
Created on : Sat May 24 16:19:32 2014
Author : Anant Pushkar
http://www.spoj.com/problems/STPAR/
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,arr[1001],exp;
	stack<int> s;
	while(true){
		scanf("%d",&n);
		while(!s.empty())s.pop();
		if(n==0)break;
		for(int i=0;i<n;++i)scanf("%d",&arr[i]);
		exp=1;
		for(int i=0;i<n;++i){
			if(debug)cout<<"arr : "<<arr[i]<<endl;
			if(debug)cout<<"expecting "<<exp<<endl;
			if(arr[i]!=exp){
				while(!s.empty() && exp==s.top()){
					if(debug)cout<<"poping "<<s.top()<<endl;
					s.pop();
					++exp;
					if(debug)cout<<"expecting "<<exp<<endl;
				}
				if(arr[i]!=exp){
					if(debug)cout<<"Pushing "<<arr[i]<<endl;
					s.push(arr[i]);
				}else ++exp;
			}else ++exp;
		}
		if(debug)cout<<"Expecting : "<<exp<<" , top : "<<s.top()<<endl<<endl;
		while(!s.empty() && exp==s.top()){
			if(debug)cout<<"poping "<<s.top()<<endl;
			s.pop();
			++exp;
			if(debug)cout<<"expecting "<<exp<<endl;
		}
		if(s.empty())printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

