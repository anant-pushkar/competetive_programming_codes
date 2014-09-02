/*
Project name : Huffman_Encoder
Created on : Sat Jul 19 11:15:03 2014
Author : Anant Pushkar
Huffman encoding algorithm for both sorted and unsorted input
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
struct character{
	char symbol;
	char* code;
	int freq; 
	int code_size;
	
	character():
	symbol(' '),
	code(NULL),
	code_size(0),
	freq(0){
		
	}
	
	void allocate(int n){
		code_size = n;
		code = new char[n+1];
	}
};

struct node{
	int freq;
	character * char_ptr;
	node * left , *right;
	
	node():
	char_ptr(NULL),
	freq(0),
	left(NULL),
	right(NULL){
		
	}
	
	node(character * c_ptr):
	char_ptr(c_ptr),
	freq(c_ptr->freq),
	left(NULL),
	right(NULL){
		
	}
	
	node(node * n1 , node * n2):
	freq(n1->freq+n2->freq),
	char_ptr(NULL),
	left(NULL),
	right(NULL){
		
	}
	
	node(const node &n):
	freq(n.freq),
	char_ptr(n.char_ptr),
	left(n.left),
	right(n.right){
		
	}
};

bool operator<(const node &n1 , const node &n2){
	return n1.freq > n2.freq;
}

class tree{
	node * root;
	void encode(node* node_ptr , queue<char> *q){
		if(node_ptr->char_ptr != NULL){
			if(debug)cout<<"Encoding "<<node_ptr->char_ptr->symbol<<endl;
			node_ptr->char_ptr->allocate(q->size());
			int index=0;
			while(!q->empty()){
				node_ptr->char_ptr->code[index++] = q->front();
				q->pop();
			}
			node_ptr->char_ptr->code[index] = '\0';
			return;
		}
		if(debug)cout<<"encode() called on node with freq "<<node_ptr->freq<<endl;
		queue<char> temp = *q;
		temp.push('1');
		q->push('0');
		
		encode(node_ptr->left , q);
		encode(node_ptr->right, &temp);
	}
public:
	tree(node * node_ptr):
	root(node_ptr){
		
	}
	
	void encode_all(){
		queue<char> q;
		encode(root , &q);
	}
};

class alphabet{
	vector<character> char_list;
	int size;
	node getMin(queue<node> &q1 , queue<node> &q2){
		node n;
		if(q1.empty()){
			n = q2.front();
			q2.pop();
		}else if(q2.empty()){
			n = q1.front();
			q1.pop();
		}else{
			if(q1.front().freq < q2.front().freq){
				n = q1.front();
				q1.pop();
			}else{
				n = q2.front();
				q2.pop();
			}
		}
		return n;
	}
public:
	alphabet(int n , char * c_list):
	char_list(vector<character>(n)),
	size(n){
		if(debug)cout<<"Creating ordered alphabet"<<endl;
		for(int i=0;i<n;++i){
			char_list[i].symbol = c_list[i];
		}
	}
	
	alphabet(int n , char * c_list , int * f_list):
	char_list(vector<character>(n)),
	size(n){
		if(debug)cout<<"Creating unordered alphabet"<<endl;
		for(int i=0;i<n;++i){
			char_list[i].symbol = c_list[i];
			char_list[i].freq   = f_list[i];
		}
	}
	
	void ordered_huffman(){
		if(debug)cout<<"Creating tree for ordered huffman"<<endl;
		queue<node> q1 , q2;
		for(int i=0;i<size;++i){
			q1.push(node(&char_list[i]));
			if(debug)cout<<char_list[i].symbol<<" added"<<endl;
		}
		
		node *n1 , *n2 , *n3;
		while(q1.size() + q2.size()>1){
			n1 = new node(getMin(q1,q2));
			n2 = new node(getMin(q1,q2));
			
			n3 = new node(n1,n2);
			n3->left  = n1;
			n3->right = n2;
			q2.push(*n3);
			
			if(debug){
				cout<<"New node with freq = "<<n3->freq<<" added"<<endl;
				cout<<"left freq : "<<n3->left->freq<<endl;
				cout<<"right freq : "<<n3->right->freq<<endl;
				cout<<endl;
			}
		}
		node n = getMin(q1,q2);
		tree t(&n);
		t.encode_all();
	}
	
	void unordered_huffman(){
		if(debug)cout<<"Creating tree for unordered huffman"<<endl;
		priority_queue<node> pq;
		for(int i=0;i<size;++i){
			pq.push(node(&char_list[i]));
			if(debug)cout<<char_list[i].symbol<<" added"<<endl;
		}
		
		node *n1 , *n2 , *n3;
		while(pq.size()>1){
			n1 = new node(pq.top());
			pq.pop();
			
			n2 = new node(pq.top());
			pq.pop();
			
			n3 = new node(n1,n2);
			n3->left  = n1;
			n3->right = n2;
			pq.push(*n3);
			
			if(debug){
				cout<<"New node with freq = "<<n3->freq<<" added"<<endl;
				cout<<"left freq : "<<n3->left->freq<<endl;
				cout<<"right freq : "<<n3->right->freq<<endl;
				cout<<endl;
			}
		}
		
		node n = pq.top();
		pq.pop();
		tree t(&n);
		t.encode_all();
	}
	
	void print_codes(){
		for(int i=0;i<size;++i){
			cout<<char_list[i].symbol<<"{"<<char_list[i].freq<<"} : "<<char_list[i].code<<endl;
		}
	}
};

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	char * c_list , c , mode;
	int  * f_list;
	
	while(t--){
		scanf("%d",&n);
		scanf("%c",&c);
		scanf("%c",&mode);
		c_list = new char[n];
		f_list = new int[n] ;
		
		for(int i=0;i<n;++i){
			scanf("%c",&c);
			scanf("%c",&c_list[i]);
		}
		
		if(mode=='u'){
			for(int i=0;i<n;++i){
				scanf("%d",&f_list[i]);
			}
			
			alphabet a(n,c_list,f_list);
			a.unordered_huffman();
			a.print_codes();
			
		}else if(mode=='o'){
			alphabet a(n,c_list);
			a.ordered_huffman();
			a.print_codes();
		}
		
		delete c_list;
		delete f_list;
	}
	return 0;
}

