/*
Project name : DISTINCT_DIGITS_II
Created on : Wed Sep 10 15:08:19 2014
Author : Anant Pushkar
http://www.hackerearth.com/the-big-bang-challenge/algorithm/distinct-digits-ii-1/description/
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

const int MAX_TYPE = 1;
const int MIN_TYPE =-1;
const int ADD = 2;
const int MUL = 3;
const int REP = 4;
const int MOD = 1000000007;

struct Soln{
	int n_digits;
	int n_num;
	int type;
	lld val;
	
	Soln(int t , lld x):
	type(t),
	val(x),
	n_num(1),
	n_digits(0){
		update(x);
	}
	
	void update(int x){
		lld mask=0;
		while(x>0){
			mask = mask|(1<<(x%10));
			x /= 10;
		}
		n_digits = 0;
		while(mask>0){
			++n_digits;
			mask = mask&(mask-1);
		}
	}
	
	Soln(const int &t , const Soln &s1 , const Soln &s2):
	type(t),
	val(-1){
		update(s1,s2);
	}
	
	void update(const Soln &s1 , const Soln &s2){
		if(s1.n_digits==s2.n_digits){
			n_digits = s1.n_digits;
			n_num    = s1.n_num + s2.n_num;
		}else if((s1.n_digits-s2.n_digits)*type > 0){
			n_digits = s1.n_digits;
			n_num    = s1.n_num;
		}else{
			n_digits = s2.n_digits;
			n_num    = s2.n_num;
		}
	}
	
};
struct Node{
	Soln * max_soln , *min_soln;
	int start;
	int end;
	Node * right;
	Node * left ;
	
	Node(int s , int e):
	start(s),
	end(e),
	max_soln(NULL),
	min_soln(NULL),
	left(NULL),
	right(NULL){
		
	}
};
class Solver{
	Node * root;
	int n;
	
	void create_tree(Node* node){
		int s = node->start , e = node->end , mid=(s+e)/2;
		if(e==s+1){
			lld x;
			scanf("%lld",&x);
			node->max_soln = new Soln(MAX_TYPE , x);
			node->min_soln = new Soln(MIN_TYPE , x);
			
			return ;
		}
		node->left = new Node(s,mid);
		create_tree(node->left);
		
		node->right= new Node(mid,e);
		create_tree(node->right);
		
		node->max_soln = new Soln(MAX_TYPE , *(node->left->max_soln) , *(node->right->max_soln));
		node->min_soln = new Soln(MIN_TYPE , *(node->left->min_soln) , *(node->right->min_soln));
	}
	
	void update(int type , Node* node , int u , lld v){
		int s = node->start , e = node->end , mid=(s+e)/2;
		if(s==u && e==u+1){
			int x;
			switch(type){
				case ADD:
					x = (node->max_soln->val+v)%MOD;
					break;
				case MUL:
					x = (node->max_soln->val*(v%MOD))%MOD;
					break;
				case REP:
					x = v%MOD;
					break;
			}
			node->max_soln->update(x);
			node->min_soln->update(x);
			
			return ;
		}
		
		if(u<mid){
			update(type , node->left  , u , v);
		}else{
			update(type , node->right , u , v);
		}
		
		node->max_soln->update(*(node->left->max_soln) , *(node->right->max_soln));
		node->min_soln->update(*(node->left->min_soln) , *(node->right->min_soln));
	}
	
	Soln query(int type , Node *node , int start , int end){
		int s = node->start , e = node->end , mid=(s+e)/2;
		if(s==start && e==end){
			switch(type){
				case MAX_TYPE:
					return *(node->max_soln);
				case MIN_TYPE:
					return *(node->min_soln);
			}
		}
		if(end<=mid){
			return query(type , node->left , start , end);
		}else if(start>=mid){
 			return query(type , node->right , start, end);
		}
		Soln left_soln = query(type , node->left , start , mid);
		Soln right_soln= query(type , node->right, mid   , end);
		
		return Soln(type , left_soln , right_soln);
	}
public:
	Solver(int x):
	n(x){
		root = new Node(0,n);
		create_tree(root);
	}
	
	void solve_query(){
		string cmd ;
		int a ;
		lld b ;
		cin>>cmd>>a>>b;
		--a;
		
		if(cmd=="ADD"){
			update(ADD , root , a,b);
		}else if(cmd=="MUL"){
			update(MUL , root , a,b);
		}else if(cmd=="REP"){
			update(REP , root , a,b);
		}else if(cmd=="MAX"){
			Soln s = query(MAX_TYPE , root , a , b);
			cout<<s.n_digits<<" "<<s.n_num<<endl;
		}else{
			Soln s = query(MIN_TYPE , root , a , b);
			cout<<s.n_digits<<" "<<s.n_num<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	int q;
	scanf("%d",&q);
	while(q--){
		s.solve_query();
	}
	
	
	return 0;
}

