#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
vector<long long int> A,D;
long long int getA(int n);
long long int getD(int n);
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	A=vector<long long int>(31,-1);
	A[0]=0;
	A[1]=1;
	
	D=vector<long long int>(31,-1);
	D[0]=1;
	D[1]=0;
	
	while(1){
		scanf("%d",&n);if(n==-1)break;
		printf("%lld\n",getD(n));
	}
	if(debug){
		cout<<"A : ";
		for(int i=0;i<31;++i)cout<<A[i]<<" ";
		cout<<endl;
		
		cout<<"D : ";
		for(int i=0;i<31;++i)cout<<D[i]<<" ";
		cout<<endl;
	}
	return 0;
}
long long int getA(int n){
	if(A[n]!=-1)return A[n];
	A[n]=getD(n-1)+getA(n-2);
	return A[n];
}
long long int getD(int n){
	if(D[n]!=-1)return D[n];
	D[n]=getD(n-2)+2*getA(n-1);
	return D[n];
}