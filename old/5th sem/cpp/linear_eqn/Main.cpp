#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
const int ADD=-1;
const int SUB=-2;
const int MUL=-3;
const int DIV=-4;
const int OPEN=-5;
const int CLOSE=-6;
bool previous_non_numeric(const string &exp , int index){
	if(index==0) return true;
	else if(exp[index-1]>='0' && exp[index-1]<='9') return false;
	return true;
}
string transform_const(string exp){
	int index=exp.find("x");
	while(index!=string::npos){
		exp.replace(index,1,"*1");
		index=exp.find("x",index+1);
	}
	for(int i=0;i<exp.size();i++){
		if(exp[i]=='*' && previous_non_numeric(exp,i)){
			exp[i]=' ';
		}
	}
	return exp;
}

int evaluate(const string &exp){
	string temp=exp;
	
	queue<char> ops;
	for(int i=0;i<temp.size();i++){
		if(temp[i]=='+' || temp[i]=='-' || temp[i]=='*' || temp[i]=='/' || temp[i]=='(' || temp[i]==')'){
			ops.push(temp[i]);
			temp[i]=' ';
		}
	}
	stringstream ss(temp);
	queue<int> q;
	int n;
	while(ss){
		ss>>n;
		q.push(n);
		if(ops.front()=='+')q.push(ADD);
		if(ops.front()=='-')q.push(SUB);
		if(ops.front()=='*')q.push(MUL);
		if(ops.front()=='/')q.push(DIV);
		if(ops.front()=='(')q.push(OPEN);
		if(ops.front()==')')q.push(CLOSE);
		ops.pop();
	}
	while(!q.empty()){
		if(q.front()>0)cout<<q.front()<<" ";
		else{
			switch(q.front()){
			case ADD : 
				cout<<"+";
				break;
			case SUB : 
				cout<<"-";
				break;
			case MUL :
				cout<<"*";
				break;
			case DIV :
				cout<<"/";
				break;
			case OPEN :
				cout<<"(";
				break;
			case CLOSE :
				cout<<")";
				break;
			}
		}
		q.pop();
	}
	cout<<endl;
	return 0;
}

int main()
{
	string exp,const_exp,rhs;
	getline(cin,exp); 
	
	rhs=exp.substr(exp.find('=')+1);
	
	const_exp=transform_const(exp.substr(0,exp.find('=')));
	
	int coef = evaluate(const_exp);
	
	return 0;
}
