/*
Project name : Mixed_Up_Words
Created on : Sat Aug  2 21:02:21 2014
Author : Anant Pushkar
Mixed Up Words
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
	
	string str;
	int u_count , l_count;
	while(t--){
		cin>>str;
		
		u_count=0;
		l_count=0;
		
		for(int i=0;i<str.size();++i){
			if(isupper(str[i])){
				++u_count;
			}else{
				++l_count;
			}
		}
		
		if(u_count>l_count){
			for(int i=0;i<str.size();++i){
				cout<<(char)toupper(str[i]);
			}
			cout<<endl;
		}else{
			for(int i=0;i<str.size();++i){
				cout<<(char)tolower(str[i]);
			}
			cout<<endl;
		}
	}
	return 0;
}

