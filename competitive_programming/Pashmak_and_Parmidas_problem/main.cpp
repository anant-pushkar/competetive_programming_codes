/*
Project name : Pashmak_and_Parmidas_problem
Created on : Sat Aug 23 22:21:01 2014
Author : Anant Pushkar
http://codeforces.com/contest/459/problem/D
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	vector<int> arr ;
	deque<int> f1 , fn;
	void preprocess(){
		map<int,int> previous;
		for(int i=0;i<n;++i){
			if(previous.find(arr[i]) == previous.end()){
				previous[arr[i]] = i;
				f1[i] = 1;
			}else{
				f1[i] = f1[previous[arr[i]]]+1;
				previous[arr[i]] = i;
			}
		}
		
		previous.clear();
		for(int i=n-1;i>-1;--i){
			if(previous.find(arr[i]) == previous.end()){
				previous[arr[i]] = i;
				fn[i] = 1;
			}else{
				fn[i] = fn[previous[arr[i]]]+1;
				previous[arr[i]] = i;
			}
		}
	}
public:
	Solver(int x):
	n(x),
	arr(vector<int>(n)),
	f1(deque<int>(n)),
	fn(deque<int>(n)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		preprocess();
	}
	int solve(){
		deque<int> temp = fn;
		deque<int>:: iterator it;
		sort(temp.begin() , temp.end());
		int count = 0;
		for(int i=0;i<n;++i){
			it = lower_bound(temp.begin() , temp.end() , fn[i]);
			temp.erase(it);
			
			count += lower_bound(temp.begin() , temp.end() , f1[i]) - temp.begin();
			if(debug)cout<<i<<" "<<count<<endl;
		}
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	printf("%d\n",s.solve());
	
	return 0;
}

