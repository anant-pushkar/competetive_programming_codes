/*
Project name : Children_Candies
Created on : Sun Oct  5 16:22:25 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/csindia14-er2/challenges/candies-1
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int n;
vector<int> a;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>n;
	a = vector<int>(n);
	lld sum=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		sum += a[i];
	}
	lld avg = sum/n;
	
	int count=0 ;
	stack<int> less , more;
	for(int i=0;i<n;++i){
		if(a[i]<avg){
			less.push(i);
		}else if(a[i]>avg){
			more.push(i);
		}
	}
	if(debug)cout<<"average : "<<avg<<endl;
	int diff ;
	while(!more.empty()){
		diff = a[more.top()]-avg;
		if(debug)cout<<"inspecting "<<more.top()<<endl;
		while(!less.empty() && diff>=avg-a[less.top()]){
			if(debug)cout<<"sending "<<(avg-a[less.top()])<<" to "<<less.top()<<endl;
			count += abs(less.top()-more.top())*(avg-a[less.top()]);
			diff -= avg-a[less.top()];
			a[less.top()] = avg;
			less.pop();
			if(debug)cout<<"count : "<<count<<endl;
		}
		if(!less.empty() && diff!=0){
			if(debug)cout<<"#sending "<<diff<<" to "<<less.top()<<endl;
			count += abs(less.top()-more.top())*diff;
			a[less.top()] += diff;
			if(debug)cout<<"count : "<<count<<endl;
		}
		a[more.top()] = avg;
		more.pop();
	}
	cout<<count<<endl;
	return 0;
}

