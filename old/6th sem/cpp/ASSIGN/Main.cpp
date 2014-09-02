/*
Project name : ASSIGN
Created on : Fri Dec 20 20:26:37 2013
http://www.spoj.com/problems/ASSIGN/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int n;
vector<vector<bool> > adjMat;
int pop(int x) {
	if(debug)cout<<"calculating for "<<x<<endl;
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,temp,sign,idx,m;
	vector<lld> sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		adjMat=vector<vector<bool> >(n,vector<bool>(n));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&temp);
				adjMat[i][j]=(temp==1);
			}
		}
		int len=(1<<n);
		sum=vector<lld>(len,0);
		sum[len-1]=1;
		for(int i=len-1;i>0;--i){
			idx=pop(i);
			for(int j=0;j<n;++j)if(i|(1<<j)){
				m=(i&(~(1<<j)));
				if(m!=i && adjMat[idx-1][j]){
					sum[m]+=sum[i];
					if(debug)cout<<"Incrementing "<<m<<" from "<<i<<" to "<<sum[m]<<endl;
				}
			}
		}
		printf("%lld\n",sum[0]);
	}
	return 0;
}

