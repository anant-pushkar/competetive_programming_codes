/*
Project name : TWENDS
Created on : Fri Dec 20 20:35:10 2013
http://www.spoj.com/problems/TWENDS/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<cmath>
using namespace std;
bool debug=false;
int n,callCount;
vector<int> arr;
vector<vector<int> > lookup;
vector<vector<int> > mem;
int process(int start,int  end){
	if(start>=end || start>=n || start<0 || end<0 || end>=n)return 0;
	if(mem[start][end]!=-1){
		++callCount;
		 return mem[start][end];
	}
	if(end-start==1)return abs((double)arr[start]-arr[end]);
	
	int a=start,b=end,dp,greedy;
	dp=arr[a];++a;
	if(arr[a]<arr[b]){
		greedy=arr[b];
		--b;
	}else {
		greedy=arr[a];
		++a;
	}
	int diff=process(a,b)+dp-greedy,temp;
	
	a=start;b=end;
	dp=arr[b];--b;
	if(arr[a]<arr[b]){
		greedy=arr[b];
		--b;
	}else {
		greedy=arr[a];
		++a;
	}
	temp=process(a,b)+dp-greedy;
	diff=diff>temp?diff:temp;
	
	mem[start][end]=diff;
	//if(debug)cout<<"for "<<start<<","<<end<<" : "<<diff<<endl;
	return diff;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int num=1;
	while(1){
		scanf("%d",&n);if(n==0)break;
		mem=vector<vector<int> >(n,vector<int>(n,-1));
		callCount=0;
		arr=vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&arr[i]);
		lookup=vector<vector<int> >(n,vector<int>(n,-1));
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",num++,process(0,n-1));
		if(debug)cout<<"Saved "<<callCount<<" calls"<<endl<<endl;
	}
	return 0;
}

