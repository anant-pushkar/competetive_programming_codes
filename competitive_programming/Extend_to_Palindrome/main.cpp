/*
Project name : Extend_to_Palindrome
Created on : Sat Sep 27 16:54:20 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EPALIN/
Longest palindromic substring : http://www.akalin.cx/longest-palindrome-linear-time
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
inline int get_min(int a , int b){
	return a<b ? a : b;
}
class Solver{
	string str;
	int size , max_index , max_len;
	vector<int> pal_len;
	vector<char> temp;
	int get_next(int i){
		for(int j=i-1;j>i-pal_len[i]-1;--j){
			if(j-pal_len[j]==i-pal_len[i]){
				return 2*i-j;
			}else{
				pal_len[2*i-j] = get_min(pal_len[j] , 2*size+1-2*i+j-1);
				if(debug)cout<<"propogating : "<<j<<"<>"<<2*i-j<<" : "<<pal_len[2*i-j]<<endl;
			}
		}
		return i+pal_len[i]+1;
	}
	void preprocess(){
		pal_len[0] = 0;
		int left , right , len = 2*size+1 , i=1;
		while(i<len){
			if(debug)cout<<"\tcenter : "<<i<<endl;
			left = i-1;
			right= i+1;
			while(left>-1 && right<len && temp[left]==temp[right]){
				--left;
				++right;
			}
			pal_len[i] = right-i-1;
			if(debug)cout<<"pal_len at "<<i<<" : "<<pal_len[i]<<endl;
			
			if(max_len<=pal_len[i]){
				max_len = pal_len[i];
				max_index = i;
			}
			
			i = get_next(i);
		}
	}
	void print_vector(const vector<int> &v){
		int size = v.size();
		for(int i=0;i<size;++i){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
public:
	Solver(string s):
	size(s.size()),
	max_len(INT_MIN),
	pal_len(vector<int>(2*s.size()+1,-1)),
	str(s){
		temp = vector<char>(2*size+1);
		temp[0] = '#';
		for(int i=0;i<size;++i){
			temp[2*i+1]  = str[i];
			temp[2*i+2]= '#';
		}
		preprocess();
		if(debug){
			cout<<"PAL_LEN : "<<endl;
			for(int i=0;i<2*size+1;++i){
				cout<<temp[i]<<" ";
			}
			cout<<endl;
			print_vector(pal_len);
		}
	}
	void print_soln(){
		cout<<str;
		for(int i=max_index-max_len;i>-1;--i)if(temp[i]!='#'){
			printf("%c",temp[i]);
		}
		cout<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string str;
	while(getline(cin,str)){
		Solver s(str);
		s.print_soln();
		if(debug)cout<<"============================="<<endl;
	}
	return 0;
}

