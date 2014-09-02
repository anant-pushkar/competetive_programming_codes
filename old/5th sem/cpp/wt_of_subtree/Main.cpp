/*
Project name : wt_of_subtree
Created on : Thu Dec 12 16:08:32 IST 2013
http://www.careercup.com/question?id=5648527329853440
Question: You are given a CSV file with 3 columns -- all integers: 
		id,parent,weight 
		10,30,1 
		30,0,10 
		20,30,2 
		50,40,3 
		40,30,4 

0 is the assumed root node with weight 0 

which describes a tree-like structure -- each line is a node, 'parent' refers to 'id' of another node. 

Print out, for each node, the total weight of a subtree below this node (by convention, the weight of a subtree for node X includes the own weight of X). 

You may assume that the input comes pre-parsed as a sequence of Node objects 
(substitute the appropriate syntax for java/python/c++): 

Node { 
	int id; 
	int parent; 
	int weight; 
// ... you can add other fields right here, if necessary 
} 

implement the following: 
public void printSubTreeWeight(List<Node> nodes) { 
....}
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
bool debug=false;
struct Node{
	int id; 
	int parent; 
	int weight; 
};
void printSubTreeWeight(vector<Node> nodes){
	int size=nodes.size(),root,index,temp;
	vector<int>val(size,0);
	vector<stack<int> > child(size);
	unordered_map<int,int> indexOf;
	vector<bool> lookup(size,false);
	for(int i=0;i<size;++i){
		indexOf[nodes[i].id]=i;
		if(nodes[i].parent==0)root=i;
	}
	for(int i=0;i<size;++i)if(nodes[i].parent!=0){
		child[indexOf[nodes[i].parent]].push(i);
	}
	stack<int> s,sum;
	s.push(root);sum.push(nodes[root].weight);
	lookup[root]=true;
	while(!s.empty()){
		index=s.top();
		if(!child[index].empty()){
			int c_index=child[index].top();
			if(!lookup[c_index]){
				s.push(c_index);
				sum.push(nodes[c_index].weight);
				lookup[c_index]=true;
			}
			child[index].pop();
		}else{
			val[index]=sum.top();
			temp=sum.top();sum.pop();
			if(!sum.empty()){
				temp+=sum.top();sum.pop();
				sum.push(temp);
			}
			s.pop();
		}
	}
	for(int i=0;i<size;++i)cout<<val[i]<<" ";
	cout<<endl;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	vector<Node> v;
	int t,n;cin>>t;
	while(t--){
		cin>>n;
		v=vector<Node>(n);
		for(int i=0;i<n;++i)cin>>v[i].id>>v[i].parent>>v[i].weight;
		printSubTreeWeight(v);
	}
	return 0;
}

