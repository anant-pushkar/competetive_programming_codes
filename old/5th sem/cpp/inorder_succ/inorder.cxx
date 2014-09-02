#include"inorder.h"
#include<ctime>
#include<cstdlib>
static const int MAX=100;
using namespace std;
Node::Node(int val , Node* p):
parent(p),
left(NULL),
right(NULL),
data(val)
{}

BST::BST(int n):
size(n)
{
	if(size==0){
		root=NULL;
		return;
	}
	srand(time(NULL));
	Node* root = new Node(rand()%MAX);
	cout<<"BST initialised with "<<root->data<<endl;
	for(int i=1;i<size;i++){
		insert(rand()%MAX);
	}
}

void BST::insert(int n)
{
	Node* ptr=root , *temp , *newNode = new Node(n);
	while(ptr!=NULL){
		temp=ptr;
		if(ptr->data > n) ptr=ptr->left;
		else if(ptr->data < n) ptr=ptr->right;
		else break;
	}
	if(ptr!=NULL) return;//if n already exists in BST 
	
	if(temp->data > n) 
		 temp->left=newNode;
	else temp->right=newNode;
	newNode->parent=temp;
	cout<<n<<" added to BST"<<endl;
}

Node* BST::find(int n)
{
	Node* ptr=root;
	while(ptr!=NULL){
		if(ptr->data > n) ptr=ptr->left;
		else if(ptr->data < n) ptr=ptr->right;
		else break; 
	}
	return ptr;
}

Node *BST::findLeftMost(Node* ptr)
{
	while(ptr->left!=NULL) ptr=ptr->left;
	return ptr;
}

Node *BST::succesor(Node *ptr , int n)
{
	if(ptr==NULL) return NULL;
	Node* temp;
	if(ptr->right!=NULL){
		temp = findLeftMost(ptr->right);
		if(temp->data > n) return temp;
	}
	if(ptr->parent!=NULL && ptr->parent->left == ptr) return ptr->parent;
	else return succesor(ptr->parent , n);
}

int BST::getSuccesor(int n)
{
	Node* ptr=find(n);
	if(ptr==NULL){
		cout<<"No node with the given value exists"<<endl;
		return -1;
	}
	ptr=succesor(ptr , n);
	if(ptr==NULL){
		cout<<"the given node has the maximum value in the tree"<<endl;
		return -1;
	}
	return ptr->data;
}














