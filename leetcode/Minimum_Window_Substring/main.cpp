/*
Project name : Minimum_Window_Substring
Created on : Wed Oct  1 16:41:32 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/minimum-window-substring/
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
#include<map>
#include<unordered_set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solution{
public:
	bool debug;
	string minWindow(string S, string T) {
		int n=S.size() , m=T.size();
		if(n<m){
			return "";
		}
    	vector<int> expected_count(256 , 0) , running_count(256 , 0);
    	
    	for(int i=0;i<m;++i){
    		++expected_count[T[i]-0];
    	}
    	
    	int count = 0 , size , min_size=INT_MAX , index , start=0 , end=0 , min_start=INT_MAX , min_end=INT_MAX;
    	for(int i=0;i<n;++i){
    		index = S[i]-0;
    		++running_count[index];
    		if(running_count[index]<=expected_count[index]){
    			++count;
    		}
    		if(count==m){
    			end = i;
    			size = end-start+1;
    			if(size<min_size){
    				min_size = size;
    				min_start= start;
    				min_end  = end;
    			}
    			if(debug)cout<<i<<" : "<<start<<" , "<<end<<endl;
    			while(expected_count[S[start]-0]==0 || running_count[S[start]-0]>expected_count[S[start]-0]){
    				--running_count[S[start]-0];
    				++start;
    				size = end-start+1;
    				if(size<=min_size){
						min_size = size;
						min_start= start;
						min_end  = end;
					}
					if(debug)cout<<i<<" : "<<start<<" , "<<end<<endl;
    			}
    			if(debug)cout<<i<<" MIN :  "<<min_start<<" , "<<min_end<<endl;
    		}
    	}
    	if(debug)cout<<"Final : "<<min_start<<" , "<<min_end<<endl;
    	return min_start==INT_MAX ? "" : S.substr(min_start , min_end - min_start + 1);
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
	
	string S,T;	
	while(t--){
		cin>>S>>T;
		cout<<s.minWindow(S,T)<<endl;
	}
	
	return 0;
}

