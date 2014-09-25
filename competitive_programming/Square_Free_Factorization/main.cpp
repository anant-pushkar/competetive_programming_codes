/*
Project name : Square_Free_Factorization
Created on : Thu Sep 25 18:04:42 2014
Author : Anant Pushkar
http://www.spoj.com/problems/AMR10C/'
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
vector<int> primes;
int n_primes;
void init(){
	vector<bool> is_prime(1000001 , true);
	n_primes=0;
	for(int i=2;i<1000001;++i)if(is_prime[i]){
		++n_primes;
		for(int j=2*i;j<1000001;j+=i){
			is_prime[j] = false;
		}
	}
	
	primes = vector<int>(n_primes);
	int index=0;
	for(int i=2;i<1000001;++i)if(is_prime[i]){
		primes[index++] = i;
	}
}
int get_count(int n){
	int max = 0 , p=0 , m=n;
	for(int i=2;m>0 && i<=n;++i)if(m%i==0){
		while(m>0 && m%i==0){
			m /= i;
			++p;
		}
		max = max>p ? max : p;
		p = 0;
	}
	return max;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	//init();
	
	int n;
	while(t--){
		scanf("%d",&n);
		printf("%d\n",get_count(n));
	}
	
	return 0;
}

