/*
Project name : A_Lot_of_Games
Created on : Fri Aug  8 21:34:41 2014
Author : Anant Pushkar
http://codeforces.com/contest/455/problem/B
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
struct Node{
	vector<Node*> child;
	bool e_dirty , o_dirty , even , odd , has_child;
	Node():
	child(vector<Node*>(26,static_cast<Node*>(NULL))),
	e_dirty(true),
	o_dirty(true),
	has_child(false){
		
	}
};
class Trie{
	Node *root;
	int k;
	void add(const string &str , int index , Node* node){
		if(index>=str.size()){
			return;
		}
		if(node->child[str[index]-'a']==static_cast<Node*>(NULL)){
			node->has_child = true;
			node->child[str[index]-'a'] = new Node;
		}
		add(str , index+1 , node->child[str[index]-'a']);
	}
	bool hasEven(Node* node){
		if(!node->has_child){
			return true;
		}
		if(!node->e_dirty){
			return node->even;
		}
		node->e_dirty = false;
		/*bool has_odd=false , has_even=false;
		for(int i=0;i<26;++i)if(node->child[i]!=static_cast<Node*>(NULL)){
			if(hasOdd(node->child[i])){
				has_odd = true;
			}else if(hasEven(node->child[i])){
				has_even= true;
			}
		}
		node->even = has_odd && !has_even;*/
		node->even = !hasOdd(node);
		return node->even;
	}
	bool hasOdd(Node *node){
		if(!node->has_child){
			return false;
		}
		if(!node->o_dirty){
			return node->odd;
		}
		node->o_dirty = false;
		bool has_odd=false , has_even=false;
		for(int i=0;i<26;++i)if(node->child[i]!=static_cast<Node*>(NULL)){
			if(hasEven(node->child[i])){
				has_even = true;
			}else if(hasOdd(node->child[i])){
				has_odd = true;
			}
		}
		node->odd = !has_odd && has_even;
		return node->odd;
	}
public:
	Trie(int n , int x):
	k(x){
		root = new Node;
		string str;
		for(int i=0;i<n;++i){
			cin>>str;
			add(str , 0 , root);
		}
	}
	string get_winner(){
		bool has_even= hasEven(root);
		bool has_odd = hasOdd(root);
		if(has_odd){
			return has_even ? "First" : k%2==1 ? "First" : "Second";
		}else{
			return "Second";
		}
	}
};

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , k;
	cin>>n>>k;
	
	Trie t(n,k);
	cout<<t.get_winner()<<endl;
	
	return 0;
}

