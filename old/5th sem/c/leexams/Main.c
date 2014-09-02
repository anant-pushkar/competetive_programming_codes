#include<stdio.h>
#include<stdlib.h>
int n,p[50],a[50],b[50],check[16]; 
double getP(int level,double pVal){
	//printf("Called on level %d with pVal:%f\n",level,pVal);
	if(level==n){
		//printf("Returning terminalwith %f\n",pVal);
		return pVal;
	}
	double netP=0;
	if(check[a[level]]!=1){	
		check[a[level]]=1;
		netP+=getP(level+1,pVal*((double)p[level]/100.0000000));
		check[a[level]]=0;
	}
	if(check[b[level]]!=1){
		check[b[level]]=1;
		netP+=getP(level+1,pVal*((double)(100-p[level])/100.0000000));
		check[b[level]]=0;
	}
	//printf("Leaving level %d with p:%f\n",level,netP);
	return netP;
}
int main()
{
	int T,t=0;scanf("%d",&T);
	int i=0;for(;i<16;i++)check[i]=0;
	for(;t<T;t++){
		scanf("%d",&n);
		int i=0;
		for(;i<n;i++){
			scanf("%d %d %d",&p[i],&a[i],&b[i]);
		}
		printf("%f\n",getP(0,1));
	}
	return 0;
}
