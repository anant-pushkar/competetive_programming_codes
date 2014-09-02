#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
bool debug=false;
int n;
long long int minVal,val;
vector<int>  arr,sum;
vector< vector<long long int> > lookup;
inline int getSum(int a , int b){
	return a==b ? arr[a] : (sum[b]-(a-1>=0?sum[a-1]:0)+100)%100;
}
void populate(int i , int j){
	if(i==j){
		lookup[i][i]=0;
		return;
	}
	minVal=LLONG_MAX;
	for(int k=i;k<j;++k){
		val = lookup[i][k]+lookup[k+1][j]+getSum(i,k)*getSum(k+1,j);
		if(debug)cout<<i<<","<<k<<","<<j<<"="<<lookup[i][k]<<"+"<<lookup[k+1][j]<<"+"<<getSum(i,k)<<"*"<<getSum(k+1,j)<<"="<<val<<endl;
		if(minVal>val){
			minVal=val;
		}
	}
	lookup[i][j]=minVal;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	while(scanf("%d",&n)==1){
		arr    = vector<int>(n);
		sum    = vector<int>(n,0);
		lookup = vector<vector<long long int> >(n,vector<long long int>(n,-1));
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
			sum[i] = ((i!=0 ? sum[i-1] : 0 ) + arr[i])%100;
		}
		for(int i=0;i<n;++i){
			for(int j=0;i+j<n;++j){
				for(int k=0;i+j+k<n;++k){
					populate(i+k,i+j+k);
				}
			}
		}
		if(debug){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<lookup[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		printf("%lld\n",lookup[0][n-1]);
	}
	return 0;
}

