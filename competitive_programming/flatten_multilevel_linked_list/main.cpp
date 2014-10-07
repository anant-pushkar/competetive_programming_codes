/*
Project name : flatten_multilevel_linked_list
Created on : Thu Oct  2 21:05:01 2014
Author : Anant Pushkar
geeks for geeks practice
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
struct ListNode{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode():next(NULL),child(NULL),val(INT_MIN){}
    ListNode(int x):next(NULL),child(NULL),val(x){}
};
class Solver{
	int n;
	ListNode *head;
	vector<ListNode*> ptr_arr;
	queue<ListNode*> q;
	void dfs(ListNode *node){
		if(debug)cout<<"dfs on "<<node->val<<endl;
		if(node->child!=NULL){
			if(debug)cout<<"enqueing child "<<node->child->val<<endl;
			q.push(node->child);
		}
		if(node->next==NULL && !q.empty()){
			if(debug)cout<<"pointing next to succeeding level : "<<node->val<<"->"<<q.front()->val<<endl;
			node->next = q.front();
		}else if(node->next!=NULL){
			dfs(node->next);
		}
		if(debug)cout<<"closing "<<node->val<<endl;
	}
public:
	Solver(int x):
	n(x),
	head(NULL),
	ptr_arr(vector<ListNode*>(x,NULL)){
		for(int i=0;i<n;++i){
			ptr_arr[i] = new ListNode(i+1);
		}
		int n_next , n_child;
		cin>>n_next>>n_child;
		
		int from , to;
		while(n_next--){
			cin>>from>>to;
			--from;
			--to;
			ptr_arr[from]->next = ptr_arr[to];
			if(debug)cout<<"Adding next relation : "<<from<<"->"<<to<<endl;
		}
		while(n_child--){
			cin>>from>>to;
			--from;
			--to;
			ptr_arr[from]->child = ptr_arr[to];
			if(debug)cout<<"Adding child relation : "<<from<<"->"<<to<<endl;
		}
		
		int h;
		cin>>h;
		head = ptr_arr[h-1];
	}
	ListNode* solve(){
		q.push(head);
		
		int l;
		ListNode* node;
		while(!q.empty()){
			node = q.front();
			q.pop();
			
			dfs(node);
		}
		
		return head;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	cin>>t;
	
	int n;
	ListNode *head;
	while(t--){
		cin>>n;
		Solver s(n);
		head = s.solve();
		while(head!=NULL){
			cout<<head->val<<" ";
			head = head->next;
		}
		cout<<endl;
	}
	return 0;
}

