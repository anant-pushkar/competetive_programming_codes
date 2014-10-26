/*
Project name : Broken_Calculator
Created on : Mon Oct 13 11:22:56 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/5214486/dashboard#s=p2
*/
#include<iostream>
#include<sstream>
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
class Solver{
	int target;
	vector<bool> is_usable;
	unordered_map<int,int> mem;
	int get_clicks(int n){
		if(mem.find(n)!=mem.end()){
			return mem[n];
		}
		if(debug)cout<<"calculating "<<n<<endl;
		int tmp=n , c=0;
		while(tmp>0){
			if(!is_usable[tmp%10]){
				break;
			}
			++c;
			tmp /=10;
		}
		if(debug)cout<<"tmp:"<<tmp<<" c:"<<c<<endl;
		if(tmp==0 && n!=0){
			mem[n] = c;
			return c;
		}
		
		int val , min_val=INT_MAX , c1 , c2;
		for(int i=2;i*i<=n;++i)if(n%i==0){
			c1 = get_clicks(i);
			if(c1==INT_MAX){
				continue;
			}
			c2 = get_clicks(n/i);
			if(c2==INT_MAX){
				continue;
			}
			val = c1+c2+1;
			if(debug)cout<<"\t"<<n<<"="<<i<<"x"<<n/i<<" : "<<c1<<" "<<c2<<" giving "<<val<<endl;
			min_val = min(min_val , val);
		}
		
		mem[n] = min_val;
		return min_val;
	}
public:
	Solver():
	is_usable(vector<bool>(10 , false)){
		int x;
		for(int i=0;i<10;++i){
			scanf("%d",&x);
			is_usable[i] = x==1;
		}
		scanf("%d",&target);
	}
	string solve(){
		int x = get_clicks(target);
		if(x==INT_MAX){
			return "Impossible";
		}
		stringstream ss;
		ss<<x+1;
		return ss.str();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		Solver s;
		cout<<"Case #"<<t<<": "<<s.solve()<<endl;
		if(debug)cout<<"==============="<<endl;
	}
	
	return 0;
}

