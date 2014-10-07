/*
Project name : quicksort_on_linked_list
Created on : Thu Oct  2 21:58:37 2014
Author : Anant Pushkar
g4g practice
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
    ListNode():next(NULL),val(INT_MIN){}
    ListNode(int x):next(NULL),val(x){}
};
class Solver{
	int n;
	ListNode *head;
	ListNode* quicksort(ListNode *node){
		if(node==NULL || node->next==NULL){
			return node;
		}
		ListNode* pivot = node , *left_head = new ListNode() , *right_head = new ListNode() , *ptr = pivot->next;
		ListNode* left_tail = left_head , *right_tail = right_head;
		if(debug)cout<<endl<<endl<<"pivot "<<pivot->val<<endl;
		while(ptr!=NULL){
			if(ptr->val<pivot->val){
				if(debug)cout<<"pushing "<<ptr->val<<" to left"<<endl;
				left_tail->next = ptr;
				left_tail = ptr;
				ptr = ptr->next;
				left_tail->next = NULL;
			}else{
				if(debug)cout<<"pushing "<<ptr->val<<" to right"<<endl;
				right_tail->next = ptr;
				right_tail = ptr;
				ptr = ptr->next;
				right_tail->next = NULL;
			}
		}
		left_head  = quicksort(left_head->next);
		right_head = quicksort(right_head->next);
		
		if(left_head==NULL){
			pivot->next = right_head;
			return pivot;
		}
		ptr =  left_head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = pivot;
		pivot->next = right_head;
		
		return left_head;
	}
public:
	Solver(int x):
	n(x),
	head(new ListNode(INT_MIN)){
		int val;
		ListNode *ptr = head;
		for(int i=0;i<n;++i){
			cin>>val;
			ptr->next = new ListNode(val);
			ptr = ptr->next;
		}
		ptr = head;
		head = head->next;
		free(ptr);
	}
	void sort(){
		head = quicksort(head);
	}
	void print_list(){
		ListNode *ptr = head;
		while(ptr!=NULL){
			cout<<ptr->val<<" ";
			ptr = ptr->next;
		}
		cout<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		cin>>n;
		Solver s(n);
		s.sort();
		s.print_list();
	}
	return 0;
}

