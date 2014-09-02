#include<iostream>
#include<vector>
using namespace std;
void swap(int &a ,int &b){
	cout<<"swapping "<<a<<","<<b<<endl;
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void traverse(vector<int>& arr){
	int i1=-1,i2=-1,i3=-1,len=arr.size();
	for(int i=0;i<len;i++){
		cout<<"i="<<i<<" i1="<<i1<<" i2="<<i2<<" i3="<<i3<<endl;
		cout<<endl;cout<<endl;
		for(int j=0;j<len;j++){
			if(j==i)cout<<"*";
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		if(arr[i]==1){
			if(i1==-1) i1=i;
			if(i1<i-1){
				swap(arr[i1+1],arr[i]);
				i1++;
				if(arr[i]==3 && i3==i1+1)i3=i;
				else{
					if(i2!=-1){
						swap(arr[i],arr[i2+1]);
						i2++;
					}
				}
			}else i1=i;
			continue;
		}
		if(arr[i]==2){
			if(i2==-1)i2=i;
			if(i2<i-1){
				swap(arr[i2+1],arr[i]);
				if(arr[i]==3 && i3==i2+1){
					i3++;
					i2++;
				}
				if(arr[i]==1){
					swap(arr[i1+1],arr[i]);
					swap(arr[i2+1],arr[i]);
				}
				i2++;
			}else i2=i;
			/*if(i3<i2){
				swap(arr[i1+1],arr[i]);
				i2=i1+1;
			}*/
			continue;
		}
		if(arr[i]==3){
			i3=i;
			continue;
		}
	}
}
int main()
{
	int n;cin>>n;
	vector<int> arr(n,-1);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	traverse(arr);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
