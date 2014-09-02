#include<iostream>
using namespace std;
void print(int left , int right, string str)
{
	if(left>0){
		print(left-1,right,str+"(");
	}
	if(left<right){
		print(left,right-1,str+")");
	}
	if(left==0 && right==0 ){
		cout<<str<<endl;
	}
}
int main()
{
	int n;cin>>n;
	print(n,n,"");
	return 0;
}
