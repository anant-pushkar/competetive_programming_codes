/*
Project name : DOSA
Created on : Sat Jan 18 02:15:56 2014
Author : Anant Pushkar
spoj : using nlogn algo of lis
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
int n;
vector<lld> arr;
int getLisSize(){
	int n=arr.size(),index=0;
	while(arr[index]<0)++index;
	vector<lld> m(n,1<<29) , p(n,-1) , v(n,1<<29);
	m[0]=index;
	v[0]=arr[index];
	p[0]=index;
	int l=1;
	for(int i=index+1;i<n;++i)if(arr[i]>=0){
		index=upper_bound(v.begin(),v.begin()+l,arr[i])-v.begin()-1;
		p[i]=index>=0?m[index]:i;
		if(v[index+1]>arr[i]){
			v[index+1]=arr[i];
			m[index+1]=i;
			l=l>index+2?l:index+2;
		}
	}
	/*index=m[l-1];
	vector<int> lis(l);
	for(int i=l-1;i>=0;--i){
		lis[i]=arr[index];
		index=p[index];
	}
	if(debug){
		cout<"Sending : ";
		for(int i=0;i<l;++i)cout<<lis[i]<<" ";
		cout<<endl<<endl;
	}*/
	return l;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d",&n);
	arr=vector<lld>(n);
	int index=0,count=0;
	for(int i=0;i<n;++i){
		scanf("%lld",&arr[i]);
		arr[i]-=i+1;
	}
	if(debug){
		cout<<"arr : ";
		for(int i=0;i<n;++i)cout<<arr[i]<<" ";
		cout<<endl;
	}
	printf("%d\n",n-getLisSize());
	return 0;
}

