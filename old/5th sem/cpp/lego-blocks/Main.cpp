#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
const int MOD=1000000007;
int getCount(int N , int M){
	int count=0;
	
	return count%MOD;
}
using namespace std;
int main() {
    int T;cin>>T;
	int N,M;
	for(int t=0;t<T;t++){
		cin>>N>>M;
		cout<<getCount(N,M)<<endl;
	}
    return 0;
}
