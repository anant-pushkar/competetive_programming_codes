/*
Project name : Search_for_a_Range
Created on : Sat Oct  4 18:39:19 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/search-for-a-range/
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
class Solution{
typedef long long int lld;
typedef unsigned long long int llu;
	int search(int A[] , int n , int target){
        int s=0 , e=n , m;
        while(e>s+1){
            m = (e+s)/2;
            if(debug)cout<<"s:"<<s<<" e:"<<e<<endl;
            if(A[m]>target){
                e=m;
            }else{
                s=m;
            }
        }
        if(debug)cout<<"search for "<<target<<" returned "<<s<<endl;
        return s;
    }
public:
	bool debug;
	vector<int> searchRange(int A[], int n, int target){
		vector<int> soln(2);
		soln[0] = search(A,n,target-1);
		if(soln[0]!=n && A[soln[0]+1]==target && A[soln[0]]!=target){
			++soln[0];
		}
		if(soln[0]==n || A[soln[0]]!=target){
			soln[0] = -1;
			soln[1] = -1;
			return soln;
		}
		soln[1] = search(A,n,target);
		return soln;
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
	
	int n,x;
	while(t--){
		cin>>n>>x;
		int arr[n];
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		vector<int> soln = s.searchRange(arr,n,x);
		cout<<soln[0]<<" "<<soln[1]<<endl;
	}
	
	return 0;
}

