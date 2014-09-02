/*
Project name : Adding_Sevens
Created on : Tue Aug 26 17:47:57 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ANARC08B/
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
string lookup[10] = {"063","010","093","079","106","103","119","011","127","107"};
int get_val(string digit){
	for(int i=0;i<10;++i){
		if(digit==lookup[i]){
			return i;
		}
	}
}
int eval(queue<int> q){
	int val=0;
	while(!q.empty()){
		val = val*10 + q.front();
		q.pop();
	}
	if(debug)cout<<val<<endl;
	return val;
}
string encode(int x){
	stack<string> digits;
	if(debug)cout<<x<<"->";
	
	bool check=true;
	while(x>0 || check){
		digits.push(lookup[x%10]);
		x /= 10;
		check = false;
	}
	
	string code="";
	while(!digits.empty()){
		code = code + digits.top();
		digits.pop();
	}
	if(debug)cout<<code<<endl;
	return code;
}
string process(string query){
	int index=0 , n=0 , l=query.size();
	vector<queue<int> > num(2);
	string digit;
	while(index<l){
		if(query[index]=='+' || query[index]==' ' || query[index]=='\t'){
			n += query[index]=='+' ? 1 : 0;
			index+=1;
		}else if(query[index]=='='){
			break;
		}else{
			digit = query.substr(index , 3);
			num[n].push(get_val(digit));
			index += 3;
		}
	}
	
	return query+encode(eval(num[0]) + eval(num[1]));
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string query;
	while(true){
		getline(cin,query);
		if(query=="BYE"){
			break;
		}
		cout<<process(query)<<endl;
		if(debug)cout<<"============================"<<endl;
	}
	return 0;
}

