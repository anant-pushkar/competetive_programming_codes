/*
Project name : Pocket_Money
Created on : Sat Sep  6 13:14:55 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LISA/
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
	string exp;
	int n;
	vector<vector<lld> > min_lookup , max_lookup;
	lld get_max(int x , int y){
		if(x<0 || x>=n || y<0 || y>n || x==y){
			return INT_MIN;
		}
		if(max_lookup[x][y]!=INT_MIN){
			return max_lookup[x][y];
		}
		
		if(debug)cout<<"called for max at "<<x<<","<<y<<endl;
		
		lld max = INT_MIN , v1 , v2 , val;
		for(int i=x+1;i<y;++i){
			v1 = get_max(x,i);
			v2 = get_max(i,y);
			val = exp[2*i-1]=='+' ? v1+v2 : v1*v2;
			
			max = max<val ? val : max;
		}
		
		max_lookup[x][y] = max;
		
		if(debug)cout<<"returning "<<x<<","<<y<<" with "<<max<<endl;
		
		return max_lookup[x][y];
	}
	lld get_min(int x , int y){
		if(x<0 || x>=n || y<0 || y>n || x==y){
			return INT_MAX;
		}
		if(min_lookup[x][y]!=INT_MAX){
			return min_lookup[x][y];
		}
		
		if(debug)cout<<"called for min at "<<x<<","<<y<<endl;
		
		lld min = INT_MAX , v1 , v2 , val;
		for(int i=x+1;i<y;++i){
			v1 = get_min(x,i);
			v2 = get_min(i,y);
			val = exp[2*i-1]=='+' ? v1+v2 : v1*v2;
			
			min = min>val ? val : min;
		}
		
		min_lookup[x][y] = min;
		
		if(debug)cout<<"returning "<<x<<","<<y<<" with "<<min<<endl;
		
		return min_lookup[x][y];
	}
	void print_vector(const vector<vector<lld> > &v){
		int size=v.size() , row_size;
		for(int i=0;i<size;++i){
			row_size = v[i].size();
			for(int j=0;j<row_size;++j){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
public:
	Solver(string s):
	exp(s),
	n(exp.size()/2+1),
	min_lookup(vector<vector<lld> >(exp.size()/2+2 , vector<lld>(exp.size()/2+2 , INT_MAX) ) ),
	max_lookup(vector<vector<lld> >(exp.size()/2+2 , vector<lld>(exp.size()/2+2 , INT_MIN) ) ){
		if(debug)cout<<exp<<endl;
		for(int i=0;i<n;++i){
			min_lookup[i][i+1] = exp[2*i]-'0';
			max_lookup[i][i+1] = exp[2*i]-'0';
		}
	}
	void print_soln(){
		cout<<get_max(0,n)<<" "<<get_min(0,n)<<endl;
	}
};

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	string exp;
	while(t--){
		cin>>exp;
		Solver s(exp);
		s.print_soln();
	}
	
	return 0;
}

