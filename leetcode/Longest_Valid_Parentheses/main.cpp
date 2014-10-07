/*
Project name : Longest_Valid_Parentheses
Created on : Sat Sep  6 20:43:32 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/longest-valid-parentheses/
()(()
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
#include<unordered_map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solution {
	inline int get_max(int a , int b){
		return a>b ? a : b;
	}
public:
	bool debug;
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0){
        	return 0;
        }
        int index , last_index=-1 , last_len=0 , l , max_len=0;
        stack<int> st;
        vector<int> len(n,0);
        for(int i=0;i<n;++i){
        	if(s[i]=='('){
        		if(debug)cout<<"pushing"<<endl;
        		st.push(i);
        	}else{
        		if(!st.empty()){
        			if(debug)cout<<"poping"<<endl;
        			index = st.top();
        			st.pop();
        			
        			l = i-index+1;
        			if(st.empty()){
        				if(last_index==index-1){
        					if(debug)cout<<"appending"<<endl;
        					last_len += l;
        				}else{
        					if(debug)cout<<"starting fresh"<<endl;
        					last_len  = l;
        				}
        				last_index = i;
        				max_len = get_max(max_len , last_len);
        				if(debug)cout<<"max:"<<max_len<<" last:"<<last_len<<" at "<<last_index<<endl;
        			}else{
        				if(debug)cout<<"remembering at "<<st.top()<<endl;
        				len[st.top()] += l;
        			}
        		}
        	}
        }
        max_len = get_max(max_len , last_len);
        if(debug)cout<<"max:"<<max_len<<" last:"<<last_len<<" at "<<last_index<<endl;
        for(int i=0;i<n;++i){
        	max_len = get_max(max_len , len[i]);
        }
        if(debug)cout<<"max : "<<max_len<<endl;
        return max_len;
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug=false;
	}
	
	string str;
	int t;
	scanf("%d",&t);
	
	while(t--){
		cin>>str;
		if(debug)cout<<str<<endl;
		cout<<s.longestValidParentheses(str)<<endl;
	}
	return 0;
}

