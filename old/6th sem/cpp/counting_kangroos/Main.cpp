/*
Project name : counting_kangroos
Created on : Wed Dec 18 13:48:46 2013
http://codeforces.com/contest/373/problem/C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int n;
vector<int> size;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d",&n);
	size=vector<int>(n);
	for(int i=0;i<n;++i)scanf("%d",&size[i]);
	sort(size.begin(),size.end());
	int j=n/2+n%2,count=0;
	
	for(int i=0;i<n && j<n;++i){
		while(j<n && size[j]<2*size[i])++j;
		if(j>=n)break;
		if(debug)cout<<"Matching "<<i<<"("<<size[i]<<") with "<<j<<"("<<size[j]<<")"<<endl;
		++count;++j;
	}
	cout<<n-count<<endl;
	return 0;
}

