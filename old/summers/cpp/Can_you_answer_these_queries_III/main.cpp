/*
Project name : Can_you_answer_these_queries_III
Created on : Mon Jun  9 16:08:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GSS3/
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
	int start;
	int end;
	int leftMax;
	int rightMax;
	int sum;
	int bestSum;
	Node* left;
	Node* right;
	
	Node(int s , int e):
	start(s),
	end(e),
	left(NULL),
	right(NULL){
		
	}
};
inline int max(int a , int b , int c){
	return a>b ? a<c ? c : a : b<c ? c : b ;
}
class SegTree{
	Node* root;
	vector<int> arr;
	void create_subtree(Node *ptr){
		int s=ptr->start , e=ptr->end , m=(s+e)/2 , val=arr[s];
		if(debug)cout<<"Creating subtree rooted at : "<<s<<" "<<e<<endl;
		if(e - s == 1){
			ptr->leftMax = val;
			ptr->rightMax= val;
			ptr->sum     = val;
			ptr->bestSum = val;
			if(debug)cout<<"Returning from leaf node"<<endl;
			return;
		}
		ptr->left = new Node(s,m);
		ptr->right= new Node(m,e);
		create_subtree(ptr->left);
		create_subtree(ptr->right);
		
		ptr->leftMax = max(ptr->left->leftMax , ptr->left->sum+ptr->right->leftMax , ptr->left->sum+ptr->right->sum);
		ptr->rightMax= max(ptr->right->rightMax , ptr->right->sum+ptr->left->rightMax , ptr->left->sum+ptr->right->sum);
		ptr->sum     = ptr->left->sum + ptr->right->sum ;
		ptr->bestSum = max(ptr->left->bestSum ,ptr->right->bestSum , ptr->left->rightMax+ptr->right->leftMax);
		
		if(debug)cout<<"Retruning from non-leaf node"<<endl;
	}
	Node* getVal(int a , int b , Node* ptr){
		if(debug)cout<<"called with : "<<a<<" "<<b<<" on node: "<<ptr->start<<" "<<ptr->end<<endl;
		int s=ptr->start , e=ptr->end , m=(s+e)/2 , v1=INT_MIN , v2=INT_MIN;
		if(s==a && e==b){
			if(debug)cout<<"returning "<<a<<" "<<b<<" with exact match "<<ptr->bestSum<<endl;
			return ptr;
		}
		if(b<=m)
			return getVal(a,b,ptr->left);
		if(a>=m)
			return getVal(a,b,ptr->right);
		
		Node* left = getVal(a,m,ptr->left);
		Node* right= getVal(m,b,ptr->right);
		Node* newPtr= new Node(a,b);
		newPtr->leftMax = max(left->leftMax , left->sum+right->leftMax , left->sum+right->sum);
		newPtr->rightMax= max(right->rightMax , right->sum+left->rightMax , right->sum+left->sum);
		newPtr->sum     = left->sum + right->sum;
		newPtr->bestSum = max(left->bestSum , right->bestSum , left->rightMax+right->leftMax);
		newPtr->left    = left;
		newPtr->right   = right;
		return newPtr;
	}
	void modifyNode(Node *ptr , int pos , int val){
		int s=ptr->start , e=ptr->end , m=(s+e)/2;
		if(e - s == 1){
			ptr->leftMax = val;
			ptr->rightMax= val;
			ptr->sum     = val;
			ptr->bestSum = val;
			if(debug)cout<<"Modified at "<<s<<" to "<<val<<endl;
			return;
		}
		if(pos<m){
			modifyNode(ptr->left,pos,val);
		}else{
			modifyNode(ptr->right,pos,val);
		}
		
		ptr->leftMax = max(ptr->left->leftMax , ptr->left->sum+ptr->right->leftMax , ptr->left->sum+ptr->right->sum);
		ptr->rightMax= max(ptr->right->rightMax , ptr->right->sum+ptr->left->rightMax , ptr->left->sum+ptr->right->sum);
		ptr->sum     = ptr->left->sum + ptr->right->sum ;
		ptr->bestSum = max(ptr->left->bestSum ,ptr->right->bestSum , ptr->left->rightMax+ptr->right->leftMax);
		if(debug)cout<<"Modification propogated to "<<s<<","<<e<<endl;
	}
public:
	SegTree(int n):
		arr(vector<int>(n)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		root = new Node(0,n);
		create_subtree(root);
	}
	int query(int s , int e){
		return getVal(s,e,root)->bestSum;
	}
	void modify(int pos , int val){
		modifyNode(root,pos,val);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	SegTree seg_tree(n);
	
	int m , a , b , type;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d %d",&type,&a,&b);
		switch(type){
			case 0:
				seg_tree.modify(a-1,b);
				break;
			case 1:
				printf("%d\n",seg_tree.query(a-1,b));
				break;
		}
		
	}
	return 0;
}

