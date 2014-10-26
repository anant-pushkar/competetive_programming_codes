/*
Project name : doubly_linked_list_stack
Created on : Sun Oct 26 15:26:58 2014
Author : Anant Pushkar
http://www.careercup.com/question?id=5964523655659520
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
#include<csignal>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class DoublyLinkedList{
	stack<int> front;
	stack<int> back;
public:
	int get_cur(){
		if(back.empty() && front.empty()){
			raise(SIGSEGV);
		}
		return !back.empty() ? back.top() : front.top();
	}
	void push_front(int val){
		front.push(val);
	}
	void push_back(int val){
		int x = back.top();
		back.pop();
		
		back.push(val);
		back.push(x);
	}
	void move_front(){
		if(back.empty()){
			back.push(front.top());
			front.pop();
		}
		back.push(front.top());
		front.pop();
	}
	void move_back(){
		if(back.size()==1){
			raise(SIGSEGV);
		}
		front.push(back.top());
		back.pop();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	DoublyLinkedList dll;
	dll.push_front(1);
	dll.push_front(2);
	dll.push_front(3);
	cout<<dll.get_cur()<<endl;
	dll.move_front();
	cout<<dll.get_cur()<<endl;
	dll.push_front(4);
	cout<<dll.get_cur()<<endl;
	dll.move_front();
	cout<<dll.get_cur()<<endl;
	dll.move_back();
	cout<<dll.get_cur()<<endl;
	dll.move_back();
	cout<<dll.get_cur()<<endl;
	dll.move_front();
	cout<<dll.get_cur()<<endl;
	dll.move_front();
	cout<<dll.get_cur()<<endl;
	dll.move_front();
	cout<<dll.get_cur()<<endl;
	
	
	return 0;
}

