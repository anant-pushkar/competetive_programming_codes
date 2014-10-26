/*
Project name : Rational_Number_Tree
Created on : Tue Oct 21 21:00:03 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2924486/dashboard#s=p1
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
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
pair<llu,llu> get_pq(stack<bool> &s , llu p , llu q){
	if(s.empty()){
		return make_pair(p,q);
	}
	bool check = s.top();
	s.pop();
	if(!check){
		return get_pq(s , p , p+q);
	}else{
		return get_pq(s , p+q , q);
	}
}
void print_pq(llu n){
	stack<bool> s;
	pair<llu,llu> soln;
	while(n>1){
		s.push(n%2==1);
		n = n>>1;
	}
	soln = get_pq(s , 1 , 1);
	cout<<soln.first<<" "<<soln.second<<endl;
}
llu get_n(llu p , llu q){
	stack<bool> s;
	while(p!=1 || q!=1){
		if(p>q){
			s.push(true);
			p = p-q;
		}else{
			s.push(false);
			q = q-p;
		}
	}
	
	llu n=1;
	while(!s.empty()){
		n = n<<1;
		n = n|(s.top() ? 1 : 0);
		s.pop();
	}
	
	return n;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	llu tp , n , p , q;
	for(int t=1;t<=T;++t){
		cin>>tp;
		cout<<"Case #"<<t<<": ";
		if(tp==1){
			cin>>n;
			print_pq(n);
		}else{
			cin>>p>>q;
			cout<<get_n(p,q)<<endl;
		}
		
	}
	
	return 0;
}

