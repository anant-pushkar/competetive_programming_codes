/*
Project name : Merge_Intervals
Created on : Thu Oct  2 19:03:47 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/merge-intervals/
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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool operator<(const Interval &i1 , const Interval &i2){
	return i1.start<i2.start;
}
class Solution{
	inline int get_max(int a , int b){
		return a>b ? a : b;
	}
	inline int get_min(int a , int b){
		return a<b ? a : b;
	}
public:
	bool debug;
	vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        int n = intervals.size();
        if(n==0){
        	return result;
        }
        sort(intervals.begin() , intervals.end());
        int i=0 , s , e;
        while(i<n){
        	s = intervals[i].start;
        	e = intervals[i].end;
        	if(debug)cout<<i<<"# s : "<<s<<" , e : "<<e<<endl;
        	while(i<n-1 && ( (intervals[i+1].start>=s && intervals[i+1].start<=e) || (intervals[i+1].end>=s && intervals[i+1].end<=e) )){
        		if(debug)cout<<"merging "<<intervals[i+1].start<<" "<<intervals[i+1].end<<endl;
        		e = get_max(intervals[i+1].end , e);
        		if(debug)cout<<"s : "<<s<<" , e : "<<e<<endl;
        		++i;
        	}
        	if(debug)cout<<"Adding "<<s<<" , "<<e<<endl;
        	result.push_back(Interval(s,e));
        	++i;
        }
        return result;
    }
};
int main(int argc , char **argv)
{
	Solution soln;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		soln.debug=true;
	}else{
		soln.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	int n , s , e;
	vector<Interval> intervals;
	while(t--){
		cin>>n;
		intervals = vector<Interval>(n);
		for(int i=0;i<n;++i){
			cin>>s>>e;
			intervals[i] = Interval(s,e);
		}
		intervals = soln.merge(intervals);
		cout<<intervals.size()<<endl;
		for(int i=0;i<intervals.size();++i){
			cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
		}
	}
	
	return 0;
}

