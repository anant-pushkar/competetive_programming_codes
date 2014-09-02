#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long int lld;
int n,k;
lld *arr;
int main(int argc , char **argv)
{
	scanf("%d %d",&n,&k);
	
	arr=(lld*) calloc(n,sizeof(lld));
	int i=0,j;
	for(;i<n;++i){
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+n);
	
	lld min=LLONG_MAX,sum;
    int start,end,w=0,offset=k-1,*w_arr=(int*)calloc(k-1,sizeof(int));
	
	//creating window
	for(i=0;i<=(k-1)/2;++i){
		w_arr[i]=w+offset;
		w += offset;
        offset-=2;
	}
	offset+=2;
	w -= offset;
	if(k%2==1){
		offset+=2;
		w -= offset;
	}
	for(;i<k-1;++i){
		offset+=2;
        w -= offset;
		w_arr[i]=w+offset;
	}
	
	//applying window
	for(i=0;i<n-k+1;++i){
        sum=0;
        start=i;end=i+k-1;
		for(j=start;j<end;++j){
			sum+=(arr[j+1]-arr[j])*w_arr[j-start];
		}
		if(min>sum) min=sum;
	}
	printf("%lld\n",min);
	
	return 0;
}
