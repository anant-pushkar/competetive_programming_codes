/*
Project name : Consecutive_Subsequences
Created on : Fri Jul  4 12:13:51 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w6/challenges/consecutive-subsequences
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
class Solver{
	int n , k;
	lld count;
	void update(int index , int a , vector<int> &lookup , vector<int> &arr){
		//arr[i] = number of sequences s ending at a such that sum(s)%k==i
		for(int i=0;i<k;++i){
			arr[i] = lookup[(i+10000*k-a)%k];
		}
		++arr[a%k];
		count += arr[0];
		if(debug){
			cout<<"at a="<<a<<endl;
			for(int i=0;i<k;++i){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			cout<<"Count : "<<count<<endl<<endl;
		}
	}
public:
	Solver(int size , int num):
	n(size),
	k(num){
		int a;
		vector<int> arr(k,0) , lookup(k,0);
		
		scanf("%d",&a);
		lookup[a%k] = 1;
		count = lookup[0];
		
		if(debug){
			cout<<"lookup : ";
			for(int i=0;i<k;++i){
				cout<<lookup[i]<<" ";
			}
			cout<<endl<<"count:"<<count<<endl<<endl;
		}
		
		for(int i=1;i<n;++i){
			scanf("%d",&a);
			update(i , a , i%2==1 ? lookup : arr , i%2==1 ? arr : lookup);
		}
	}
	lld solve(){
		return count;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n , k;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d",&n,&k);
		Solver s(n,k);
		printf("%lld\n",s.solve());
	}
	
	return 0;
}

