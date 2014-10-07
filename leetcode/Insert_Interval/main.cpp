/*
Project name : Insert_Interval
Created on : Thu Oct  2 18:44:29 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/insert-interval/
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
class Solution{
	inline int get_min(int a , int b){
        return a<b ? a : b;
    }
    inline int get_max(int a , int b){
        return a>b ? a : b;
    }
public:
	bool debug;
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int n = intervals.size();
        if(n==0){
            result.push_back(newInterval);
            return result;
        }
        const int START = 1;
        const int END   = 2;
        int state , s , e ;
        bool new_added = false;
        if(newInterval.end<intervals[0].start){
        	if(debug)cout<<"adding newInterval as it preceeds the rest"<<endl;
            if(newInterval.end<intervals[0].start){
                state=END;
                result.push_back(newInterval);
                new_added = true;
            }else{
                state = START;
                s = newInterval.start;
            }
        }else{
            state = END;
        }
        for(int i=0;i<n;++i){
            switch(state){
                case START:
                    if(intervals[i].end>=s && intervals[i].start<=e){
                        e = get_max(intervals[i].end , newInterval.end);
                        if(debug)cout<<"Updated composite interval :"<<s<<" "<<e<<endl;
                    }else{
                    	if(debug)cout<<"Adding composite interval :"<<s<<" "<<e<<endl;
                        result.push_back(Interval(s,e));
                        
                        if(debug)cout<<"Adding non-coinciding interval :"<<intervals[i].start<<" "<<intervals[i].end<<endl;
                        result.push_back(intervals[i]);
                        state = END;
                    }
                    break;
                case END:
                    if(intervals[i].end>=newInterval.start && intervals[i].start<=newInterval.end){
                        state = START;
                        s = get_min(intervals[i].start , newInterval.start);
                        e = get_max(intervals[i].end , newInterval.end);
                        new_added = true;
                        if(debug)cout<<"Starting composite interval :"<<s<<" "<<e<<endl;
                    }else{
                    	if(!new_added && newInterval.end<intervals[i].end){
							if(debug)cout<<"adding newInterval as it succeeds the running intervals"<<endl;
							result.push_back(newInterval);
							new_added = true;
						}
						
                    	if(debug)cout<<"Adding non-coinciding interval :"<<intervals[i].start<<" "<<intervals[i].end<<endl;
                        result.push_back(intervals[i]);
                    }
                    break;
            }
        }
        if(state==START){
        	if(debug)cout<<"Adding composite interval :"<<s<<" "<<e<<endl;
            result.push_back(Interval(s,e));
            state = END;
        }
        if(!new_added){
        	if(debug)cout<<"adding newInterval as it succeeds the rest"<<endl;
            result.push_back(newInterval);
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
	
	int n , s , e , index;
	vector<Interval> intervals;
	while(t--){
		cin>>n;
		intervals=vector<Interval>(n);
		index = 0;
		for(int i=0;i<n;++i){
			cin>>s>>e;
			intervals[index++] = Interval(s,e);
		}
		cin>>s>>e;
		intervals = soln.insert(intervals , Interval(s,e));
		for(int i=0;i<intervals.size();++i){
			cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
		}
	}
	
	return 0;
}

