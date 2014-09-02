/*
Project name : Sort_the_Array
Created on : Thu Jul 24 21:16:30 2014
Author : Anant Pushkar
http://codeforces.com/contest/451/problem/B
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
const int INC = 1;
const int DEC = 2;
class Solver{
	int n;
	vector<int> a;
	stack<int> inc , dec;
	bool is_sortable;
	pair<int,int> pos;
	void populate_stack(){
		int state;
		
		if(a[0]<=a[1]){
			state = INC;
			inc.push(0);
		}else{
			state = DEC;
			dec.push(0);
		}
		
		for(int i=1;i<n-1;++i){
			if(state == INC){
				if(a[i]>a[i+1]){
					state = DEC;
					dec.push(i);
					inc.push(i);
				}
			}else if(state == DEC){
				if(a[i]<a[i+1]){
					state = INC;
					dec.push(i);
					inc.push(i);
				}
			}
		}
		
		if(state ==INC){
			inc.push(n-1);
		}else if(state==DEC){
			dec.push(n-1);
		}
	}
	int get_max(int start , int end){
		int max = INT_MIN;
		for(int i=start;i<end;++i){
			max = max<a[i] ? a[i] : max;
		}
		return max;
	}
	int get_min(int start , int end){
		int min = INT_MAX;
		for(int i=start;i<end;++i){
			min = min>a[i] ? a[i] : min;
		}
		return min;
	}
	bool validate_soln(){
		int max_left = get_max(0,pos.first-1);
		int min_right= get_min(pos.second,n);
		
		int max_seg  = get_max(pos.first-1,pos.second);
		int min_seg  = get_min(pos.first-1,pos.second);
		
		if(debug){
			cout<<max_left<<" "<<min_seg<<","<<max_seg<<" "<<min_right<<endl;
			cout<<pos.first<<" "<<pos.second<<endl;
		}
		
		return max_left<=min_seg && max_seg<=min_right ;
	}
	void solve(){
		if(inc.size()==2 && dec.size()==0){
			pos.first = 1;
			pos.second= 1;
		}else if((inc.size()%2==0 && inc.size()<=4) && dec.size()==2){
			pos.second = dec.top()+1;
			dec.pop();
		
			pos.first  = dec.top()+1;
			dec.pop();
		}
		is_sortable = validate_soln();
		/*if(is_sortable==false){
			while(pos.first>1 && a[pos.first-1]==a[pos.first-2]){
				if(debug)cout<<"first:"<<a[pos.first-1]<<" "<<a[pos.first-2]<<endl;
				--pos.first;
			}
			while(pos.second<n && a[pos.second-1]==a[pos.second]){
				if(debug)cout<<"second:"<<a[pos.second-1]<<" "<<a[pos.first-2]<<endl;
				++pos.second;
			}
			is_sortable = validate_soln();
		}*/
	}
public:
	Solver(int num):
	n(num),
	a(vector<int>(num)),
	is_sortable(false){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		populate_stack();
	}
	void print_soln(){
		solve();
		if(is_sortable){
			printf("yes\n%d %d\n",pos.first , pos.second);
		}else{
			printf("no\n");
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	s.print_soln();
	
	return 0;
}

