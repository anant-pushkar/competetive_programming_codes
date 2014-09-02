/*
Project name : Aaryan_and_the_Magical_Numbers
Created on : Wed Aug 27 16:51:33 2014
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
class Solver{
	string n;
	vector< vector<lld> > lookup;
	lld get_count(int index , bool bounded , bool encountered){
		if(index==n.size()){
			return encountered ? 1 : 0;
		}
		
		int id = (bounded?1:0) | (encountered?2:0);
		if(lookup[id][index]!=INT_MIN){
			return lookup[id][index];
		}
		if(debug)cout<<index<<endl;
		
		int lim = bounded ? n[index]-'0'+1 : 10;
		lld count = 0;
		for(int i=0;i<lim;++i){
			count += get_count(index+1 , (i==n[index]-'0') && bounded , encountered||i==2||i==3||i==5||i==7);
		}
		
		lookup[id][index] = count;
		return count;
	}
public:
	Solver(string num):
	n(num),
	lookup(vector< vector<lld> >(4 , vector<lld>(num.size() , INT_MIN))){
		
	}
	lld solve(){
		return get_count(0 , true , false);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	string n;
	while(t--){
		cin>>n;
		Solver s(n);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

