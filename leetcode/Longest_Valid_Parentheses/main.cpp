/*
Project name : Longest_Valid_Parentheses
Created on : Sat Sep  6 20:43:32 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/longest-valid-parentheses/
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
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if(size==0){
            return 0;
        }
        
        stack<char> st ;
        stack<int> count , idx;
        char top;
        int index , sum=0;
        for(int i=0;i<size;++i){
        	if(s[i]=='('){
        		st.push('(');
        		idx.push(i);
        	}else{
        		if(st.empty()){
        			sum=0;
        		}else if(st.top()=='('){
        			st.pop();
        			
        			index = idx.top();
        			idx.pop();
        			
        			if(st.empty()){
        				if(count.empty()){
        					sum = 0;
        				}else{
        					sum = count.top();
	        				count.pop();
	        			}
        				count.push(sum+2);
        			}else{
        				count.push(2);
        			}
        		}else if(st.top()==')'){
        			
        		}
        	}
        }
        int max=0;
        while(!count.empty()){
        	max = max<count.top() ? count.top() : max;
        	count.pop();
        }
        
        return max;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solution s;
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

