/*
Project name : Divide_Two_Integers
Created on : Sun Oct  5 14:30:58 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/divide-two-integers/
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
	llu mult(llu a , llu b){
		if(a==0||b==0){
			return 0;
		}
		if(a==1){
			return b;
		}
		if(b==1){
			return a;
		}
		if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}
		llu pow=a , val=0 , p=b;
		while(p>0){
			if((p&1)!=0){
				val += pow;
			}
			pow += pow;
			p = p>>1;
		}
		if(debug)cout<<a<<"*"<<b<<"="<<val<<endl;
		return val;
	}
	lld reverse(lld x){
		if(debug)cout<<"reversing sign of "<<x;
		x = ~x;
		x+= 1;
		if(debug)cout<<" to "<<x<<endl;
		return x;
	}
public:
	bool debug;
	int divide(int dividend, int divisor) {
		if(divisor==1){
            return dividend;
        }
        if(divisor==2){
            return dividend>>1;
        }
        int s1=0,s2=0;
        lld d=divisor , D=dividend;
        if(divisor<0){
        	if(debug)cout<<"negative divisor found"<<endl;
        	d = reverse(divisor);
        	s1 = 1;
        }
        if(dividend<0){
        	if(debug)cout<<"negative dividend found"<<endl;
        	D = reverse(dividend);
        	s2 = 1;
        }
        if(debug)cout<<"d:"<<d<<" D:"<<D<<endl;
        if(D<d){
        	return 0;
        }
		lld s=1,e=D,m;
		
		while(e>s+1){
			m=(s+e)/2;
			if(debug)cout<<"s:"<<s<<" e:"<<e<<" m:"<<m<<endl;
			if(mult(d,m)>D){
				e = m;
			}else{
				s = m;
			}
		}
		if(debug)cout<<"s1:"<<s1<<" s2;"<<s2<<endl;
		return s1+s2==1 ? reverse(s) : s;
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
	
	int D,d;
	while(t--){
		cin>>D>>d;
		cout<<s.divide(D,d)<<endl;
	}
	
	return 0;
}

