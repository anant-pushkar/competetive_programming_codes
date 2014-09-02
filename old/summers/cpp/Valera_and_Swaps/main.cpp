/*
Project name : Valera_and_Swaps
Created on : Sun Jun 29 12:06:10 2014
Author : Anant Pushkar
http://codeforces.com/contest/441/problem/D
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
bool operator<(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.first<p2.first;
}
class Solver{
	queue<pair<int,int> > invQ , orderQ;
	vector<int> p;
	int n , m;
	queue<pair<int,int> > getTop(queue<pair<int,int> > &q){
		int size = q.size();
		vector<pair<int,int> > arr(size);
		int index=0;
		while(!q.empty()){
			arr[index++] = q.front();
			q.pop();
		}
		sort(arr.begin(),arr.end());
		for(int i=0;i<size;++i){
			q.push(arr[i]);
		}
		return q;
	}
	void getInv(int start , int end){
		if(start<0 || end>n || end==start+1){
			return;
		}
		int mid = (start+end)/2;
		
		getInv(start,mid);
		getInv(mid,end);
		
		int i=start , j=mid , index=start;
		vector<int> left(p.begin()+start,p.begin()+mid) , right(p.begin()+mid,p.begin()+end);
		
		while(i<mid && j<end){
			if(left[i-start] > right[j-mid]){
				invQ.push(make_pair(i+1,j+1));
				p[index++] = right[j-mid];
				++j;
			}else{
				p[index++] = left[i-start];
				orderQ.push(make_pair(i+1,j+1));
				++i;
			}
		}
		
		while(i<mid){
			p[index++] = left[i-start];
			++i;
		}
		
		while(j<end){
			p[index++] = right[j-mid];
			++j;
		}
	}
public:
	Solver(int num):
	n(num),
	p(vector<int>(num)){
		for(int i=0;i<n;++i){
			scanf("%d",&p[i]);
		}
		scanf("%d",&m);
	}
	queue<pair<int,int> > solve(){
		getInv(0,n);
		int nInv = invQ.size();
		
		if(nInv>m){
			return getTop(invQ);
		}else{
			return getTop(orderQ);
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	Solver s(n);
	queue<pair<int,int> > soln = s.solve();
	printf("%d\n",soln.size());
	while(!soln.empty()){
		printf("%d %d ",soln.front().first,soln.front().second);
		soln.pop();
	}
	printf("\n");
	return 0;
}

