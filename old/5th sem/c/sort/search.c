#include"search.h"
long int Search(Array arr , int key)
{
	if(arr.count==0) return -1;
	long int i = _binarySearch(arr.head,0,arr.count,key);
	return arr.head[i]==key ? i : -1 ;
}
long int _binarySearch(int* arr , long int lo , long int hi , int k)
{
	if(hi==lo+1) return arr[lo]==k ?  lo : hi ;//return lo if k found at lo otherwise hi
	long int mid = (hi+lo)>>1 ;//mid=(hi+lo)/2
	if(arr[mid]>k) return _binarySearch(arr,lo,mid,k);
	else if(arr[mid]==k) return mid;
	else return _binarySearch(arr,mid+1,hi,k);
}