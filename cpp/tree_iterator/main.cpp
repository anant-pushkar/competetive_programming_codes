/*
Project name : tree_iterator
Created on : Thu Oct  9 17:51:59 2014
Author : Anant Pushkar
inorder iterator for tree data structure
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
struct TreeNode{
	int val;
	TreeNode *left , *right;
	TreeNode():left(NULL),right(NULL),val(INT_MIN){};
	TreeNode(int x):left(NULL),right(NULL),val(x){};
};
class InorderIterator{
	TreeNode *root;
	stack<TreeNode*> node_stack;
	stack<int> state_stack;
public:
	InorderIterator(TreeNode *ptr):
	root(ptr){
		node_stack.push(root);
		state_stack.push(0);
		
		TreeNode *node;
		int state;
		while(!node_stack.empty()){
			node = node_stack.top();
			node_stack.pop();
			
			state = state_stack.top();
			state_stack.pop();
			
			if(state==0){
				node_stack.push(node);
				state_stack.push(1);
				if(node->left!=NULL){
					node_stack.push(node->left);
					state_stack.push(0);
				}
			}else{
				node_stack.push(node);
				state_stack.push(1);
				break;
			}
		}
	}
	TreeNode* get_node(){
		return node_stack.empty() ? NULL : node_stack.top();
	}
	void proceed(){
		if(state_stack.empty()){
			return;
		}
		TreeNode *node;
		int state;
		
		while(true){
			node = node_stack.top();
			node_stack.pop();
		
			state = state_stack.top();
			state_stack.pop();
			
			if(state==0){
				node_stack.push(node);
				state_stack.push(1);
				if(node->left!=NULL){
					node_stack.push(node->left);
					state_stack.push(0);
				}
			}else{
				if(node->right!=NULL){
					node_stack.push(node->right);
					state_stack.push(0);
				}
			}
			if(state_stack.top()==1){
				break;
			}
		}
	}
};
class PreorderIterator{
	TreeNode *root;
	stack<TreeNode*> node_stack;
	stack<int> state_stack;
public:
	PreorderIterator(TreeNode *ptr):
	root(ptr){
		node_stack.push(root);
		state_stack.push(0);
	}
	TreeNode* get_node(){
		return node_stack.empty() ? NULL : node_stack.top();
	}
	void proceed(){
		if(state_stack.empty()){
			return;
		}
		TreeNode *node;
		int state;
		
		while(true){
			node = node_stack.top();
			node_stack.pop();
		
			state = state_stack.top();
			state_stack.pop();
			
			if(state==0){
				node_stack.push(node);
				state_stack.push(1);
				if(node->left!=NULL){
					node_stack.push(node->left);
					state_stack.push(0);
				}
			}else{
				if(node->right!=NULL){
					node_stack.push(node->right);
					state_stack.push(0);
				}
			}
			if(state_stack.top()==0){
				break;
			}
		}
	}
};
class PostorderIterator{
	TreeNode *root;
	stack<TreeNode*> node_stack;
	stack<int> state_stack;
public:
	PostorderIterator(TreeNode *ptr):
	root(ptr){
		node_stack.push(root);
		state_stack.push(0);
		
		TreeNode *node;
		int state;
		while(true){
			node = node_stack.top();
			node_stack.pop();
			
			state = state_stack.top();
			state_stack.pop();
			
			if(state==0){
				node_stack.push(node);
				state_stack.push(1);
				if(node->left!=NULL){
					node_stack.push(node->left);
					state_stack.push(0);
				}
			}else if(state==1){
				node_stack.push(node);
				state_stack.push(2);
				if(node->right!=NULL){
					node_stack.push(node->right);
					state_stack.push(0);
				}
			}else{
				node_stack.push(node);
				state_stack.push(2);
				break;
			}
		}
	}
	TreeNode* get_node(){
		return node_stack.empty() ? NULL : node_stack.top();
	}
	void proceed(){
		if(state_stack.empty()){
			return;
		}
		TreeNode *node;
		int state;
		
		while(true){
			node = node_stack.top();
			node_stack.pop();
		
			state = state_stack.top();
			state_stack.pop();
			
			if(state==0){
				node_stack.push(node);
				state_stack.push(1);
				if(node->left!=NULL){
					node_stack.push(node->left);
					state_stack.push(0);
				}
			}else if(state==1){
				node_stack.push(node);
				state_stack.push(2);
				if(node->right!=NULL){
					node_stack.push(node->right);
					state_stack.push(0);
				}
			}
			if(state_stack.top()==2){
				break;
			}
		}
	}
};
class Solver{
	int n;
	TreeNode *root;
	vector<TreeNode*> node_list;

public:
	Solver(int x):
	n(x),
	node_list(vector<TreeNode*>(n,NULL))
	{
		for(int i=0;i<n;++i){
			node_list[i] = new TreeNode(i+1);
		}
		int root_index;
		cin>>root_index;
		root = node_list[root_index];
		int l,r;
		cin>>l>>r;
		int a,b;
		for(int i=0;i<l;++i){
			cin>>a>>b;
			node_list[a]->left = node_list[b];
		}
		for(int i=0;i<r;++i){
			cin>>a>>b;
			node_list[a]->right = node_list[b];
		}
	}
	void print_inorder(){
		InorderIterator it(root);
		TreeNode *node;
		while(true){
			node = it.get_node();
			if(node==NULL){
				break;
			}
			cout<<node->val<<endl;
			it.proceed();
		}
	}
	void print_preorder(){
		PreorderIterator it(root);
		TreeNode *node;
		while(true){
			node = it.get_node();
			if(node==NULL){
				break;
			}
			cout<<node->val<<endl;
			it.proceed();
		}
	}
	void print_postorder(){
		PostorderIterator it(root);
		TreeNode *node;
		while(true){
			node = it.get_node();
			if(node==NULL){
				break;
			}
			cout<<node->val<<endl;
			it.proceed();
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		s.print_postorder();
	}
	
	return 0;
}

