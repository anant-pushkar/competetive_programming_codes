/*
Project name : mittens
Created on : Wed Dec 11 15:35:16 IST 2013
http://codeforces.com/contest/370/problem/C

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
    if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
    int n,m,c;scanf("%d %d",&n,&m);
    int arr[n],match[n];
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
        match[i]=arr[i];
    }
    sort(arr,arr+n);
    sort(match,match+n);
    reverse(match,match+n);
    int count=0;
    for(int i=0;i<n;++i){
        if(arr[i]!=match[i])++count;
		else{
			for(int j=0;j<n;++j)if(i!=j){
				if(arr[j]!=arr[i] && match[j]!=arr[i] && match[i]!=match[j] && match[i]!=arr[j]){
					match[i]=match[i]^match[j];
					match[j]=match[i]^match[j];
					match[i]=match[i]^match[j];
					++count;
					break;
				}
			}
		}
    }
    printf("%d\n",count);
    for(int i=0;i<n;++i){
        printf("%d %d\n",arr[i],match[i]);
    }
    return 0;
}