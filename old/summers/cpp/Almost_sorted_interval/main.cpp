/*
Project name : Almost_sorted_interval
Created on : Wed Jun 18 10:33:00 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101may14/challenges/almost-sorted-interval
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
struct BIT{
	vector<lld> tree;
	
	BIT(int n):
	tree(vector<lld>(n+2,0)){}
	void set(int i,lld v){
		++i;
		while(i<tree.size()){
			tree[i]+=v;
			i+=i&(-i);
		}
	}
	lld get(int i){
		++i;
		lld s=0;
		while(i>0){
			s+=tree[i];
			i-=i&(-i);
		}
		return s;
	}
};
class Solver{
	int n;
	vector<int> arr , left , right , del_list;
	BIT tree;
	void populate_left(){
		stack<int> left_index;
		left[0] = -1;
		left_index.push(0);
		for(int i=1;i<n;++i){
			while(!left_index.empty() && arr[left_index.top()]<arr[i]){
				left_index.pop();
			}
			left[i] = left_index.empty() ? -1 : left_index.top();
			left_index.push(i);
		}
	}
	void populate_right(){
		stack<int> right_index;
		right[n-1] = -1;
		right_index.push(n-1);
		for(int i=n-2;i>-1;--i){
			while(!right_index.empty() && arr[right_index.top()]>arr[i]){
				right_index.pop();
			}
			right[i] = right_index.empty() ? -1 : right_index.top();
			right_index.push(i);
		}
	}
	void print_vector(const vector<int> &v){
		int size = v.size();
		for(int i=0;i<size;++i){
			cout<<v[i]<<" ";
		}
	}
public:
	Solver(int num):
	n(num),
	arr(vector<int>(num)),
	left(vector<int>(num)),
	right(vector<int>(num)),
	tree(num){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		populate_left();
		populate_right();
	}
	int solve(){
		int index=0 , count=0;
		vector<queue<int> > insert_list(n);
		while(index<n){
			if(debug)cout<<"index:"<<index<<endl;
			tree.set(index,1);
			tree.set(right[index]<0 ? n-1 : right[index],-1);
			if(right[index]>=0){
				insert_list[right[index]].push(index);
			}
			
			count += tree.get(index) - (left[index]<0 ? 0 : tree.get(left[index]));
			
			while(!insert_list[index].empty()){
				tree.set(insert_list[index].front(),-1);
				tree.set(index,1);
				insert_list[index].pop();
			}
			
			if(debug)cout<<"count:"<<count<<endl<<endl;
			++index;
		}
		return count+n;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	printf("%d\n",s.solve());
	return 0;
}

