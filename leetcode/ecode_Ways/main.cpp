/*
Project name : ecode_Ways
Created on : Tue Sep 30 18:04:49 2014
Author : Anant Pushkar

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
    int numDecodings(string s) {
        int n = s.size() , val;
        if(n==0){
            return 0;
        }
        if(n==1){
            return s[0]=='0' ? 0 : 1;
        }
        if(n==2){
            val = 10*(s[0]-'0')+s[1]-'0';
            return (val>9 && val<27 ? 1 : 0) + (s[0]!='0' && s[1]!='0' ? 1 : 0);
        }
        vector<int>lookup(n+1 , 0);
        lookup[n] = 1;
        
        for(int i=n-1;i>-1;--i){
            lookup[i]  = s[i]!='0' ? lookup[i+1] : 0;
            val=10*(s[i]-'0') + s[i+1]-'0';
            lookup[i] += val>9 && val<27 ? lookup[i+2] : 0; 
        }
        
        if(debug){
        	for(int i=0;i<n;++i){
        		cout<<s[i]<<" ";
        	}
        	cout<<endl;
        	for(int i=0;i<n;++i){
        		cout<<lookup[i]<<" ";
        	}
        	cout<<endl;
        }
        
        return lookup[0];
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	Solution s;
	string str;
	while(t--){
		cin>>str;
		cout<<s.numDecodings(str)<<endl;
	}
	
	return 0;
}

