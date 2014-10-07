/*
Project name : trapping_rainwater
Created on : Fri Oct  3 20:23:39 2014
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
class Solution{
	int get_min(int a , int b){
		return a<b ? a : b;
	}
public:
	bool debug;
	int trap(int A[] , int n){
		if(debug){
			cout<<"====================="<<endl;
			for(int i=0;i<n;++i){
				cout<<A[i]<<" ";
			}
			cout<<endl;
		}
		stack<int> s;
		int sum=0 , h , index , l;
		for(int i=0;i<n;++i){
			if(s.empty() || A[s.top()]>A[i]){
				if(debug)cout<<"Pushing "<<i<<":"<<A[i]<<endl;
				s.push(i);
			}else if(A[s.top()]==A[i]){
				if(debug)cout<<"replacing "<<s.top()<<" with "<<i<<" for h:"<<A[i]<<endl;
				s.pop();
				s.push(i);
			}else{
				while(!s.empty() && A[s.top()]<A[i]){
					index = s.top();
					s.pop();
				
					h = s.empty() ? 0 : get_min(A[s.top()] , A[i]) - A[index];
					l = s.empty() ? 0 : index-s.top() + i-index-1;
					if(debug)cout<<"calculaing : index:"<<index<<" h:"<<h<<" l:"<<l<<endl;
					sum += h*l;
				}
				
				if(!s.empty() && A[s.top()]==A[i]){
					if(debug)cout<<"replacing "<<s.top()<<" with "<<i<<" for h:"<<A[i]<<endl;
					s.pop();
					s.push(i);
				}else{
					if(debug)cout<<"Pushing "<<i<<":"<<A[i]<<endl;
					s.push(i);
				}
			}
			if(debug)cout<<"sum:"<<sum<<endl;
		}
		return sum;
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
		cout<<s.trap(A,n)<<endl;
	}
	
	return 0;
}

