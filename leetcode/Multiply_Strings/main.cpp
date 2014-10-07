/*
Project name : Multiply_Strings
Created on : Fri Oct  3 19:40:52 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/multiply-strings/
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
#include<sstream>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solution{
public:
	bool debug;
	string multiply(string num1, string num2) {
		int n=num1.size() , m=num2.size();
		reverse(num1.begin() , num1.end());
		reverse(num2.begin() , num2.end());
		if(debug)cout<<"n:"<<n<<" m:"<<m<<endl;
		vector<llu> coeff(n+m , 0);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				coeff[i+j] += (num1[i]-'0')*(num2[j]-'0');
			}
		}
		llu carry=0 , val;
		for(int i=0;i<n+m;++i){
			val = coeff[i]+carry;
			coeff[i] = val%10;
			carry    = val/10;
		}
		stringstream ss;
		if(carry!=0){
			ss<<carry;
		}
		int index=n+m-1;
		while(index>-1 && coeff[index]==0){
			--index;
		}
		for(int i=index;i>-1;--i){
			ss<<coeff[i];
		}
        
		string result = ss.str();
        return result=="" ? "0" : result;
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
	
	string num1 , num2;
	while(t--){
		cin>>num1>>num2;
		cout<<s.multiply(num1,num2)<<endl;
	}
	
	return 0;
}

