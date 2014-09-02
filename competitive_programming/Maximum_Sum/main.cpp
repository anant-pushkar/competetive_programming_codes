/*
Project name : Maximum_Sum
Created on : Wed Jul 30 14:27:26 2014
Author : Anant Pushkar
http://www.spoj.com/problems/KGSS/
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
struct Node{
	int start , end , top1 , top2;
	Node *left , *right;
	
	Node(int s , int e):
	start(s),
	end(e),
	left(NULL),
	right(NULL){
		
	}
};
inline int get_max(int a , int b){
	return a>b ? a : b;
}
class SegTree{
	const vector<int> &val;
	Node *root;
	void build_tree(Node *node){
		int s = node->start , e = node->end , m = (s+e)/2;
		
		if(e==s+1){
			node->top1 = val[s];
			node->top2 = INT_MIN;
			return;
		}
		
		node->left = new Node(s,m);
		node->right= new Node(m,e);
		
		build_tree(node->left);
		build_tree(node->right);
		
		node->top1 = get_max( node->left->top1 , node->right->top1 );
		node->top2 = get_max(get_max(node->left->top1+node->right->top1-node->top1 , node->left->top2) , node->right->top2);
	}
	void update_tree(Node *node , int index , int v){
		int s = node->start , e = node->end , m = (s+e)/2;
		
		if(e==s+1){
			node->top1 = v;
			node->top2 = INT_MIN;
			return;
		}
		
		if(index<m){
			update_tree(node->left , index , v);
		}else{
			update_tree(node->right, index , v);
		}
		
		node->top1 = get_max( node->left->top1 , node->right->top1 );
		node->top2 = get_max(get_max(node->left->top1+node->right->top1-node->top1 , node->left->top2) , node->right->top2);
	}
	pair<int,int> query_tree(Node *node , int start , int end){
		int s = node->start , e = node->end , m = (s+e)/2;
		pair<int,int> soln;
		
		if(debug)cout<<"Called on "<<s<<","<<e<<" with "<<start<<","<<end<<endl;
		
		if((e==s+1) || (s==start && e==end)){
			soln = make_pair(node->top1 , node->top2);
		}else if(start>=m && end>m){
			soln = query_tree(node->right , start , end);
		}else if(end<=m){
			soln = query_tree(node->left , start , end);
		}else{
			pair<int,int> left_soln , right_soln;
		
			left_soln = query_tree(node->left , start , m);
			right_soln= query_tree(node->right , m , end);
		
			soln.first = get_max(left_soln.first , right_soln.first);
			soln.second= get_max(left_soln.second , get_max(left_soln.first+right_soln.first-soln.first , right_soln.second));
		}
		
		if(debug){
			cout<<"Querying "<<s<<","<<e<<" with "<<start<<","<<end<<endl;
			cout<<"Returning with "<<soln.first<<","<<soln.second<<endl<<endl;
		}
		return soln;
	}
public:
	SegTree(const vector<int> &arr):
	val(arr){
		root = new Node(0,arr.size());
		build_tree(root);
	}
	void update(int index , int v){
		update_tree(root , index , v);
	}
	int query(int start , int end){
		pair<int,int> soln = query_tree(root , start , end+1);
		return soln.first + soln.second;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	scanf("%d",&n);
	
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	
	SegTree tree(arr);
	char q[2];
	int a , b;
	
	scanf("%d",&m);
	while(m--){
		scanf("%s %d %d",q , &a , &b);
		switch(q[0]){
			case 'Q':
				printf("%d\n" , tree.query(a-1,b-1));
				break;
			case 'U':
				tree.update(a-1 , b);
				break;
		}
	}

	return 0;
}

