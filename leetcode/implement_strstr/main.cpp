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
	vector<int> get_failure_func(const char *str){
		int n=strlen(str);
		vector<int> ff(n,0);
		
		int i=0 , j=1;
		while(j<n){
			if(str[i]==str[j]){
				++i;
				ff[j] = i;
				++j;
			}else if(i>0){
				i = ff[i-1];
			}else{
				ff[j] = 0;
				++j;
			}
		}
		
		return ff;
	}
public:
	bool debug;
	char *strStr(char *haystack, char *needle) {
        int n=strlen(haystack) , m=strlen(needle);
        
        if(m==0){
            return haystack;
        }
        if(n==0){
            return NULL;
        }
        vector<int> ff = get_failure_func(needle);
        if(debug)cout<<haystack<<" "<<needle<<endl;
        int i=0 , j=0;
        while(j<n){
        	if(debug)cout<<"At"<<j<<" index:"<<i<<endl;
        	if(haystack[j]==needle[i]){
        		if(i==m-1){
        			return haystack+j-m+1;
        		}
        		++i;++j;
        	}else if(i>0){
        		i = ff[i-1];
        	}else{
        		++j;
        	}
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

