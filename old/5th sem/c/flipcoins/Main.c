#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct _node{
	int val;
	int start;
	int end;
	bool flag;
	struct _node *left;
	struct _node *right;
};
typedef struct _node Node;
Node *createTree(int start , int end){
	Node *root = (Node*)malloc(sizeof(Node));
	root->val  = 0;
	root->flag = false;
	root->left = createTree(n/2);
	root->right= createTree(n-n/2-1);
	return root;
}
int main()
{
	
	return 0;
}
