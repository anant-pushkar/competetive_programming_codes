/*
Project name : The_Great_Ball
Created on : Wed Jul 30 12:51:48 2014
Author : Anant Pushkar
http://www.spoj.com/problems/BYTESE2/
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
const int START = 1;
const int END   = 2;
struct Event{
	int time , type;
	
	Event(int t , int tp):
	time(t),
	type(tp){
		
	}
	
	Event():
	time(-1),
	type(-1){
	
	}
	
	Event(const Event &e):
	time(e.time),
	type(e.type){
	
	}
};
ostream& operator<<(ostream &out , const Event &e){
	out<<"Time:"<<e.time<<" type:"<<(e.type==START?"Start":"End");
}
struct compare{
	bool operator()(const Event &e1 , const Event &e2){
		return e1.time > e2.time;
	}
};
class Solver{
	int n;
	priority_queue<Event , vector<Event> , compare> event_queue;
public:
	Solver(int num):
	n(num){
		int time;
		for(int i=0;i<n;++i){
			scanf("%d",&time);
			event_queue.push(Event(time , START));
			
			scanf("%d",&time);
			event_queue.push(Event(time , END));
		}
	}
	int solve(){
		int max = INT_MIN , count = 0;
		Event e;
		while(!event_queue.empty()){
			e = event_queue.top();
			event_queue.pop();
			
			if(debug)cout<<e<<endl;
			
			count += e.type==START ? 1 : -1;
			
			max = max<count ? count : max;
		}
		return max;
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
		printf("%d\n",s.solve());
	}
	return 0;
}

