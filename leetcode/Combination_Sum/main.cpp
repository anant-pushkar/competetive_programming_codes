/*
Project name : Combination_Sum
Created on : Sat Oct  4 11:56:57 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/combination-sum/
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
#include<unordered_map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solution {
    vector<vector<int> > soln;
    int n;
    void create_soln(int target , vector<int> ans , int sum , unordered_map<int,int>::iterator freq , unordered_map<int,int>::iterator used , unordered_map<int,int>::iterator end){
        if(debug){
        	cout<<"====================\nans : ";
        	for(int i=0;i<ans.size();++i){
        		cout<<ans[i]<<" ";
        	}
        	cout<<endl;
        	cout<<"sum:"<<sum<<endl;
        }
        if(sum>=target){
            if(sum==target){
                soln.push_back(ans);
            }
            return;
        }
        while(freq!=end){
        	if(debug)cout<<"processing "<<freq->first<<":"<<freq->second<<" used "<<used->first<<":"<<used->second<<endl;
        	vector<int> v(ans.begin() , ans.end());
        	int tmp=sum;
        	while(tmp+freq->first <= target && freq->second > used->second){    	
        		v.push_back(freq->first);
        		tmp += freq->first;
        		if(debug)cout<<"adding "<<freq->first<<" tmp:"<<tmp<<endl;
        		create_soln(target , v , tmp , next(freq,1) , next(used,1) , end);
        		++used->second;
        	}
        	used->second = 0;
        	++freq;
        	++used;
        }
        if(debug){
        	cout<<"retruning from "<<sum<<endl;
        }
    }
public:
    bool debug;
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		//sort(candidates.begin() , candidates.end());
        n = candidates.size();
        if(debug){
        	cout<<n<<" candidates"<<endl;
        	for(int i=0;i<n;++i){
        		cout<<candidates[i]<<" ";
        	}
        	cout<<endl;
        }
        unordered_map<int,int> freq , used;
        for(int i=0;i<n;++i){
        	if(freq.find(candidates[i])==freq.end()){
        		freq[candidates[i]] = 1;
        		used[candidates[i]] = 0;
        		if(debug)cout<<"counting "<<candidates[i]<<endl;
        	}else{
        		++freq[candidates[i]];
        	}
        }
        vector<int> v;
        create_soln(target , v , 0 , freq.begin() , used.begin() , freq.end());
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
	
	int n , target;
	while(t--){
		cin>>n>>target;
		vector<int> c(n);
		for(int i=0;i<n;++i){
			cin>>c[i];
		}
		vector<vector<int> > soln = s.combinationSum2(c , target);
		cout<<soln.size()<<endl;
		for(int i=0;i<soln.size();++i){
			for(int j=0;j<soln[i].size();++j){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}

