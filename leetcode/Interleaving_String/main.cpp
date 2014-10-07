/*
Project name : Interleaving_String
Created on : Tue Sep 30 11:35:02 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/interleaving-string/
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
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()==0){
            return s2==s3;
        }
        if(s2.size()==0){
            return s1==s3;
        }
        
        int size1 = s1.size() , size2 = s2.size() , size3=s3.size();
        
        vector<int> count(256 , 0);
        for(int i=0;i<size1;++i){
            ++count[s1[i]-0];
        }
        for(int i=0;i<size2;++i){
            ++count[s2[i]-0];
        }
        for(int i=0;i<size3;++i){
            --count[s3[i]-0];
        }
        for(int i=0;i<256;++i){
            if(count[i]!=0){
                return false;
            }
        }
        
        vector<vector<int> > dp(size1+1 , vector<int>(size2+1 , 0));
        for(int i=1;i<=size1;++i){
            dp[i][0] = dp[i-1][0] + (s1[i-1]==s3[dp[i-1][0]] ? 1 : 0);
        }
        for(int i=1;i<=size2;++i){
            dp[0][i] = dp[0][i-1] + (s2[i-1]==s3[dp[0][i-1]] ? 1 : 0);
        }
        
        int v1 , v2;
        for(int i=1;i<=size1;++i){
            for(int j=1;j<=size2;++j){
                v1 = dp[i-1][j] + (s3[dp[i-1][j]]==s1[i-1] ? 1 : 0);
                v2 = dp[i][j-1] + (s3[dp[i][j-1]]==s2[j-1] ? 1 : 0);
                dp[i][j] = v1>v2 ? v1 : v2;
            }
        }
        
        if(debug){
        	cout<<"DP for "<<s3<<" : "<<endl;
        	cout<<"    ";
        	for(int i=0;i<size2;++i){
        		cout<<s2[i]<<" ";
        	}
        	cout<<endl;
        	for(int i=0;i<=size1;++i){
       			cout<<(i>0 ? s1[i-1] : ' ')<<" ";
        		for(int j=0;j<=size2;++j){
        			cout<<dp[i][j]<<" ";
        		}
        		cout<<endl;
        	}
        }
        
        return dp[size1][size2]==size3;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	Solution s;
	string s1,s2,s3;
	while(t--){
		cin>>s1>>s2>>s3;
		cout<<s.isInterleave(s1,s2,s3)<<endl;
	}
	return 0;
}

