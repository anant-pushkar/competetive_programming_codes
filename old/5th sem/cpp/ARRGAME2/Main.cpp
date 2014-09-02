#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
inline bool wins(int a,int b){
	if(a==1 && b!=1)return false;
	if(a!=1 && b==1)return true;
	return b>a;
}
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,index;scanf("%d",&t);
	vector<int> A,B;
	while(t){
		int n;scanf("%d",&n);
		
		A=vector<int>(n);
		B=vector<int>(n);
		
		for(int i=0;i<n;++i){
			scanf("%d",&A[i]);
			if(A[i]==2)A[i]=4;
		}
		for(int i=0;i<n;++i){
			scanf("%d",&B[i]);	
			if(B[i]==2)B[i]=4;
		}
		sort(A.begin(),A.end());
		index=0;while(index<n && A[index]<=1)++index;
		//if(index==n)index--;
		reverse(A.begin()+index,A.end());
		
		sort(B.begin(),B.end());
		index=0;while(index<n && B[index]<=1)++index;
		//if(index==n)index--;
		reverse(B.begin()+index,B.end());
		
		if(debug){
			cout<<"A : ";
			for(int i=0;i<A.size();++i)cout<<A[i]<<" ";
			cout<<endl<<"B : ";
			for(int i=0;i<B.size();++i)cout<<B[i]<<" ";
			cout<<endl;
		}	
		int j=0;
		double sum=0;
		for(int i=0;i<n;++i){
			while(j<n && wins(A[i],B[j])){
				if(debug)cout<<A[i]<<" wins over "<<B[j]<<endl;
				++j;
			}
			if(debug)cout<<A[i]<<":adding "<<j<<endl;
			sum+= j;
		}
		printf("%f\n",(sum)/n);
		--t;
	}
	return 0;
}


