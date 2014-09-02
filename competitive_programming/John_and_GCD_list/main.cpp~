/*
Project name : John_and_GCD_list
Created on : Sat Aug  9 10:17:38 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w8/challenges/john-and-gcd-list
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
	vector<int> gcd_list;
	lld get_gcd(lld a , lld b){
		if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}
		if(a%b==0){
			return b;
		}
		return get_gcd(b , a%b);
	}
	stack<lld> get_soln(){
		stack<lld> s;
		s.push(gcd_list[0]);
		s.push(gcd_list[0]);
		
		lld x , gcd;
		for(int i=1;i<n;++i){
			if(s.top()%gcd_list[i]!=0){
				x = s.top();s.pop();
				gcd = get_gcd(x , gcd_list[i]);
				x *= gcd_list[i]/gcd;
				s.push(x);
			}
			s.push(gcd_list[i]);
		}
		
		stack<lld> soln;
		while(!s.empty()){
			soln.push(s.top());
			s.pop();
		}
		
		return soln;
	}
public:
	Solver(int x):
	n(x),
	gcd_list(vector<int>(x)){
		for(int i=0;i<n;++i){
			scanf("%d",&gcd_list[i]);
		}
	}
	void print_soln(){
		stack<lld> s = get_soln();
		while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<endl;
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


