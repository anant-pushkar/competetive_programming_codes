/*
Project name : rectilinear
Created on : Mon Mar 24 19:48:23 2014
Author : Anant Pushkar
wrfv
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
inline int area(int x1 , int y1 , int x2 , int y2){
	int x=x1-x2;x=x>0?x:-x;
	int y=y1-y2;y=y>0?y:-y;
    return x*y;
}
inline bool test(int P , int Q , int K , int L , int M , int N){
	return P>=K && P<=M && Q>=L && Q<=N;
}
int get_area(int K, int L, int M, int N, int P, int Q, int R, int S){
	int a2=area(P,Q,R,S);
	int a3=0;
	if(test(P,S,K,L,M,N)){
		if(test(R,Q,K,L,M,N))a3=a2;
		else if(test(R,S,K,L,M,N))a3=area(P,S,R,L);
		else if(test(P,Q,K,L,M,N))a3=area(P,S,M,Q);
		else a3=area(P,S,M,L);
	}
	else if(test(R,S,K,L,M,N)){
		if(test(P,Q,K,L,M,N))a3=a2;
		else if(test(R,Q,K,L,M,N))a3=area(R,S,K,Q);
		else a3=area(K,L,R,S);
	}
	else if(test(R,Q,K,L,M,N)){
		if(test(P,Q,K,L,M,N))a3=area(P,N,R,Q);
		else a3=area(R,Q,K,N);
	}
	else if(test(P,Q,K,L,M,N)){
		a3=area(P,Q,M,N);
	}
	return a3;
}
int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
    int a1=area(K,L,M,N);
	int a2=area(P,Q,R,S);
	int a3=get_area(K,L,M,N,P,Q,R,S);
	if(a3==0)a3=get_area(P,Q,R,S,K,L,M,N);
	int a = a1+a2-a3;
	return a>0?a:-1;
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,k,l,m,n,p,q,r,s;
	cin>>t;
	while(t--){
		cin>>k>>l>>m>>n>>p>>q>>r>>s;
		cout<<solution(k,l,m,n,p,q,r,s)<<endl;
	}
	return 0;
}

