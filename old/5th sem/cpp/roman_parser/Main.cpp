#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
/*
Roman numeral parser based on following LL(1) grammar
	S -> xTU | lX | X
	T -> c | l
	X -> xX | U
	U -> iY | vI | I
	Y -> x | v
	I -> iI | epsilon
Implemented using recursive descent
*/
class Parser{
	string input;
	int readHead;
	int val;
	void printErr(){
		if(readHead!=input.size())printf("Error matching %c at %d.\n",input[readHead],readHead);
	}
	bool match(char c){
		if(input[readHead]==c){
			++readHead;
			return true;
		}else return false;
	}
	int S(){
		if(match('x'))return T()+U()-10;
		if(match('l'))return X()+50;
		return X();
	}
	int T(){
		if(match('c'))return 100;
		if(match('l'))return 50;
		printErr();
		return 0;
	}
	int X(){
		if(match('x'))return 10+X();
		return U();
	}
	int U(){
		if(match('i'))return Y()-1;
		if(match('v'))return 5+I();
		return I();
	}
	int Y(){
		if(match('x'))return 10;
		if(match('v'))return 5;
		printErr();
		return 0;
	}
	int I(){
		if(match('i')) return 1+I();
		if(readHead==input.size()-1)return 0;
		printErr();
		return 0;
	}
public:
	Parser(string in):
	input(in),readHead(0),val(0)
	{}
	
	int parse(){
		return S();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;cin>>T;
	while(T){
		string str;
		if(debug)cout<<"Enter Roman numeral : ";
		cin>>str;
		
		Parser p(str);
		cout<<p.parse()<<endl;
		--T;
	}
	
	return 0;
}

