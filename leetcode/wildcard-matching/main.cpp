/*
Project name : wildcard-matching
Created on : Fri Oct  3 18:20:53 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/wildcard-matching/
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
class Solution{
public:
	bool debug;
    bool isMatch(const char *s, const char *p) {
    	if(debug)cout<<"s : |"<<s<<"| p : |"<<p<<"|"<<endl;
        int i=0 , j=0 , k=-1 , index , n=strlen(s) , m=strlen(p);
        while(i<n){
        	if(debug)cout<<"i:"<<i<<" j:"<<j<<endl;
            if(j<m && p[j]=='?' || s[i]==p[j]){
                ++i;
                ++j;
            }else if(j<m && p[j]=='*'){
                k = j;
                index = i;
                ++j;
            }else if(k!=-1){
                j = k+1;
                i = index+1;
                ++index;
            }else{
	            return false;
	        }
        }
        while(j<m && p[j]=='*'){
        	++j;
        }
        return j==m;
    }
};


int main(int argc , char **argv)
{
	Solution soln;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		soln.debug=true;
	}else{
		soln.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	char s[1000] , p[1000];
	while(t--){
		scanf("%s %s",s,p);
		cout<<soln.isMatch(s,p)<<endl;
	}
	
	return 0;
}

