#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;
void printSeq(vector<int> arr , int start , int end){
	for(int i=start;i<end+1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void printAll(vector<int> arr){
	map<int,stack<int> > lookup;
	map<int,stack<int> >::iterator it;
	stack<int> temp;
	int sum=0;
	lookup[0]=stack<int>();
	lookup[0].push(-1);
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
		it=lookup.find(sum);
		if(it!=lookup.end()){
			lookup[sum].push(i);
		}else{
			lookup[sum]=stack<int>();
			lookup[sum].push(i);
		}
	}
	/*
	for(it=lookup.begin();it!=lookup.end();it++){
		cout<<it->first<<" : ";
		temp=it->second;
		while(!temp.empty()){
			cout<<temp.top()<<" ";
			temp.pop();
		}
		cout<<endl;
	}*/
	int start=0,end=0;
	for(it=lookup.begin();it!=lookup.end();it++){
		temp=it->second;
		while(temp.size()>1){
			end=temp.top();
			temp.pop();
			printSeq(arr,temp.top()+1,end);
		}
	}
}
int main()
{
	int n;cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++) cin>>arr[i];
	printAll(arr);
	return 0;
}
