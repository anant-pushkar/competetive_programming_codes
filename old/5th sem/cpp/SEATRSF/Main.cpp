#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
bool debug=false;
const int mod = 1000000007;
class Solver{
	int n,m,q,k;
public:
	Solver(int _n,int _m, int _q , int _k):
	n(_n),
	m(_m),
	q(_q),
	k(_k)
	{}
	int getPow(int n){
		if(debug)cout<<"called on : "<<n<<endl;
		if(n==1)return 0;
		int p=1,i=0;
		while(p<n){
			p=p<<1;++i;
		}
		if((n&(n-1))!=0)--i;
		if(debug)cout<<"returning "<<i<<endl;
		return i;
	}
	long long int solve(){
		if(m<=q || n==1)return 0;
		long long int p1=1,p2=1,p3=1,s=0,p=getPow(n),pro1=q+1,pro2=q,pro3=q-1;
		while(n>1){
			if(debug){
				cout<<(m-q)<<"("<<p1<<"-2*"<<p2<<"+"<<p3<<")="<<s<<endl;
			}
			for(int i=0;i<p;++i){
				pro1*=pro1;pro1=pro1%mod;
				pro2*=pro2;pro2=pro2%mod;
				pro3*=pro3;pro3=pro3%mod;
				if(debug){
					cout<<pro1<<","<<pro2<<","<<pro3<<endl;
				}
			}
			p1*=pro1;p2*=pro2;p3*=pro3;
			p1=p1%mod;p2=p2%mod;p3=p3%mod;
			if(debug){
				cout<<(m-q)<<"("<<p1<<"-2*"<<p2<<"+"<<p3<<")="<<s<<endl;
			}
			pro1=q+1;pro2=q;pro3=q-1;
			n=n-(1<<p);
			p=getPow(n);
			if(debug)cout<<endl<<endl;
		}
		
		if(n==1){
			p1*=q+1;p1=p1%mod;
			p2*=q  ;p2=p2%mod;
			p3*=q-1;p3=p3%mod;
		}
		s=p1-2*p2+p3+2*mod; s=s%mod;
		s=s*(m-q); s=s%mod;
		if(debug){
			cout<<(m-q)<<"("<<p1<<"-2*"<<p2<<"+"<<p3<<")="<<s<<endl;
		}
		return s;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,m,q,k;scanf("%d",&t);
	while(t){
		scanf("%d %d %d %d",&n,&m,&q,&k);
		Solver s(n,m,q,k);
		printf("%lld\n",s.solve());
		--t;
	}
	return 0;
}


