/*
Project name : Find_the_Clones
Created on : Fri Aug  1 14:24:35 2014
Author : Anant Pushkar
http://www.spoj.com/problems/CLONE/
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	map<string,int> count;
	map<string,int>::iterator it;
	vector<int> freq;
	string dna;
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0){
			break;
		}
		freq = vector<int>(n,0);
		count.clear();
		while(n--){
			cin>>dna;
			if(count.find(dna)==count.end()){
				count[dna]  = 0;
			}else{
				count[dna] += 1;
			}
		}
		for(it=count.begin() ; it!=count.end() ; ++it){
			++freq[it->second];
		}
		n = freq.size();
		for(int i=0;i<n;++i){
			printf("%d\n",freq[i]);
		}
	}
	return 0;
}

