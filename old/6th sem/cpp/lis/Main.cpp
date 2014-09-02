/*
Project name : lis
Created on : Sun Jan 19 14:35:05 2014
Author : Anant Pushkar
longest increasing subsequence : nlogn soln
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<time.h>
#include<utility>
#include <sys/time.h>
#include<algorithm>
using namespace std;
bool debug=false;
const int MAX=100;
typedef unsigned long long timestamp_t;
static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
    }

pair<int,vector<int> > getLis(vector<int> arr){
	if(debug){
		cout<<"arr : ";
		for(int i=0;i<arr.size();++i)cout<<arr[i]<<" ";
		cout<<endl;
	}
	int n=arr.size(),index;
	vector<int> m(n,1<<29) , p(n,-1) , v(n,1<<29);
	m[0]=0;
	v[0]=arr[0];
	p[0]=0;
	int l=1;
	for(int i=1;i<n;++i){
		index=upper_bound(v.begin(),v.begin()+l,arr[i])-v.begin()-1;
		p[i]=index>=0?m[index]:i;
		if(debug){
			cout<<i<<" >> for "<<arr[i]<<" : arr["<<index<<"]="<<arr[index]<<endl;
			cout<<"v : ";
			for(int i=0;i<l;++i)cout<<v[i]<<"\t";
			cout<<endl;
			
			cout<<"m : ";
			for(int i=0;i<l;++i)cout<<m[i]<<"\t";
			cout<<endl;
			
			cout<<"p : ";
			for(int i=0;i<n;++i)cout<<p[i]<<"\t";
			cout<<endl;
			
			cout<<endl;
		}
		if(v[index+1]>arr[i]){
			v[index+1]=arr[i];
			m[index+1]=i;
			l=l>index+2?l:index+2;
		}
	}
	index=m[l-1];
	vector<int> lis(l);
	for(int i=l-1;i>=0;--i){
		lis[i]=arr[index];
		index=p[index];
	}
	/*if(debug){
		cout<"Sending : ";
		for(int i=0;i<l;++i)cout<<lis[i]<<" ";
		cout<<endl<<endl;
	}*/
	return make_pair(l,lis);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	srand(time(NULL));
	int t,T,n;
	scanf("%d",&T);
	vector<timestamp_t> time(T);
	timestamp_t begin,end;
	for(t=0;t<T;t++){
		scanf("%d",&n);
		begin = get_timestamp();
		vector<int> arr(n,-1) , seq(2*n/3) , noise(n-2*n/3);
		for(int i=0;i<2*n/3;++i)seq[i]=rand()%MAX+MAX/2+i;
		for(int i=0;i<n-2*n/3;++i)noise[i]=rand()%MAX-MAX/2;
		int i1=0,i2=0;
		sort(seq.begin(),seq.end());
		//for(int i=1;i<seq.size();++i)if(seq[i]==seq[i-1])seq[i]+=1;
		if(debug){
			cout<<"seq : ";
			for(int i=0;i<seq.size();++i)cout<<seq[i]<<" ";
			cout<<endl;
		}
		for(int i=0;i<n;i+=3){
			arr[i]=seq[i1++];
			if(i+1<n)arr[i+1]=seq[i1++];
			if(i+2<n)arr[i+2]=noise[i2++];
		}
		pair<int,vector<int> > soln=getLis(arr);
		vector<int> lis=soln.second;
		int l=soln.first;
		bool check=true;
		if(debug)cout<<"lis : ";
		if(debug)cout<<lis[0]<<" ";
		for(int i=1;i<l;++i){
			if(debug)cout<<lis[i];
			if(lis[i]<lis[i-1]){
				check=false;
				if(debug)cout<<"<"<<lis[i-1];
				//break;
			}
			if(debug)cout<<" ";
		}
		end=get_timestamp();
		time[t]=end-begin;
		if(debug)cout<<endl;
		if(check)printf("success\n");
		else printf("failed\n");
	}
	cout<<"^{\"type\":\"data\",\"obj\":[";
	for(int i=0;i<T-1;++i)cout<<"\""<<time[i]<<"\",";
	cout<<"\""<<time[T-1]<<"\"],\"name\":\"computational time\"}\n";
	return 0;
}

