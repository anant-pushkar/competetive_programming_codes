/*
Project name : HORRIBLE
Created on : Sun Dec 15 14:33:16 IST 2013
http://www.spoj.com/problems/HORRIBLE/  
BIT implementation

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
vector<lld> acc,sub;
int n;
void set(vector<lld> &tree,int i , lld v){
	while(i<n+4){
		tree[i]+=v;
		if(debug)cout<<"set at "<<i<<" to "<<tree[i]<<endl;
		i+=i&(-i);
	}
}
lld get(vector<lld> &tree,int i){
	if(i==-1)return 0;
	lld s=0;
	while(i>0){
		s+=tree[i];
		if(debug)cout<<"accumulated at "<<i<<" to "<<s<<endl;
		i-=i&(-i);
	}
	return s;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,c,start,end,q;scanf("%d",&t);
	lld v;
	while(t--){
		scanf("%d",&n);
		acc=vector<lld>(n+4,0);
		sub=vector<lld>(n+4,0);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d %d",&c,&start,&end);
			++start;++end;
			switch(c){
			case 0:
				scanf("%lld",&v);
				set(acc,end+1,-v);
				set(acc,start,v);
				set(sub,start,-v*start);
				set(sub,end+1,v*(end+1));
				break;
			case 1:
				v=((end+1)*get(acc,end)+get(sub,end))-(start*get(acc,start-1)+get(sub,start-1));
				printf("%lld\n",v);
				break;
			}
		}
	}
	return 0;
}

