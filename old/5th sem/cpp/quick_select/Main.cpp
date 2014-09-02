#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
const int MAX=100;
inline void swap(int &a , int &b){
	//cout<<"Swaping : "<<a<<" , "<<b<<endl;
	if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}
int quick_select(vector<int> arr , int k , int start , int end){
	cout<<endl<<endl<<"Searching at order "<<k<<" in : ";
	for(int i=start;i<end;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int index=rand()%(end-start)+start;
	int pivot = arr[index] , i=start , j=end-1;
	if(arr[start]!=arr[index])swap(arr[start],arr[index]);
	cout<<"Pivot : "<<pivot<<endl;
	while(1){
		while(arr[j]>=pivot) j--;
		while(arr[i]< pivot) i++;
		if(i>=j) break;
		swap(arr[i],arr[j]);
	}
	for(int q=end-1;q>i;q--){
		if(arr[q]==pivot){
			swap(arr[q],arr[i]);
			i++;
		}
	}
	cout<<"Processed array : ";
	for(int i=start;i<end;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	if(j<k-1 && i>=k-1) return pivot;
	if(j>=k-1)  return quick_select(arr , k , start , j+1);
	else       return quick_select(arr , k , i , end);
}
void partial_sort(vector<int> &arr , int start , int end , int k , bool isSorted){
	cout<<"Partial sort called on : ";
	for(int i=start;i<end;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"start : "<<start<<" end : "<<end<<" k : "<<k<<endl;
	if(k<start || k>=end || start>=end-1) return;
	int index=rand()%(end-start)+start;
	int pivot=arr[index] , i=start , j=end-1;
	if(arr[index]!=arr[start])swap(arr[start],arr[index]);
	while(1){
		while(arr[j]>=pivot) j--;
		while(arr[i] <pivot) i++;
		if(i>=j) break;
		swap(arr[i],arr[j]);
	}
	for(int q=end-1;q>i;q--){
		if(arr[q]==pivot){
			swap(arr[q],arr[i]);
			i++;
		}
	}
	cout<<endl<<endl;
	if(isSorted || (k>=start && k<=j) )partial_sort(arr , start , j+1 , k , isSorted);
	if(isSorted || (k>=i && k<end) )partial_sort( arr , i , end , k , isSorted );
}
int main()
{
	srand(time(NULL));
	
	cout<<"Enter number of elements (n) : ";
	int n;cin>>n;
	
	cout<<"Enter order (k) : ";
	int k;cin>>k;
	
	if(k>n || k<0 || n<0){
		cout<<"Invalid input"<<endl;
		return 0;
	}
	
	vector<int> arr(n);
	cout<<"Generating array :"<<endl;
	for(int i=0;i<n;i++){
		arr[i]=rand()%MAX;
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	partial_sort(arr,0,n,k,false);
	cout<<"Partially sorted array :"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	//cout<<k<<"th smallest element in the array is : "<<quick_select(arr,k,0,n)<<endl;
	
	return 0;
}
