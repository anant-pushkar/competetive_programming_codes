#include"tree.h"
#include"queue.h"
#define MAX 1000
node *generateRandom(int n, int r1,int r2)
{
	if(n<1) return NULL;
	node *newNode=(node*)malloc(sizeof(node));
	newNode->val=rand()%MAX;
	printf("%d added to tree\n",newNode->val);
	newNode->left = generateRandom(n/r1 , r1,r2);
	newNode->right= generateRandom(n/r2 , r1,r2);
	return newNode;
}
static node *insertToBST(int n,node *root)
{
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->val=n;
		printf("%d added to BST\n",n);
	}
	else if(n<root->val){
		root->left = insertToBST(n,root->left);
	}else if(n>root->val){
		root->right= insertToBST(n,root->right);
	}
	return root;
}
node *generateBST(int n)
{
	int i,val;
	node *root=NULL;
	for(i=0;i<n;i++){
		root=insertToBST(rand()%MAX,root);
	}
	return root;
}
int getParents(int n , node* root)
{
	if(root== NULL ) return 0;
	if(root->val==n){
		printf("%d(found) ",n);
		return 1;
	}
	int check=getParents(n,root->left)+getParents(n,root->right);
	if(check==0) return 0;
	if(check==1){
		printf("%d , ",root->val);
		return 1;
	}
	if(check==2){
		printf("%d(common parent) , ",root->val);
		return 1;
	}
}
int getLeastCommonParent(int n1, int n2, node* root)
{
	if(root==NULL) return 0;
	if(root->val==n1 || root->val==n2) return 1;
	int check=getLeastCommonParent(n1,n2,root->left) + getLeastCommonParent(n1,n2,root->right);
	if(check==0) return 0;
	if(check==1) return 1;
	if(check==2){
		printf("Common parent found : %d\n",root->val);
		return 1;
	}
}
int checkBalance(node *root)
{
	if(root==NULL) return 1;
	int leftCount=checkBalance(root->left);
	int rightCount=checkBalance(root->right);
	if(rightCount-leftCount>1) printf("Tree right biased at : %d\n",root->val);
	if(leftCount-rightCount>1) printf("Tree left biased at : %d\n", root->val);
	return leftCount+rightCount;
}
void checkBSTBalance(node *root,queue *q,int max,int min)
{
	if(root==NULL) return;
	if(max!=-1){
		if(root->val>max){
			printf("Max limit exceeded at %d\n",root->val);
		}
	}
	if(min!=-1){
		if(root->val<min){
			printf("Min limit exceeded at %d\n",root->val);
		}
	}
	if(root->left!=NULL){
		if(root->left->val > root->val){
			printf("BST unbalanced at %d->%d\n",root->val,root->left->val);
			enqueue(q,root->left,0) ;
			enqueue(q,root,0);
		}
	}
	if(root->right!=NULL){
		if(root->right->val < root->val){
			printf("BST unbalanced at %d->%d\n",root->val,root->right->val);
			enqueue(q,root,0);
			enqueue(q,root->right,0);
		}
	}
	checkBSTBalance(root->left, q,root->val,min);
	checkBSTBalance(root->right,q,max,root->val);
}
void swap(node *root)
{
	node *ptr=root,*tempPtr;
	
	while(ptr->left->left->left!=NULL) ptr=ptr->left;
	tempPtr = ptr;
	ptr=root;
	
	while(ptr->right->right->left!=NULL) ptr=ptr->right;
	
	printf("Swaping %d ,%d\n",ptr->val,tempPtr->val);
	int temp;
	temp=ptr->val;
	ptr->val=tempPtr->val;
	tempPtr->val=temp;
}
node *getMaxAlt(queue *q)
{
	link *temp=q->front;
	node *n;
	int max=-1;
	while(temp!=NULL){
		if(max<temp->n->val){
			max= temp->n->val;
			n  = temp->n;
		}
		if(temp->next==NULL) break;
		temp=temp->next->next;
	}
	return n;
}
node *getMinAlt(queue *q)
{
	link *temp=q->front->next;
	node *n;
	int min=MAX;
	while(temp!=NULL){
		if(min>temp->n->val){
			min= temp->n->val;
			n  = temp->n;
		}
		if(temp->next==NULL) break;
		temp=temp->next->next;
	}
	return n;
}
void restore(node* root)
{
	queue *q=initQ();
	checkBSTBalance(root,q,-1,-1);
	
	if(q->size==0){
		printf("BST already in order\n");
		return;
	}
	
	node *nMax=getMaxAlt(q) , *nMin=getMinAlt(q);
	
	printf("Swaping %d,%d\n",nMax->val,nMin->val);
	int temp=nMin->val;
	nMin->val=nMax->val;
	nMax->val=temp;
	printf("BST restored :)\n");
}
void levelOrderTraversal(node* root)
{
	queue *q  = initQ();
	
	node* ptr = root;
	int level=0;
	enqueue(q,ptr,level);
	while(q->size!=0){
		if(getFrontLevel(q)!=level) printf("\n");
		ptr=getFront(q);
		level=getFrontLevel(q);
		if(ptr->right!=NULL) enqueue(q,ptr->right,level+1);
		if(ptr->left !=NULL) enqueue(q,ptr->left ,level+1);
		dequeue(q);
		printf("%d ",ptr->val);
	}
	printf("\nHeight of tree : %d  \n",level+1);
}

node *find(node* root , int n)
{
	if(root==NULL || root->val==n) return root;
	if(root->val > n) return find(root->left,n);
	else return find(root->right,n);
}

int traversePara(node* t1 , node* t2)
{
	if(t1==NULL && t2==NULL) return 0;
	if( ( t1!=NULL && t2==NULL ) || ( t1==NULL && t2!=NULL ) ) return -1;
	if(t1->val!=t2->val) return -1;
	
	int n=traversePara(t1->left , t2->left);
	if(n<0) return -1;
	
	n=traversePara(t1->right , t2->right);
	if(n<0) return -1;
	
	return 0;
}

node *getSubTree(node* root , int n)
{
	int temp=n;
	while(n>temp/2 && root!=NULL){
		n--;
		root=root->left;
	}
	while(n>0 && root!=NULL){
		n--;
		root=root->right;
	}
	return root;
}

int checkSubTree(node* t1 , node* t2)
{
	node* ptr=find(t1,t2->val);
	if(ptr==NULL) return -1;
	return traversePara(ptr,t2);
}
node* _getNext(int val , node *root){
	node *ptr;
	if(root->val==val){
		ptr = root->right;
		if(ptr==NULL){
			return root;
		}else{
			while(ptr!=NULL){
				ptr=ptr->left;
			}
			return ptr;
		}
	}else if(root->val > val){
		ptr = _getNext(val , root->left);
		if(ptr!=NULL){
			if(ptr->val==val){
				return root;
			}else{
				return ptr;
			}
		}
	}
	else{
		ptr = _getNext(val , root->right);
		if(ptr!=NULL){
			return ptr;
		}
	}
	return NULL;
}
int getNext(node* root , int val){
	node *ptr = _getNext(val,root);
	return ptr->val;
}
node* convertToDList(node* root , int mode){
	if(root==NULL) return NULL;
	root->left = convertToDList(root->left , -1);
	if(root->left!=NULL)root->left->right=root;
	root->right= convertToDList(root->right,  1);
	if(root->right!=NULL)root->right->left=root;
	node* ptr=root;
	if(mode==-1){
		while(ptr->right!=NULL){
			ptr=ptr->right;
		}
	}
	if(mode== 1){
		while(ptr->left!=NULL){
			ptr=ptr->left;
		}
	}
	return ptr;
}
node* getDList(node *root){
	convertToDList(root,0);
	node* ptr=root;
	while(ptr->right!=NULL){
		ptr=ptr->right;
	}
	return ptr;
}
void printDList(node *root){
	while(root!=NULL){
		printf("%d ",root->val);
		root=root->left;
	}
	printf("\n");
}





















