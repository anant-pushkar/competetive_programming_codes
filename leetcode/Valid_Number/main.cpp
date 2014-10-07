/*
Project name : Valid_Number
Created on : Thu Oct  2 12:33:12 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/valid-number/
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
public:
	bool debug;
	bool isNumber(const char *s) {
        int decimal=0 , exp=0 , n=strlen(s) , i=n-1;
        while(i>-1 && s[i]==' '){
        	if(debug)cout<<"skipping ending space at "<<i<<endl;
            --i;
            --n;
        }
        
        i = 0;
        while(i<n && s[i]==' '){
        	if(debug)cout<<"skipping starting space at "<<i<<endl;
            ++i;
        }
        
        if(s[i]=='+' || s[i]=='-'){
            ++i;
        }
        
        if(debug)cout<<"Starting check at "<<i<<"|"<<s[i]<<"|"<<endl;
        
        if(i==n || s[i]=='e' || s[i]==' ' || (s[i]=='.' && i!=n-1 && !isdigit(s[i+1]) )){
            return false;
        }
        
        bool has_digit=false;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ++i;
                has_digit = true;
                continue;
            }else if(s[i]=='.'){
                if(decimal!=0 || exp==1){
                    return false;
                }
                decimal = 1;
            }else if(s[i]=='e'){
                if( exp!=0 || i==0 || i==n-1 || (s[i-1]!='.' && !isdigit(s[i-1])) || ( !isdigit(s[i+1]) && s[i+1]!='-' && s[i+1]!='+' ) ){
                    return false;
                }
                exp = 1;
                if((s[i+1]=='-' || s[i+1]=='+') && (i!=n-2 && isdigit(s[i+2]))){
                    ++i;
                }
            }else{
                return false;
            }
            ++i;
        }
        return decimal==1 ? has_digit : true;
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
	
	char str[1000];
	while(t--){
		scanf("%s",str);
		cout<<s.isNumber(str)<<endl;
	}
	
	return 0;
}

