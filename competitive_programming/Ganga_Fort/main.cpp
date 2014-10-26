/*
Project name : Ganga_Fort
Created on : Thu Oct  9 23:05:17 2014
Author : Anant Pushkar
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=606&page=show_problem&problem=4746
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
const int START = 2;
const int END   = 1;
class Solver{
	int n , m , k;
	vector<pair<int,pair<int,int> > > event_list;
	inline int get_min(int a , int b){
		return a<b ? a : b;
	}
public:
	Solver(){
		scanf("%d %d %d",&n,&m,&k);
		event_list = vector<pair<int,pair<int,int> > >(m);
		
		int start , end , cost , index=0;
		for(int i=0;i<m;++i){
			scanf("%d %d %d",&start,&end,&cost);
			event_list[i] = make_pair(end,make_pair(start,cost) );
		}
		sort(event_list.begin() , event_list.end());
	}
	int solve(){
		if(event_list[0].second.first>=k || n-event_list[m-1].first>=k){
			return 0;
		}
	
		pair<int,pair<int,int> > pre = event_list[0];
		int i=1 , cost=event_list[0].second.second , min_cost=INT_MAX , pre_index=0 , bound=1;
		
		int last_interval , new_interval , gap , sum=cost;
		while(i<m){
			last_interval = event_list[i].second.first - bound;
			new_interval  = (i==m-1 ? n : event_list[i].first) - pre.first ;
			gap           = event_list[i].second.first - pre.first - 1;
			
			if(gap>=k && i==pre_index+1){
				return 0;
			}
			
			if(new_interval>=k && last_interval>=k){
				if(pre.second.second>event_list[i].second.second){
					cost -= pre.second.second;
					cost += event_list[i].second.second;
					bound = pre.first+1;
					pre   = event_list[pre_index+1];
					++pre_index;
				}
			}else if(new_interval>=k && last_interval<k){
				cost -= pre.second.second;
				cost += event_list[i].second.second;
				bound = pre.first+1;
				pre   = event_list[pre_index+1];
				++pre_index;
			}else if(new_interval<k && last_interval<k){
				cost += event_list[i].second.second;
			}else if(new_interval<k && last_interval>=k){
				cost += event_list[i].second.second;
			}
			
			if(new_interval>=k || last_interval>=k){
				min_cost = get_min(cost , min_cost);
			}
			
			sum += event_list[i].second.second;
			++i;
		}
		
		return min_cost==INT_MAX ? sum : min_cost;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	while(t--){
		Solver s;
		printf("%d\n",s.solve());
	}
	
	return 0;
}

