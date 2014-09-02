/*
Project name : Suffix_Structures
Created on : Thu Jul 17 19:47:03 2014
Author : Anant Pushkar
http://codeforces.com/contest/448/problem/
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
string s,t;
const char* checkTree(){
    vector<int> count(26,0);
    
    for(int i=0;i<t.size();++i){
        ++count[t[i]-'a'];
    }
    
    int index=0;
    for(int i=0;i<s.size();++i){
        --count[s[i]-'a'];
		if(s[i]==t[index]){
			++index;
		}
    }
    
    if(index==t.size()){
		return "automaton";
	}
    
    int zeroCount=0;
    for(int i=0;i<26;++i){
        if(count[i]>0 || (s.size()==t.size() && count[i]<0)){
            return "need tree";
        }
        if(count[i]==0){
			++zeroCount;
		}
    }
	return zeroCount==26 ? "array" : "both";
}
int main(int argc , char **argv)
{
    if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
    
    cin>>s>>t;
    if(s.size() < t.size()){
        printf("need tree\n");
    }else if(s.size() > t.size()){
        if(s.find(t)!=string::npos){
            printf("automaton\n");
        }else{
            printf("%s\n",checkTree());
        }
    }else{
        printf("%s\n",checkTree());
    }
    return 0;
}