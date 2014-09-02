/*
Project name : Little_Pony_and_Harmony_Chest
Created on : Fri Aug  1 21:57:32 2014
Author : Anant Pushkar

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
vector<vector<int> > lookup , min_arr;
vector<int> min_val , arr;
int n , current_min;
inline void exchange(int &a , int &b){
	a = a^b;
	b = a^b;
	a = a^b;
}
int get_gcd(int a , int b){
	if(a%b==0){
		return b;
	}
	return get_gcd(b , a%b);
}
void init(){
	lookup  = vector<vector<int> >(31 , vector<int>(31,1));
	min_arr = vector<vector<int> >(n , vector<int>(n));
	min_val = vector<int>(n);
	arr = vector<int>(n);
	current_min = INT_MAX;
	for(int i=2;i<31;++i){
		for(int j=i;j<31;++j){
			lookup[i][j] = get_gcd(j,i);
			lookup[j][i] = lookup[i][j];
		}
	}
	/*if(debug){
		int count=0 , max_count=0;
		for(int i=0;i<31;++i){
			for(int j=0;j<31;++j){
				printf("%02d ",lookup[i][j]);
			}
			cout<<endl;
		}
	}*/
}
int get_closest(int a , int b){
	int i=a , diff;
	while(i<31 && lookup[i][b]!=1){
		++i;
	}
	diff = i-a;
	i=a;
	while(i>-1 && lookup[i][b]!=1){
		--i;
	}
	if(diff>a-i){
		return a;
	}else{
		return a+diff;
	}
}
int find_min(int index){
	int val , diff=0;
	for(int i=0;i<n;++i){
		min_arr[index][i] = arr[i];
	}
	for(int i=0;i<n;++i)if(index!=i){
		val = get_closest(arr[i] , arr[index]);
		diff += abs(arr[i]-val);
		if(diff>current_min){
			return INT_MAX;
		}
		min_arr[index][i] = val;
		for(int j=0;j<n;++j)if(index!=j && i!=j){
			val = get_closest(min_arr[index][j] , min_arr[index][i]);
			diff += abs(min_arr[index][i]-val);
			if(diff>current_min){
				return INT_MAX;
			}
			min_arr[index][i] = val;
				if(debug){
				cout<<"caliberating "<<min_arr[index][j]<<endl;
				for(int j=0;j<n;++j){
					cout<<min_arr[index][j]<<" ";
				}
				cout<<endl;
			}
		}	
	}
	min_val[index] = diff;
	return diff;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d",&n);
	init();
	
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	
	int min , index=-1;
	for(int i=0;i<n;++i){
		min = find_min(i);
		if(current_min>min){
			current_min = min;
			index = i;
		}
		if(debug)cout<<"min for "<<i<<" "<<min<<endl;
	}
	
	for(int i=0;i<n;++i){
		cout<<min_arr[index][i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

