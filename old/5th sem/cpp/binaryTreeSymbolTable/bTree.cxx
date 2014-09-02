#include "bTree.h"
#include<string>
#include<iostream>
node::node(std::string k, std::string v):
key(k),
val(v),
right(NULL),
left(NULL){
	
}

BinaryTree::BinaryTree():
_count(0),
_root(NULL){

}

int BinaryTree::size()
{
	return _count;
}

void BinaryTree::put(std::string key,std::string val)
{
	if(_count==0){
		//std::cout<<"Creating new node at root."<<std::endl;
		_root = new node(key,val);
		_count++;
	}else{
		node* parent=traverse(_root,NULL,key);
		if(parent==NULL){
			//std::cout<<"Attempting to add child to root."<<std::endl;
			insertVal(_root,key,val);
		}
		else{
			//std::cout<<"Attempting to add new node to pre-exixsting node."<<std::endl;
			insertVal(parent,key,val);
		}
	}
}

void BinaryTree::insertVal(node* parent,std::string key,std::string val)
{
	if(parent==NULL){
		//std::cout<<"Attempting to insert at null root."<<std::endl;
		return;
	}
	//std::cout<<"Attempting an insert at "<<parent->key<<" with val "<<parent->val<<"  |  ";
	if(parent->key.compare(key) > 0){
		if(parent->right==NULL){
			parent->right = new node(key,val);
			_count++;
		}else{
			parent->right->key=key;
			parent->right->val=val;
		}
	}else if(parent->key.compare(key) < 0){
		if(parent->left==NULL){
			parent->left = new node(key,val);
			_count++;
		}else{
			parent->left->key=key;
			parent->left->val=val;
		}
	}
}

void BinaryTree::remove(std::string key)
{
	if(_count==0){
		//std::cout<<"Attempt to remove from empty tree."<<std::endl;
		return;
	}else{
		node* parent=traverse(_root,NULL,key);
		if(parent==NULL){
			//std::cout<<"Attempting to remove child from root."<<std::endl;
			deleteNode(_root,key,val);
		}
		else{
			//std::cout<<"Attempting to remove new node from pre-exixsting node."<<std::endl;
			deleteNode(parent,key,val);
		}
	}
}

void BinaryTree::deleteNode(node* parent,std::string key,std::string val)
{
	if(parent==NULL){
		//std::cout<<"Attempting to delete at null root."<<std::endl;
		return;
	}
	//std::cout<<"Attempting an delete at "<<parent->key<<" with val "<<parent->val<<"  |  ";
	node* element;
	if(parent->key.compare(key) > 0){
		if(parent->right==NULL){
			//std::cout<<"No delete needed."<<std::endl;
			return;
		}else{
			element=parent->right;
			_count--;
		}
	}else if(parent->key.compare(key) < 0){
		if(parent->right==NULL){
			//std::cout<<"No delete needed."<<std::endl;
			return;
		}else{
			element=parent->left;
			_count--;
		}
	}
	if(element->left==NULL){
		//std::cout<<"Left child found to be null."<<std::endl;;
		node* temp=element;
		if(element->right!=NULL)*element = element->right;
		delete temp;
		return;
	}else{
		if(element->right==NULL){
			//std::cout<<"Right child found to be null."<<std::endl;;
			node* temp=element;
			*element = element->left;
			delete temp;
			return;
		}
		if(parent->key.compare(element->key) < 0){
			//std::cout<<"Going to left."<<std::endl;
			parent->left=element->right;
		}
		if(parent->key.compare(element->key) > 0){
			//std::cout<<"Going to right."<<std::endl;
			return traverse(present->right,present,key);
		}
	}
}

std::string BinaryTree::search(std::string key)
{

}

node* BinaryTree::traverse(node* present,node* parent,std::string key)
{
	if(present == NULL || present->key.compare(key) == 0){
		//std::cout<<"Leaf found, returning."<<std::endl;
		return parent;
	}
	if(present->key.compare(key) < 0){
		//std::cout<<"Going to left."<<std::endl;
		return traverse(present->left,present,key);
	}
	if(present->key.compare(key) > 0){
		//std::cout<<"Going to right."<<std::endl;
		return traverse(present->right,present,key);
	}
}






