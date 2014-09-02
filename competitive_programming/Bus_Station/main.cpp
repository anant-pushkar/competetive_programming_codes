/*
Project name : Bus_Station
Created on : Sat Jul 26 18:45:35 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101jul14/challenges/bus-station
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
	int n , sum , max_size;
	vector<int> arr;
	stack<int> soln;
	bool is_valid(int m){
		int i=0 , count;
		while(i<n){
			count = 0;
			while(i<n && count<m){
				count += arr[i];
				++i;
			}
			if(count!=m){
				return false;
			}
		}
		return true;
	}
	void solve(){
		int temp;
		soln.push(sum);
		for(int i = 2 ; sum/i >= max_size ; ++i)if(sum%i==0){
			if(is_valid(sum/i)){
				soln.push(sum/i);
			}
		}
	}
public:
	Solver(int num):
	n(num),
	sum(0),
	max_size(0),
	arr(vector<int>(num)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			sum += arr[i];
			max_size = max_size<arr[i] ? arr[i] : max_size;
		}
		solve();
	}
	void print_soln(){
		while(!soln.empty()){
			cout<<soln.top()<<" ";
			soln.pop();
		}
		cout<<endl;
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

