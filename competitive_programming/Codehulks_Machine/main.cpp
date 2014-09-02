/*
Project name : Codehulks_Machine
Created on : Sat Aug  9 21:50:42 2014
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
lld n;
int one_count , zero_count , odd_count , even_count , c , tmp , x;
deque<int> count_list;
int get_odd_benefit(){
	/*if(x-(x%2) < even_count){
		return -1;
	}*/
	
	int delta = x>even_count ? even_count : x;
	
	int zero_count_temp = zero_count - delta;
	int one_count_temp  = one_count + delta;
	int odd_count_temp  = odd_count + delta;
	int even_count_temp = even_count - delta;
	int x_temp		    = x - delta;
	x_temp -= x_temp%2 + (delta%2);
	
	delta=0;
	int size = count_list.size();
	for(int i=0;i<size;++i){
		delta += count_list[i]-(count_list[i]%2==0 ? 1 : 0)-1;
	}
 	if(debug)cout<<"ODD : one_count:"<<one_count_temp<<" delta:"<<delta<<" x:"<<x_temp<<endl;
	return one_count_temp + (delta>x_temp ? x_temp : delta);
}

int get_even_benefit(){
	/*if(x-(x%2) < even_count){
		return -1;
	}*/
	
	int delta = x>odd_count ? odd_count : x;
	
	int zero_count_temp = zero_count - delta;
	int one_count_temp  = one_count + delta;
	int odd_count_temp  = odd_count - delta;
	int even_count_temp = even_count + delta;
	int x_temp		    = x -delta;
	x_temp -= x_temp%2 + (delta%2);
	if(debug)cout<<"EVEN : one_count:"<<one_count_temp<<" delta:"<<delta<<" x:"<<x_temp<<endl;
	delta=0;
	int size = count_list.size();
	for(int i=0;i<size;++i){
		delta += count_list[i] - (count_list[i]%2);
	}
 	if(debug)cout<<"EVEN : one_count:"<<one_count_temp<<" delta:"<<delta<<" x:"<<x_temp<<endl;
	return one_count_temp + (delta>x_temp ? x_temp : delta);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>n;
	cin>>x;
	
	one_count=0 ;
	zero_count=0 ;
	odd_count=0;
	even_count=0;
	c=0;
	tmp=n;
	for(int i=0;i<64;++i){
		if(tmp%2==1){
			++one_count;
			if(c>0){
				if(c%2==0){
					++even_count;
				}else{
					++odd_count;
				}
				count_list.push_back(c);
				c=0;
			}
		}else{
			++zero_count;
			++c;
		}
		tmp = tmp>>1;
	}
	if(c>0){
		if(c%2==0){
			++even_count;
		}else{
			++odd_count;
		}
		count_list.push_back(c);
		c=0;
	}
	
	int odd_benefit = get_odd_benefit();
	int even_benefit = get_even_benefit();	
	
	printf("%d\n",odd_benefit>even_benefit ? odd_benefit : even_benefit);

	//printf("%d\n",one_count+x-delta);
	
	return 0;
}

