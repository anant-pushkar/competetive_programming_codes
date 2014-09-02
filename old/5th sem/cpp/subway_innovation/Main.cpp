/*
Project name : subway_innovation
Created on : Tue Dec 10 03:58:31 IST 2013
http://codeforces.com/contest/371/problem/E

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
bool debug=false;
typedef long long int lld;
struct station{
	int n;
	lld x;
};
bool compare(const station &s1 , const station &s2){
	return s1.x<s2.x;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,k;
	cin>>n;
	station arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i].x;
		arr[i].n=i+1;
	}
	sort(arr,arr+n,compare);
	cin>>k;
	lld val=0,sum=0;
	for(int i=0;i<k;++i){
		val+=arr[k-1].x-arr[i].x;
		sum+=arr[i].x;
	}
	lld minVal=val,minStart=0,minEnd=k-1;
	if(debug){
		cout<<"val : "<<val<<endl;
	}
	for(int i=0;i+k<n;++i){
		sum-=arr[i].x;
		val=val+(k-1)*(arr[i].x+arr[i+k].x)-2*sum;
		sum+=arr[k+i].x;
		if(debug){
			cout<<"val : "<<val<<endl;
		}
		if(val<minVal){
			minVal=val;
			minStart=i+1;
			minEnd=i+k;
		}
	}
	for(int i=minStart;i<=minEnd;++i)cout<<arr[i].n<<" ";
	printf("\n");
	return 0;
}

