/*
Project name : Distinct_Subsequences
Created on : Mon Sep 29 10:26:56 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/distinct-subsequences/
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
class Solution {
public:
    int numDistinct(string S, string T) {
        int n=S.size() , m=T.size();
        if(n<m){
            return 0;
        }
        vector<vector<int> > lookup(n , vector<int>(m,0));
        
        lookup[0][0] = S[0]==T[0] ? 1 : 0;
        for(int i=1;i<n;++i){
            lookup[i][0] = lookup[i-1][0] + (S[i]==T[0] ? 1 : 0);
        }
        
        int count;
        for(int i=1;i<m;++i){
            lookup[i][i] = S[i]==T[i] ? lookup[i-1][i-1] : 0;
            count = T[i]==S[i] ? 1 : 0;
            for(int j=i+1;j<n;++j){
                if(S[j]==T[i]){
                	++count;
                    lookup[j][i] = lookup[j-1][i-1] + lookup[j-1][i];
                }else{
                    lookup[j][i] = lookup[j-1][i];
                }
            }
        }
        
        if(debug){
        	cout<<"lookup : "<<endl;
        	cout<<"  ";
        	for(int i=0;i<n;++i){
        		cout<<S[i]<<" ";
        	}
        	cout<<endl;
        	for(int i=0;i<m;++i){
        		cout<<T[i]<<" ";
        		for(int j=0;j<n;++j){
        			cout<<lookup[j][i]<<" ";
        		}
        		cout<<endl;
        	}
        }
        
        return lookup[n-1][m-1];
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	Solution s;
	string S,T;
	while(t--){
		cin>>S>>T;
		cout<<s.numDistinct(S,T)<<endl;
	}
	
	return 0;
}

