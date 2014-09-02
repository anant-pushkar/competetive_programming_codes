/*
Project name : Kolya_and_Tandem_Repeat
Created on : Sun Jun 22 10:21:09 2014
Author : Anant Pushkar
http://codeforces.com/contest/443/problem/B
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
bool compare(const void *s1 , const void* s2){
	return strcmp((char*)s1,(char*)s2)<=0;
}
bool is_prefix(char *prefix , char*str){
	int len = strlen(prefix);
	if(len>strlen(str)){
		if(debug)cout<<len<<" "<<strlen(str)<<endl;
		return false;
	}
	for(int i=0;i<len;++i){
		if(prefix[i]!=str[i]){
			if(debug)cout<<"mismatch "<<prefix[i]<<" "<<str[i]<<endl;
			return false;
		}
	}
	return true;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	char str[201];
	scanf("%s",str);
	int len = strlen(str);
	vector<char*> suffix_arr(len);
	for(int i=0;i<len;++i){
		suffix_arr[i] = str+i;
	}
	sort(suffix_arr.begin(),suffix_arr.end(),compare);
	if(debug){
		for(int i=0;i<len;++i){
			cout<<suffix_arr[i]<<endl;
		}
	}
	int n,max=0,l1,l2 , l;
	scanf("%d",&n);
	char* p , *s;
	for(int i=1;i<len;++i){
		for(int j=1;i-j>-1;++j){
			l1 = strlen(suffix_arr[i-j]);
			l2 = strlen(suffix_arr[i]);
			p = l1<l2 ? suffix_arr[i-j] : suffix_arr[i];
			s = l1<l2 ? suffix_arr[i] : suffix_arr[i-j];
			l = strlen(s)-2*strlen(p);
			if(debug)cout<<"looking for "<<p<<" "<<s<<" l:"<<l<<endl;
			if(is_prefix(p,s) && l<=n && l>0){
				if(debug)cout<<p<<" "<<s<<endl;
				l += strlen(s) ;
				max = max<l ? l : max;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}

