/*
Project name : Remove_Duplicates_from_Sorted_List_II
Created on : Wed Oct  1 12:58:55 2014
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
public:
	bool debug;
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *dummy = new ListNode(INT_MIN)  ;
        dummy->next = head;
        
        ListNode *ptr=dummy , *tmp1 , *tmp2;
        while(ptr!=NULL && ptr->next!=NULL && ptr->next->next!=NULL){
        	if(debug)cout<<"At : "<<ptr->val<<endl;
            if(ptr->next->val==ptr->next->next->val){
            	if(debug)cout<<"Found after "<<ptr->val<<endl;
                tmp1 = ptr->next;
                while(ptr->next->next!=NULL && ptr->next->val==ptr->next->next->val){
                    tmp2 = ptr->next->next;
                    ptr->next->next = tmp2->next;
                    
                    if(debug)cout<<"deleting "<<tmp2->val<<endl;
                    free(tmp2);
                }
                ptr->next = ptr->next->next;
                if(debug)cout<<"deleting first node "<<tmp1->val<<endl;
                free(tmp1);
            }else{
                ptr = ptr->next;
                if(debug)cout<<"going to "<<ptr->val<<endl;
            }
            if(debug)cout<<"=============="<<endl;
        }
        
        tmp1 = dummy->next;
        free(dummy);
        if(debug)cout<<"Returning"<<endl;
        return tmp1;
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug = false;
	}	
	
	int t;
	scanf("%d",&t);
	
	ListNode *head , *ptr;
	int n , x;
	while(t--){
		scanf("%d",&n);
		head=NULL;
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			if(head==NULL){
				head = new ListNode(x);
				ptr = head;
			}else{
				ptr->next = new ListNode(x);
				ptr = ptr->next;
			}	
		}
		head = s.deleteDuplicates(head);
		ptr  = head;
		while(ptr!=NULL){
			cout<<ptr->val<<" ";
			ptr = ptr->next;
		}
		cout<<endl;
		if(s.debug)cout<<"#################################"<<endl;
	}

	
	return 0;
}

