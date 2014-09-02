#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
const int limit=100;
vector<int> A,B,C;
int getA(int);
int getB(int);
int getC(int);
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,w,i=1;scanf("%d",&n);
	
	A=vector<int>(limit,-1);
	A[1]=0;A[2]=1;
	
	B=vector<int>(limit,-1);
	B[1]=1;B[2]=2;
	
	C=vector<int>(limit,-1);
	C[0]=0;C[1]=1;C[2]=5;
	
	while(n--){
		scanf("%d",&w);
		printf("%d %d\n",i++,getC(w));
	}
	if(debug){
		cout<<"A : ";
		for(int i=0;i<20;++i)cout<<A[i]<<" ";
		cout<<endl;
		
		cout<<"B : ";
		for(int i=0;i<20;++i)cout<<B[i]<<" ";
		cout<<endl;
		
		cout<<"C : ";
		for(int i=0;i<20;++i)cout<<C[i]<<" ";
		cout<<endl;
	}
	return 0;
}
int getA(int n){
	if(A[n]!=-1)return A[n];
	A[n]=getC(n-2)+getA(n-2);
	return A[n];
}
int getB(int n){
	if(B[n]!=-1) return B[n];
	B[n]=getB(n-2)+getC(n-1)+getC(n-2);
	return B[n];
}
int getC(int n){
	if(C[n]!=-1) return C[n];
	C[n]=getC(n-1)+getC(n-2)+getA(n)+2*getB(n-1);
	return C[n];
}
