/*
Project name : Bear_and_Strings
Created on : Fri Jan 24 21:27:56 2014
Author : Anant Pushkar
codeforces 385: B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include <string> 
#include<set>
#include<queue>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string str;
	cin>>str;
	int s=str.size(),e=0;
	queue<int> q;
	size_t found=-1;
	while(1){
		found=str.find("bear",found+1,4);
		if(found==string::npos)break;
		if(debug)cout<<found<<endl;
		q.push(found);
		s=s>found?found:s;
		e=e<found+4?found+4:e;
	}
	if(debug)cout<<(s+3)<<" "<<(e-4)<<endl;
	int count=0;
	string temp;
	for(int i=0;!q.empty() && i<=q.front();++i){
		if(debug)cout<<endl<<q.front()<<endl;
		for(int j=(i>q.front()?i:q.front())+3;j<str.size();++j){
			++count;
			if(debug)cout<<i<<","<<j<<endl;
		}
		if(i==q.front())q.pop();
	}
	
	cout<<count<<endl;
	return 0;
}

