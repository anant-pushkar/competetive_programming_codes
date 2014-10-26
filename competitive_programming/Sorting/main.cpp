/*
Project name : Sorting
Created on : Mon Oct 20 02:34:31 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2924486/dashboard#s=p2
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	for(int t=1;t<=T;++t){
		deque<int> odd;
		deque<int> even;
		int x , n;
		
		cin>>n;
		vector<int> type(n);
		for(int i=0;i<n;++i){
			cin>>x;
			type[i] = abs(x)%2;
			if(abs(x)%2==0){
				even.push_back(x);
			}else{
				odd.push_back(x);
			}
		}
		
		sort(odd.begin() , odd.end());
		sort(even.begin() , even.end() , greater<int>());
		
		cout<<"Case #"<<t<<": ";
		int i=0 , j=0;
		for(int s=0;s<n;++s){
			if(type[s]==1){
				cout<<odd[i++]<<" ";
			}else{
				cout<<even[j++]<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}

