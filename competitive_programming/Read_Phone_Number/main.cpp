/*
Project name : Read_Phone_Number
Created on : Mon Oct 20 02:43:37 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/2924486/dashboard#s=p0
*/
#include<iostream>
#include<sstream>
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
vector<string> names , quant;
void init(){
	names = vector<string>(10);
	names[0] = "zero";
	names[1] = "one";
	names[2] = "two";
	names[3] = "three";
	names[4] = "four";
	names[5] = "five";
	names[6] = "six";
	names[7] = "seven";
	names[8] = "eight";
	names[9] = "nine";
	
	quant = vector<string>(11 , "");
	quant[2] = "double";
	quant[3] = "triple";
	quant[4] = "quadruple";
	quant[5] = "quintuple";
	quant[6] = "sextuple";
	quant[7] = "septuple";
	quant[8] = "octuple";
	quant[9] = "nonuple";
	quant[10]= "decuple";
}
deque<int> split(const string &s){
	deque<int> arr;
	int n=s.size() , val=0 ;
	
	for(int i=0;i<n;++i){
		if(isdigit(s[i])){
			val = val*10 + s[i]-'0';
		}else{
			arr.push_back(val);
			val = 0;
		}
	}
	arr.push_back(val);
	
	//reverse(arr.begin() , arr.end());
	return arr;
}
string spell(const string &s , int start , int end){
	int i=start;
	stringstream ss;
	
	char c;
	int count;
	while(i<end){
		count=1;
		c = s[i];
		++i;
		while(i<end && s[i]==c){
			++count;
			++i;
		}
		
		if(count!=1){
			if(count<11){
				ss<<quant[count]<<" "<<names[c-'0']<<" ";
			}else{
				while(count--){
					ss<<names[c-'0']<<" ";
				}
			}
		}else{
			ss<<names[c-'0']<<" ";
		}
	}
	
	return ss.str();
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	cin>>T;
	
	init();
	int index;
	string num,pat;
	deque<int> slots;
	for(int t=1;t<=T;++t){
		cin>>num>>pat;
		slots = split(pat);
		
		if(debug){
			cout<<"slots : ";
			for(int i=0;i<slots.size();++i){
				cout<<slots[i]<<" ";
			}
			cout<<endl;
		}
		
		cout<<"Case #"<<t<<": ";
		index=0;
		for(int i=0;i<slots.size();++i){
			cout<<spell(num,index,index+slots[i]);
			index += slots[i];
		}
		
		cout<<endl;
	}
	
	return 0;
}

