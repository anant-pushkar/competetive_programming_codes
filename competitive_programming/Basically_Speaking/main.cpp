/*
Project name : Basically_Speaking
Created on : Fri Aug 29 18:09:05 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BASE/
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
#include<ctype.h>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string num;
	int b1 , b2 , l;
	lld val , digit;
	bool check;
	stack<char> s;
	while(true){
		cin>>num;
		if(cin.eof()){
			break;
		}
		scanf("%d %d",&b1 , &b2);
		l = num.size();
		val=0;
		check=true;
		if(debug)cout<<"num : "<<num<<endl;
		for(int i=0;i<l;++i){
			digit = isdigit(num[i]) ? num[i]-'0' : num[i]-'A'+10;
			if(digit>=b1){
				check = false;
				break;
			}
			if(debug)cout<<digit<<" ";
			val = val*b1 + digit;
		}
		if(debug)cout<<endl;
		if(!check){
			printf("  ERROR\n");
			continue;
		}
		
		if(debug)cout<<"val : "<<val<<endl;
		
		while(val>0){
			digit = val%b2;
			s.push(static_cast<char>(digit<10 ? digit+'0' : digit+'A'-10));
			val /= b2;
		}
		
		if(s.size()>7){
			while(!s.empty()){
				s.pop();
			}
			printf("  ERROR\n");
			continue;
		}else{
			l = s.size();
			for(int i=0;i<7-l;++i){
				printf(" ");
			}
		}
		
		while(!s.empty()){
			printf("%c",s.top());
			s.pop();
		}
		printf("\n");
		
		if(debug)cout<<"============================"<<endl;
	}
	return 0;
}

