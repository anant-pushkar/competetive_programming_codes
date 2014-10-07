/*
Project name : Delete_N_nodes_after_M_nodes_of_a_linked_list
Created on : Thu Oct  2 21:37:30 2014
Author : Anant Pushkar
http://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
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
public:
	Solver(int x):
	n(x),
	head(new ListNode(INT_MIN)){
		ListNode *ptr = head;
		int val;
		for(int i=0;i<n;++i){
			cin>>val;
			ptr->next = new ListNode(val);
			ptr = ptr->next;
		}
		ptr = head->next;
		free(head);
		head = ptr;
	}
	ListNode *solve(){
		int m,n,x,y;
		cin>>m>>n;
		--m;
		ListNode *node = head , *ptr;
		while(node!=NULL){
			x=m;
			y=n;
			while(node!=NULL && x>0){
				if(debug)cout<<"accepting "<<node->val<<endl;
				node = node->next;
				--x;
			}
			if(debug)cout<<"NODE : "<<(node!=NULL?node->val:-1)<<endl;
			if(node==NULL){
				break;
			}
			while(node->next!=NULL && y>0){
				if(debug)cout<<"rejecting "<<node->next->val<<endl;
				ptr = node->next->next;
				free(node->next);
				node->next = ptr;
				--y;
			}
			node = node->next;
			if(debug)cout<<"NODE : "<<(node!=NULL?node->val:-1)<<endl;
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
	ListNode *node;
	while(t--){
		cin>>n;
		Solver s(n);
		node = s.solve();
		while(node!=NULL){
			cout<<node->val<<" ";
			node=node->next;
		}
		cout<<endl;
	}
	return 0;
}

