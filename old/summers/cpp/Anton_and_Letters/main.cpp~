/*
Project name : Anton_and_Letters
Created on : Sun Jun 22 10:06:27 2014
Author : Anant Pushkar
http://codeforces.com/contest/443/problem/A
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
	char str[4];
	vector<bool> isPresent(26,false);
	scanf("%s",str);
	if(str[1]>='a' && str[1]<='z')isPresent[str[1]-'a'] = true;
	while(str[1]!='}' && str[0]!='}' && str[2]!='}'){
		scanf("%s",str);
		if(str[0]>='a' && str[0]<='z')isPresent[str[0]-'a'] = true;
	}
	if(debug){
		for(int i=0;i<26;++i){
			cout<<isPresent[i]<<" ";
		}
		cout<<endl;
	}
	int count=0;
	for(int i=0;i<26;++i){
		if(isPresent[i]){
			++count;
		}
	}
	printf("%d\n",count);
	return 0;
}

