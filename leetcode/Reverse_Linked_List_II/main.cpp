/*
Project name : Reverse_Linked_List_II
Created on : Tue Sep 30 13:40:29 2014
Author : Anant Pushkar

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *reverse(ListNode* head , int count){
        ListNode *pre=head , *next=head->next , *tmp=NULL;

        while(count>1){
            tmp = next->next;
            if(debug)cout<<next->val<<"->"<<pre->val<<endl;
            next->next = pre;
            pre = next;
            next = tmp;
            
            --count;
        }
        head->next = next;
        if(debug)cout<<head->val<<"->"<<(next==NULL ? -1 : next->val)<<endl;
        if(debug)cout<<"returing "<<pre->val<<endl;
        return pre;
    }
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n){
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int i = 0;
        
        ListNode* tmp = dummy;
        while(i<m-1){
            if(tmp==NULL){
                return dummy->next;
            }
            if(debug)cout<<"tmp : "<<tmp->val<<endl;
            tmp = tmp->next;
            ++i;
        }
        if(tmp==NULL){
            return dummy->next;
        }
        if(debug)cout<<"tmp : "<<tmp->val<<endl;
        if(debug)cout<<"reversing from "<<tmp->next->val<<endl;
        tmp->next = reverse(tmp->next,n-m+1);
        if(debug)cout<<tmp->val<<"->"<<(tmp->next==NULL ? -1 : tmp->next->val)<<endl;
        if(debug)cout<<dummy->val<<"->"<<(dummy->next==NULL ? -1 : dummy->next->val)<<endl;
        return dummy->next;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(5);
	Solution s;
	head = s.reverseBetween(head , 1 , 2);
	if(debug)cout<<"printing"<<endl;
	while(head!=NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}

