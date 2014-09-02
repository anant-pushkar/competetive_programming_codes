/*
Project name : Reducto
Created on : Tue May 20 20:29:24 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/apc/challenges/reducto
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
class Automata{
	vector<vector<int> > trans;
public:
	void create(char s[51]){
		trans = vector<vector<int> >(strlen(s) , vector<int>(26,0));
		int a=0,b=1;
		trans[0][s[0]-'a'] = 1;
		while(b<strlen(s)){
			for(int i=0;i<26;++i)trans[b][i] = trans[a][i];
			trans[b][s[b]-'a'] = b+1;
			if(s[a]==s[b])++a;
			else a = trans[a][s[a]-'a'];
			++b;
		}
	}
	int getNext(int state , char input){
		return trans[state][input-'a'];
	}
	int isFinal(int state){
		return state==trans.size();
	}
};
class Solver{
	char str[51] , res[50][51];
	vector<Automata> machine;
	int n , index , len;
	vector<int> state;
	char getNext(){
		while(index<len && str[index]=='*')++index;
		return index==len ? '\0' : str[index++];
	}
	void reset(){
		index=0;
		for(int i=0;i<n;++i)state[i]=0;
	}
	void remove(int idx , int l){
		while(l--){
			while(str[idx]=='*')--idx;
			str[idx]='*';
		}
	}
	void print(){
		for(int i=0;i<len;++i)if(str[i]!='*'){
			printf("%c",str[i]);
		}
	}
	int getLen(){
		int l=0;
		for(int i=0;i<len;++i)if(str[i]!='*')++l;
		return l;
	}
public:
	Solver(int num):
		n(num),
		index(0),
		machine(vector<Automata>(num)){
		scanf("%s",str);
		len = strlen(str);
		for(int i=0;i<n;++i){
			scanf("%s",res[i]);
			machine[i].create(res[i]);
		}
	}
	int solve(){
		bool check=true;
		char c;
		state = vector<int>(n,0);
		while(check){
			check=false;
			reset();
			while(true){
				c = getNext();
				if(c=='\0')break;
				for(int i=0;i<n;++i){
					state[i] = machine[i].getNext(state[i],c);
					if(machine[i].isFinal(state[i])){
						remove(index-1,strlen(res[i]));
						check =true;
						reset();
						break;
					}
				}
			}
		}
		if(debug){
			cout<<"Final String : ";
			print();
			cout<<endl;
		}
		return getLen();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%d\n",s.solve());
	}
	return 0;
}

