/*
Project name : collecting_beats
Created on : Wed Dec 18 13:03:30 2013
http://codeforces.com/contest/373/problem/A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int k;scanf("%d",&k);
	vector<int> count(10,0);
	char c;
	for(int i=0;i<4;++i){
		scanf("%c",&c);
		for(int j=0;j<4;++j){
			scanf("%c",&c);
			if(c!='.'){
				++count[c-'0'];
			}
		}
	}
	bool check=true;
	for(int i=0;i<10;++i)if(count[i]>2*k){
		if(debug)cout<<"limit passed at "<<i<<endl;
		check=false;
		break;
	}
	if(check)printf("YES\n");
	else printf("NO\n");
	return 0;
}

