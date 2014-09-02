/*
Project name : George_and_Round
Created on : Thu Feb  6 14:29:53 2014
Author : Anant Pushkar
codeforces 387 B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<int> a(n),count(n,0);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	
	int b,index;
	for(int i=0;i<m;++i){
		scanf("%d",&b);
		index=upper_bound(a.begin(),a.end(),b)-a.begin();
		if(a[index]!=b)--index;
		if(b>=a[index])++count[index];
	}
	
	int acc=0,c=0;
	for(int i=n-1;i>=0;--i){
		if(count[i]>0){
			acc+=count[i]-1;
		}else{
			if(acc==0)++c;
			else --acc;
		}
		if(debug)cout<<"c="<<c<<"acc="<<acc<<endl;
	}
	printf("%d\n",c);
	
	return 0;
}

