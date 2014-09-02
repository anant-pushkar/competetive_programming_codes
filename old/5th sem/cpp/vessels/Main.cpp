/*
Project name : vessels
Created on : Tue Dec 10 03:06:02 IST 2013
http://codeforces.com/contest/371/problem/D

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
	int n;cin>>n;	//number of vessels
	vector<lld> c(n);			//vessel capacities
	for(int i=0;i<n;++i)cin>>c[i];
	int q;cin>>q;	//number of queries
	int type,k,idx;
	lld p;
	vector<lld> v(n,0);
	vector<int> index(n);
	for(int i=0;i<n;++i)index[i]=i;
	while(q--){
		cin>>type;
		cin>>k;--k;
		switch(type){
		case 1:
			cin>>p;
			idx=k;if(index[k]==n)continue;
			while(k<n && v[k]==c[k] && k!=index[k])k=index[k];
			while(k<n && p>0){
				if(v[k]<c[k]){
					v[k]+=p;
					p=v[k]-c[k];
					if(p>0)v[k]=c[k];
					if(p<=0)break;
					++k;
				}else{
					while(k<n && v[k]==c[k])++k;
				}
				while(k<n && v[k]==c[k] &&  k!=index[k])k=index[k];
			}
			while(k<=n && k>0 && v[k-1]==c[k-1])++k;
			for(int i=idx;k>0 && i<k && i<n && v[i]==c[i];++i)index[i]=k-1;
			break;
		case 2:
			cout<<v[k]<<endl;
			break;
		}
		
	}
	return 0;
}

