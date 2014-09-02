/*
Project name : Sorting_Bank_Accounts
Created on : Wed May 28 11:42:46 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SBANK/
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	int n;
	char line[64];
	map<string,int> freq;
	map<string,int>::iterator iter ;
	while(t--){
		if(debug)cout<<"start : "<<t<<endl;
		scanf("%d",&n);
		if(debug)cout<<"n : "<<n<<endl;
		freq.clear();
		fgets(line, 64, stdin);
		while(n--){
			fgets(line, 64, stdin);
			line[32] = 0;
			++freq[line] ;
			if(debug)cout<<"n : "<<n<<" : "<<line<<endl;
		}
		
		for(iter=freq.begin() ; iter!=freq.end() ; ++iter){
			cout<<iter->first<<iter->second<<endl;
		}
		cout<<endl;
		if(debug)cout<<"end : "<<t<<endl;
	}
	return 0;
}

