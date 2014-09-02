/*
Project name : Phone_List
Created on : Thu Jun 12 18:26:27 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PHONELST/
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
struct Node{
	vector<Node*> child;
	bool isValid , isTaken;
	Node():
		child(vector<Node*>(10,static_cast<Node*>(NULL))){
			isValid = false;
			isTaken = false;
		}
	void validate(){
		isValid = true;
	}
};
class SuffixTree{
	Node *root;
	bool _isValid;
	bool _node_insert(Node* node , char num[]){
		if(debug)cout<<"inserting "<<num[0]<<endl;
		if(num[0]=='\0'){
			node->validate();
			if(debug)cout<<"node validated"<<endl;
			if(node->isTaken){
				return false;
			}else{
				node->isTaken = true;
				return true;
			}
		}
		node->isTaken = true;
		if(node->isValid){
			if(debug)cout<<"valid node found"<<endl;
			return false;
		}
		int index = num[0]-'0';
		if(node->child[index]==static_cast<Node*>(NULL)){
			if(debug)cout<<"creating node"<<endl;
			node->child[index] = new Node;
		}
		return _node_insert(node->child[index] , num+1);
	}
public:
	SuffixTree():
		root(new Node),
		_isValid(true){
			
		}
	void insert(char n[]){
		if(!_isValid){
			return;
		}
		if(!_node_insert(root,n)){
			_isValid = false;
		}
	}
	bool isValid(){
		return _isValid;
	}
};
class Solver{
	SuffixTree tree;
public:
	Solver(int n){
		char num[10];
		for(int i=0;i<n;++i){
			scanf("%s",num);
			tree.insert(num);
		}
	}
	bool solve(){
		return tree.isValid();
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
		printf("%s\n",s.solve()? "YES" : "NO");
	}
	return 0;
}

