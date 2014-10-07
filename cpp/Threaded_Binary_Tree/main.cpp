/*
Project name : Threaded_Binary_Tree
Created on : Tue Oct  7 14:20:08 2014
Author : Anant Pushkar
http://geeksquiz.com/threaded-binary-tree/
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
class Solver{
	int n;
	TreeNode *root;
	vector<TreeNode*> node_list;
	TreeNode* solve(TreeNode *node){
		if(node==NULL){
			return NULL;
		}
		if(debug)cout<<"Called on "<<node->val<<endl;
		TreeNode *left = solve(node->left);
		if(left!=NULL){
			left->right = node;
			if(debug)cout<<"pointing "<<left->val<<" to "<<node->val<<endl;
		}
		
		TreeNode * ptr=node;
		while(ptr->right!=NULL){
			ptr = ptr->right;
		}
		
		solve(node->right);
		
		if(debug)cout<<"returning "<<ptr->val<<endl;
		return ptr;
	}
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
		if(debug)cout<<"Assigning root to "<<root->val<<endl;
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
	void print_soln(){
		
		solve(root);
		for(int i=0;i<n;++i){
			cout<<(node_list[i]->right==NULL ? -1 : node_list[i]->right->val)<<" ";
		}
		cout<<endl;
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
		s.print_soln();
	}
	
	return 0;
}

