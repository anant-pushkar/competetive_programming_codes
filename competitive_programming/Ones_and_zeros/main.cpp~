/*
Project name : Ones_and_zeros
Created on : Wed Sep  3 13:05:00 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ONEZERO/
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
class Solver{
	int n;
	vector<int> parent;
	vector<char> digitlist;
	vector<bool> visited;
	queue<int> q;
	queue<char> c;
	queue<int> p;
	void visit(int state){
		if(visited[state]){
			return ;
		}
		visited[state]   = true;
		
		if(debug)cout<<"pushing "<<(10*state)%n<<" char 0"<<endl;
		q.push((10*state)%n);
		c.push('0');
		p.push(state);
		
		if(debug)cout<<"pushing "<<(10*state+1)%n<<" char 1"<<endl;
		q.push((10*state+1)%n);
		c.push('1');
		p.push(state);
	}
	void solve(){
		int state , par;
		char digit;
		
		while(!q.empty()){
			state = q.front();
			q.pop();
			
			par   = p.front();
			p.pop();
			
			digit = c.front();
			c.pop();
			
			if(visited[state]){
				continue;
			}
			
			if(debug)cout<<"visiting "<<state<<"char "<<digit<<endl;
			
			parent[state]    = par;
			digitlist[state] = digit;
			
			if(state==0){
				return;
			}
			
			visit(state);
		}
	}
public:
	Solver(int x):
	n(x),
	parent(vector<int>(x,-1)),
	digitlist(vector<char>(x,'\0')),
	visited(vector<bool>(x,false)){
		visit(1);
	}
	
	void print_soln(){
		if(n==1 || n==10 || n==11){
			printf("%d\n",n);
			return;
		}
		solve();
		int node =0;
		stack<char> s;
		while(parent[node]!=-1){
			s.push(digitlist[node]);
			node = parent[node];
		}
		s.push('1');
		
		while(!s.empty()){
			printf("%c",s.top());
			s.pop();
		}
		printf("\n");
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
		s.print_soln();
	}
	
	return 0;
}

