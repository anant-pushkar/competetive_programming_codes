/*
Project name : CHOCOLA
Created on : Fri Dec  6 16:55:14 IST 2013
http://www.spoj.com/problems/CHOCOLA/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
class Solver{
	int m,n;
	vector<int> x,y;
public:
	Solver(int a, int b):
	m(a-1),
	n(b-1),
	x(vector<int>(a-1,0)),
	y(vector<int>(b-1,0)){
		for(int i=0;i<m;++i)scanf("%d",&x[i]);
		for(int i=0;i<n;++i)scanf("%d",&y[i]);
		
		sort(x.begin(),x.end());reverse(x.begin(),x.end());
		sort(y.begin(),y.end());reverse(y.begin(),y.end());
	}
	lld solve(){
		int i=0,j=0;
		lld sum=0;
		while(i<m && j<n){
			if(debug)cout<<"x="<<x[i]<<"y="<<y[j]<<endl;
			sum+=x[i]>y[j]?x[i++]*(j+1):y[j++]*(i+1);
		}
		while(i<m){
			if(debug)cout<<"x="<<x[i]<<"y="<<y[j]<<endl;
			sum+=x[i++]*(j+1);
		}
		while(j<n){
			if(debug)cout<<"x="<<x[i]<<"y="<<y[j]<<endl;
			sum+=y[j++]*(i+1);
		}
		return sum;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,m,n;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		Solver s(m,n);
		printf("%lld\n",s.solve());
	}
	return 0;
}

