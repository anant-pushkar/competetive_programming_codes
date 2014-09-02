#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , k ;
	scanf("%d %d",&n,&k);
	
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}	
	sort(arr.begin() , arr.end());
	
	int min=1000000000 , diff;
	for(int i=0;i<n-k;++i){
		diff=arr[i+k-1]-arr[i];
		if(min>diff){
			min=diff;
		}
	}
	printf("%d\n",min);
	return 0;
}

