/*
Project name : George_and_Number
Created on : Thu Feb  6 14:49:40 2014
Author : Anant Pushkar
codeforces 387 C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string s;
	cin>>s;
	
	int count=0,index=s.size()-1;
	while(index>=0){
		if(debug)cout<<index<<":"<<s[index]<<endl;
		if(s[index]=='0'){
			int n=0;
			while(index>=0 && s[index]=='0'){
				--index;
				++n;
			}
			if(index-n-1>=0 && s[index-n-1]-'0'>s[index]-'0'){
				++count;
			}else if(index-n-1>=0){
				index=index-n-1;
				count+=1;
			}else break;
			if(debug)cout<<"index="<<index<<endl;
		}else{
			if(index!=1 || s[0]>=s[1])++count;
		}
		if(debug)cout<<"count="<<count<<endl<<endl;
		--index;
	}
	
	cout<<count<<endl;
	return 0;
}

