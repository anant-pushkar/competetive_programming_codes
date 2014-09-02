/*
Project name : making_sequence
Created on : Wed Dec 18 13:19:26 2013
http://codeforces.com/contest/373/problem/B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld w,m,k,next=0,count=0,len=0;
	cin>>w>>m>>k;
	w=w/k;
	k=1;
	lld n=m;
	while(n>0){
		n/=10;
		++count;
		next=10*next+9;
	}
	if(debug)cout<<"count="<<count<<" next="<<next<<" len="<<len<<endl;
	while(w>=count*k*(next-m+1)){
		w-=count*k*(next-m+1);
		if(debug)cout<<"cost incurred : "<<count*k*(next-m+1)<<endl;
		++count;
		len+=next-m+1;
		m=next+1;
		next=10*next+9;
		if(debug)cout<<"count="<<count<<" next="<<next<<" len="<<len<<endl;
	}
	len+=w/(k*count);
	cout<<len<<endl;
	return 0;
}

