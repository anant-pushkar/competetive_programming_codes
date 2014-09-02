/*
Project name : Devu_and_Partitioning_of_the_Array
Created on : Mon Jun 30 15:57:36 2014
Author : Anant Pushkar
http://codeforces.com/contest/439/problem/C
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
	int n , p , k , oddCount , elementCount;
	queue<int> oddlist , evenlist;
	bool isSolvable;
	vector<queue<int> > partitions;
	void solve(){
		int index=0;
		partitions = vector<queue<int> >(k);
		while(!evenlist.empty() || oddlist.size()>k-p){
			if(debug)cout<<"\neven:"<<evenlist.size()<<" odd:"<<oddlist.size()<<endl;
			if(!evenlist.empty()){
				if(debug)cout<<"Putting "<<evenlist.front()<<" to "<<index<<endl;
				partitions[index].push(evenlist.front());
				++elementCount;
				evenlist.pop();
			}else if(!oddlist.empty()){
				if(debug)cout<<"Putting "<<oddlist.front()<<" to "<<index<<endl;
				partitions[index].push(oddlist.front());
				oddlist.pop();
				
				if(oddlist.size()<k-p || oddlist.empty()){
					isSolvable = false;
					if(debug)cout<<"oddlist.size() : "<<oddlist.size()<<"<"<<k-p<<endl;
					return;
				}
				
				if(debug)cout<<"Putting "<<oddlist.front()<<" to "<<index<<endl;
				partitions[index].push(oddlist.front());
				oddlist.pop();
				
				++elementCount;
			}else{
				isSolvable = false;
				if(debug)cout<<"Both lists empty"<<endl;
				return;
			}
			++index;
			index=index%k;
		}
		while(!oddlist.empty()){
			if(debug)cout<<"\nodd:"<<oddlist.size()<<endl;
			if(debug)cout<<"Putting "<<oddlist.front()<<" to "<<index<<endl;
			partitions[index].push(oddlist.front());
			oddlist.pop();
			
			++index;
			index=index%k;
			++oddCount;
			++elementCount;
		}
		if(debug)cout<<"oddCount : "<<oddCount<<endl;
		if(debug)cout<<"elementCount : "<<elementCount<<endl;
	}
public:
	Solver():
	isSolvable(true),
	oddCount(0),
	elementCount(0){
		scanf("%d %d %d",&n,&k,&p);
		int a;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			if(a%2==0){
				if(debug)cout<<"putting "<<a<<" to evenlist"<<endl;
				evenlist.push(a);
			}else{
				if(debug)cout<<"putting "<<a<<" to oddlist"<<endl;
				oddlist.push(a);
			}
		}
	}
	void print(){
		solve();
		if(oddCount!=k-p || !isSolvable || elementCount<k){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(int i=0;i<k;++i){
				printf("%d ",partitions[i].size());
				while(!partitions[i].empty()){
					printf("%d ",partitions[i].front());
					partitions[i].pop();
				}
				printf("\n");
			}
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	s.print();
	return 0;
}

