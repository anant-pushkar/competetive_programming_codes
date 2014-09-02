/*
Project name : abc_consecutive
Created on : Fri Dec 13 19:38:30 IST 2013
http://www.careercup.com/question?id=6227714491023360
suppose a string is consists of a, b, and c 
Now given a integer N, output the amount of all possible strings of length N that don't of have consecutive a,b,c. 
e.g. given N=5, string bacca is invalid since the first 3 letters have consecutive a,b,c. and bbbbb is valid.
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int n;
const int aa=0,ab=1,ac=2,ba=3,bb=4,bc=5,ca=6,cb=7,cc=8;
int recurse(vector<int> &lookup , vector<int> &arr,int level){
	if(level==n){
		int sum=0;
		for(int i=0;i<9;++i)sum+=lookup[i];
		return sum;
	}
	arr[aa]=lookup[ba]+lookup[ca]+lookup[aa];
	arr[ab]=lookup[ba]+lookup[aa];
	arr[ac]=lookup[aa]+lookup[ca];
	arr[ba]=lookup[ab]+lookup[bb];
	arr[bb]=lookup[ab]+lookup[bb]+lookup[cb];
	arr[bc]=lookup[bb]+lookup[cb];
	arr[ca]=lookup[ac]+lookup[cc];
	arr[cb]=lookup[bc]+lookup[cc];
	arr[cc]=lookup[ac]+lookup[bc]+lookup[cc];
	return recurse(arr,lookup,level+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	vector<int>lookup(9,1),arr(9);
	cin>>n;
	switch(n){
	case 1:
		cout<<"3"<<endl;
		break;
	case 2:
		cout<<"9"<<endl;
		break;
	default:	
		cout<<recurse(lookup,arr,2)<<endl;
		break;
	}
	return 0;
}

