/*
Project name : Little_Pony_and_Sort_by_Shift
Created on : Fri Aug  1 21:10:19 2014
Author : Anant Pushkar

*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	cin>>n;
	vector<int> arr(2*n);
	
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
		arr[i+n] = arr[i];
	}
	
	int max_count=0 , max_index=-1 , count=0;
	bool check = true;
	for(int i=1;i<2*n;++i){
		if(arr[i-1]<=arr[i]){
			++count;
		}else{
			if(max_count<count){
				max_count = count;
				max_index = i;
			}
			count=0;
		}
		check = check && arr[i-1]==arr[i];
	}
	if(check){
		cout<<0<<endl;
	}else if(max_count==n-1){
		cout<<(max_index==n ? 0 : 2*n-max_index)<<endl;
	}else{
		cout<<-1<<endl;
	}
	
	return 0;
}

