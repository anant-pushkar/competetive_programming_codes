#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSum(vector<int> arr){
	int len=arr.size();
	vector<int> lookup(len,0);
	lookup[0]=arr[0];
	lookup[1]=arr[1];
	
	for(int i=2;i<len;i++){
		lookup[i]=*max_element(lookup.begin(),lookup.begin()+i-1)+arr[i];
	}
	/*for(int i=0;i<len;i++){
		cout<<lookup[i]<<" ";
	}
	cout<<endl;*/
	
	return *max_element(lookup.begin(),lookup.end());
}
int main()
{
	int T;cin>>T;
	int N;
	vector<int> arr;
	for(int t=0;t<T;t++){
		cin>>N;
		arr=vector<int>(N,0);
		for(int n=0;n<N;n++){
			cin>>arr[n];
		}
		cout<<maxSum(arr)<<endl;
	}
	return 0;
}
