/*
Project name : Remy_paints_the_fence
Created on : Tue Oct  7 09:33:47 2014
Author : Anant Pushkar
http://www.codechef.com/OCT14/problems/FATCHEF
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
const int mod = 1000000009;
inline int get_max(int a , int b){
	return a>b ? a : b;
}
class Solver{
	int n , m;
	vector<char> color;
	deque<int>  color_count;

public:
	Solver(int x , int y):
	n(x),
	m(y),
	color(vector<char>(n,'\0')){
		char c[2];
		int index;
		for(int i=0;i<m;++i){
			cin>>c>>index;
			--index;
			color[index] = c[0];
		}
		if(debug){
			cout<<"color profile: ";
			for(int i=0;i<n;++i){
				cout<<(color[i]=='\0' ? '0' : color[i])<<" ";
			}
			cout<<endl;
		}
	}
	llu solve(){
		int index=0;
		while(index<n && color[index]=='\0'){
			++index;
		}
		int count=1;
		char c=color[index++];
		llu result=1;
		while(index<n){
			if(color[index]!='\0' && color[index]!=c){
				c = color[index];
				result *= count;
				result  = result%mod;
				count= 1;
			}else{
				++count;
			}
			++index;
		}
		
		return result;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	cin>>t;
	
	int n,m;
	while(t--){
		cin>>n>>m;
		Solver s(n,m);
		cout<<s.solve()<<endl;
	}
	return 0;
}

