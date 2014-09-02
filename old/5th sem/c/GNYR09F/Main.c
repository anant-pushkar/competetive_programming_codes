#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int n , k;
lld getCount(lld* lookup , lld* arr0 ,lld* arr1 , int bc){
	if(bc==k+1){
		return lookup[n-1] + arr0[n-1];
	}
	int i=0;
	for(;i<bc;++i){
		arr1[i]=0;
		arr0[i]=0;
	}
	for(;i<n;++i){
		arr1[i] = arr0[i-1] + lookup[i-1];
		arr0[i] = arr0[i-1] + arr1[i-1];
	}
	if(debug){
		printf("bit count = %d\narr1\t: ",bc);
		int q;
		for(q=0;q<n;++q) printf("%lld ",arr1[q]);
		printf("\narr0\t: ");
		for(q=0;q<n;++q) printf("%lld ",arr0[q]);
		printf("\nlookup\t: ");
		for(q=0;q<n;++q) printf("%lld ",lookup[q]);
		printf("\n\n");
	}
	return getCount(arr1 , arr0 , lookup , bc+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i,j;scanf("%d",&t);
	lld *arr1,*arr0,*lookup;
	while(t--){
		scanf("%d %d %d",&i,&n,&k);
		if(n<3){
			int val=0;
			if(n==1)val = k==0 ? 2 : 0;
			if(n==2)val = k==1 ? 1 : k==0 ? 3 : 0;
			printf("%d %d\n",i,val);
			continue;
		}
		arr1 = (lld*)calloc(n,sizeof(lld));
		arr0 = (lld*)calloc(n,sizeof(lld));
		lookup=(lld*)calloc(n,sizeof(lld));
		
		arr0[0] = 1;
		lookup[0]=1;
		for(j=1;j<n;++j){
			lookup[j]=arr0[j-1];
			arr0[j] = arr0[j-1] + lookup[j-1];
		}
		
		printf("%d %lld\n",i,getCount(lookup,arr0,arr1,1));
		
		free(arr1);free(arr0);free(lookup);
	}
	return 0;
}
