/*
Project name : CHOCOLA
Created on : Fri Dec  6 16:55:14 IST 2013
http://www.spoj.com/problems/CHOCOLA/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
bool debug=false;
typedef long long int lld;
class Solver{
	int m,n;
	vector<int> x,y;
	vector<vector<vector<vector<lld> > > > lookup;
	lld calculate(int i1,int i2,int j1,int j2){
		if(i1==i2 || j1==j2) return 0;
		if(i2-i1==1 && j2-j1==1)return 0;
		if(lookup[i1][i2][j1][j2]!=0)return lookup[i1][i2][j1][j2];
		if(debug)cout<<"Calculating "<<i1<<","<<i2<<","<<j1<<","<<j2<<endl;
		lld min=LLONG_MAX,val;
		int a=0,b=2,c=0,d=2;
		for(int i=i1+1;i<i2;++i){
			val=x[i]+calculate(i1,i,j1,j2)+calculate(i,i2,j1,j2);
			/*if(i1==a && i2==b && j1==c && j2==d){
				cout<<"Choosing x"<<i<<" : "<<val<<"="<<x[i]<<"+"<<lookup[i1][i][j1][j2]<<"+"<<lookup[i][i2][j1][j2]<<endl;
			}*/
			if(val<min){
				/*if(i1==a && i2==b && j1==c && j2==d){
					cout<<"Choosing "<<val<<endl;
				}*/
				min=val;
			}
		}
		for(int j=j1+1;j<j2;++j){
			val=y[j]+calculate(i1,i2,j1,j)+calculate(i1,i2,j,j2);
			/*if(i1==a && i2==b && j1==c && j2==d){
				cout<<"Choosing y"<<j<<" : "<<val<<"="<<y[j]<<"+"<<lookup[i1][i2][j1][j]<<"+"<<lookup[i1][i2][j][j2]<<endl;
			}*/
			if(val<min){
				/*if(i1==a && i2==b && j1==c && j2==d){
					cout<<"Choosing "<<val<<endl;
				}*/
				min=val;
			}
		}
		return min;
	}
public:
	Solver(int a, int b):
	m(a),
	n(b),
	x(vector<int>(a+1,0)),
	y(vector<int>(b+1,0)),
	lookup(vector<vector<vector<vector<lld> > > >(a+1,vector<vector<vector<lld> > >(a+1,vector<vector<lld> >(b+1,vector<lld>(b+1,0))))){
		for(int i=1;i<m;++i)scanf("%d",&x[i]);
		for(int i=1;i<n;++i)scanf("%d",&y[i]);
		
		for(int i1=0;i1<m-1;++i1){
			for(int i2=i1+2;i2<m+1;++i2){
				for(int j=1;j<n+1;++j){
					for(int i=i1+1;i<i2;++i){
						lookup[i1][i2][j-1][j]+=x[i];
					}
				}
			}
		}
		for(int j1=0;j1<n-1;++j1){
			for(int j2=j1+2;j2<n+1;++j2){
				for(int i=1;i<m+1;++i){
					for(int j=j1+1;j<j2;++j){
						lookup[i-1][i][j1][j2]+=y[j];
					}
				}
			}
		}
	}
	lld solve(){
		for(int i1=0;i1<m-1;++i1){
			for(int i2=i1+2;i2<m+1;++i2){
				for(int j1=0;j1<n-1;++j1){
					for(int j2=j1+2;j2<n+1;++j2){
						lookup[i1][i2][j1][j2]=calculate(i1,i2,j1,j2);
					}
				}
			}
		}
		//lookup[0][m][0][n]=calculate(0,m,0,n);
		if(debug){
			cout<<endl<<"final:"<<endl;
			for(int i1=0;i1<m+1;++i1){
				for(int i2=i1+1;i2<m+1;++i2){
					for(int j1=0;j1<n+1;++j1){
						for(int j2=j1+1;j2<n+1;++j2){
							printf("(%d,%d)-(%d,%d) : %lld\n",i1,i2,j1,j2,lookup[i1][i2][j1][j2]);
						}
					}
				}
			}
		}
		return lookup[0][m][0][n];
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

