/*
Project name : Frequent_values
Created on : Wed Sep  3 17:16:57 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FREQUENT/
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
struct Soln{
	int freq , val;
	
	Soln(int v, int f):
	val(v),
	freq(f){
		
	}
	
	Soln(const Soln &s):
	val(s.val),
	freq(s.freq){
		
	}
	
	void print(){
		cout<<"Val : "<<val<<" Freq : "<<freq<<endl;
	}
};
struct Ans{
	Soln left , right , soln;
	
	Ans(Soln l , Soln r , Soln s):
	left(l),
	right(r),
	soln(s){
		
	}
}	;
bool operator>(const Soln &s1 , const Soln &s2){
	return s1.freq>s2.freq;
}
Soln get_max(Soln s1 , Soln s2 , Soln s3){
	return s1>s2 ? s3>s1 ? s3 : s1 : s3>s2 ? s3 : s2;
}
struct Node{
	int start ;
	int end   ;
	Soln left_soln ;
	Soln right_soln;
	Soln soln ;
	Node* left;
	Node* right;
	
	Node(int s,int e):
	start(s),
	end(e),
	left(NULL),
	right(NULL),
	left_soln(Soln(0,0)),
	right_soln(Soln(0,0)),
	soln(Soln(0,0)){
		
	}
	
	Node(const Node &n):
	start(n.start),
	end(n.end),
	left(n.left),
	right(n.right),
	left_soln(n.left_soln),
	right_soln(n.right_soln),
	soln(n.soln){
		
	}
	
	void print(){
		cout<<"Start : "<<start<<endl;
		cout<<"End   : "<<end<<endl;
		
		cout<<"LEFT  : "<<endl;
		left_soln.print();
		
		cout<<"RIGHT : "<<endl;
		right_soln.print();
		
		cout<<"SOLN :"<<endl;
		soln.print();
		
		cout<<"=============================="<<endl;
	}
};
class Solver{
	int n , q;
	Node *root;
	void create_tree(Node *node){
		if(node->end == node->start+1){
			scanf("%d",&node->soln.val);
			node->soln.freq = 1;
			
			node->left_soln = node->soln;
			node->right_soln= node->soln;
			
			return;
		}
		int s=node->start , e=node->end , m=(s+e)/2;
		
		node->left = new Node(s,m);
		create_tree(node->left);
		
		node->right = new Node(m,e);
		create_tree(node->right);
		
		node->left_soln = node->left->left_soln;
		if(node->left->left_soln.val == node->right->left_soln.val){
			node->left_soln.freq += node->right->left_soln.freq;	
		}
		
		node->right_soln= node->right->right_soln;
		if(node->left->right_soln.val == node->right->right_soln.val){
			node->right_soln.freq += node->left->right_soln.freq;
		}
		
		Soln mid(0,-1);
		if(node->left->right_soln.val == node->right->left_soln.val){
			mid.val  = node->left->right_soln.val;
			mid.freq = node->left->right_soln.freq + node->right->left_soln.freq;
		}
		
		node->soln = get_max(mid , node->left->soln , node->right->soln);
		
		if(debug)node->print();
	}
	Ans query(int start , int end , Node* node){
		int s=node->start , e=node->end , m=(s+e)/2;
		if(start==s && end==e){
			return Ans(node->left_soln , node->right_soln , node->soln);
		}
		
		if(start >= m){
			return query(start , end , node->right);
		}else if(end<=m){
			return query(start , end , node->left);
		}
		
		Ans left = query(start,m,node->left);
		Ans right= query(m,end, node->right);
		
		Ans soln(left.left , right.right , Soln(0,0));
		if(left.left.val == right.left.val){
			soln.left.freq += right.left.freq;
		}
		if(right.right.val == left.right.val){
			soln.right.freq += left.right.freq;
		}
		
		Soln mid(0,-1);
		if(left.right.val == right.left.val){
			mid.val = left.right.val;
			mid.freq= left.right.freq + right.left.freq;
		}
		
		soln.soln = get_max(mid , left.soln , right.soln );
		
		return soln;
	}
public:
	Solver(int a,int b):
	n(a),
	q(b),
	root(new Node(0,a)){
		create_tree(root);
	}
	void solve_queries(){
		int x , y;
		while(q--){
			scanf("%d %d",&x,&y);
			--x;
			printf("%d\n",query(x,y,root).soln.freq);
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , q;
	while(true){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		scanf("%d",&q);
	
		Solver s(n,q);
		s.solve_queries();
	}
	
	return 0;
}

