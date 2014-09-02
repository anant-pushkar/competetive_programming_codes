/*
Project name : online_median
Created on : Fri Jul 18 10:58:37 2014
Author : Anant Pushkar
Algortihm to find median of a stream of numbers in real time
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
class median_finder{
	int n , val , count; 
	priority_queue<int> left;
	priority_queue<int , vector<int> , greater<int> > right;
	void read(){
		int x;
		scanf("%d",&x);
		
		if(count==0){
			val = x;
		}else if(count%2 == 1){
			if(x>val){
				right.push(x);
				left.push(val);
			}else{
				right.push(val);
				left.push(x);
			}
		}else{
			if(x>left.top()){
				right.push(x);
				val = right.top();
				right.pop();
			}else{
				left.push(x);
				val = left.top();
				left.pop();
			}
		}
		++count;
	}
	float get_median(){
		if(count%2==0){
			return( static_cast<float>(left.top()) + right.top() )/2;
		}
		return val;
	}
public:
	median_finder(int num):
	n(num),
	count(0){
		
	}
	void start(){
		while(n--){
			read();
			cout<<get_median()<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	median_finder mf(n);
	mf.start();
	return 0;
}

