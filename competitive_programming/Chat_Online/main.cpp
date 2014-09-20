/*
Project name : Chat_Online
Created on : Sat Sep 20 18:41:46 2014
Author : Anant Pushkar
codeforces 268
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
int p , q , l , r;
vector<pair<int , int> > x , y;
bool is_suited(int start , const vector<int> &last){
	if(debug)cout<<"looking for "<<start<<endl;
	for(int i=0;i<q;++i){
		if(y[i].first+start<=1000 && last[y[i].first+start]<=y[i].second+start){
			if(debug)cout<<"suited"<<endl;
			return true;
		}
	}
	return false;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>p>>q>>l>>r;
	
	x = vector<pair<int , int> >(p);
	y = vector<pair<int , int> >(q);
	for(int i=0;i<p;++i){
		cin>>x[i].first>>x[i].second;
	}
	sort(x.begin() , x.end());
	
	for(int i=0;i<q;++i){
		cin>>y[i].first>>y[i].second;
	}
	
	vector<int> last(1001 , -1);
	int index=0 , i = 0;
	while(index<1001){
		if(index==x[i].first){
			index = x[i].second+1;
			++i;
			if(i>=p){
				while(index<1001){
					last[index++] = INT_MAX;
				}
				break;
			}
		}else{
			last[index] = x[i].first;
			++index;
		}
	}
	
	if(debug){
		for(int i=0;i<10;++i){
			cout<<last[i]<<" ";
		}
		cout<<endl;
	}
	
	int count = 0;
	while(l<=r){
		count += is_suited(l , last) ? 1 : 0;
		++l;
	}
	cout<<count<<endl;
	
	return 0;
}

