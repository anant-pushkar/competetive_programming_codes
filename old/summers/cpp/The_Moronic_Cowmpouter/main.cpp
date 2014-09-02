/*
Project name : The_Moronic_Cowmpouter
Created on : Mon Jun  2 16:29:12 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NEG2/
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
lld n;
vector<int> bits;
int sign;
void printBits(){
	int index=bits.size();
	for(int i=bits.size()-1;i>-1;--i){
		if(bits[i]==0)
			--index;
		else
			break;
	}
	for(int i=index-1;i>-1;--i)
		printf("%d",bits[i]);
	printf("\n");
}
void createBinary(){
	queue<int> q;
	while(n>0){
		q.push(n%2);
		n /=2 ;
	}
	bits = vector<int>(q.size()*2,0);
	int size = q.size();
	for(int i=0;i<size;++i){
		bits[i] = q.front();
		q.pop();
	}
}
void propogateBinary(){
	int carry = 0 , val;
	for(int i=0;i<bits.size();++i){
		if(debug){
			cout<<"bits : ";
			printBits();
			cout<<endl;
		}
		val = bits[i] + carry;
		carry=0;
		bits[i] = val%2;
		if((sign==1 && i%2==1) || (sign==-1 && i%2==0)){
			carry = bits[i];
		}
		carry += val/2 ;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%lld",&n);
	sign = n>0 ? 1 : n<0 ? -1 : 0;
	n *= sign;
	if(n==0)
		printf("0\n");
	else{
		createBinary();
		propogateBinary();
		printBits();
	}
		
	return 0;
}

