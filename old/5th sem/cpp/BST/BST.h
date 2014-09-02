#pragma once
#include<string>
struct node{
	int size;
	node* right;
	node* left;
	std::string key;
	std::string val;
	node(std::string, std::string);
};
class BST{
	node* _root;
	node* _put(node*,std::string,std::string);
	node* _search(node*,std::string);
	node* _remove(node*&,std::string);
	int   _getSize(node*);
	node* _min(node*);
	node* _max(node*);
	node* _deleteMin(node*&);
	node* _deleteMax(node*&);
	node* _leftParent(std::string);
	node* _rightParent(std::string);
public:
	BST();
	int size();
	void put(std::string,std::string);
	void remove(std::string);
	std::string search(std::string);
	std::string min();
	std::string max();
	std::string floor(std::string);
	std::string ceiling(std::string);
};