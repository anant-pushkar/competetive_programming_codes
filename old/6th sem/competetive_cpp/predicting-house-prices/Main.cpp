/*
Project name : predicting-house-prices
Created on : Sat May  3 16:55:06 2014
Author : Anant Pushkar
Hackerrank ML linear Regression
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
const double delta = 0.1 ;
const double alpha = 0.1 ;
const bool plot = false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int nFeature,nTraining;
	scanf("%d %d",&nFeature,&nTraining);
	
	vector<double> y(nTraining) , param(nFeature+1,1);
	vector<vector<double> > f(nTraining , vector<double>(nFeature));
	for(int i=0;i<nTraining;++i){
		for(int j=0;j<nFeature;++j)scanf("%lf",&f[i][j]);
		scanf("%lf",&y[i]);
	}
	
	double diff=0,val,h,temp,tDiff;
	if(plot)printf("^{\"type\":\"data\",\"name\" : \"Diff vs time\",\"obj\":[[");
	do{
		tDiff=diff;
		diff=0;
		for(int t=0;t<nTraining;++t){
			h = param[0];
			temp=0;
			for(int j=0;j<nFeature;++j)h += param[j+1]*f[t][j];
			for(int j=0;j<=nFeature;++j){
				val = param[j] - alpha * (j==0?1:f[t][j-1]) * (h-y[t]);
				temp += abs(param[j]-val);
				param[j] = val;
			}
			diff+=temp/nFeature;
		}
		diff/=nTraining;
		if(plot)printf("\"%f\",",diff);
	}while(abs(tDiff-diff)>0.000001 && diff>delta);
	if(plot)printf("\"0\"]]}\n");
	
	int t;scanf("%d",&t);
	vector<double> x(nFeature);
	while(t--){
		for(int i=0;i<nFeature;++i)scanf("%lf",&x[i]);
		h = param[0];
		for(int j=0;j<nFeature;++j)h += param[j+1]*x[j];
		printf("%lf\n",h);
	}
	
	return 0;
}

