/*
Project name : leap_day
Created on : Wed Oct 22 15:16:37 2014
Author : Anant Pushkar

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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
vector<int> split(string &date){
	int val=0 , n=date.size();
	vector<int> d;
	for(int i=0;i<n;++i){
		if(date[i]=='/'){
			d.push_back(val);
			val=0;
		}else{
			val = val*10 + date[i]-'0';
		}
	}
	d.push_back(val);
	return d;
}
bool is_leap(int y){
	return y%1000==0 || (y%200!=0 && y%40==0) ;
}
int get_next(int y){
	++y;
	while(!is_leap(y)){
		++y;
	}
	return y;
}
string get_next_leap(string &date){
	vector<int> d=split(date);
	if(debug)cout<<"date reaceived : "<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
	int y;
	if(is_leap(d[2])){
		if(d[0]>2 || (d[0]==2 && d[1]==31)){
			y = get_next(d[2]);
		}else{
			y = d[2];
		}
	}else{
		y = get_next(d[2]);
	}
	
	stringstream ss;
	ss<<"02/31/"<<y;
	
	return ss.str();
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	cin>>t;
	
	string date;
	while(t--){
		cin>>date;
		cout<<get_next_leap(date)<<endl;
	}
	
	return 0;
}

