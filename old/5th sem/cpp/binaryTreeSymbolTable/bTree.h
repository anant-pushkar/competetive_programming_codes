#pragma once
#include <string>
struct node{
	node* right;
	node* left;
	std::string key;
	std::string val;
	node(std::string, std::string);
};
class BinaryTree{
	node* _root;
	int _count;
	node* traverse(node*,node*,std::string);
	void insertVal(node*,std::string,std::string);
	void deleteNode(node*,std::string,std::string);
public:
	BinaryTree();
	int size();
	void put(std::string,std::string);
	void remove(std::string);
	std::string search(std::string);
};