/*
Project name : Towers
Created on : Thu Sep 11 12:48:42 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w10/challenges/towers
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
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
const lld MOD = 1000000007;
vector<lld> operator+(const vector<lld> &v1 , const vector<lld> &v2){
	int size = v1.size();
	vector<lld> v(size);
	for(int i=0;i<size;++i){
		v[i] = v1[i] + v2[i];
	}
	return v;
}
class Solver{
	lld n;
	lld k;
	vector<lld> b , f;
	vector<vector<lld> > mat;
	void update(vector<lld>&v , const vector<lld> &s){
		lld size = v.size();
		for(lld i=0;i<size;++i){
			v[i] = s[i];
		}
	}
	void populate_mat(){
		lld index;
		for(lld i=0;i<15;++i){
			for(lld j=0;j<k;++j){
				index = i - b[j] + 15;
				if(debug)cout<<i<<","<<index<<endl;
				if(index<15){
					mat[i][index] += 1;
				}else{
					update(mat[i] , mat[i] + mat[index-15]);
				}
				if(debug)print_mat(mat);
			}
		}
		/*for(lld i=0;i<15;++i){
			reverse(mat[i].begin() , mat[i].end());
		}*/
		for(lld i=0;i<k;++i){
			f[b[i]-1] = 1;
		}
		lld sum;
		for(lld i=0;i<15;++i){
			sum = 0;
			for(lld j=0;j<k;++j)if(i-b[j]>-1){
				sum += f[i-b[j]]%MOD;
				sum  = sum%MOD;
			}	
			f[i] += sum%MOD;
		}
	}
	void print_mat(const vector<vector<lld> > &m){
		//cout<<"MAT : "<<endl;
		for(lld i=0;i<15;++i){
			for(lld j=0;j<15;++j){
				cout<<m[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"F : ";
		for(lld i=0;i<15;++i){
			cout<<f[i]<<" ";
		}
		cout<<endl;
		cout<<"======================================================="<<endl;
	}
	//v1 *=v2
	void mult(vector<vector<lld> > &v1 , const vector<vector<lld> > &v2){
		vector<vector<lld> > v(15 , vector<lld>(15 , 0));
		for(lld i=0;i<15;++i){
			for(lld j=0;j<15;++j){
				for(lld k=0;k<15;++k){
					v[i][j] += (v1[i][k] * v2[k][j])%MOD;
					v[i][j]  = v[i][j]%MOD;
				}
			}
		}
		for(lld i=0;i<15;++i){
			for(lld j=0;j<15;++j){
				v1[i][j] = v[i][j];
			}
		}
	}
	vector<vector<lld> > get_identity(){
		vector<vector<lld> > I(15 , vector<lld>(15));
		for(lld i=0;i<15;++i){
			I[i][i] = 1;
		}
		return I;
	}
	vector<vector<lld> > pow(lld p){
		vector<vector<lld> > temp = mat , m = get_identity();
		if(debug)cout<<"p : "<<p<<endl;
		while(p>0){
			if( (p%2)==1 ){
				mult(m , temp);
			}
			mult(temp , temp);
			if(debug){
				cout<<" m : "<<endl;
				print_mat(m);		
				
				cout<<" temp : "<<endl;
				print_mat(temp)	;
			}	
			
			p = p/2;
		}
		return m;
	}
	
public:
	Solver():
	mat(vector<vector<lld> >(15 , vector<lld>(15,0))),
	f(vector<lld>(15)){
		scanf("%lld",&n);
		scanf("%lld",&k);
		
		b = vector<lld>(k);
		for(lld i=0;i<k;++i){
			scanf("%lld",&b[i]);
		}
		
		populate_mat();
		if(debug)print_mat(mat);
	}
	lld solve(){
		vector<vector<lld> > m = pow((n-1)/15);
		if(debug){
			cout<<"POW"<<endl;
			print_mat(m);
		}
		lld index = (n-1)%15;
		
		lld sum=0;
		for(lld i=0;i<15;++i){
			sum += (m[index][i]*f[i])%MOD;
			sum  = sum%MOD;
		}
		
		return (2*sum)%MOD;
	}
};

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	cout<<s.solve()<<endl;
	return 0;
}

