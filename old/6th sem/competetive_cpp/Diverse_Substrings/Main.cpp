/*
Project name : Diverse_Substrings
Created on : Fri Jan 17 21:28:11 2014
Author : Anant Pushkar
codeforces testing round problem C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[300001];
	scanf("%s,",str);
	int l=strlen(str);
	vector<int>div(26,0);
	vector<bool>lookup(26,false);
	vector<int> last(26,0),lastseen(l,-1);
	int count=0;
	for(int i=0;i<l;++i){
		if(!lookup[str[i]-'a']){
			lookup[str[i]-'a']=true;
			++count;
		}
		lastseen[i]=last[str[i]-'a'];
		last[str[i]-'a']=i;
	}
	vector<vector<int> > freq(l,vector<int>(count,0));
	int lim;
	freq[0][0]=1;
	for(int i=1;i<l;++i){
		if(str[i]==str[i-1]){
			for(int j=0;j<count;++j){
				freq[i][j]=freq[i-1][j]+1;
			}
		}else{
			freq[i][0]=1;
			for(int j=1;j<count;++j){
				freq[i][j]=freq[i-1][j-1];
			}
		}
	}
	printf("%d\n",count);
	int sum;
	for(int i=0;i<count;++i){
		sum=0;
		for(int j=0;j<l;++j)sum+=freq[j][i];
		printf("%d\n",sum);
	}
	return 0;
}

