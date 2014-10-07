/*
Project name : First_Missing_Positive
Created on : Fri Oct  3 21:26:54 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/first-missing-positive/
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
	int get_min(int a , int b){
        return a<b ? a : b;
    }
    int get_max(int a , int b){
        return a>b ? a : b;
    }
public:
	bool debug;
	int firstMissingPositive(int A[], int n) {
		if(n==0){
			return 1;
		}
        int min=INT_MAX , max=INT_MIN;
        for(int i=0;i<n;++i){
            if(A[i]>0){
                min = get_min(min , A[i]);
                max = get_max(max , A[i]);
            }else{
                A[i] = 0;
            }
        }
        if(debug)cout<<"min : "<<min<<" max:"<<max<<endl;
        if(min==INT_MAX){
        	return 1;
        }
        if(min!=1){
        	return 1;
        }
        int x , index;
        for(int i=0;i<n;++i)if(A[i]!=INT_MIN && A[i]!=0){
            x = A[i] & INT_MAX;
            if(debug)cout<<"found "<<x<<endl;
            index = x-min;
            A[index] = A[index] | INT_MIN;
            if(debug)cout<<"index;"<<index<<" A:"<<A[index]<<endl;
        }
        
        if(debug){
        	cout<<"A :";
        	for(int i=0;i<n;++i){
        		cout<<A[i]<<" ";
        	}
        	cout<<endl;
        }
        
        for(int i=0;i<n;++i)if(A[i]>=0){
            return min+i;
        }
        return min==1 ? max+1 : min-1;
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
	
	int n;
	while(t--){
		cin>>n;
		int A[n];
		for(int i=0;i<n;++i){
			cin>>A[i];
		}
		cout<<s.firstMissingPositive(A,n)<<endl;
		if(s.debug)cout<<"============================="<<endl;
	}
	
	return 0;
}

