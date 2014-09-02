#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct _node{
	int start;
	int end;
	int val;
	bool flag;
	struct _node *left;
	struct _node *right;
};
typedef struct _node Node;
int getVal(Node* node){
	if(node==NULL) return 0;
	return node->val;
}
Node *createTree(int start , int end)
{
	if(start>end) return NULL;
	//printf("Creating node between %d,%d\n",start,end);
	Node *nodePtr = (Node*)malloc(sizeof(Node));
	nodePtr->start= start;
	nodePtr->end  = end;
	nodePtr->flag = false;
	if(start==end){
		nodePtr->left = NULL;
		nodePtr->right= NULL;
		nodePtr->val  = 0;
	}else{
		int mid=(start+end)>>1;
		nodePtr->left = createTree(start,mid);
		nodePtr->right= createTree(mid+1,end);
		nodePtr->val  = 0;
	}
	return nodePtr;
}
void flip(int start , int end , Node* root ,bool flag)
{
	if(root==NULL) return;
	bool nextSignal=(flag+root->flag)%2;
	if(end<root->start || start>root->end){
		if(root->start!=root->end)root->flag = nextSignal;
		if((flag))root->val  = root->end-root->start-root->val+1;
		//printf("Returning with out of range with falg=%d\n",root->flag);
		return;
	}
	//printf("Flipping at %d,%d : flag=%d with propogate=%d\n",root->start,root->end,root->flag,flag);
	if(root->start>=start && root->end<=end){
		if(root->start!=root->end)root->flag = !nextSignal;
		if(!(flag))root->val  = root->end-root->start-root->val+1;
		//printf("Returning from exact match with root->val=%d and flag=%d\n",root->val,root->flag);
		return;
	}
	flip(start,end,root->left ,nextSignal);
	flip(start,end,root->right,nextSignal);
	root->flag= false;
	root->val = getVal(root->left) + getVal(root->right);
	//printf("Returning %d,%d from intermediate node with val=%d\n",root->start,root->end,root->val);
}
int count(int start , int end , Node *root , bool flag)
{
	if(root==NULL) return 0;
	//printf("Counting at %d,%d : flag=%d with propogate=%d\n",root->start,root->end,root->flag,flag);
	bool nextSignal=(flag+root->flag)%2;
	if(root->start>=start && root->end<=end){
		if((flag))root->val  = root->end-root->start-root->val+1;
		if(root->start!=root->end)root->flag = nextSignal;
		//printf("Returning from exact match with root->val=%d and flag=%d\n",root->val,root->flag);
		return root->val ;
	}
	if(end<root->start || start>root->end){
		if(root->start!=root->end)root->flag = nextSignal;
		if((flag))root->val  = root->end-root->start-root->val+1;
		//printf("Returning with out of range with falg=%d\n",root->flag);
		return 0;
	}
	int sum = count(start,end,root->left ,nextSignal);
	sum    += count(start,end,root->right,nextSignal);
	root->flag= false;
	root->val = getVal(root->left) + getVal(root->right);
	//printf("Returning from exact match with val=%d\n",sum);
	return sum;
}
int main()
{
	int n , q , op , a , b;
	scanf("%d",&n);
	scanf("%d",&q);
	Node *root = createTree(0,n-1);
	while(q!=0){
		scanf("%d %d %d",&op,&a,&b);
		--a;--b;
		switch(op){
		case 0:
			flip(a,b,root,false);
			break;
		case 1:
			printf("%d\n",count(a,b,root,false));
			break;
		}
		--q;
	}
	return 0;
}
