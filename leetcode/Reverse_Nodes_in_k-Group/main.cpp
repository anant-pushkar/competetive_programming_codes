/*
Project name : Reverse_Nodes_in_k-Group
Created on : Wed Oct  8 22:16:32 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
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
class Solution{
	int count_changeable(ListNode *ptr , int k){
		int count=0 , len=0;
		while(ptr!=NULL){
			ptr = ptr->next;
			++len;
		}
		
		if(debug)cout<<"len:"<<len<<endl;
		return len/k;
	}
public:
	bool debug;
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(head==NULL ||head->next==NULL || k==1){
			return head;
		}
		ListNode *dummy = new ListNode(INT_MIN);
		dummy->next = head;
		
		ListNode *node , *ptr , *next , *tmp;
		node = dummy;
		int count , n= count_changeable(node->next,k);
		if(debug)cout<<"n:"<<n<<endl;
		while(n>0 && node!=NULL && node->next!=NULL){
			if(debug)cout<<"changing next slot : "<<node->next->val<<endl;
			ptr = node->next;
			next = node->next->next;
			count = k-1;
			if(debug)cout<<"count:"<<count<<endl;
			while(ptr!=NULL && next!=NULL){
				if(debug)cout<<"reversing : "<<ptr->val<<next->val<<endl;
				tmp = next->next;
				
				next->next = ptr;
				--count;
				ptr = next;
				next= tmp;
				if(count==0){
					break;
				}
			}
			
			node->next->next = next;
			tmp = node->next;
			node->next = ptr;
			
			node = tmp;
			if(debug){
				cout<<"List : ";
				ptr = dummy->next;
				count=10;
				while(ptr!=NULL && --count){
					cout<<ptr->val<<" ";
					ptr = ptr->next;
				}
				cout<<endl;
			}
			--n;
		}
		
		if(debug)cout<<"returnig "<<dummy->next->val<<endl;
		return dummy->next;
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	int n , x , k;
	ListNode *dummy = new ListNode(INT_MIN) , *ptr;
	while(t--){
		cin>>n>>k;
		ptr = dummy;
		for(int i=0;i<n;++i){
			cin>>x;
			ptr->next = new ListNode(x);
			ptr = ptr->next;
		}
		ptr = s.reverseKGroup(dummy->next , k);
		while(ptr!=NULL){
			cout<<ptr->val<<" ";
			ptr = ptr->next;
		}
		cout<<endl;
	}
	
	return 0;
}

