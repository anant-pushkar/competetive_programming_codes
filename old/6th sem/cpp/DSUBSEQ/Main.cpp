/*
Project name : DSUBSEQ
Created on : Thu Dec 19 14:53:20 2013
http://www.spoj.com/problems/DSUBSEQ/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
const int mod=1000000007;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,l;scanf("%d",&t);
	char s[100002];
	vector<int> dp,last,sum;
	while(t--){
		scanf("%s",s);
		l=strlen(s);
		dp=vector<int>(l+1,0);
		sum=vector<int>(l+1,0);
		last=vector<int>(26,-1);
		dp[0]=1;
		sum[0]=1;
		for(int i=1;i<=l;++i){
			dp[i]=sum[i-1]%mod - (last[s[i-1]-'A']!=-1?sum[last[s[i-1]-'A']]%mod:0) ;
			dp[i]=(dp[i]+mod)%mod;
			
			sum[i]=(sum[i-1] + dp[i])%mod;
			
			last[s[i-1]-'A']=i-1;
		}
		printf("%d\n",sum[l]);
	}
	return 0;
}

