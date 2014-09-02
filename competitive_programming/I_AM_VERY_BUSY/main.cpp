/*
Project name : I_AM_VERY_BUSY
Created on : Tue Aug 26 00:22:13 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BUSYMAN/
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
const int START = 2 ;
const int END   = 1 ;
struct Event{
	int time;
	int type;
	int index;
};
bool operator<(const Event &e1 , const Event &e2){
	return e1.time*2+e1.type < e2.time*2+e2.type;
}
class Solver{
	int n;
	vector<Event> event_list;
	vector<int> count;
public:
	Solver(int x):
	n(x),
	count(vector<int>(x)),
	event_list(vector<Event>(2*x)){
		for(int i=0;i<n;++i){
			scanf("%d %d",&event_list[2*i].time , &event_list[2*i+1].time);
			
			event_list[2*i].type  = START;
			event_list[2*i].index = i;
			
			event_list[2*i+1].type = END;
			event_list[2*i+1].index= i;
		}
		sort(event_list.begin() , event_list.end());
	}
	int solve(){
		int max_count = 0;
		for(int i=0;i<2*n;++i){
			switch(event_list[i].type){
				case START:
					count[event_list[i].index] = max_count + 1;
					break;
				case END:
					max_count = max_count>count[event_list[i].index] ? max_count : count[event_list[i].index];
					break;
			}
		}
		return max_count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

