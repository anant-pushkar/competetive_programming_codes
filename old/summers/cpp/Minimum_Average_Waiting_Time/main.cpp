/*
Project name : Minimum_Average_Waiting_Time
Created on : Fri Jul  4 15:03:56 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w6/challenges/minimum-average-waiting-time
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
struct Customer{
	lld t,l;
};
bool compareLen(const Customer &c1 , const Customer &c2){
	return c1.l > c2.l;
}
bool compareTime(const Customer &c1 , const Customer &c2){
	return c1.t < c2.t;
}
class Solver{
	int n;
	vector<Customer> customerList;;
public:
	Solver(int num):
	n(num),
	customerList(vector<Customer>(num)){
		for(int i=0;i<n;++i){
			scanf("%lld %lld",&customerList[i].t,&customerList[i].l);
		}
		sort(customerList.begin(),customerList.end(),compareTime);
	}
	lld solve(){
		priority_queue<Customer, vector<Customer>, decltype(&compareLen)> customerQ(&compareLen);
		priority_queue<lld, vector<lld> , greater<lld> > eventQ;
		lld time = 0 , event , next=0;
		Customer customer;
		int index=0 , count=0;
		
		for(int i=0;i<n;++i){
			if(debug)cout<<"pushed event : "<<customerList[i].t<<endl;
			eventQ.push(customerList[i].t);
		}
		if(debug)cout<<endl;
		
		while(count<n && !eventQ.empty()){
			event = eventQ.top();
			eventQ.pop();
			if(debug)cout<<"Event : "<<event<<endl;
			
			while(customerList[index].t == event){
				customerQ.push(customerList[index]);
				if(debug)cout<<"pushed customer : "<<customerList[index].t<<" "<<customerList[index].l<<endl;
				++index;
			}
			
			if(event>=next){
				customer = customerQ.top();
				customerQ.pop();
				++count;
				
				next = event+customer.l;
				eventQ.push(next);
				if(debug)cout<<"Next Set to "<<next<<endl;
				
				time += next - customer.t;
				if(debug)cout<<"Waiting time for "<<customer.t<<" "<<customer.l<<" : "<<(event+customer.l) - customer.t<<endl<<endl;
			}
		}
		
		return time/n;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	
	printf("%lld\n",s.solve());
	
	return 0;
}

