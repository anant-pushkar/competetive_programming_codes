#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
const int MOD=1000000007;
using namespace std;
int n,m,k; 
int nCr(int n , int r){
	if(r>n)return 0;
	r = n-r>r ? r : n-r;
	int pro=1;
	for(int i=0;i<r;i++){
		pro*=n-i;
	}
	for(int i=0;i<r;i++){
		pro/=r-i;
	}
	//printf("%dC%d=%d\n",n,r,pro);
	return pro%MOD;
	
}
int getSingleCount(int x,int y){
	double slope;
	unordered_map<double, int> lookup;
	//printf("Performing on %d,%d\n",x,y);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m-1;j++){
			//printf("Checking on %d,%d",i,j);
			if(i!=x && j!=y){
				slope=static_cast<double>(j-y)/static_cast<double>(i-x);
				if(slope!=0 && slope!=1 && slope!=-1)lookup[slope]++;
			}
		}
	}
	unordered_map<double,int>::iterator it;
	int count=0;
	for(it=lookup.begin();it!=lookup.end();it++){
		//printf("\n\t checking slope:%f with count %d",it->first,it->second);
		if(it->second >= k-1){
			//printf("Adding slope %f\n",it->first);
			count+=nCr(it->second,k-1);
		}
	}
	//printf("\n\n");
	return count;
}
int getDoubleCount(int x , int y){
	int count=0;
	for(int i=1;i<x;i++){
		if((y*i)%x==0)
			count++;
	}
	//printf("\n\tbetween %d,%d : %d\n",x,y,count);
	if(count<k-2)return 0;
	else return nCr(count,k-2)%MOD;
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
	int count=0;
	for(int i=0;i<=n;i++){
		count+=2*getSingleCount(i,0);
		count=count%MOD;
	}//printf("after x : %d\n",count);
	for(int j=1;j<m;j++){
		count+=2*getSingleCount(0,j);
		count=count%MOD;
	}//printf("after y : %d\n",count);
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			count+=4*getDoubleCount(i,j);
			count=count%MOD;
		}
	}//printf("after double : %d\n",count);
	n=n>m?m:n;
	m=n>m?n:m;
	count+=2*nCr(n+1,k)*(m-n+1);
	//printf("after diagonal : %d\n",count);
	for(int i=n-1;i>=k;i--){
		count+=4*nCr(i,k);
	}
	//printf("count after partial diagonal : %d\n",count);
	n++;m++;
	count+=m*(nCr(n,k)) + n*(nCr(m,k));
	printf("%d\n",count);
    return 0;
}
