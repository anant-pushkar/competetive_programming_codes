/*
Project name : Longest_Palindromic_Substring
Created on : Sat Sep 27 17:38:22 2014
Author : Anant Pushkar
http://www.spoj.com/problems/LPS/
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
	char *str;
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
			
			if(max_len<pal_len[i]){
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
	Solver(char *s , int n):
	size(n),
	max_len(INT_MIN),
	pal_len(vector<int>(2*n+1,-1)),
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
	void print_palin(){
		for(int i=max_index-max_len;i<=max_index+max_len;++i)if(temp[i]!='#'){
			cout<<temp[i];
		}
		cout<<endl;
	}
	int solve(){
		return 2*(max_len/2) + (max_index%2);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	cin>>t;
	
	char str[101];
	while(t--){
		scanf("%s",str);
		Solver s(str,strlen(str));
		s.print_palin();
	}
	
	return 0;
}

