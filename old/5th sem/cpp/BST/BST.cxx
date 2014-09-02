#include "BST.h"
node::node(std::string k, std::string v):
size(1),
key(k),
val(v),
right(NULL),
left(NULL){
	
}

BST::BST():
_root(NULL){

}

int BST::size()
{
	return _getSize(_root);
}

int BST::_getSize(node* n)
{
	return n==NULL ? 0 : n->size;
}

void BST::put(std::string key , std::string val)
{
	_root=_put(_root,key,val);
}

node* BST::_put(node* present, std::string k , std::string v)
{
	if(present==NULL) present = new node(k,v);
	else if(present->key.compare(k)>0) present->left=_put(present->left,k,v);
	else if(present->key.compare(k)<0) present->right=_put(present->right,k,v);
	else present->val = v;
	present->size = _getSize(present->left) + _getSize(present->right) + 1;
	return present;
}

void BST::remove(std::string key)
{
	_remove(_root,key);
}

node* BST::_remove(node*& present, std::string k)
{
	if(present==NULL) return NULL;
	else if(present->key.compare(k)>0) present->left=_remove(present->left,k);
	else if(present->key.compare(k)<0) present->right=_remove(present->right,k);
	else{
		node* leaf;
		if(present->right==NULL && present->left==NULL) return NULL;
		else if(present->right!=NULL) leaf=_deleteMin(present->right);
		else leaf=_deleteMax(present->left);
		present->val=leaf->val;present->key=leaf->key;
	}
	present->size = _getSize(present->left) + _getSize(present->right) + 1;
	return present;
}

node* BST::_deleteMin(node*& present)
{
	node* ptr=NULL;
	if(present->left==NULL)
	{
		ptr = new node(present->key,present->val);
		present=present->right;
	}else{
		ptr=_deleteMin(present->left);
		present->size = _getSize(present->left) + _getSize(present->right) + 1;
	}
	return ptr;
}

node* BST::_deleteMax(node*& present)
{
	node* ptr=NULL;
	if(present->right==NULL)
	{
		ptr = new node(present->key,present->val);
		present=present->left;
	}else{
		ptr=_deleteMin(present->right);
		present->size = _getSize(present->left) + _getSize(present->right) + 1;
	}
	return ptr;
}

std::string BST::search(std::string key)
{
	node* result=_search(_root,key);
	return result==NULL ? "Key not Found" : result->val;
}

node* BST::_search(node* present,std::string k)
{
	if(present==NULL) return NULL;
	if(present->key.compare(k)>0) return _search(present->left,k);
	if(present->key.compare(k)<0) return _search(present->right,k);
	else return present;
}	

std::string BST::min()
{
	return _min(_root)->val;
}

node* BST::_min(node* present)
{
	if(present->left==NULL) return present;
	return _min(present->left);
}

std::string BST::max()
{
	return _max(_root)->val;
}

node* BST::_max(node* present)
{
	if(present->right==NULL) return present;
	return _max(present->right);
}

std::string BST::floor(std::string key)
{
	node* result = _search(_root,key);
	if(result==NULL) return "Invalid Key.";
	if(result->left!=NULL) return _max(result->left)->val;
	result=_leftParent(key);
	if(result==NULL) return "No Floor exists";
	return result->val;
}

std::string BST::ceiling(std::string key)
{
	node* result = _search(_root,key);
	if(result==NULL) return "Invalid Key.";
	if(result->right!=NULL) return _min(result->right)->val;
	result=_rightParent(key);
	if(result==NULL) return "No Ceiling Exists";
	return result->val;
}

node* BST::_leftParent(std::string k)
{
	node* ptr=_root;
	if(ptr->right!=NULL && ptr->right->key==k) return ptr;
	do{
		if(ptr->key.compare(k)>0) ptr=ptr->left;
		else if(ptr->key.compare(k)<0) ptr=ptr->right;
		else if(ptr==NULL) break;
	}while(ptr->right!=NULL && ptr->right->key!=k);
	return ptr->right==NULL ? NULL : ptr;
}

node* BST::_rightParent(std::string k)
{
	node* ptr=_root;
	if(ptr->left!=NULL && ptr->left->key==k) return ptr;
	do{
		if(ptr->key.compare(k)>0) ptr=ptr->left;
		else if(ptr->key.compare(k)<0) ptr=ptr->right;
		else if(ptr==NULL) break;
	}while(ptr->left!=NULL && ptr->left->key!=k);
	return ptr->left==NULL ? NULL : ptr;
}










