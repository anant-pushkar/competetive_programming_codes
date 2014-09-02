/*
Project name : gem-stones
Created on : Sat May  3 13:46:21 2014
Author : Anant Pushkar
Hackerank April101
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
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	vector<int> count(26,0);
	vector<bool>visited(26) ;
	int N;
	scanf("%d",&N);
	char str[101];
	for(int n=0;n<N;++n){
		scanf("%s",str);
		visited = vector<bool>(26,false);
		for(int i=0;i<strlen(str);++i)if(!visited[str[i]-'a']){
			visited[str[i]-'a'] = true;
			++count[str[i]-'a'] ;
		}
	}
	int n=0;
	for(int i=0;i<26;++i)if(count[i]==N)++n;
	printf("%d\n",n);
	return 0;
}

