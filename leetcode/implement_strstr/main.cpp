/*
Project name : implement_strstr
Created on : Wed Oct  8 20:56:22 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/implement-strstr/
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
class Solution{
	vector<vector<int> > getDFS(char *str){
        int n = strlen(str);
        vector<vector<int> > dfs(n , vector<int>(256,0));
        dfs[0][str[0]-0] = 1;
        
        if(debug)cout<<"creating dfs for "<<str<<endl;
        int i=0 , j=1;
        while(j<n){
        	if(debug)cout<<"At "<<j<<endl;
            for(int x=0;x<256;++x){
                dfs[j][x] = dfs[i][x];
            }
            dfs[j][str[j]-0] = j+1;
            
            i = dfs[i][str[j]-0];
            ++j;
        }
        
        return dfs;
    }
public:
	bool debug;
	char *strStr(char *haystack, char *needle) {
        int n=strlen(haystack) , m=strlen(needle);
        if(debug)cout<<"n:"<<n<<" m:"<<m<<endl;
        if(n==0){
            return NULL;
        }
        if(m==0){
            return haystack;
        }
        vector<vector<int> > dfs = getDFS(needle);
        
        int state=0 , index=0;
        while(index<n){
        	if(debug)cout<<"At "<<index<<" state : "<<state<<endl;
        	if(debug)cout<<"going to "<<dfs[state][haystack[index]-0]<<endl;
            state = dfs[state][haystack[index]-0];
            if(state==m){
                return haystack+index-m+1;
            }
            ++index;
        }
        
        return NULL;
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
	
	int t;
	scanf("%d",&t);
	
	char h[10000] , n[100];
	while(t--){
		scanf("%s %s",h,n);
		cout<<s.strStr(h,n)<<endl;
		cout<<strstr(h,n)<<endl;
	}
	
	return 0;
}

