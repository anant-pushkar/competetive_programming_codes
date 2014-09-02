#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
inline unsigned long long int countArr(unsigned long long int n , int k ,unsigned long long int j)
{
	if(j==0) return 0;
	return n/k+(j<=n%k?1:0);
}
unsigned long long int getNumPairs(unsigned long long int n , int k)
{
	//printf("Adding %lld\n",((n/k)*(n/k-1)/2));
	unsigned long long int count=(n/k)*(n/k-1)/2;
	if(k%2==0){
		//printf("Adding %lld\n",(countArr(n,k,k/2)*(countArr(n,k,k/2)-1)/2));
		count+=countArr(n,k,k/2)*(countArr(n,k,k/2)-1)/2;
	}
	for(int  i=1;i<k/2+k%2;i++){
		//printf("Adding %lld\n",countArr(n,k,i)*countArr(n,k,k-i));
		count+=countArr(n,k,i)*countArr(n,k,k-i);
	}
	return count;
}
int main() {
    int T,k;scanf("%d",&T); 
	unsigned long long int n;
	for(int t=0;t<T;t++){
		scanf("%lld",&n);
		scanf("%d",&k);
		printf("%lld\n",getNumPairs(n,k));
	}
    return 0;
}
