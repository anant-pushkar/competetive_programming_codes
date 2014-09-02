/*
Project name : Little_Pony_and_Crystal_Mine
Created on : Fri Aug  1 21:01:13 2014
Author : Anant Pushkar

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
	cin>>n;
	
	string s;
	stack<string> st;
	for(int i=0;i<n;++i){
		s = "";
		if(i<n/2){
			for(int j=0;j<n/2-i;++j){
				s += "*";
			}
			for(int j=0;j<2*i+1;++j){
				s += "D";
			}
			for(int j=n/2+i+1;j<n;++j){
				s += "*";
			}
			st.push(s);
			cout<<s<<endl;
		}else if(i==n/2){
			for(int j=0;j<n;++j){
				cout<<"D";
			}
			cout<<endl;
		}else{
			cout<<st.top()<<endl;
			st.pop();
		}
	}
	return 0;
}

